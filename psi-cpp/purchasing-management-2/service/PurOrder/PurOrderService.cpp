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
	}
	vo.setEntry(pur_order_entry_vo_list);
	return vo;
}

// 保存数据
uint64_t PurOrderService::saveData(const PurOrderDTO& dto)
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
bool PurOrderService::updateData(const PurOrderDTO& dto)
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
