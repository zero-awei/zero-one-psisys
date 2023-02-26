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
entryData.setMid(entrydto.getMid());\
entryData.setBill_no(entrydto.getBill_no());\
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

	return pages;
}

// 查询单个数据
PurOrderDetailVO PurOrderService::getPurOrder(string bill_no)
{
	PurOrderDetailVO data;
	PurOrderDAO dao;
	list<PurOrderDO> do_datas;
	do_datas = dao.selectDetail(bill_no);
	for (auto do_data : do_datas)
	{
		data.setId(do_data.getId());
	}
	return data;
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

	if (dao.count(data))
	{
		result = dao.update(data);
	}
	else
	{
		return -1;
	}

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
