#include "stdafx.h"
#include "PyrkService.h"
#include "../../dao/Pyrk/PyrkDao.h"
#include"domain/do/Pyrk/QueryPyrkBillListDo.h"
#include <ctime>
#include "../../../lib-common/include/SnowFlake.h"
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
	// 数据校验辅助函数
	auto f = [](const PyrkBillDetailDTO& dto) {
		for (auto& list : dto.getDetail()) {
			if (list.getEntryNo() < 0 || list.getQty() < 0 || list.getCost() < 0) {
				return true;
			}
		}
		return false;
	};
	// 数据校验
	if ((dto.getSave() != 0 && dto.getSave() != 1) || f(dto)) {
		return -1;
	}

	// 定义DAO层对象
	PyrkDao dao;

	// 上传附件
	// 定义传入数据库内的附件名称
	string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = dao.insertFile(file);
		if (!fileName.empty()) {
			attachment += fileName;
			attachment += ",";
		}
		else {
			return -4;
		}
	}
	int n = attachment.size();

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
	data1.setAttachment((n != 0 ? attachment.substr(0, n - 1) : ""));
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
		data2.setMaterialId(entry.getMaterialId());
		data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
		data2.setWarehouseId(entry.getWarehouseId());
		data2.setStockIoDirection("1");
		data2.setUnitId(entry.getUnitId());
		data2.setQty(entry.getQty());
		data2.setCost(entry.getCost());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		if (dao.insert(data2) == 0) {
			// 回滚
			dao.getSqlSession()->rollbackTransaction();
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
