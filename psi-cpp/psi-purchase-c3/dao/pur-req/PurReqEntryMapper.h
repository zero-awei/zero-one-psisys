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
#ifndef _PUR_REQ_ENTRY_MAPPER_
#define _PUR_REQ_ENTRY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pur-req/PurReqEntryAdamDO.h"

/**
 * Ê¾ÀýÖ÷±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurReqEntryMapper : public Mapper<PurReqEntryAdamDO>
{
public:
	PurReqEntryAdamDO mapper(ResultSet* resultSet) const override
	{
		int i = 1;
		PurReqEntryAdamDO data;
		data.setId(resultSet->getString(i++));
		data.setMid(resultSet->getString(i++));
		data.setBillNo(resultSet->getString(i++));
		data.setEntryNo(resultSet->getInt(i++));
		data.setSrcBillType(resultSet->getString(i++));
		data.setSrcBillId(resultSet->getString(i++));
		data.setSrcEntryId(resultSet->getString(i++));
		data.setSrcNo(resultSet->getString(i++));
		data.setMaterialId(resultSet->getString(i++));
		data.setUnitId(resultSet->getString(i++));
		data.setQty(resultSet->getDouble(i++));
		data.setTaxRate(resultSet->getDouble(i++));
		data.setPrice(resultSet->getDouble(i++));
		data.setAmt(resultSet->getDouble(i++));
		data.setSuggestSupplierId(resultSet->getString(i++));
		data.setOrderedQty(resultSet->getDouble(i++));
		data.setRemark(resultSet->getString(i++));
		data.setCustom1(resultSet->getString(i++));
		data.setCustom2(resultSet->getString(i++));
		data.setVersion(resultSet->getInt(i++));

		return data;
	}
};

#endif // !_PUR_REQ_ENTRY_MAPPER_