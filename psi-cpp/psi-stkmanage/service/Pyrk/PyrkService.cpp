#include "stdafx.h"
#include "PyrkService.h"
#include "../../dao/Pyrk/PyrkDao.h"
#include"domain/do/Pyrk/QueryPyrkBillListDo.h"
#include "../../../lib-common/include/SnowFlake.h"
#include "../../../lib-common/include/StringUtil.h"
#include <ctime>
#include <algorithm>
//#include "../../dao/sample/SampleDAO.h"
PageVO<QueryPyrkBillListVO> PyrkService::queryAllFitBill(const QueryPyrkBillListQuery& query) {
	//构建返回对象
	PageVO<QueryPyrkBillListVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	QueryPyrkBillListDo obj; //这是查询数据库的条件  封装成类
	obj.setId(query.getId());
	obj.setBeginData(query.getBeginData());
	obj.setEndData(query.getEndData());
	obj.setTheme(query.getTheme());
	obj.setStage(query.getStage());
	obj.setIsClosed(query.getIsClosed());
	obj.setIsEffective(query.getIsEffective());
	obj.setIsVoided(query.getIsVoided());
	//SampleDAO dao;
	return pages;
}

int PyrkService::saveBillData(const PyrkBillDetailDTO& dto, const PayloadDTO& payload)
{
	// 数据校验
	if ((dto.getSave() != 0 && dto.getSave() != 1) ||
		[](const PyrkBillDetailDTO& dto) {
			for (auto& list : dto.getDetail()) {
				if (list.getEntryNo() < 0 || list.getQty() < 0 || list.getCost() < 0) {
					return true;
				}
			}
			return false;
		}(dto)) {
		return -1;
	}

	// 定义DAO层对象
	PyrkDao dao;

	// 上传附件
	// 定义传入数据库内的附件名称
	string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = dao.insertAttachment(file);
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
	data1.setId(to_string(sf.nextId()));
	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSubject(dto.getSubject());
	data1.setStockIoType("102"); // "102":盘盈入库
	data1.setHandler(dto.getHandler());
	data1.setRemark(dto.getRemark());
	data1.setBillStage((dto.getSave() == 0 ? "12" : "14")); // "12":编制中, "14":编制完
	data1.setAttachment(attachment);
	data1.setSysOrgCode(dao.selectOrgCodeByUsername(payload.getUsername()));
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
	dao.getSqlSession()->beginTransaction();
	// 执行数据添加
	uint64_t row = dao.insert(data1);
	if (row == 0) {
		// 回滚
		dao.getSqlSession()->rollbackTransaction();
		// 删除附件
		vector<string_view> fileNames = split(attachment, ",");
		for (const auto& file : fileNames) {
			dao.deleteAttachment(string(file));
		}
		return -2;
	}
	// 组装明细数据
	StkIoEntryDO data2;
	string mid = dao.selectBillIdByBillNo(dto.getBillNo());
	for (auto& entry : dto.getDetail()) {
		data2.setId(to_string(sf.nextId()));
		data2.setMid(mid);
		data2.setBillNo(dto.getBillNo());
		data2.setEntryNo(to_string(entry.getEntryNo()));
		data2.setMaterialId(dao.selectMaterialIdByAuxName(entry.getMaterial()));
		data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
		data2.setWarehouseId(dao.selectWarehouseIdByAuxName(entry.getWarehouse()));
		data2.setStockIoDirection("1");
		data2.setUnitId(dao.selectUnitIdByName(entry.getUnit()));
		data2.setQty(entry.getQty());
		data2.setCost(entry.getCost());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		if (dao.insert(data2) == 0) {
			// 回滚
			dao.getSqlSession()->rollbackTransaction();
			// 删除附件
			vector<string_view> fileNames = split(attachment, ",");
			for (const auto& file : fileNames) {
				dao.deleteAttachment(string(file));
			}
			return -3;
		}
	}
	// 提交
	dao.getSqlSession()->commitTransaction();
	return row;
}

int PyrkService::updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload)
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
	PyrkDao dao;
	//// 事务开始
	//dao.getSqlSession()->beginTransaction();
	// 执行更新数据
	int row = dao.updateApproval(data);
	if (row == 0) {
		return -2;
	}
	return row;
}

int PyrkService::updateBillData(const PyrkBillDetailDTO& dto, const PayloadDTO& payload)
{
	// 数据校验
	if ((dto.getSave() != 0 && dto.getSave() != 1) || 
		[](const PyrkBillDetailDTO& dto) {
			for (auto& list : dto.getDetail()) {
				if (list.getEntryNo() < 0 || list.getQty() < 0 || list.getCost() < 0) {
					return true;
				}
			}
			return false;
		}(dto)) {
		return -1;
	}

	// 定义DAO层对象
	PyrkDao dao;

	// 查询表中对应单据的附件名
	string attachments = dao.selectAttachmentByBillNo(dto.getBillNo());
	// 定义需删除的附件列表
	list<string> needDeleteFile;
	// 定义需新增的附件列表
	list<string> needUploadFile;

	// 组装数据
	StkIoDO data1;
	SnowFlake sf(1, 5);
	data1.setId(to_string(sf.nextId()));
	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSubject(dto.getSubject());
	data1.setStockIoType("102"); // "102":盘盈入库
	data1.setHandler(dto.getHandler());
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
				string f = dao.insertAttachment(file);
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
	data1.setSysOrgCode(dao.selectOrgCodeByUsername(payload.getUsername()));
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
	dao.getSqlSession()->beginTransaction();
	// 执行数据添加
	uint64_t row = dao.update(data1);
	if (row == 0) {
		// 回滚
		dao.getSqlSession()->rollbackTransaction();
		// 删除新增的附件
		for (const auto& file : needUploadFile) {
			dao.deleteAttachment(file);
		}
		return -2;
	}
	// 组装明细数据
	StkIoEntryDO data2;
	string mid = dao.selectBillIdByBillNo(dto.getBillNo());
	for (auto& entry : dto.getDetail()) {
		data2.setId(to_string(sf.nextId()));
		data2.setMid(mid);
		data2.setBillNo(dto.getBillNo());
		data2.setEntryNo(to_string(entry.getEntryNo()));
		data2.setMaterialId(dao.selectMaterialIdByAuxName(entry.getMaterial()));
		data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
		data2.setWarehouseId(dao.selectWarehouseIdByAuxName(entry.getWarehouse()));
		data2.setStockIoDirection("1");
		data2.setUnitId(dao.selectUnitIdByName(entry.getUnit()));
		data2.setQty(entry.getQty());
		data2.setCost(entry.getCost());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		if (dao.update(data2) == 0) {
			// 回滚
			dao.getSqlSession()->rollbackTransaction();
			// 删除新增的附件
			for (const auto& file : needUploadFile) {
				dao.deleteAttachment(file);
			}
			return -3;
		}
	}
	// 提交
	dao.getSqlSession()->commitTransaction();
	// 删除需要删除的附件
	for (const auto& file : needDeleteFile) {
		dao.deleteAttachment(file);
	}
	return row;
}
