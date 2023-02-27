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
#ifndef _PUR_INQUIRY_MAPPER_
#define _PUR_INQUIRY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/PurInquiry/PurInquiryDO.h"

/**
 * ≤…π∫∂©µ•entry±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class PurInquiryMapper : public Mapper<PurInquiryDO>
{
public:
	PurInquiryDO mapper(ResultSet* resultSet) const override
	{
		PurInquiryDO data;
		data.setId(resultSet->getString(1));
		data.setBill_no(resultSet->getString(2));
		data.setBill_date(resultSet->getString(3));
		data.setSrc_bill_type(resultSet->getString(4));
		data.setSrc_bill_id(resultSet->getString(5));
		data.setSrc_no(resultSet->getString(6));
		data.setSubject(resultSet->getString(7));
		data.setIs_rubric(resultSet->getInt(8));
		data.setPur_type(resultSet->getString(9));
		data.setRequest_dept(resultSet->getString(10));
		data.setRequester(resultSet->getString(11));
		data.setRequest_time(resultSet->getString(12));
		data.setQty(resultSet->getDouble(13));
		data.setAmt(resultSet->getDouble(14));
		data.setOrdered_qty(resultSet->getDouble(15));
		data.setAttachment(resultSet->getString(16));
		data.setRemark(resultSet->getString(17));
		data.setIs_auto(resultSet->getInt(18));
		data.setBill_stage(resultSet->getString(19));
		data.setApprover(resultSet->getString(20));
		data.setBpmi_instance_id(resultSet->getString(21));
		data.setApproval_result_type(resultSet->getString(22));
		data.setApproval_remark(resultSet->getString(23));
		data.setIs_effective(resultSet->getInt(24));
		data.setEffective_time(resultSet->getString(25));
		data.setIs_closed(resultSet->getInt(26));
		data.setIs_voided(resultSet->getInt(27));
		data.setSys_org_code(resultSet->getString(28));
		data.setCreate_by(resultSet->getString(29));
		data.setCreate_time(resultSet->getString(30));
		data.setUpdate_by(resultSet->getString(31));
		data.setUpdate_time(resultSet->getString(32));
		data.setVersion(resultSet->getInt(33));
		return data;
	}
};

#endif // !_PUR_ORDER_DETAIL_MAPPER