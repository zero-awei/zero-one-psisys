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
#ifndef _PURORDERENTRY_MAPPER_
#define _PURORDERENTRY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Cgrk/PurOrderEntryDO.h"



/**
 * pur_order_entryÊý¾Ý¿â
 */
class PurOrderEntryMapper : public Mapper<PurOrderEntryDO>
{
public:
	PurOrderEntryDO mapper(ResultSet* resultSet) const override
	{
		PurOrderEntryDO  data;

		data.setId(resultSet->getString(1));
		data.setMid(resultSet->getString(2));
		data.setBillNo(resultSet->getString(3));
		data.setEntryNo(resultSet->getInt(4));
		data.setSrcBillType(resultSet->getString(5));
		data.setSrcBillId(resultSet->getString(6));
		data.setSrcEntryId(resultSet->getString(7));
		data.setSrcNo(resultSet->getString(8));
		data.setMaterialId(resultSet->getString(9));
		data.setUnitId(resultSet->getString(10));
		data.setQty(resultSet->getDouble(11));
		data.setTaxRate(resultSet->getDouble(12));
		data.setPrice(resultSet->getDouble(13));
		data.setDiscountRate(resultSet->getDouble(14));
		data.setTax(resultSet->getDouble(15));
		data.setAmt(resultSet->getDouble(16));
		data.setInQty(resultSet->getDouble(17));
		data.setInCost(resultSet->getDouble(18));
		data.setSettleQty(resultSet->getDouble(19));
		data.setSettleAmt(resultSet->getDouble(20));
		data.setInvoicedQty(resultSet->getDouble(21));
		data.setInvoicedAmt(resultSet->getDouble(22));
		data.setRemark(resultSet->getString(23));
		data.setCustom1(resultSet->getString(24));
		data.setCustom2(resultSet->getString(25));
		data.setVersion(resultSet->getInt(26));

		return data;
	}
};

#endif // !_STKIOENTRY_MAPPER_