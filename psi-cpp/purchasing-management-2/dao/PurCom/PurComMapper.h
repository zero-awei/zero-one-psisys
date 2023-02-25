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
#ifndef _PUR_COM_MAPPER_
#define _PUR_COM_MAPPER_

#include "Mapper.h"
#include "../../domain/do/PurCom/PurComDO.h"
#include "../../domain/do/PurCom/PurComEntryDO.h"


/**
 * 采购比价表字段匹配映射
 */

class PurComMapper :public Mapper<PurComDO> {
public:
	PurComDO mapper(ResultSet* resultSet) const override {



		// 生成DO对象,将sql语句中的表项名与DO中的成员名进行映射关系
		PurComDO data;

		data.setId(resultSet->getString("id"));
		data.setBill_no(resultSet->getString("bill_no"));
		data.setBill_date(resultSet->getString("bill_date"));
		data.setSrc_bill_type(resultSet->getString("src_bill_type"));
		data.setSrc_bill_id(resultSet->getString("src_bill_id"));
		data.setSrc_no(resultSet->getString("src_no"));
		data.setSubject(resultSet->getString("subject"));
		data.setIs_rubric(resultSet->getInt("is_rubric"));
		data.setCandi_date_quot_ids(resultSet->getString("candidate_quot_ids"));
		data.setPayment_method(resultSet->getString("payment_method"));
		data.setDelivery_place(resultSet->getString("delivery_place"));
		data.setDelivery_time(resultSet->getString("delivery_time"));
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

	}
};



#endif // !_PUR_COM_MAPPER_