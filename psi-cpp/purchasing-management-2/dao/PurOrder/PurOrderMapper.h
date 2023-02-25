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
#ifndef _PUR_ORDER_MAPPER
#define _PUR_ORDER_MAPPER

#include "Mapper.h"
#include "../../domain/do/PurOrder/PurOrderDO.h"

/**
 * 采购订单表字段匹配映射
 */
class SampleMapper : public Mapper<PurOrderDO>
{
public:
	PurOrderDO mapper(ResultSet* resultSet) const override
	{
		PurOrderDO data;
		data.setId(resultSet->getString(1));
		data.setBill_no(resultSet->getString(2));
		data.setBill_date(resultSet->getString(3));
		data.setSrc_bill_type(resultSet->getString(4));
		data.setSrc_bill_id(resultSet->getString(5));
		data.setSrc_no(resultSet->getString(6));
		data.setSubject(resultSet->getString(7));
		data.setIs_rubric(resultSet->getInt(8));
		data.setPur_type(resultSet->getString(9));
		data.setSupplier_id(resultSet->getString(10));
		data.setContact(resultSet->getString(11));
		data.setPhone(resultSet->getString(12));
		data.setFax(resultSet->getString(13));
		data.setEmail(resultSet->getString(14));
		data.setOp_dept(resultSet->getString(15));
		data.setOp_er(resultSet->getString(16));
		data.setDelivery_method(resultSet->getString(17));
		data.setDelivery_place(resultSet->getString(18));
		data.setDelivery_time(resultSet->getString(19));
		data.setTransport_method(resultSet->getString(20));
		data.setPayment_method(resultSet->getString(21));
		data.setSettle_method(resultSet->getString(22));
		data.setSettle_time(resultSet->getString(23));
		data.setInvoice_type(resultSet->getString(24));
		data.setInvoice_method(resultSet->getString(25));
		data.setCurrency(resultSet->getString(26));

		data.setExchange_rate(resultSet->getDouble(27));
		data.setQty(resultSet->getDouble(28));
		data.setAmt(resultSet->getDouble(29)); // 此处没有getfloat
		data.setPrepayment_bal(resultSet->getDouble(30)); //
		data.setSettle_qty(resultSet->getDouble(31));
		data.setSettle_amt(resultSet->getDouble(32)); //
		data.setIn_qty(resultSet->getDouble(33));
		data.setIn_cost(resultSet->getDouble(34)); //
		data.setSettled_amt(resultSet->getDouble(35)); //
		data.setInvoiced_amt(resultSet->getDouble(36)); //

		data.setAttachment(resultSet->getString(37));
		data.setRemark(resultSet->getString(38));
		data.setIs_auto(resultSet->getInt(39));
		data.setBill_stage(resultSet->getString(40));
		data.setApprover(resultSet->getString(41));
		data.setBpmi_instance_id(resultSet->getString(42));
		data.setApproval_result_type(resultSet->getString(43));
		data.setApproval_remark(resultSet->getString(44));
		data.setIs_effective(resultSet->getInt(45));
		data.setEffective_time(resultSet->getString(46));
		data.setIs_closed(resultSet->getInt(47));
		data.setIs_voided(resultSet->getInt(48));

		data.setSys_org_code(resultSet->getString(49));
		data.setCreate_by(resultSet->getString(50));
		data.setCreate_time(resultSet->getString(51));
		data.setUpdate_by(resultSet->getString(52));
		data.setUpdate_time(resultSet->getString(53));
		data.setVersion(resultSet->getInt(54));
		return data;
	}
};

#endif // !_PUR_ORDER_MAPPER