#include "stdafx.h"
#include "ZdrkService.h"
#include "../psi-stkmanage/dao/CommonDAO.h"
#include "../psi-stkmanage/dao/Zdrk/ZdrkDao.h"
#include "../../../lib-common/include/SnowFlake.h"

int ZdrkService::saveBillData(const AddZdrkBillDTO& dto, const PayloadDTO& payload)
{
	// 数据校验
	if ((dto.getSave() != 0 && dto.getSave() != 1) ||
		[](const AddZdrkBillDTO& dto) {
			for (auto& list : dto.getDetail()) {
				if (list.getEntryNo() < 0 || list.getQty() < 0 || list.getCost() < 0 || list.getPrice() < 0) {
					return true;
				}
			}
			return false;
		}(dto)) {
		return -1;
	}

	// 定义DAO层对象
	ZdrkDAO zDao;
	CommonDAO cDao;

	// 上传附件
	// 定义传入数据库内的附件名称
	string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = cDao.insertAttachment(file);
		cout << fileName << endl;
		if (!fileName.empty()) {
			if (attachment.size() != 0) {
				attachment += ",";
			}
			attachment += fileName;
		}
		else {
			return -4;
		}
	}

	// 组装数据
	StkIoDO data1;
	SnowFlake sf(1, 5);
	string mid = to_string(sf.nextId());
	data1.setId(mid);
	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSubject(dto.getSubject());
	data1.setStockIoType("198"); // "198":涨吨入库
	data1.setSupplierId(cDao.selectSupplyIdByAuxName(dto.getSupplier()));
	data1.setHandler(dto.getHandler());
	data1.setCost([](const list<ZdrkBillDetailDTO>& details) {
		double cost = 0;
		for (const auto& entry : details) {
			cost += entry.getCost();
		}
		return cost;
		}(dto.getDetail()));
	data1.setRemark(dto.getRemark());
	data1.setBillStage((dto.getSave() == 0 ? "12" : "14")); // "12":编制中, "14":编制完
	data1.setAttachment(attachment);
	data1.setSysOrgCode(cDao.selectOrgCodeByUsername(payload.getUsername()));
	data1.setCreateBy(payload.getUsername());
	// 生成当前时间
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data1.setCreateTime(string(buffer));
	// 事务开始
	zDao.getSqlSession()->beginTransaction();
	// 执行数据添加
	uint64_t row = zDao.insert(data1);
	if (row == 0) {//失败
		// 回滚
		zDao.getSqlSession()->rollbackTransaction();
		// 删除附件
		vector<string_view> fileNames = split(attachment, ",");
		if (!fileNames.empty()) {
			for (const auto& file : fileNames) {
				cDao.deleteAttachment(string(file));
			}
		}
		return -2;
	}

	// 组装明细数据
	StkIoEntryDO data2;
	for (auto& entry : dto.getDetail()) {
		data2.setId(to_string(sf.nextId()));
		data2.setMid(mid);
		data2.setBillNo(dto.getBillNo());
		data2.setEntryNo(to_string(entry.getEntryNo()));
		data2.setMaterialId(cDao.selectMaterialIdByAuxName(entry.getMaterial()));
		data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
		data2.setWarehouseId(cDao.selectWarehouseIdByAuxName(entry.getWarehouse()));
		data2.setStockIoDirection("1");
		data2.setUnitId(cDao.selectUnitIdByName(entry.getUnit()));
		data2.setQty(entry.getQty());
		data2.setPrice(entry.getPrice());
		data2.setCost(entry.getCost());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		if (zDao.insert(data2) == 0) {
			// 回滚
			zDao.getSqlSession()->rollbackTransaction();
			// 删除附件
			vector<string_view> fileNames = split(attachment, ",");
			if (!fileNames.empty()) {
				for (const auto& file : fileNames) {
					cDao.deleteAttachment(string(file));
				}
			}
			return -3;
		}
	}
	// 提交
	zDao.getSqlSession()->commitTransaction();
	return row;
}

int ZdrkService::updateBillData(const ModifyZdrkBillDTO& dto, const PayloadDTO& payload)
{
	// 数据校验
	if ((dto.getSave() != 0 && dto.getSave() != 1) ||
		[](const ModifyZdrkBillDTO& dto) {
			for (auto& list : dto.getDetail()) {
				if (list.getEntryNo() < 0 || list.getQty() < 0 || list.getCost() < 0 || list.getPrice() < 0) {
					return true;
				}
			}
			return false;
		}(dto)) {
		return -1;
	}

	// 定义DAO层对象
	ZdrkDAO zDao;
	CommonDAO cDao;

	// 查询表中对应单据的附件名
	string attachments = cDao.selectAttachmentByBillNo(dto.getBillNo());
	// 定义需删除的附件列表
	list<string> needDeleteFile;
	// 定义需新增的附件列表
	list<string> needUploadFile;

	// 组装数据
	StkIoDO data1;
	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSubject(dto.getSubject());
	data1.setSupplierId(cDao.selectSupplyIdByAuxName(dto.getSupplier()));
	data1.setHandler(dto.getHandler());
	data1.setCost([](const list<ZdrkBillDetailDTO>& details) {
		double cost = 0;
		for (const auto& entry : details) {
			cost += entry.getCost();
		}
		return cost;
		}(dto.getDetail()));
	data1.setRemark(dto.getRemark());
	data1.setBillStage((dto.getSave() == 0 ? "12" : "14")); // "12":编制中, "14":编制完
	data1.setAttachment([&](list<string> files) -> string { // 更新附件
		string result = "";
		// 数据表中附件名列表
		vector<string_view> fileNames = split(attachments, ",");
		for (const auto& file : files) {
			auto it = find(fileNames.begin(), fileNames.end(), file);
			if (it != fileNames.end()) { // 原有的附件
				if (!result.empty()) {
					result += ",";
				}
				result += file;
				fileNames.erase(it);
			}
			else { // 新增附件
				if (!result.empty()) {
					result += ",";
				}
				string f = cDao.insertAttachment(file);
				result += f;
				needUploadFile.push_back(f);
			}
		}
		if (!fileNames.empty()) { // 记录需要删除的附件
			for (const auto& file : fileNames) {
				needDeleteFile.push_back(string(file));
			}
		}
		return result;
		}(dto.getFiles()));
	data1.setUpdateBy(payload.getUsername());

	// 生成当前时间
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data1.setUpdateTime(string(buffer));
	// 事务开始
	zDao.getSqlSession()->beginTransaction();
	// 执行数据添加
	uint64_t row = zDao.update(data1);
	if (row == 0) {
		// 回滚
		zDao.getSqlSession()->rollbackTransaction();
		// 删除新增的附件
		if (!needUploadFile.empty()) {
			for (const auto& file : needUploadFile) {
				cDao.deleteAttachment(file);
			}
		}
		return -2;
	}

	if (!dto.getDetail().empty()) {
		// 组装明细数据
		StkIoEntryDO data2;
		// 原来存在的明细分录号
		list<int> oldEntryNo = cDao.selectEntryNoByBillNo(dto.getBillNo());
		for (auto& entry : dto.getDetail()) {
			data2.setBillNo(dto.getBillNo());
			data2.setEntryNo(to_string(entry.getEntryNo()));
			data2.setMaterialId(cDao.selectMaterialIdByAuxName(entry.getMaterial()));
			data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
			data2.setWarehouseId(cDao.selectWarehouseIdByAuxName(entry.getWarehouse()));
			data2.setUnitId(cDao.selectUnitIdByName(entry.getUnit()));
			data2.setSupplierId(cDao.selectSupplyIdByAuxName(dto.getSupplier()));
			data2.setQty(entry.getQty());
			data2.setPrice(entry.getPrice());
			data2.setCost(entry.getCost());
			data2.setRemark(entry.getRemark());
			data2.setCustom1(entry.getCustom1());
			data2.setCustom2(entry.getCustom2());
			auto it = find(oldEntryNo.begin(), oldEntryNo.end(), atoi(data2.getEntryNo().c_str()));
			if (it != oldEntryNo.end()) { // 更新原有的明细
				zDao.update(data2);
				oldEntryNo.erase(it);
			}
			else { // 新增明细
				SnowFlake sf(1, 5);
				data2.setId(to_string(sf.nextId()));
				data2.setMid(cDao.selectBillIdByBillNo(dto.getBillNo()));
				data2.setStockIoDirection("1");
				if (zDao.insert(data2) == 0) {
					// 回滚
					zDao.getSqlSession()->rollbackTransaction();
					// 删除新增的附件
					if (!needUploadFile.empty()) {
						for (const auto& file : needUploadFile) {
							cDao.deleteAttachment(file);
						}
					}
					return -3;
				}
			}
		}
		if (!oldEntryNo.empty()) {
			for (const auto& entryNo : oldEntryNo) { // 删除应该删除的明细
				zDao.deleteDetailById(dto.getBillNo(), entryNo);
			}
		}
	}

	// 提交
	zDao.getSqlSession()->commitTransaction();
	// 删除需要删除的附件
	if (!needDeleteFile.empty()) {
		for (const auto& file : needDeleteFile) {
			cDao.deleteAttachment(file);
		}
	}
	return row;
}

int ZdrkService::updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload)
{
	// 数据校验
	if (dto.getApprovalResultType() != 1 && dto.getApprovalResultType() != 2) {
		return -1;
	}
	// 组装数据
	StkIoDO data;
	data.setBillNo(dto.getBillId());
	data.setApprovalResultType(to_string(dto.getApprovalResultType()));
	data.setApprovalRemark(dto.getApprovalRemark());
	data.setApprover(payload.getUsername());
	data.setUpdateBy(payload.getUsername());
	// 生成当前时间
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data.setUpdateTime(string(buffer));
	if (dto.getApprovalResultType() == 1) { // 审核通过
		data.setIsEffective(1);
		data.setEffectiveTime(string(buffer));
		data.setIsClosed(1);
		data.setBillStage("34"); // "34":执行完
	}
	else { // 审核拒绝
		data.setBillStage("24"); // "24":核批完
	}

	// 定义DAO层对象
	ZdrkDAO dao;
	//// 事务开始
	//dao.getSqlSession()->beginTransaction();
	// 执行更新数据
	int row = dao.updateApproval(data);
	if (row == 0) {
		return -2;
	}
	return row;
}

int ZdrkService::updateStateToClose(const string& billNo, const PayloadDTO& payload)
{
	StkIoDO data;
	data.setBillNo(billNo);
	data.setIsClosed(1);

	// 生成当前时间
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data.setUpdateTime(buffer);
	data.setUpdateBy(payload.getUsername());
	ZdrkDAO dao;
	return dao.updateState(data);
}

int ZdrkService::updateStateToUnclose(const string& billNo, const PayloadDTO& payload)
{
	StkIoDO data;
	data.setBillNo(billNo);
	data.setIsClosed(0);

	// 生成当前时间
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data.setUpdateTime(buffer);
	data.setUpdateBy(payload.getUsername());
	ZdrkDAO dao;
	return dao.updateState(data);
}

int ZdrkService::updateStateToVoid(const string& billNo, const PayloadDTO& payload)
{
	StkIoDO data;
	data.setBillNo(billNo);
	data.setIsVoided(1);

	// 生成当前时间
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data.setUpdateTime(buffer);
	data.setUpdateBy(payload.getUsername());
	ZdrkDAO dao;
	return dao.updateState(data);
}

int ZdrkService::removeBillById(const string& billNo)
{
	ZdrkDAO pDao;
	CommonDAO cDao;
	// 删除明细
	pDao.deleteDetailById(billNo);
	// 附件
	string attachments = cDao.selectAttachmentByBillNo(billNo);
	if (!attachments.empty()) { // 删除附件
		vector<string_view> attachment = split(attachments, ",");
		for (const auto& file : attachment) {
			cDao.deleteAttachment(string(file));
		}
	}
	// 删除单据
	return pDao.deleteBillById(billNo);
}


