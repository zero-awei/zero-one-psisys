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
#include "../../dao/PurOrder/PurOrderDAO.h"

#define PUR_ORDER_DTO2DO

// 分页查询所有数据
PageVO<PurOrderVO> PurOrderService::listPurOrder(const PurOrderQuery& query)
{
	//构建返回对象
	PageVO<PurOrderVO> pages;

	return pages;
}

// 查询单个数据
PurOrderVO PurOrderService::getPurOrder(uint64_t id)
{
	PurOrderVO data;

	return data;
}

// 保存数据
uint64_t PurOrderService::saveData(const PurOrderDTO& dto)
{
	//组装数据
	PurOrderDO data;
	PurOrderDAO dao;

	//调用雪花算法
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	data.setBill_date(dto.getBill_date());
	data.setSrc_bill_type(dto.getSrc_bill_type());
	data.setSrc_bill_id(dto.getSrc_bill_id());
	data.setSrc_no(dto.getSrc_no());
	data.setSubject(dto.getSubject());
	data.setIs_rubric(dto.getIs_rubric());
	data.setPur_type(dto.getPur_type());
	data.setSupplier_id(dto.getSupplier_id());
	data.setContact(dto.getContact());
	data.setPhone(dto.getPhone());
	data.setFax(dto.getFax());
	data.setEmail(dto.getEmail());
	data.setOp_dept(dto.getOp_dept());
	data.setOp_er(dto.getOp_er());
	data.setDelivery_method(dto.getDelivery_method());
	data.setDelivery_place(dto.getDelivery_place());
	data.setDelivery_time(dto.getDelivery_time());
	data.setTransport_method(dto.getTransport_method());
	data.setPayment_method(dto.getPayment_method());
	data.setSettle_method(dto.getSettle_method());
	data.setSettle_time(dto.getSettle_time());
	data.setInvoice_method(dto.getInvoice_method());
	data.setInvoice_type(dto.getInvoice_type());
	data.setCurrency(dto.getCurrency());
	data.setExchange_rate(dto.getExchange_rate());
	data.setQty(dto.getQty());
	data.setAmt(dto.getAmt());
	data.setPrepayment_bal(dto.getPrepayment_bal());
	data.setSettle_qty(dto.getSettle_qty());
	data.setSettle_amt(dto.getSettle_amt());
	data.setIn_qty(dto.getIn_qty());
	data.setIn_cost(dto.getIn_cost());
	data.setSettled_amt(dto.getSettled_amt());
	data.setInvoiced_amt(dto.getInvoiced_amt());
	data.setAttachment(dto.getAttachment());
	data.setRemark(dto.getRemark());
	data.setIs_auto(dto.getIs_auto());
	data.setBill_stage(dto.getBill_stage());
	data.setApprover(dto.getApprover());
	data.setBpmi_instance_id(dto.getBpmi_instance_id());
	data.setApproval_result_type(dto.getApproval_result_type());
	data.setApproval_remark(dto.getApproval_remark());
	data.setIs_effective(dto.getIs_effective());
	data.setEffective_time(dto.getEffective_time());
	data.setIs_closed(dto.getIs_closed());
	data.setIs_voided(dto.getIs_voided());
	data.setSys_org_code(dto.getSys_org_code());
	data.setCreate_by(dto.getCreate_by());
	data.setCreate_time(dto.getCreate_time());
	data.setUpdate_by(dto.getUpdate_by());
	data.setUpdate_time(dto.getUpdate_time());
	data.setVersion(dto.getVersion());

	return dao.insert(data);
}

// 修改数据
bool PurOrderService::updateData(const PurOrderDTO& dto)
{
	return true;
}

// 修改数据
bool PurOrderService::updateStatus(const PurOrderDTO& dto)
{
	return true;
}

// 通过ID删除数据
bool PurOrderService::removeData(uint64_t id)
{
	return true;
}
