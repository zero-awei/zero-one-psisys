﻿#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/20 14:55:59

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
#ifndef _PUR_COM_FIND_DETAIL_BILL_MAPPER_
#define _PUR_COM_FIND_DETAIL_BILL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pur-compare/PurCompareDO.h"
#include "CharsetConvertHepler.h"

#define ITOWORD(t) (t==1 ?CharsetConvertHepler::ansiToUtf8("是"):CharsetConvertHepler::ansiToUtf8("否"))
/**
 * 查看指定单据详细信息字段匹配映射
 */
class PurComFindDetailBillMapper : public Mapper<PurCompareDO>
{
public:
	PurCompareDO mapper(ResultSet* resultSet) const override
	{
		PurCompareDO data;
		data.setBillNo(resultSet->getString("bill_no"));
		data.setBillDate(resultSet->getString("bill_date"));
		data.setBillStage(resultSet->getString("bill_stage"));
		data.setIsEffective(ITOWORD(resultSet->getInt("is_effective")));
		data.setIsClosed(ITOWORD(resultSet->getInt("is_closed")));
		data.setIsVoided(ITOWORD(resultSet->getInt("is_voided")));
		data.setEffectiveTime(resultSet->getString("effective_time"));
		data.setApprover(resultSet->getString("approver"));
		data.setBpmiInstanceId(resultSet->getString("bpmi_instance_id"));
		data.setCreateTime(resultSet->getString("create_time"));
		data.setSysOrgCode(resultSet->getString("sys_org_code"));
		data.setCreateBy(resultSet->getString("create_by"));
		data.setUpdateTime(resultSet->getString("update_time"));
		data.setUpdateBy(resultSet->getString("update_by"));
		data.setIsAuto(ITOWORD(resultSet->getInt("is_auto")));
		data.setIsRubric(ITOWORD(resultSet->getInt("is_rubric")));
		data.setSrcBillType(resultSet->getString("src_bill_type"));
		data.setSubject(resultSet->getString("subject"));
		data.setSrcNo(resultSet->getString("src_no"));
		data.setPaymentMethod(resultSet->getString("payment_method"));
		data.setDeliveryTime(resultSet->getString("delivery_time"));
		data.setDeliveryPlace(resultSet->getString("delivery_place"));
		data.setRemark(resultSet->getString("remark"));
		data.setApprovalResultType(resultSet->getString("approval_result_type"));
		data.setApprovalRemark(resultSet->getString("approval_remark"));
		//todo：附件
		data.setAttachment(resultSet->getString("attachment"));
		return data;
	}
};

#endif
