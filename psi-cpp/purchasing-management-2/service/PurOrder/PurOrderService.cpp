/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/17 11:13:11

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
#include "PurOrderService.h"
#include "../../../lib-common/include/SnowFlake.h"

// from c3-adam
string getTime()
{
	time_t now = time(0);
	struct tm t;

	localtime_s(&t, &now);

	// 将信息输出到字符串流
	stringstream ss;
	ss << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec;
	return ss.str();
}

#define SET_PUR_ORDER_DO() \
data.setBill_no(dto.getBill_no());\
data.setBill_date(dto.getBill_date());\
data.setSrc_bill_type(dto.getSrc_bill_type());\
data.setSrc_bill_id(dto.getSrc_bill_id());\
data.setSrc_no(dto.getSrc_no());\
data.setSubject(dto.getSubject());\
data.setIs_rubric(dto.getIs_rubric());\
data.setPur_type(dto.getPur_type());\
data.setSupplier_id(dto.getSupplier_id());\
data.setContact(dto.getContact());\
data.setPhone(dto.getPhone());\
data.setFax(dto.getFax());\
data.setEmail(dto.getEmail());\
data.setOp_dept(dto.getOp_dept());\
data.setOp_er(dto.getOp_er());\
data.setDelivery_method(dto.getDelivery_method());\
data.setDelivery_place(dto.getDelivery_place());\
data.setDelivery_time(dto.getDelivery_time());\
data.setTransport_method(dto.getTransport_method());\
data.setPayment_method(dto.getPayment_method());\
data.setSettle_method(dto.getSettle_method());\
data.setSettle_time(dto.getSettle_time());\
data.setInvoice_method(dto.getInvoice_method());\
data.setInvoice_type(dto.getInvoice_type());\
data.setCurrency(dto.getCurrency());\
data.setExchange_rate(dto.getExchange_rate());\
data.setQty(dto.getQty());\
data.setAmt(dto.getAmt());\
data.setPrepayment_bal(dto.getPrepayment_bal());\
data.setSettle_qty(dto.getSettle_qty());\
data.setSettle_amt(dto.getSettle_amt());\
data.setIn_qty(dto.getIn_qty());\
data.setIn_cost(dto.getIn_cost());\
data.setSettled_amt(dto.getSettled_amt());\
data.setInvoiced_amt(dto.getInvoiced_amt());\
data.setAttachment(dto.getAttachment());\
data.setRemark(dto.getRemark());\
data.setIs_auto(dto.getIs_auto());\
data.setBill_stage(dto.getBill_stage());\
data.setApprover(dto.getApprover());\
data.setBpmi_instance_id(dto.getBpmi_instance_id());\
data.setApproval_result_type(dto.getApproval_result_type());\
data.setApproval_remark(dto.getApproval_remark());\
data.setIs_effective(dto.getIs_effective());\
data.setEffective_time(dto.getEffective_time());\
data.setIs_closed(dto.getIs_closed());\
data.setIs_voided(dto.getIs_voided());\
data.setSys_org_code(dto.getSys_org_code());\
data.setCreate_by(dto.getCreate_by());\
data.setCreate_time(dto.getCreate_time());\
data.setUpdate_by(dto.getUpdate_by());\
data.setUpdate_time(dto.getUpdate_time());\
data.setVersion(dto.getVersion());

#define SET_PUR_ORDER_ENTRY_DO() \
entryData.setMid(data.getId());\
entryData.setBill_no(dto.getBill_no());\
entryData.setEntry_no(entrydto.getEntry_no());\
entryData.setSrc_bill_type(entrydto.getSrc_bill_type());\
entryData.setSrc_bill_id(entrydto.getSrc_bill_id());\
entryData.setSrc_entry_id(entrydto.getSrc_entry_id());\
entryData.setSrc_no(entrydto.getSrc_no());\
entryData.setMaterial_id(entrydto.getMaterial_id());\
entryData.setUnit_id(entrydto.getUnit_id());\
entryData.setQty(entrydto.getQty());\
entryData.setTax_rate(entrydto.getTax_rate());\
entryData.setPrice(entrydto.getPrice());\
entryData.setDiscount_rate(entrydto.getDiscount_rate());\
entryData.setTax(entrydto.getTax());\
entryData.setAmt(entrydto.getAmt());\
entryData.setIn_qty(entrydto.getIn_qty());\
entryData.setIn_cost(entrydto.getIn_cost());\
entryData.setSettle_qty(entrydto.getSettle_qty());\
entryData.setSettle_amt(entrydto.getSettle_amt());\
entryData.setInvoiced_qty(entrydto.getInvoiced_qty());\
entryData.setInvoiced_amt(entrydto.getInvoiced_amt());\
entryData.setRemark(entrydto.getRemark());\
entryData.setCustom1(entrydto.getCustom1());\
entryData.setCustom2(entrydto.getCustom2());\
entryData.setVersion(entrydto.getVersion());

// 分页查询所有数据
PageVO<PurOrderVO> PurOrderService::listPurOrder(const PurOrderQuery& query)
{
	//构建返回对象
	PageVO<PurOrderVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	PurOrderDO obj;
	obj.setBill_no(query.getBill_no());
	obj.setBill_date(query.getBill_date());
	obj.setSubject(query.getSubject());
	obj.setSupplier_id(query.getSupplier_id());
	obj.setOp_er(query.getOp_er());
	obj.setBill_stage(query.getBill_stage());

	obj.setIs_effective(query.getIs_effective());
	obj.setIs_closed(query.getIs_closed());
	obj.setIs_voided(query.getIs_voided());
	PurOrderDAO dao;
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
		vo.setSubject(sub.getSubject());
		vo.setSrc_no(sub.getSrc_no());
		vo.setPur_type(sub.getPur_type());
		vo.setQty(sub.getQty());
		vo.setAmt(sub.getAmt());
		vo.setBill_stage(sub.getBill_stage());
		vo.setIs_effective(sub.getIs_effective());
		vo.setIs_closed(sub.getIs_closed());
		vo.setIs_voided(sub.getIs_voided());
		vo.setRemark(sub.getRemark());
		vo.setIs_auto(sub.getIs_auto());
		vo.setIs_rubric(sub.getIs_rubric());
		vo.setEffective_time(sub.getEffective_time());
		vo.setCreate_time(sub.getCreate_time());
		vo.setCreate_by(sub.getCreate_by());
		vo.setSys_org_code(sub.getSys_org_code());
		vo.setUpdate_time(sub.getUpdate_time());
		vo.setUpdate_by(sub.getUpdate_by());
		vo.setId(sub.getId());
		vo.setSrc_bill_type(sub.getSrc_bill_type());
		vo.setSrc_bill_id(sub.getSrc_bill_id());
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
		vo.setPrepayment_bal(sub.getPrepayment_bal());
		vo.setSettle_qty(sub.getSettle_qty());
		vo.setSettle_amt(sub.getSettle_amt());
		vo.setIn_qty(sub.getIn_qty());
		vo.setIn_cost(sub.getIn_cost());
		vo.setSettled_amt(sub.getSettled_amt());
		vo.setInvoiced_amt(sub.getInvoiced_amt());
		vo.setAttachment(sub.getAttachment());
		vo.setApprover(sub.getApprover());
		vo.setBpmi_instance_id(sub.getBpmi_instance_id());
		vo.setApproval_result_type(sub.getApproval_result_type());
		vo.setApproval_remark(sub.getApproval_remark());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

// 查询单个数据
PurOrderDetailVO PurOrderService::getPurOrder(string bill_no)
{
	PurOrderDetailVO vo;
	PurOrderDAO dao;
	list<PurOrderDO> do_datas;
	do_datas = dao.selectDetail(bill_no);
	if (do_datas.empty()) return vo;
	for (auto do_data : do_datas)
	{
		vo.setId(do_data.getId());
		vo.setBill_no(do_data.getBill_no());
		vo.setBill_date(do_data.getBill_date());
		vo.setSubject(do_data.getSubject());
		vo.setSrc_no(do_data.getSrc_no());
		vo.setPur_type(do_data.getPur_type());
		vo.setQty(do_data.getQty());
		vo.setAmt(do_data.getAmt());
		vo.setBill_stage(do_data.getBill_stage());
		vo.setIs_effective(do_data.getIs_effective());
		vo.setIs_closed(do_data.getIs_closed());
		vo.setIs_voided(do_data.getIs_voided());
		vo.setRemark(do_data.getRemark());
		vo.setIs_auto(do_data.getIs_auto());
		vo.setIs_rubric(do_data.getIs_rubric());
		vo.setEffective_time(do_data.getEffective_time());
		vo.setCreate_time(do_data.getCreate_time());
		vo.setCreate_by(do_data.getCreate_by());
		vo.setSys_org_code(do_data.getSys_org_code());
		vo.setUpdate_time(do_data.getUpdate_time());
		vo.setUpdate_by(do_data.getUpdate_by());
		vo.setId(do_data.getId());
		vo.setSrc_bill_type(do_data.getSrc_bill_type());
		vo.setSrc_bill_id(do_data.getSrc_bill_id());
		vo.setSupplier_id(do_data.getSupplier_id());
		vo.setContact(do_data.getContact());
		vo.setPhone(do_data.getPhone());
		vo.setFax(do_data.getFax());
		vo.setEmail(do_data.getEmail());
		vo.setOp_dept(do_data.getOp_dept());
		vo.setOp_er(do_data.getOp_er());
		vo.setDelivery_method(do_data.getDelivery_method());
		vo.setDelivery_place(do_data.getDelivery_place());
		vo.setDelivery_time(do_data.getDelivery_time());
		vo.setTransport_method(do_data.getTransport_method());
		vo.setPayment_method(do_data.getPayment_method());
		vo.setSettle_method(do_data.getSettle_method());
		vo.setSettle_time(do_data.getSettle_time());
		vo.setInvoice_method(do_data.getInvoice_method());
		vo.setInvoice_type(do_data.getInvoice_type());
		vo.setCurrency(do_data.getCurrency());
		vo.setExchange_rate(do_data.getExchange_rate());
		vo.setPrepayment_bal(do_data.getPrepayment_bal());
		vo.setSettle_qty(do_data.getSettle_qty());
		vo.setSettle_amt(do_data.getSettle_amt());
		vo.setIn_qty(do_data.getIn_qty());
		vo.setIn_cost(do_data.getIn_cost());
		vo.setSettled_amt(do_data.getSettled_amt());
		vo.setInvoiced_amt(do_data.getInvoiced_amt());
		vo.setAttachment(do_data.getAttachment());
		vo.setApprover(do_data.getApprover());
		vo.setBpmi_instance_id(do_data.getBpmi_instance_id());
		vo.setApproval_result_type(do_data.getApproval_result_type());
		vo.setApproval_remark(do_data.getApproval_remark());
	}

	vector<string> pur_req, pur_req_entry;
	vector<string> pur_compare, pur_compare_entry;
	vector<string> pur_inquiry, pur_inquiry_entry;
	vector<string> pur_quot, pur_quot_entry;

	PurOrderEntryDAO entry_dao;
	list<PurOrderEntryDO> pur_order_entry_do = entry_dao.selectPurOrderEntry(bill_no);
	list<PurOrderEntryVO> pur_order_entry_vo_list;
	PurOrderEntryVO pur_order_entry_vo;
	for (auto do_data : pur_order_entry_do)
	{
		pur_order_entry_vo.setId(do_data.getId());
		pur_order_entry_vo.setMid(do_data.getMid());
		pur_order_entry_vo.setBill_no(do_data.getBill_no());
		pur_order_entry_vo.setEntry_no(do_data.getEntry_no());
		pur_order_entry_vo.setSrc_bill_type(do_data.getSrc_bill_type());
		pur_order_entry_vo.setSrc_bill_id(do_data.getSrc_bill_id());
		pur_order_entry_vo.setSrc_entry_id(do_data.getSrc_entry_id());
		pur_order_entry_vo.setSrc_no(do_data.getSrc_no());
		pur_order_entry_vo.setMaterial_id(do_data.getMaterial_id());
		pur_order_entry_vo.setUnit_id(do_data.getUnit_id());
		pur_order_entry_vo.setQty(do_data.getQty());
		pur_order_entry_vo.setTax_rate(do_data.getTax_rate());
		pur_order_entry_vo.setPrice(do_data.getPrice());
		pur_order_entry_vo.setDiscount_rate(do_data.getDiscount_rate());
		pur_order_entry_vo.setTax(do_data.getTax());
		pur_order_entry_vo.setAmt(do_data.getAmt());
		pur_order_entry_vo.setIn_qty(do_data.getIn_qty());
		pur_order_entry_vo.setIn_cost(do_data.getIn_cost());
		pur_order_entry_vo.setSettle_qty(do_data.getSettle_qty());
		pur_order_entry_vo.setSettle_amt(do_data.getSettle_amt());
		pur_order_entry_vo.setInvoiced_qty(do_data.getInvoiced_qty());
		pur_order_entry_vo.setInvoiced_amt(do_data.getInvoiced_amt());
		pur_order_entry_vo.setRemark(do_data.getRemark());
		pur_order_entry_vo.setCustom1(do_data.getCustom1());
		pur_order_entry_vo.setCustom2(do_data.getCustom2());
		pur_order_entry_vo.setVersion(do_data.getVersion());
		pur_order_entry_vo_list.push_back(pur_order_entry_vo);

		if (do_data.getSrc_bill_type() == "PurReq")
		{
			pur_req.push_back(do_data.getSrc_bill_id());
			if(!do_data.getSrc_entry_id().empty())
				pur_req_entry.push_back(do_data.getSrc_entry_id());
		}
		if (do_data.getSrc_bill_type() == "PurInquiry")
		{
			pur_inquiry.push_back(do_data.getSrc_bill_id());
			if (!do_data.getSrc_entry_id().empty())
				pur_inquiry_entry.push_back(do_data.getSrc_entry_id());
		}
		if (do_data.getSrc_bill_type() == "PurCompare")
		{
			pur_compare.push_back(do_data.getSrc_bill_id());
			if (!do_data.getSrc_entry_id().empty())
				pur_compare_entry.push_back(do_data.getSrc_entry_id());
		}
		if (do_data.getSrc_bill_type() == "PurQuot")
		{
			pur_quot.push_back(do_data.getSrc_bill_id());
			if (!do_data.getSrc_entry_id().empty())
				pur_quot_entry.push_back(do_data.getSrc_entry_id());
		}
	}
	vo.setEntry(pur_order_entry_vo_list);

	list<PurReqVO> pur_req_vo_list;
	for (auto item : pur_req)
	{
		list<PurReqDO> pur_req_do = entry_dao.selectPurReq(item);
		PurReqVO pur_req_vo;
		for (auto do_data : pur_req_do)
		{
			pur_req_vo.setId(do_data.getId());
			pur_req_vo.setBill_no(do_data.getBill_no());
			pur_req_vo.setBill_date(do_data.getBill_date());
			pur_req_vo.setSrc_bill_type(do_data.getSrc_bill_type());
			pur_req_vo.setSrc_bill_id(do_data.getSrc_bill_id());
			pur_req_vo.setSrc_no(do_data.getSrc_no());
			pur_req_vo.setSubject(do_data.getSubject());
			pur_req_vo.setIs_rubric(do_data.getIs_rubric());
			pur_req_vo.setPur_type(do_data.getPur_type());
			pur_req_vo.setRequest_dept(do_data.getRequest_dept());
			pur_req_vo.setRequester(do_data.getRequester());
			pur_req_vo.setRequest_time(do_data.getRequest_time());
			pur_req_vo.setQty(do_data.getQty());
			pur_req_vo.setAmt(do_data.getAmt());
			pur_req_vo.setOrdered_qty(do_data.getOrdered_qty());
			pur_req_vo.setAttachment(do_data.getAttachment());
			pur_req_vo.setRemark(do_data.getRemark());
			pur_req_vo.setIs_auto(do_data.getIs_auto());
			pur_req_vo.setBill_stage(do_data.getBill_stage());
			pur_req_vo.setApprover(do_data.getApprover());
			pur_req_vo.setBpmi_instance_id(do_data.getBpmi_instance_id());
			pur_req_vo.setApproval_result_type(do_data.getApproval_result_type());
			pur_req_vo.setApproval_remark(do_data.getApproval_remark());
			pur_req_vo.setIs_effective(do_data.getIs_effective());
			pur_req_vo.setEffective_time(do_data.getEffective_time());
			pur_req_vo.setIs_closed(do_data.getIs_closed());
			pur_req_vo.setIs_voided(do_data.getIs_voided());
			pur_req_vo.setSys_org_code(do_data.getSys_org_code());
			pur_req_vo.setCreate_by(do_data.getCreate_by());
			pur_req_vo.setCreate_time(do_data.getCreate_time());
			pur_req_vo.setUpdate_by(do_data.getUpdate_by());
			pur_req_vo.setUpdate_time(do_data.getUpdate_time());
			pur_req_vo.setVersion(do_data.getVersion());
			pur_req_vo_list.push_back(pur_req_vo);
		}
	}
	vo.setPur_req(pur_req_vo_list);

	list<PurReqEntryVO> pur_req_entry_vo_list;
	for (auto item : pur_req_entry)
	{
		list<PurReqEntryDO> pur_req_entry_do = entry_dao.selectPurReqEntry(item);
		PurReqEntryVO pur_req_entry_vo;
		for (auto do_data : pur_req_entry_do)
		{
			pur_req_entry_vo.setId(do_data.getId());
			pur_req_entry_vo.setMid(do_data.getMid());
			pur_req_entry_vo.setBill_no(do_data.getBill_no());
			pur_req_entry_vo.setEntry_no(do_data.getEntry_no());
			pur_req_entry_vo.setSrc_bill_type(do_data.getSrc_bill_type());
			pur_req_entry_vo.setSrc_bill_id(do_data.getSrc_bill_id());
			pur_req_entry_vo.setSrc_entry_id(do_data.getSrc_entry_id());
			pur_req_entry_vo.setSrc_no(do_data.getSrc_no());
			pur_req_entry_vo.setMaterial_id(do_data.getMaterial_id());
			pur_req_entry_vo.setUnit_id(do_data.getUnit_id());
			pur_req_entry_vo.setQty(do_data.getQty());
			pur_req_entry_vo.setTax_rate(do_data.getTax_rate());
			pur_req_entry_vo.setPrice(do_data.getPrice());
			pur_req_entry_vo.setAmt(do_data.getAmt());
			pur_req_entry_vo.setSuggest_supplier_id(do_data.getSuggest_supplier_id());
			pur_req_entry_vo.setOrdered_qty(do_data.getOrdered_qty());
			pur_req_entry_vo.setRemark(do_data.getRemark());
			pur_req_entry_vo.setCustom1(do_data.getCustom1());
			pur_req_entry_vo.setCustom2(do_data.getCustom2());
			pur_req_entry_vo.setVersion(do_data.getVersion());
			pur_req_entry_vo_list.push_back(pur_req_entry_vo);
		}
	}
	vo.setPur_req_entry(pur_req_entry_vo_list);
	
	list<PurCompareVO> pur_compare_vo_list;
	for (auto item : pur_compare)
	{
		list<PurComDO> pur_compare_do = entry_dao.selectPurCompare(item);
		PurCompareVO pur_compare_vo;
		for (auto do_data : pur_compare_do)
		{
			pur_compare_vo.setId(do_data.getId());
			pur_compare_vo.setBill_no(do_data.getBill_no());
			pur_compare_vo.setBill_date(do_data.getBill_date());
			pur_compare_vo.setSrc_bill_type(do_data.getSrc_bill_type());
			pur_compare_vo.setSrc_bill_id(do_data.getSrc_bill_id());
			pur_compare_vo.setSrc_no(do_data.getSrc_no());
			pur_compare_vo.setSubject(do_data.getSubject());
			pur_compare_vo.setIs_rubric(do_data.getIs_rubric());
			pur_compare_vo.setCandidate_quot_ids(do_data.getCandi_date_quot_ids());
			pur_compare_vo.setPayment_method(do_data.getPayment_method());
			pur_compare_vo.setDelivery_place(do_data.getDelivery_place());
			pur_compare_vo.setDelivery_time(do_data.getDelivery_time());
			pur_compare_vo.setAttachment(do_data.getAttachment());
			pur_compare_vo.setRemark(do_data.getRemark());
			pur_compare_vo.setIs_auto(do_data.getIs_auto());
			pur_compare_vo.setBill_stage(do_data.getBill_stage());
			pur_compare_vo.setApprover(do_data.getApprover());
			pur_compare_vo.setBpmi_instance_id(do_data.getBpmi_instance_id());
			pur_compare_vo.setApproval_result_type(do_data.getApproval_result_type());
			pur_compare_vo.setApproval_remark(do_data.getApproval_remark());
			pur_compare_vo.setIs_effective(do_data.getIs_effective());
			pur_compare_vo.setEffective_time(do_data.getEffective_time());
			pur_compare_vo.setIs_closed(do_data.getIs_closed());
			pur_compare_vo.setIs_voided(do_data.getIs_voided());
			pur_compare_vo.setSys_org_code(do_data.getSys_org_code());
			pur_compare_vo.setCreate_by(do_data.getCreate_by());
			pur_compare_vo.setCreate_time(do_data.getCreate_time());
			pur_compare_vo.setUpdate_by(do_data.getUpdate_by());
			pur_compare_vo.setUpdate_time(do_data.getUpdate_time());
			pur_compare_vo.setVersion(do_data.getVersion());
			pur_compare_vo_list.push_back(pur_compare_vo);
		}
	}
	vo.setPur_compare(pur_compare_vo_list);

	list<PurCompareEntryVO> pur_compare_entry_vo_list;
	for (auto item : pur_compare_entry)
	{
		list<PurComEntryDO> pur_compare_entry_do = entry_dao.selectPurCompareEntry(item);
		PurCompareEntryVO pur_compare_entry_vo;

		for (auto do_data : pur_compare_entry_do)
		{
			pur_compare_entry_vo.setId(do_data.getId());
			pur_compare_entry_vo.setMid(do_data.getMid());
			pur_compare_entry_vo.setBill_no(do_data.getBill_no());
			pur_compare_entry_vo.setEntry_no(do_data.getEntry_no());
			pur_compare_entry_vo.setSrc_bill_type(do_data.getSrc_bill_type());
			pur_compare_entry_vo.setSrc_bill_id(do_data.getSrc_bill_id());
			pur_compare_entry_vo.setSrc_entry_id(do_data.getSrc_entry_id());
			pur_compare_entry_vo.setSrc_no(do_data.getSrc_no());
			pur_compare_entry_vo.setSupplier_id(do_data.getSupplier_id());
			pur_compare_entry_vo.setMaterial_id(do_data.getMaterial_id());
			pur_compare_entry_vo.setUnit_id(do_data.getUnit_id());
			pur_compare_entry_vo.setQty(do_data.getQty());
			pur_compare_entry_vo.setTax_rate(do_data.getTax_rate());
			pur_compare_entry_vo.setPrice(do_data.getPrice());
			pur_compare_entry_vo.setDiscount_rate(do_data.getDiscount_rate());
			pur_compare_entry_vo.setAmt(do_data.getAmt());
			pur_compare_entry_vo.setRanking(do_data.getRanking());
			pur_compare_entry_vo.setRemark(do_data.getRemark());
			pur_compare_entry_vo.setCustom1(do_data.getCustom1());
			pur_compare_entry_vo.setCustom2(do_data.getCustom2());
			pur_compare_entry_vo.setVersion(do_data.getVersion());
			pur_compare_entry_vo_list.push_back(pur_compare_entry_vo);
		}
	}
	vo.setPur_compare_entry(pur_compare_entry_vo_list);
	
	list<PurInquiryVO> pur_inquiry_vo_list;
	for (auto item : pur_inquiry)
	{
		list<PurInquiryDO> pur_inquiry_do = entry_dao.selectPurInquiry(item);
		PurInquiryVO pur_inquiry_vo;
		for (auto do_data : pur_inquiry_do)
		{
			pur_inquiry_vo.setId(do_data.getId());
			pur_inquiry_vo.setBill_no(do_data.getBill_no());
			pur_inquiry_vo.setBill_date(do_data.getBill_date());
			pur_inquiry_vo.setSrc_bill_type(do_data.getSrc_bill_type());
			pur_inquiry_vo.setSrc_bill_id(do_data.getSrc_bill_id());
			pur_inquiry_vo.setSrc_no(do_data.getSrc_no());
			pur_inquiry_vo.setSubject(do_data.getSubject());
			pur_inquiry_vo.setIs_rubric(do_data.getIs_rubric());
			pur_inquiry_vo.setPayment_method(do_data.getPayment_method());
			pur_inquiry_vo.setDelivery_place(do_data.getDelivery_place());
			pur_inquiry_vo.setDelivery_time(do_data.getDelivery_time());
			pur_inquiry_vo.setContact(do_data.getContact());
			pur_inquiry_vo.setPhone(do_data.getPhone());
			pur_inquiry_vo.setFax(do_data.getFax());
			pur_inquiry_vo.setEmail(do_data.getEmail());
			pur_inquiry_vo.setQty(do_data.getQty());
			pur_inquiry_vo.setAmt(do_data.getAmt());
			pur_inquiry_vo.setQuot_count(do_data.getQuot_count());
			pur_inquiry_vo.setAttachment(do_data.getAttachment());
			pur_inquiry_vo.setRemark(do_data.getRemark());
			pur_inquiry_vo.setIs_auto(do_data.getIs_auto());
			pur_inquiry_vo.setBill_stage(do_data.getBill_stage());
			pur_inquiry_vo.setApprover(do_data.getApprover());
			pur_inquiry_vo.setBpmi_instance_id(do_data.getBpmi_instance_id());
			pur_inquiry_vo.setApproval_result_type(do_data.getApproval_result_type());
			pur_inquiry_vo.setApproval_remark(do_data.getApproval_remark());
			pur_inquiry_vo.setIs_effective(do_data.getIs_effective());
			pur_inquiry_vo.setEffective_time(do_data.getEffective_time());
			pur_inquiry_vo.setIs_closed(do_data.getIs_closed());
			pur_inquiry_vo.setIs_voided(do_data.getIs_voided());
			pur_inquiry_vo.setSys_org_code(do_data.getSys_org_code());
			pur_inquiry_vo.setCreate_by(do_data.getCreate_by());
			pur_inquiry_vo.setCreate_time(do_data.getCreate_time());
			pur_inquiry_vo.setUpdate_by(do_data.getUpdate_by());
			pur_inquiry_vo.setUpdate_time(do_data.getUpdate_time());
			pur_inquiry_vo.setVersion(do_data.getVersion());
			pur_inquiry_vo_list.push_back(pur_inquiry_vo);
		}
	}
	vo.setPur_inquiry(pur_inquiry_vo_list);

	list<PurInquiryEntryVO> pur_inquiry_entry_vo_list;
	for (auto item : pur_inquiry_entry)
	{
		list<PurInquiryEntryDO> pur_inquiry_entry_do = entry_dao.selectPurInquiryEntry(item);
		PurInquiryEntryVO pur_inquiry_entry_vo;
		for (auto do_data : pur_inquiry_entry_do)
		{
			pur_inquiry_entry_vo.setId(do_data.getId());
			pur_inquiry_entry_vo.setMid(do_data.getMid());
			pur_inquiry_entry_vo.setBill_no(do_data.getBill_no());
			pur_inquiry_entry_vo.setEntry_no(do_data.getEntry_no());
			pur_inquiry_entry_vo.setSrc_bill_type(do_data.getSrc_bill_type());
			pur_inquiry_entry_vo.setSrc_bill_id(do_data.getSrc_bill_id());
			pur_inquiry_entry_vo.setSrc_entry_id(do_data.getSrc_entry_id());
			pur_inquiry_entry_vo.setSrc_no(do_data.getSrc_no());
			pur_inquiry_entry_vo.setMaterial_id(do_data.getMaterial_id());
			pur_inquiry_entry_vo.setUnit_id(do_data.getUnit_id());
			pur_inquiry_entry_vo.setQty(do_data.getQty());
			pur_inquiry_entry_vo.setTax_rate(do_data.getTax_rate());
			pur_inquiry_entry_vo.setPrice(do_data.getPrice());
			pur_inquiry_entry_vo.setAmt(do_data.getAmt());
			pur_inquiry_entry_vo.setRemark(do_data.getRemark());
			pur_inquiry_entry_vo.setCustom1(do_data.getCustom1());
			pur_inquiry_entry_vo.setCustom2(do_data.getCustom2());
			pur_inquiry_entry_vo.setVersion(do_data.getVersion());
			pur_inquiry_entry_vo_list.push_back(pur_inquiry_entry_vo);
		}
	}
	vo.setPur_inquiry_entry(pur_inquiry_entry_vo_list);

	list<PurQuotVO> pur_quot_vo_list;
	for (auto item : pur_quot)
	{
		list<PurQuotDO> pur_quot_do = entry_dao.selectPurQuot(item);
		PurQuotVO pur_quot_vo;
		for (auto do_data : pur_quot_do)
		{
			pur_quot_vo.setId(do_data.getId());
			pur_quot_vo.setBill_no(do_data.getBill_no());
			pur_quot_vo.setBill_date(do_data.getBill_date());
			pur_quot_vo.setSrc_bill_type(do_data.getSrc_bill_type());
			pur_quot_vo.setSrc_bill_id(do_data.getSrc_bill_id());
			pur_quot_vo.setSrc_no(do_data.getSrc_no());
			pur_quot_vo.setSubject(do_data.getSubject());
			pur_quot_vo.setIs_rubric(do_data.getIs_rubric());
			pur_quot_vo.setIs_temp_supplier(do_data.getIs_temp_supplier());
			pur_quot_vo.setSupplier_id(do_data.getSupplier_id());
			pur_quot_vo.setSupplier_name(do_data.getSupplier_name());
			pur_quot_vo.setPayment_method(do_data.getPayment_method());
			pur_quot_vo.setDelivery_time(do_data.getDelivery_time());
			pur_quot_vo.setDelivery_place(do_data.getDelivery_place());
			pur_quot_vo.setContact(do_data.getContact());
			pur_quot_vo.setPhone(do_data.getPhone());
			pur_quot_vo.setFax(do_data.getFax());
			pur_quot_vo.setEmail(do_data.getEmail());
			pur_quot_vo.setQty(do_data.getQty());
			pur_quot_vo.setAmt(do_data.getAmt());
			pur_quot_vo.setAttachment(do_data.getAttachment());
			pur_quot_vo.setRemark(do_data.getRemark());
			pur_quot_vo.setIs_auto(do_data.getIs_auto());
			pur_quot_vo.setBill_stage(do_data.getBill_stage());
			pur_quot_vo.setApprover(do_data.getApprover());
			pur_quot_vo.setBpmi_instance_id(do_data.getBpmi_instance_id());
			pur_quot_vo.setApproval_result_type(do_data.getApproval_result_type());
			pur_quot_vo.setApproval_remark(do_data.getApproval_remark());
			pur_quot_vo.setIs_effective(do_data.getIs_effective());
			pur_quot_vo.setEffective_time(do_data.getEffective_time());
			pur_quot_vo.setIs_closed(do_data.getIs_closed());
			pur_quot_vo.setIs_voided(do_data.getIs_voided());
			pur_quot_vo.setSys_org_code(do_data.getSys_org_code());
			pur_quot_vo.setCreate_by(do_data.getCreate_by());
			pur_quot_vo.setCreate_time(do_data.getCreate_time());
			pur_quot_vo.setUpdate_by(do_data.getUpdate_by());
			pur_quot_vo.setUpdate_time(do_data.getUpdate_time());
			pur_quot_vo.setVersion(do_data.getVersion());
			pur_quot_vo_list.push_back(pur_quot_vo);
		}
	}
	vo.setPur_quot(pur_quot_vo_list);


	list<PurQuotEntryVO> pur_quot_entry_vo_list;
	for (auto item : pur_quot_entry)
	{
		list<PurQuotEntryDO> pur_quot_entry_do = entry_dao.selectPurQuotEntry(item);
		PurQuotEntryVO pur_quot_entry_vo;
		for (auto do_data : pur_quot_entry_do)
		{
			pur_quot_entry_vo.setId(do_data.getId());
			pur_quot_entry_vo.setMid(do_data.getMid());
			pur_quot_entry_vo.setBill_no(do_data.getBill_no());
			pur_quot_entry_vo.setEntry_no(do_data.getEntry_no());
			pur_quot_entry_vo.setSrc_bill_type(do_data.getSrc_bill_type());
			pur_quot_entry_vo.setSrc_bill_id(do_data.getSrc_bill_id());
			pur_quot_entry_vo.setSrc_entry_id(do_data.getSrc_entry_id());
			pur_quot_entry_vo.setSrc_no(do_data.getSrc_no());
			pur_quot_entry_vo.setMaterial_id(do_data.getMaterial_id());
			pur_quot_entry_vo.setUnit_id(do_data.getUnit_id());
			pur_quot_entry_vo.setQty(do_data.getQty());
			pur_quot_entry_vo.setTax_rate(do_data.getTax_rate());
			pur_quot_entry_vo.setPrice(do_data.getPrice());
			pur_quot_entry_vo.setDiscount_rate(do_data.getDiscount_rate());
			pur_quot_entry_vo.setAmt(do_data.getAmt());
			pur_quot_entry_vo.setRemark(do_data.getRemark());
			pur_quot_entry_vo.setCustom1(do_data.getCustom1());
			pur_quot_entry_vo.setCustom2(do_data.getCustom2());
			pur_quot_entry_vo.setVersion(do_data.getVersion());
			pur_quot_entry_vo_list.push_back(pur_quot_entry_vo);
		}
	}
	vo.setPur_quot_entry(pur_quot_entry_vo_list);
	return vo;
}

// 保存数据
uint64_t PurOrderService::saveData(const PurOrderDTO& dto,const PayloadDTO& payload)
{
	//组装数据
	PurOrderDO data;
	PurOrderDAO dao;
	uint64_t result = -1;

	//调用雪花算法
	SnowFlake sf(1, 4);
	string time = getTime();
	
	if (dto.getBill_no() == "" || dto.getBill_date() == "" || dto.getOp_dept() == "" || dto.getOp_er() == "" || dto.getSupplier_id() == "" || dto.getInvoice_type() == "")
	{
		return result;
	}

	data.setId(std::to_string(sf.nextId()));
	SET_PUR_ORDER_DO();
	// 创建人，从payload获取
	data.setCreate_by(payload.getUsername());
	data.setCreate_time(time);
	result = dao.insert(data);
	if (!result) return result;

	list<PurOrderEntryDTO> poe = dto.getDetail();
	PurOrderEntryDAO entryDao;
	for (auto entrydto: poe)
	{
		if (entrydto.getEntry_no() == 0 || entrydto.getMaterial_id() == "" || entrydto.getUnit_id() == "" || entrydto.getQty() == 0 || entrydto.getTax_rate() == 0 || entrydto.getPrice() == 0 || entrydto.getDiscount_rate() == 0)
			return -1;

		PurOrderEntryDO entryData;
		entryData.setId(std::to_string(sf.nextId()));
		SET_PUR_ORDER_ENTRY_DO();
		result = entryDao.insert(entryData);
		if (!result) return result;
	}
	
	return result;
}

// 修改数据
bool PurOrderService::updateData(const PurOrderDTO& dto, const PayloadDTO& payload)
{
	//组装数据
	PurOrderDO data;
	PurOrderDAO dao;
	uint64_t result = -1;
	string time = getTime();

	//调用雪花算法
	SnowFlake sf(1, 4);

	data.setId(dto.getId());
	SET_PUR_ORDER_DO();
	// 创建人，从payload获取
	data.setUpdate_by(payload.getUsername());
	data.setUpdate_time(time);

	result = dao.update(data);

	list<PurOrderEntryDTO> poe = dto.getDetail();

	PurOrderEntryDAO entryDao;
	for (auto entrydto : poe)
	{
		PurOrderEntryDO entryData;
		entryData.setId(entrydto.getId());
		SET_PUR_ORDER_ENTRY_DO();

		if (entryDao.count(entryData))
		{
			result = entryDao.update(entryData);
		}
		else
		{
			entryData.setId(std::to_string(sf.nextId()));
			entryDao.insert(entryData);
		}
	}
	
	return result;
}

// 修改状态
bool PurOrderService::updateStatus(const PurOrderDTO& dto)
{
	PurOrderDO data;
	PurOrderDAO dao;
	uint64_t result = -1;
	string time = getTime();
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	data.setIs_voided(dto.getIs_voided());
	data.setIs_closed(dto.getIs_closed());
	data.setIs_effective(dto.getIs_effective());
	data.setUpdate_time(time);

	if (dao.count(data))
	{
		result = dao.update(data);
	}
	else
	{
		return false;
	}
	return result;
}

// 通过ID删除数据
bool PurOrderService::removeData(uint64_t id)
{
	return true;
}
