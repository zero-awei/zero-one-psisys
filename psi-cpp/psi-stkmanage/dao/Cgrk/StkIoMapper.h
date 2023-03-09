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
#ifndef _STKIO_MAPPER_
#define _STKIO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Cgrk/StkIoDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class StkIoMapper : public Mapper<StkIoDO>
{
public:
	StkIoDO mapper(ResultSet* resultSet) const override
	{
		StkIoDO  data;
		data.setId(resultSet->getString(1));
		data.setBillNo(resultSet->getString(2));
		data.setBillDate(resultSet->getString(3));
		data.setSrcBillType(resultSet->getString(4));
		data.setSrcBillId(resultSet->getString(5));
		data.setSrcNo(resultSet->getString(6));
		data.setSubject(resultSet->getString(7));
		data.setIsRubric(resultSet->getInt(8));
		data.setStockIoType(resultSet->getString(9));
		data.setOpDept(resultSet->getString(10));
		data.setOperator1(resultSet->getString(11));
		data.setHandler(resultSet->getString(12));
		data.setHasRp(resultSet->getInt(13));
		data.setHasSwell(resultSet->getInt(14));
		data.setSupplierId(resultSet->getString(15));
		data.setCustomerId(resultSet->getString(16));
		data.setInvoiceType(resultSet->getString(17));
		data.setCost(resultSet->getDouble(18));
		data.setSettleAmt(resultSet->getDouble(19));
		data.setSettledAmt(resultSet->getDouble(20));
		data.setInvoicedAmt(resultSet->getDouble(21));
		data.setAttachment(resultSet->getString(22));
		data.setRemark(resultSet->getString(23));
		data.setIsAuto(resultSet->getInt(24));
		data.setBillStage(resultSet->getString(25));
		data.setApprover(resultSet->getString(26));
		data.setBpmiInstanceId(resultSet->getString(27));
		data.setApprovalResultType(resultSet->getString(28));
		data.setApprovalRemark(resultSet->getString(29));
		data.setIsEffective(resultSet->getInt(30));
		data.setEffectiveTime(resultSet->getString(31));
		data.setIsClosed(resultSet->getInt(32));
		data.setIsVoided(resultSet->getInt(33));
		data.setSysOrgCode(resultSet->getString(34));
		data.setCreateBy(resultSet->getString(35));
		data.setCreateTime(resultSet->getString(36));
		data.setUpdateBy(resultSet->getString(37));
		data.setUpdateTime(resultSet->getString(38));
		data.setVersion(resultSet->getString(39));

		return data;
	}
};

#endif // !_SAMPLE_MAPPER_