#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: adam
 @Date: 2022/2/24 10:05:55

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
#ifndef _PUE_REQ_MAPPER_
#define _PUE_REQ_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pur-req/PurReqAdamDO.h"

/**
 * Ê¾ÀýÖ÷±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurReqMapper : public Mapper<PurReqAdamDO>
{
public:
	PurReqAdamDO mapper(ResultSet* resultSet) const override
	{
		int i = 1;
		PurReqAdamDO data;
		data.setId(resultSet->getString(i++));
		data.setBillNo(resultSet->getString(i++));
		data.setBillDate(resultSet->getString(i++));
		data.setSrcBillType(resultSet->getString(i++));
		data.setSrcBillId(resultSet->getString(i++));
		data.setSrcNo(resultSet->getString(i++));
		data.setSubject(resultSet->getString(i++));
		data.setIsRubric(resultSet->getInt(i++));
		data.setPurType(resultSet->getString(i++));
		data.setRequestDept(resultSet->getString(i++));
		data.setRequester(resultSet->getString(i++));
		data.setRequestTime(resultSet->getString(i++));
		data.setQty(resultSet->getDouble(i++));
		data.setAmt(resultSet->getDouble(i++));
		data.setOrderedQty(resultSet->getDouble(i++));
		data.setAttachment(resultSet->getString(i++));
		data.setRemark(resultSet->getString(i++));
		data.setIsAuto(resultSet->getInt(i++));
		data.setBillStage(resultSet->getString(i++));
		data.setApprover(resultSet->getString(i++));
		data.setBpmiInstanceId(resultSet->getString(i++));
		data.setApprovalResultType(resultSet->getString(i++));
		data.setApprovalRemark(resultSet->getString(i++));
		data.setIsEffective(resultSet->getInt(i++));
		data.setEffectiveTime(resultSet->getString(i++));
		data.setIsClosed(resultSet->getInt(i++));
		data.setIsVoided(resultSet->getInt(i++));
		data.setSysOrgCode(resultSet->getString(i++));
		data.setCreateBy(resultSet->getString(i++));
		data.setCreateTime(resultSet->getString(i++));
		data.setUpdateBy(resultSet->getString(i++));
		data.setUpdateTime(resultSet->getString(i++));
		data.setVersion(resultSet->getInt(i++));
		return data;
	}
};

#endif // !_PUE_REQ_MAPPER_