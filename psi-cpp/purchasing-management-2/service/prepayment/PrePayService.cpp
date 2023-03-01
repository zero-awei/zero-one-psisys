/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2022/10/25 11:08:56

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
#include "PrePayService.h"
#include "../../api/prepayment/PrePayController.h"
// 删除
#include "../../dao/prepayment/PrepaymentDAO.h"
#include "../../domain/do/prepayment/PrepaymentDO.h"
// 采购订单列表
#include "../../domain/do/PurOrder/PurOrderDO.h"
#include "../../domain/do/PurOrder/PurOrderEntryDO.h"


// 分页查询 采购订单所有数据(多个对象)
PageVO<PurOrderVO> PrePayService::listAll(const PurOrderQuery& query)
{
	//构建返回对象
	PageVO<PurOrderVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	PurOrderDO obj;
	obj.setBill_no(query.getBill_no());
	obj.setBill_date(query.getBill_date());
	obj.setPur_type(query.getPur_type());
	obj.setPayment_method(query.getPayment_method());
	obj.setSettle_method(query.getSettle_method());
	obj.setSettle_time(query.getSettle_time());
	obj.setDelivery_method(query.getDelivery_method());
	obj.setInvoice_type(query.getInvoice_type());

	obj.setOp_er(query.getOp_er());
	obj.setOp_dept(query.getOp_dept());
	obj.setSupplier_id(query.getSupplier_id());

	PrepaymentDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<PurOrderDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<PurOrderVO> vr;
	for (PurOrderDO sub : result)
	{
		PurOrderVO vo;
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setSrc_bill_type(sub.getSrc_bill_type());
		vo.setSrc_bill_id(sub.getSrc_bill_id());
		vo.setSrc_no(sub.getSrc_no());
		vo.setSubject(sub.getSubject());
		vo.setIs_rubric(sub.getIs_rubric());
		vo.setPur_type(sub.getPur_type());
		vo.setSupplier_id(sub.getSupplier_id());
		vo.setContact(sub.getContact());
		vo.setPhone(sub.getPhone());
		vo.setFax(sub.getFax());
		vo.setEmail(sub.getEmail());
		vo.setOp_dept(sub.getOp_dept());
		vo.setOp_er(sub.getOp_er());
		vo.setDelivery_method(sub.getDelivery_method());
		vo.setDelivery_place(sub.getDelivery_place());
		vo.setDelivery_time(sub.getDelivery_time());
		vo.setTransport_method(sub.getTransport_method());
		vo.setPayment_method(sub.getPayment_method());
		vo.setSettle_method(sub.getSettle_method());
		vo.setSettle_time(sub.getSettle_time());
		vo.setInvoice_method(sub.getInvoice_method());
		vo.setInvoice_type(sub.getInvoice_type());
		vo.setCurrency(sub.getCurrency());
		vo.setExchange_rate(sub.getExchange_rate());
		vo.setQty(sub.getQty());
		vo.setAmt(sub.getAmt());
		vo.setPrepayment_bal(sub.getPrepayment_bal());
		vo.setSettle_qty(sub.getSettle_qty());
		vo.setSettle_amt(sub.getSettle_amt());
		vo.setIn_qty(sub.getIn_qty());
		vo.setIn_cost(sub.getIn_cost());
		vo.setSettled_amt(sub.getSettled_amt());
		vo.setInvoiced_amt(sub.getInvoiced_amt());
		vo.setAttachment(sub.getAttachment());
		vo.setRemark(sub.getRemark());
		vo.setIs_auto(sub.getIs_auto());
		vo.setBill_stage(sub.getBill_stage());
		vo.setApprover(sub.getApprover());
		vo.setBpmi_instance_id(sub.getBpmi_instance_id());
		vo.setApproval_result_type(sub.getApproval_result_type());
		vo.setApproval_remark(sub.getApproval_remark());
		vo.setIs_effective(sub.getIs_effective());
		vo.setEffective_time(sub.getEffective_time());
		vo.setIs_closed(sub.getIs_closed());
		vo.setIs_voided(sub.getIs_voided());
		vo.setSys_org_code(sub.getSys_org_code());
		vo.setCreate_by(sub.getCreate_by());
		vo.setCreate_time(sub.getCreate_time());
		vo.setUpdate_by(sub.getUpdate_by());
		vo.setUpdate_time(sub.getUpdate_time());
		vo.setVersion(sub.getVersion());

		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}




 //查询指定单据详细信息-通过单据编号查询数据
PurOrderVO PrePayService::getAll(const PurOrderQuery& query) {
	// 构建返回对象
	PurOrderVO detail;

	// 领域模型转换
	PurOrderDO obj;
	obj.setBill_no(query.getBill_no());
	PurOrderEntryDO obj2;
	obj2.setBill_no(query.getBill_no());
	
	// 查询指定询价单数据
	PrepaymentDAO dao;
	list <PurOrderDO> result=dao.selectByBill_no(obj);
	for (PurOrderDO sub : result)
	{
		PurOrderVO detail;
		detail.setBill_no(sub.getBill_no());
		detail.setBill_date(sub.getBill_date());
		detail.setSrc_bill_type(sub.getSrc_bill_type());
		detail.setSrc_bill_id(sub.getSrc_bill_id());
		detail.setSrc_no(sub.getSrc_no());
		detail.setSubject(sub.getSubject());
		detail.setIs_rubric(sub.getIs_rubric());
		detail.setPur_type(sub.getPur_type());
		detail.setSupplier_id(sub.getSupplier_id());
		detail.setContact(sub.getContact());
		detail.setPhone(sub.getPhone());
		detail.setFax(sub.getFax());
		detail.setEmail(sub.getEmail());
		detail.setOp_dept(sub.getOp_dept());
		detail.setOp_er(sub.getOp_er());
		detail.setDelivery_method(sub.getDelivery_method());
		detail.setDelivery_place(sub.getDelivery_place());
		detail.setDelivery_time(sub.getDelivery_time());
		detail.setTransport_method(sub.getTransport_method());
		detail.setPayment_method(sub.getPayment_method());
		detail.setSettle_method(sub.getSettle_method());
		detail.setSettle_time(sub.getSettle_time());
		detail.setInvoice_method(sub.getInvoice_method());
		detail.setInvoice_type(sub.getInvoice_type());
		detail.setCurrency(sub.getCurrency());
		detail.setExchange_rate(sub.getExchange_rate());
		detail.setQty(sub.getQty());
		detail.setAmt(sub.getAmt());
		detail.setPrepayment_bal(sub.getPrepayment_bal());
		detail.setSettle_qty(sub.getSettle_qty());
		detail.setSettle_amt(sub.getSettle_amt());
		detail.setIn_qty(sub.getIn_qty());
		detail.setIn_cost(sub.getIn_cost());
		detail.setSettled_amt(sub.getSettled_amt());
		detail.setInvoiced_amt(sub.getInvoiced_amt());
		detail.setAttachment(sub.getAttachment());
		detail.setRemark(sub.getRemark());
		detail.setIs_auto(sub.getIs_auto());
		detail.setBill_stage(sub.getBill_stage());
		detail.setApprover(sub.getApprover());
		detail.setBpmi_instance_id(sub.getBpmi_instance_id());
		detail.setApproval_result_type(sub.getApproval_result_type());
		detail.setApproval_remark(sub.getApproval_remark());
		detail.setIs_effective(sub.getIs_effective());
		detail.setEffective_time(sub.getEffective_time());
		detail.setIs_closed(sub.getIs_closed());
		detail.setIs_voided(sub.getIs_voided());
		detail.setSys_org_code(sub.getSys_org_code());
		detail.setCreate_by(sub.getCreate_by());
		detail.setCreate_time(sub.getCreate_time());
		detail.setUpdate_by(sub.getUpdate_by());
		detail.setUpdate_time(sub.getUpdate_time());
		detail.setVersion(sub.getVersion());
	}

	return detail;
}


// 通过ID删除数据
bool PrePayService::DePrePayId(const DePayDTO& dto)
{
	PrepaymentDAO dao;
	PrepaymentDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//执行数据修改
	if (dto.getId() != "" || dto.getBill_no() != "")
	{
		data.setId(dto.getId());
		return dao.deleteById(data) == 1;
	}
}
