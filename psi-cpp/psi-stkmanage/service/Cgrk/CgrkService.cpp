/*
 Copyright Zero One Star. All rights reserved.
 //
 @Author: awei
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "CgrkService.h"
#include "../../dao/Cgrk/CgrkDAO.h"
#include "../../dao/CommonDAO.h"
#include <algorithm>
#include <ctime>
#include "../../../lib-common/include/SnowFlake.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include"../../domain/do/Cgrk/ModifyCgrkBillStatusDO.h"
//查询单据列表
PageVO<QueryCgrkBillListVO> CgrkService::listCgrkBillList(const QueryCgrkBillListQuery& query)
{
	//构建返回对象
	PageVO<QueryCgrkBillListVO> billList;

	CgrkDAO dao;



	list<StkIoDO> result = dao.selectBillList(query);
	list<QueryCgrkBillListVO> vr;
	for (StkIoDO sub : result)
	{
		QueryCgrkBillListVO vo;
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

//高级查询单据列表
PageVO<QueryCgrkBillListVO>  CgrkService::listCgrkBillListAdvanced(const QueryCgrkBillListAdvancedQuery& query)
{
	//构建返回对象
	PageVO<QueryCgrkBillListVO> billList;
	CgrkDAO dao;
	list<StkIoDO> result = dao.selectBillListAnvanced(query);
	list<QueryCgrkBillListVO> vr;
	for (StkIoDO sub : result)
	{
		QueryCgrkBillListVO vo;
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
QueryCgrkBillDetailsVO CgrkService::getCgrkBillDetails(const QueryCgrkBillDetailsQuery& query)
{
	//构建返回对象
	QueryCgrkBillDetailsVO details;

	//
	StkIoDO SIDO;
	SIDO.setBillNo(query.getBillNo());
	StkIoEntryDO SIEDO;
	SIEDO.setBillNo(query. getBillNo());

	CgrkDAO dao;

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
	list<CgrkBillEntryVO> vr;
	for (StkIoEntryDO sub : result1)
	{
		CgrkBillEntryVO vo;
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

	CgrkDAO CDAO;

	return details;

}

//查询采购订单列表
PageVO<QueryPurOrderListVO> CgrkService::listPurOrderList(const QueryPurOrderListQuery& query)
{
	//构建返回对象
	PageVO<QueryPurOrderListVO> billList;
	PurOrderDO obj;
	obj.setBillNo(query.getBillNo());

	CgrkDAO dao; 




	list<PurOrderDO> result = dao.selectPurOrderList(query);
	list<QueryPurOrderListVO> vr;

	for (PurOrderDO sub : result)
	{
		QueryPurOrderListVO vo;
		vo.setId(sub.getId());
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setPurType(sub.getPurType());
		vo.setPaymentMethod(sub.getPaymentMethod());
		vo.setPrePaymentBal(sub.getPrePaymentBal());
		vo.setSettleMethod(sub.getSettleMethod());
		vo.setDeliverTime(sub.getDeliveryMethod());
		vo.setDeliverPlace(sub.getDeliveryPlace());
		vo.setDeliverMethod(sub.getDeliveryMethod());
		vo.setInQty(sub.getInQty());
		vo.setInCost(sub.getInCost());
		vo.setInvoicedAmt(sub.getInvoicedAmt());
		vo.setInvoiceType(sub.getInvoiceType());
		vo.setAmt(sub.getAmt());
		vo.setIsClosed(sub.getIsClosed());
		vo.setOpDept(sub.getOpDept());
		vo.setOperator1(sub.getOperator1());
		vo.setQty(sub.getQty());
		vo.setRemark(sub.getRemark());
		vo.setSettleAmt(sub.getSettleAmt());
		vo.setSettledAmt(sub.getSettledAmt());
		vo.setSrcNo(sub.getSrcNo());
		vo.setSubject(sub.getSubject());
		vo.setSupplierId(sub.getSupplierId());

		vr.push_back(vo);
	}
	billList.setRows(vr);

	return billList;



}

//采购订单分录列表
PageVO<QueryPurOrderEntryVO> CgrkService::listPurOrderEntry(const QueryPurOrderEntryQuery& query)
{
	//构建返回对象
	PageVO<QueryPurOrderEntryVO> billList;
	PurOrderEntryDO obj;
	obj.setBillNo(query.getBillNo());

	CgrkDAO dao;
	list<PurOrderEntryDO> result = dao.selectPurOrderEntry(query);
	list<QueryPurOrderEntryVO> vr;

	for (PurOrderEntryDO sub : result)
	{
		QueryPurOrderEntryVO vo;
		vo.setId(sub.getId());
		vo.setMid(sub.getMid());
		vo.setBillNo(sub.getBillNo());
		vo.setBillNo(sub.getBillNo());
		vo.setEntryNo(sub.getEntryNo());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSrcBillId(sub.getSrcBillId());
		vo.setSrcEntryId(sub.getSrcEntryId());
		vo.setSrcNo(sub.getSrcNo());
		vo.setMaterialId(sub.getMaterialId());
		vo.setUnitId(sub.getUnitId());
		vo.setQty(sub.getQty());
		vo.setTaxRate(sub.getTaxRate());
		vo.setPrice(sub.getPrice());
		vo.setDiscountRate(sub.getDiscountRate());
		vo.setTax(sub.getTax());
		vo.setAmt(sub.getAmt());
		vo.setInQty(sub.getInQty());
		vo.setInCost(sub.getInCost());
		vo.setSettleQty(sub.getSettleQty());
		vo.setSettleAmt(sub.getSettleAmt());
		vo.setInvoicedQty(sub.getInvoicedQty());
		vo.setInvoicedAmt(sub.getInvoicedAmt());
		vo.setRemark(sub.getRemark());
		vo.setVersion(sub.getVersion());

		vr.push_back(vo);
	}
	billList.setRows(vr);

	return billList;
}

//添加采购入库单
int CgrkService::saveCgrkBill(const AddCgrkBillDTO& dto, const PayloadDTO& payload)
{

	// 定义DAO层对象
	CgrkDAO dao;
	CommonDAO cDao;

	// 上传附件
	// 定义传入数据库内的附件名称
	string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = cDao.insertAttachment(file);
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

	// 组装数据stk_io表
	StkIoDO data1;
	SnowFlake sf(1, 5);
	string mid = to_string(sf.nextId());
	data1.setId(mid);//生成id
	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSupplierId(dto.getSupplierId());
	data1.setSrcBillType(dao.selectSrcBillTypeBySrcNo(dto.getSrcNo()));
	data1.setSrcBillId(dao.selectSrcBillIdBySrcNo(dto.getSrcNo()));
	data1.setSrcNo(dto.getSrcNo());
	data1.setSubject(dto.getSubject());
	data1.setStockIoType("101"); // 采购入库
	data1.setOpDept(dao.selectOpDeptById(dto.getOperator1()));
	data1.setOperator1(dto.getOperator1());
	data1.setHandler(dto.getHandler());
	data1.setHasRp(1);
	data1.setHasSwell(dto.getHasSwell());
	data1.setSupplierId(dto.getSupplierId());
	data1.setInvoiceType(dto.getInvoiceType());
	data1.setCost([](const list<CgrkBillEntryDTO>& details) {
		double cost = 0;
		for (const auto& entry : details) {
			cost += entry.getCost();
		}
		return cost;
		}(dto.getEntry()));
	data1.setAttachment(attachment);
	data1.setRemark(dto.getRemark());
	data1.setIsAuto(0);
	data1.setBillStage((dto.getSave() == 0 ? "12" : "14")); // "12":编制中, "14":编制完
	data1.setIsEffective(0);
	data1.setIsClosed(0);
	data1.setIsVoided(0);
	data1.setSysOrgCode(cDao.selectOrgCodeByUsername(payload.getUsername()));
	data1.setCreateBy(payload.getUsername());
	// 生成当前时间
	data1.setCreateTime(SimpleDateTimeFormat::format());
	// 事务开始
	dao.getSqlSession()->beginTransaction();
	// 执行数据添加
	uint64_t row = dao.insertCgrkBill(data1);
	if (row == 0) {
		// 回滚
		dao.getSqlSession()->rollbackTransaction();
		// 删除附件
		vector<string_view> fileNames = split(attachment, ",");
		if (!fileNames.empty()) {
			for (const auto& file : fileNames) {
				cDao.deleteAttachment(string(file));
			}
		}
		return -2;
	}
	// 组装明细数据stk_io_entry
	StkIoEntryDO data2;
	for (auto& entry : dto.getEntry()) {
		data2.setId(to_string(sf.nextId()));
		data2.setMid(mid);
		data2.setBillNo(dto.getBillNo());
		data2.setEntryNo(entry.getEntryNo());
		data2.setSrcBillType(data1.getSrcBillType());
		data2.setSrcBillId(data1.getSrcBillId());
		data2.setSrcEntryId(entry.getSrcEntryId());
		data2.setSrcNo(data1.getSrcNo());
		data2.setMaterialId(entry.getMaterialId());
		data2.setBatchNo(dto.getBillNo() + "-" +(entry.getEntryNo()));
		data2.setWarehouseId(entry.getWarehouseId());
		data2.setStockIoDirection("1");
		data2.setSupplierId(entry.getSupplierId());
		data2.setUnitId(entry.getUnitId());	
		data2.setSwellQty(entry.getSwellQty());
		data2.setQty(entry.getQty());
		data2.setExpense(entry.getExpense());
		data2.setCost(entry.getCost());
		data2.setSettleQty(entry.getSettleQty());
		data2.setTaxRate(entry.getTaxRate());
		data2.setPrice(entry.getPrice());
		data2.setDiscountRate(entry.getDiscountRate());
		data2.setTax(entry.getTax());
		data2.setSettleAmt(entry.getSettleAmt());
		data2.setInvoicedQty(entry.getInvoicedQty());
		data2.setInvoicedAmt(entry.getInvoicedAmt());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		dao.insertCgrkBillEntry(data2);

	}
	// 提交
	dao.getSqlSession()->commitTransaction();
	return row;
}


//修改采购入库单
int CgrkService::updateCgrkBill(const ModifyCgrkBillDTO dto, const PayloadDTO& payload)
{

	// 定义DAO层对象
	CgrkDAO dao;
	CommonDAO cDao;

	// 上传附件
	// 定义传入数据库内的附件名称
	string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = cDao.insertAttachment(file);
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

	// 组装数据stk_io表
	StkIoDO data1;
	SnowFlake sf(1, 5);

	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSupplierId(dto.getSupplierId());
	data1.setSrcBillType(dao.selectSrcBillTypeBySrcNo(dto.getSrcNo()));
	data1.setSrcBillId(dao.selectSrcBillIdBySrcNo(dto.getSrcNo()));
	data1.setSrcNo(dto.getSrcNo());
	data1.setSubject(dto.getSubject());
	data1.setOpDept(dao.selectOpDeptById(dto.getOperator1()));
	data1.setOperator1(dto.getOperator1());
	data1.setHandler(dto.getHandler());
	data1.setHasSwell(dto.getHasSwell());
	data1.setSupplierId(dto.getSupplierId());
	data1.setInvoiceType(dto.getInvoiceType());
	data1.setCost([](const list<CgrkBillEntryDTO>& details) {
		double cost = 0;
		for (const auto& entry : details) {
			cost += entry.getCost();
		}
		return cost;
		}(dto.getEntry()));
	data1.setAttachment(attachment);
	data1.setRemark(dto.getRemark());
	data1.setIsAuto(0);
	if (dto.getApprove() == 1)
	{
		data1.setBillStage("24");//"24"核批完
	}
	else
	{
		data1.setBillStage((dto.getSave() == 0 ? "12" : "14")); // "12":编制中, "14":编制完
	}

	if ((dto.getApprove() == 1)&& (dto.getApprovalResultType() == "1")) {

			data1.setIsEffective(1);
			data1.setIsClosed(1);

	}
	else
	{
		data1.setIsEffective(0);
		data1.setIsClosed(0);
	}

	data1.setApprovalRemark(dto.getApprovalRemark());
	data1.setSysOrgCode(cDao.selectOrgCodeByUsername(payload.getUsername()));
	data1.setUpdateBy(payload.getId());
	// 生成当前时间
	data1.setUpdateTime(SimpleDateTimeFormat::format());
	// 事务开始
	dao.getSqlSession()->beginTransaction();
	// 执行数据更新
	int row = dao.updateCgrkBill(data1);
	if (row == 0) {
		// 回滚
		dao.getSqlSession()->rollbackTransaction();
		// 删除附件
		vector<string_view> fileNames = split(attachment, ",");
		if (!fileNames.empty()) {
			for (const auto& file : fileNames) {
				cDao.deleteAttachment(string(file));
			}
		}
		return -2;
	}
	// 组装明细数据stk_io_entry
	dao.deleteCgrkBillEntry(dto.getBillNo());
	StkIoEntryDO data2;
	for (auto& entry : dto.getEntry()) {
		data2.setId(to_string(sf.nextId()));
		data2.setMid(dao.selectIdBySrcNo(dto.getSrcNo()));
		data2.setBillNo(dto.getBillNo());
		data2.setEntryNo(entry.getEntryNo());
		data2.setSrcBillType(data1.getSrcBillType());
		data2.setSrcBillId(data1.getSrcBillId());
		data2.setSrcEntryId(entry.getSrcEntryId());
		data2.setSrcNo(data1.getSrcNo());
		data2.setMaterialId(entry.getMaterialId());
		data2.setBatchNo(dto.getBillNo() + "-" + entry.getEntryNo());
		data2.setWarehouseId(entry.getWarehouseId());
		data2.setStockIoDirection("1");
		data2.setSupplierId(entry.getSupplierId());
		data2.setUnitId(entry.getUnitId());
		data2.setSwellQty(entry.getSwellQty());
		data2.setQty(entry.getQty());
		data2.setExpense(entry.getExpense());
		data2.setCost(entry.getCost());
		data2.setSettleQty(entry.getSettleQty());
		data2.setTaxRate(entry.getTaxRate());
		data2.setPrice(entry.getPrice());
		data2.setDiscountRate(entry.getDiscountRate());
		data2.setTax(entry.getTax());
		data2.setSettleAmt(entry.getSettleAmt());
		data2.setInvoicedQty(entry.getInvoicedQty());
		data2.setInvoicedAmt(entry.getInvoicedAmt());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		dao.insertCgrkBillEntry(data2);
	}
	// 提交
	dao.getSqlSession()->commitTransaction();
	return row;
}


//删除采购入库单
bool CgrkService::removeCgrkBill(string billNo)
{
	CgrkDAO dao;
	return dao.deleteCgrkBill(billNo)>=1;

}
bool CgrkService::updataBillStatus(const ModifyCgrkBillStateDTO& dto) {
	//组装传输数据
	ModifyCgrkBillStatusDO data;
	data.setBillNo(dto.getBillNo());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());

	//执行数据修改
	CgrkDAO cd;
	return cd.updataBillStatus(data) == 1;
}
