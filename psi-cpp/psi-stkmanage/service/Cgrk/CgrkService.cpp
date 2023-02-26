/*
 Copyright Zero One Star. All rights reserved.

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

//查询单据列表
PageVO<QueryCgrkBillListVO> CgrkService::listCgrkBillList(const QueryCgrkBillListQuery& query)
{
	//构建返回对象
	PageVO<QueryCgrkBillListVO> billList;
	StkIoDO obj;
	obj.setBillNo(query.getBillNo());

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
uint64_t CgrkService::saveCgrkBill(const AddCgrkBillDTO& DTO)
{
	//组装数据
	StkIoDO data;
	data.setBillNo
	//执行数据添加
	CgrkDAO dao;
	return dao.insertCgrkBill(DTO);
}


//删除采购入库单
uint64_t CgrkService::removeCgrkBill(string id)
{
	CgrkDAO dao;
	dao.deleteCgrkBill(id);

}