#include "stdafx.h"
#include "ZdrkService.h"
#include "../psi-stkmanage/dao/CommonDAO.h"
#include "../../dao/Zdrk/ZdrkDAO.h"
#include "../../../lib-common/include/SnowFlake.h"
#include "FastDfsClient.h"
#include <ctime>

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
	
#ifdef LINUX
	// 定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	// 定义客户端对象
	FastDfsClient client("1.15.240.108");
#endif

	// 定义传入数据库内的附件名称
	string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = client.uploadFile(file);
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
	data1.setSupplierId(dto.getSupplier());
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
				client.deleteFile(string(file));
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
		data2.setEntryNo(entry.getEntryNo());
		data2.setMaterialId(entry.getMaterial());
		data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
		data2.setWarehouseId(entry.getWarehouse());
		data2.setStockIoDirection("1");
		data2.setUnitId(entry.getUnit());
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
					client.deleteFile(string(file));
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

#ifdef LINUX
	// 定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	// 定义客户端对象
	FastDfsClient client("1.15.240.108");
#endif

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
	data1.setSupplierId(dto.getSupplier());
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
				string f = client.uploadFile(file);
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
				client.deleteFile(file);
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
			data2.setEntryNo(entry.getEntryNo());
			data2.setMaterialId(entry.getMaterial());
			data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
			data2.setWarehouseId(entry.getWarehouse());
			data2.setUnitId(entry.getUnit());
			data2.setSupplierId(dto.getSupplier());
			data2.setQty(entry.getQty());
			data2.setPrice(entry.getPrice());
			data2.setCost(entry.getCost());
			data2.setRemark(entry.getRemark());
			data2.setCustom1(entry.getCustom1());
			data2.setCustom2(entry.getCustom2());
			auto it = find(oldEntryNo.begin(), oldEntryNo.end(), data2.getEntryNo());
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
							client.deleteFile(file);
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
			client.deleteFile(file);
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

#ifdef LINUX
	// 定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	// 定义客户端对象
	FastDfsClient client("1.15.240.108");
#endif

	string attachments = cDao.selectAttachmentByBillNo(billNo);
	if (!attachments.empty()) { // 删除附件
		vector<string_view> attachment = split(attachments, ",");
		for (const auto& file : attachment) {
			client.deleteFile(string(file));
		}
	}
	// 删除单据
	return pDao.deleteBillById(billNo);
}


//查询单据列表
PageVO<QueryZdrkBillListVO> ZdrkService::listZdrkBillList(const QueryZdrkBillListQuery& query)
{
	//构建返回对象
	PageVO<QueryZdrkBillListVO> billList;
	StkIoDO obj;

	ZdrkDAO dao;

	list<StkIoDO> result = dao.selectBillList(query);
	list<QueryZdrkBillListVO> vr;
	for (StkIoDO sub : result)
	{
		QueryZdrkBillListVO vo;
		vo.setId(sub.getId());
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSrcBillId(sub.getSrcBillId());
		vo.setSrcNo(sub.getSrcNo());
		vo.setSubject(sub.getSubject());
		vo.setIsRubric(sub.getIsRubric());
		vo.setStockIoType(sub.getStockIoType());
		vo.setOpDept(sub.getOpDept());
		vo.setOperator1(sub.getOperator1());
		vo.setHandler(sub.getHandler());
		vo.setHasRp(sub.getHasRp());
		vo.setHasSwell(sub.getHasSwell());
		vo.setSupplierId(sub.getSupplierId());
		vo.setCustomerId(sub.getCustomerId());
		vo.setInvoiceType(sub.getInvoiceType());
		vo.setCost(sub.getCost());
		vo.setSettleAmt(sub.getSettleAmt());
		vo.setSettledAmt(sub.getSettledAmt());
		vo.setInvoicedAmt(sub.getInvoicedAmt());
		vo.setAttachment(sub.getAttachment());
		vo.setRemark(sub.getRemark());
		vo.setIsAuto(sub.getIsAuto());
		vo.setBillStage(sub.getBillStage());
		vo.setApprover(sub.getApprover());
		vo.setBpmiInstanceId(sub.getBpmiInstanceId());
		vo.setApprovalResultType(sub.getApprovalResultType());
		vo.setApprovalRemark(sub.getApprovalRemark());
		vo.setIsEffective(sub.getIsEffective());
		vo.setEffectiveTime(sub.getEffectiveTime());
		vo.setIsClosed(sub.getIsClosed());
		vo.setIsVoided(sub.getIsVoided());
		vo.setSysOrgCode(sub.getSysOrgCode());
		vo.setCreateBy(sub.getCreateBy());
		vo.setCreateTime(sub.getCreateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setVersion(sub.getVersion());

		vr.push_back(vo);
	}
	billList.setRows(vr);

	return billList;
}




//查询单据详细信息
QueryZdrkBillDetailsVO ZdrkService::getZdrkBillDetails(const QueryZdrkBillDetailsQuery& query)
{
	//构建返回对象
	QueryZdrkBillDetailsVO details;

	//
	StkIoDO SIDO;
	SIDO.setBillNo(query.getBillNo());
	StkIoEntryDO SIEDO;
	SIEDO.setBillNo(query.getBillNo());

	ZdrkDAO dao;

	list<StkIoDO> result = dao.selectBillListByBillNo(query.getBillNo());

	for (StkIoDO sub : result)
	{
		details.setId(sub.getId());
		details.setBillNo(sub.getBillNo());
		details.setBillDate(sub.getBillDate());
		details.setSrcBillType(sub.getSrcBillType());
		details.setSrcBillId(sub.getSrcBillId());
		details.setSrcNo(sub.getSrcNo());
		details.setSubject(sub.getSubject());
		details.setIsRubric(sub.getIsRubric());
		details.setStockIoType(sub.getStockIoType());
		details.setOpDept(sub.getOpDept());
		details.setOperator1(sub.getOperator1());
		details.setHandler(sub.getHandler());
		details.setHasRp(sub.getHasRp());
		details.setHasSwell(sub.getHasSwell());
		details.setSupplierId(sub.getSupplierId());
		details.setCustomerId(sub.getCustomerId());
		details.setInvoiceType(sub.getInvoiceType());
		details.setCost(sub.getCost());
		details.setSettleAmt(sub.getSettleAmt());
		details.setSettledAmt(sub.getSettledAmt());
		details.setInvoicedAmt(sub.getInvoicedAmt());
		details.setAttachment(sub.getAttachment());
		details.setRemark(sub.getRemark());
		details.setIsAuto(sub.getIsAuto());
		details.setBillStage(sub.getBillStage());
		details.setApprover(sub.getApprover());
		details.setBpmiInstanceId(sub.getBpmiInstanceId());
		details.setApprovalResultType(sub.getApprovalResultType());
		details.setApprovalRemark(sub.getApprovalRemark());
		details.setIsEffective(sub.getIsEffective());
		details.setEffectiveTime(sub.getEffectiveTime());
		details.setIsClosed(sub.getIsClosed());
		details.setIsVoided(sub.getIsVoided());
		details.setSysOrgCode(sub.getSysOrgCode());
		details.setCreateBy(sub.getCreateBy());
		details.setCreateTime(sub.getCreateTime());
		details.setUpdateBy(sub.getUpdateBy());
		details.setUpdateTime(sub.getUpdateTime());
		details.setVersion(sub.getVersion());
	}


	list<StkIoEntryDO> result1 = dao.selectBillDetails(query.getBillNo());
	list<ZdrkBillEntryVO> vr;
	for (StkIoEntryDO sub : result1)
	{
		ZdrkBillEntryVO vo;
		vo.setBatchNo(sub.getBatchNo());
		vo.setBillNo(sub.getBillNo());
		vo.setCost(sub.getCost());
		vo.setCustom1(sub.getCustom1());
		vo.setCustom2(sub.getCustom2());
		vo.setDiscountRate(sub.getDiscountRate());
		vo.setEntryNo(sub.getEntryNo());
		vo.setExpense(sub.getExpense());
		vo.setInvoicedAmt(sub.getInvoicedAmt());
		vo.setInvoicedQty(sub.getInvoicedQty());
		vo.setMaterialId(sub.getMaterialId());
		vo.setMid(sub.getMid());
		vo.setPrice(sub.getPrice());
		vo.setQty(sub.getQty());
		vo.setRemark(sub.getRemark());
		vo.setSettleAmt(sub.getSettleAmt());
		vo.setSettleQty(sub.getSettleQty());
		vo.setSrcBillId(sub.getSrcBillId());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSrcNo(sub.getSrcNo());
		vo.setStockIoDirection(sub.getStockIoDirection());
		vo.setSupplierId(sub.getSupplierId());
		vo.setSwellQty(sub.getSwellQty());
		vo.setTax(sub.getTax());
		vo.setTaxRate(sub.getTaxRate());
		vo.setUnitId(sub.getUnitId());
		vo.setVersion(sub.getVersion());
		vo.setWarehouseId(sub.getWarehouseId());

		vr.push_back(vo);
	}
	details.setEntry(vr);



	return details;

}
