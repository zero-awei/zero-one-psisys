#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/26 14:21:55

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
#ifndef _PUR_QUOT_MAPPER_
#define _PUR_QUOT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/PurQuot/PurQuotDO.h"

/**
 * ≤…π∫∂©µ•entry±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class PurQuotMapper : public Mapper<PurQuotDO>
{
public:
	PurQuotDO mapper(ResultSet* resultSet) const override
	{
		PurQuotDO data;
		data.setId(resultSet->getString(1));
		data.setBill_no(resultSet->getString(2));
		data.setBill_date(resultSet->getString(3));
		data.setSrc_bill_type(resultSet->getString(4));
		data.setSrc_bill_id(resultSet->getString(5));
		data.setSrc_no(resultSet->getString(6));
		data.setSubject(resultSet->getString(7));
		data.setIs_rubric(resultSet->getInt(8));
		data.setIs_temp_supplier(resultSet->getInt(9));
		data.setSupplier_id(resultSet->getString(10));
		data.setSupplier_name(resultSet->getString(11));
		data.setPayment_method(resultSet->getString(12));
		data.setDelivery_time(resultSet->getString(13));
		data.setDelivery_place(resultSet->getString(14));
		data.setContact(resultSet->getString(15));
		data.setPhone(resultSet->getString(16));
		data.setFax(resultSet->getString(17));
		data.setEmail(resultSet->getString(18));
		data.setQty(resultSet->getDouble(19));
		data.setAmt(resultSet->getDouble(20));
		data.setAttachment(resultSet->getString(21));
		data.setRemark(resultSet->getString(22));
		data.setIs_auto(resultSet->getInt(23));
		data.setBill_stage(resultSet->getString(24));
		data.setApprover(resultSet->getString(25));
		data.setBpmi_instance_id(resultSet->getString(26));
		data.setApproval_result_type(resultSet->getString(27));
		data.setApproval_remark(resultSet->getString(28));
		data.setIs_effective(resultSet->getInt(29));
		data.setEffective_time(resultSet->getString(30));
		data.setIs_closed(resultSet->getInt(31));
		data.setIs_voided(resultSet->getInt(32));
		data.setSys_org_code(resultSet->getString(33));
		data.setCreate_by(resultSet->getString(34));
		data.setCreate_time(resultSet->getString(35));
		data.setUpdate_by(resultSet->getString(36));
		data.setUpdate_time(resultSet->getString(37));
		data.setVersion(resultSet->getInt(38));
		return data;
	}
};

#endif // !_PUR_ORDER_DETAIL_MAPPER