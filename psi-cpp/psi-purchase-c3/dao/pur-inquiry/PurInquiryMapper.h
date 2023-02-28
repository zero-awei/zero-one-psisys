#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef __PUR_INQUIRY_FIND_BILL_MAPPER_
#define __PUR_INQUIRY_FIND_BILL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pur-inquiry/PurInquiryDO.h"
#include "../../domain/do/pur-inquiry/PurInquiryEntryDO.h"
#include "../../domain/do/pur-inquiry/PurReqDO.h"
#include "../../domain/do/pur-inquiry/PurReqEntryDO.h"

/**
 * 普通查询列表字段匹配映射
 */
class PurInquiryFindBillMapper : public Mapper<PurInquiryDO>
{
public:
	PurInquiryDO mapper(ResultSet* resultSet) const override
	{
		PurInquiryDO data;
		//data.setId(to_string(resultSet->getInt("id")));
		data.setBill_no(resultSet->getString("bill_no"));
		data.setBill_date(resultSet->getString("bill_date"));
		data.setSrc_bill_type(resultSet->getString("src_bill_type"));
		data.setSrc_bill_id(resultSet->getString("src_bill_id"));
		data.setSrc_no(resultSet->getString("src_no"));
		data.setSubject(resultSet->getString("subject"));
		data.setIs_rubric(resultSet->getInt("is_rubric"));
		data.setDelivery_place(resultSet->getString("delivery_place"));
		data.setDelivery_time(resultSet->getString("delivery_time"));
		data.setContact(resultSet->getString("contact"));
		data.setPhone(resultSet->getString("phone"));
		data.setFax(resultSet->getString("fax"));
		data.setEmail(resultSet->getString("email"));
		data.setQty(resultSet->getDouble("qty"));
		data.setAmt(resultSet->getDouble("amt"));
		data.setQuot_count(resultSet->getInt("quot_count"));
		data.setAttachment(resultSet->getString("attachment"));
		data.setRemark(resultSet->getString("remark"));
		data.setIs_auto(resultSet->getInt("is_auto"));
		data.setBill_stage(resultSet->getString("bill_stage"));
		data.setApprover(resultSet->getString("approver"));
		data.setBpmi_instance_id(resultSet->getString("bpmi_instance_id"));
		data.setApproval_result_type(resultSet->getString("approval_result_type"));
		data.setApproval_remark(resultSet->getString("approval_remark"));
		data.setIs_effective(resultSet->getInt("is_effective"));
		data.setEffective_time(resultSet->getString("effective_time"));
		data.setIs_closed(resultSet->getInt("is_closed"));
		data.setIs_voided(resultSet->getInt("is_voided"));
		data.setSys_org_code(resultSet->getString("sys_org_code"));
		data.setCreate_by(resultSet->getString("create_by"));
		data.setCreate_time(resultSet->getString("create_time"));
		data.setUpdate_by(resultSet->getString("update_by"));
		data.setUpdate_time(resultSet->getString("update_time"));
		data.setVersion(resultSet->getInt("version"));
		return data;
	}
};


/**
 * 指定单据详情基础信息字段匹配映射
 */
class PurInquiryFindDetailBillMapper : public Mapper<PurInquiryDO>
{
public:
	PurInquiryDO mapper(ResultSet* resultSet) const override
	{
		PurInquiryDO data;
		data.setId(to_string(resultSet->getInt("id")));
		data.setBill_no(resultSet->getString("bill_no"));
		data.setBill_date(resultSet->getString("bill_date"));
		data.setSrc_bill_type(resultSet->getString("src_bill_type"));
		data.setSrc_bill_id(resultSet->getString("src_bill_id"));
		data.setSrc_no(resultSet->getString("src_no"));
		data.setSubject(resultSet->getString("subject"));
		data.setPayment_method(resultSet->getString("payment_method"));
		data.setDelivery_place(resultSet->getString("delivery_place"));
		data.setContact(resultSet->getString("contact"));
		data.setPhone(resultSet->getString("phone"));
		data.setFax(resultSet->getString("fax"));
		data.setEmail(resultSet->getString("email"));
		data.setQty(resultSet->getDouble("qty"));
		data.setQuot_count(resultSet->getInt("quot_count"));
		data.setRemark(resultSet->getString("remark"));
		data.setAttachment(resultSet->getString("attachment"));
		data.setApproval_remark(resultSet->getString("approval_remark"));
		data.setApproval_result_type(resultSet->getString("approval_result_type"));
		return data;
	}
};


// 明细分录列表字段匹配映射
class PurInquiryEntryMapper : public Mapper<PurInquiryEntryDO>
{
public:
	PurInquiryEntryDO mapper(ResultSet* resultSet) const override
	{
		PurInquiryEntryDO data;
		data.setEntry_src_bill_type(resultSet->getString("src_bill_type"));
		data.setEntry_src_no(resultSet->getString("src_no"));
		data.setMaterial_id(resultSet->getString("material_id"));
		// 规格型号
		data.setUnit_id(resultSet->getString("unit_id"));
		data.setEntry_qty(resultSet->getDouble("qty"));
		data.setTax_rate(resultSet->getDouble("tax_rate"));
		data.setPrice(resultSet->getDouble("price"));
		data.setEntry_Amt(resultSet->getDouble("amt"));
		data.setEntry_remark(resultSet->getString("remark"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setCustom2(resultSet->getString("custom2"));

		return data;
	}
};


// 申请单分录列表字段匹配映射
//class PurReqMapper : public Mapper<PurReqDO>
//{
//public:
//	PurReqDO mapper(ResultSet* resultSet) const override
//	{
//		PurReqDO data;
//		data.setBill_no(resultSet->getString("bill_no"));
//		data.setBill_date(resultSet->getString("bill_date"));
//		data.setSubject(resultSet->getString("subject"));
//		data.setSubject(resultSet->getString("pur_type"));
//		data.setRequest_time(resultSet->getString("request_time"));
//		data.setQty(resultSet->getDouble("qty"));
//		data.setOrdered_qty(resultSet->getDouble("ordered_qty"));
//		data.setAmt(resultSet->getDouble("amt"));
//		data.setRemark(resultSet->getString("remark"));
//
//		return data;
//	}
//};
//
//// 申请单分录明细列表字段匹配映射
//class PurReqEntryMapper : public Mapper<PurReqEntryDO>
//{
//public:
//	PurReqEntryDO mapper(ResultSet* resultSet) const override
//	{
//		PurReqEntryDO data;
//		data.setEntry_bill_no(resultSet->getString("bill_no"));
//		data.setEntry_no(resultSet->getString("entry_no"));
//		data.setMaterial_id(resultSet->getString("material_id"));
//		// 规格型号
//		data.setUnit_id(resultSet->getString("unit_id"));
//		data.setEntry_qty(resultSet->getDouble("qty"));
//		data.setOrdered_qty(resultSet->getDouble("ordered_qty"));
//		data.setTax_rate(resultSet->getDouble("tax_rate"));
//		data.setPrice(resultSet->getDouble("price"));
//		data.setEntry_Amt(resultSet->getDouble("amt"));
//		data.setSuggest_supplier_id(resultSet->getString("suggest_supplier_id"));
//		data.setEntry_remark(resultSet->getString("remark"));
//		data.setCustom1(resultSet->getString("custom1"));
//		data.setCustom2(resultSet->getString("custom2"));
//
//		return data;
//	}
//};



// 导出列表字段匹配映射
class PurInquiryExportMapper : public Mapper<PurInquiryDO>
{
public:
	PurInquiryDO mapper(ResultSet* resultSet) const override
	{
		PurInquiryDO data;
		data.setId(to_string(resultSet->getInt("id")));
		data.setBill_no(resultSet->getString("bill_no"));
		data.setBill_date(resultSet->getString("bill_date"));
		data.setBill_stage(resultSet->getString("bill_stage"));
		data.setSubject(resultSet->getString("subject"));
		data.setSrc_no(resultSet->getString("src_no"));
		data.setSrc_bill_id(resultSet->getString("src_bill_id"));
		data.setSrc_bill_type(resultSet->getString("src_bill_type"));
		data.setPayment_method(resultSet->getString("payment_method"));
		data.setDelivery_place(resultSet->getString("delivery_place"));
		data.setDelivery_time(resultSet->getString("delivery_time"));
		data.setContact(resultSet->getString("contact"));
		data.setPhone(resultSet->getString("phone"));
		data.setFax(resultSet->getString("fax"));
		data.setEmail(resultSet->getString("email"));
		data.setQty(resultSet->getDouble("qty"));
		data.setAmt(resultSet->getDouble("amt"));
		data.setQuot_count(resultSet->getInt("quot_count"));
		data.setRemark(resultSet->getString("remark"));
		data.setIs_effective(resultSet->getInt("is_effective"));
		data.setEffective_time(resultSet->getString("effective_time"));
		data.setIs_closed(resultSet->getInt("is_closed"));
		data.setIs_voided(resultSet->getInt("is_voided"));
		data.setIs_auto(resultSet->getInt("is_auto"));
		data.setIs_rubric(resultSet->getInt("is_rubric"));
		data.setCreate_by(resultSet->getString("create_by"));
		data.setCreate_time(resultSet->getString("create_time"));
		data.setSys_org_code(resultSet->getString("sys_org_code"));
		data.setUpdate_by(resultSet->getString("update_by"));
		data.setAttachment(resultSet->getString("attachment"));
		data.setBpmi_instance_id(resultSet->getString("bpmi_instance_id"));
		data.setApprover(resultSet->getString("approver"));
		data.setApproval_result_type(resultSet->getString("approval_result_type"));
		data.setApproval_remark(resultSet->getString("approval_remark"));

		return data;
	}
};


// 导出列表明细字段匹配映射
class PurInquiryExportEntryMapper : public Mapper<PurInquiryEntryDO>
{
public:
	PurInquiryEntryDO mapper(ResultSet* resultSet) const override
	{
		PurInquiryEntryDO data;
		data.setEntry_bill_no(resultSet->getString("bill_no"));
		data.setEntry_no(resultSet->getInt("entry_no"));
		data.setSrc_entry_id(resultSet->getString("src_entry_id"));
		data.setEntry_src_no(resultSet->getString("src_no"));
		data.setEntry_src_bill_id(resultSet->getString("src_bill_id"));
		data.setEntry_src_bill_type(resultSet->getString("src_bill_type"));
		data.setMaterial_id(resultSet->getString("material_id"));
		data.setUnit_id(resultSet->getString("unit_id"));
		data.setEntry_qty(resultSet->getDouble("qty"));
		data.setTax_rate(resultSet->getDouble("tax_rate"));
		data.setPrice(resultSet->getDouble("price"));
		data.setEntry_Amt(resultSet->getDouble("amt"));
		data.setEntry_remark(resultSet->getString("remark"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setCustom2(resultSet->getString("custom2"));

		return data;
	}
};





#endif // !_PUR_INQUIRY_FIND_BILL_MAPPER_