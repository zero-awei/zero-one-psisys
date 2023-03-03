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
#ifndef _STKIOENTRY_MAPPER_
#define _STKIOENTRY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"



/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class StkIoEntryMapper : public Mapper<StkIoEntryDO>
{
public:
	StkIoEntryDO mapper(ResultSet* resultSet) const override
	{	
		StkIoEntryDO  data;

		data.setId(resultSet->getString(1));
		data.setMid(resultSet->getString(2));
		data.setBillNo(resultSet->getString(3));
		data.setEntryNo(resultSet->getString(4));
		data.setSrcBillType(resultSet->getString(5));
		data.setSrcBillId(resultSet->getString(6));
		data.setSrcEntryId(resultSet->getString(7));
		data.setSrcNo(resultSet->getString(8));
		data.setMaterialId(resultSet->getString(9));
		data.setBatchNo(resultSet->getString(10));
		data.setWarehouseId(resultSet->getString(11));
		data.setStockIoDirection(resultSet->getString(12));
		data.setSupplierId(resultSet->getString(13));
		data.setUnitId(resultSet->getString(14));
		data.setSwellQty(resultSet->getDouble(15));
		data.setQty(resultSet->getDouble(16));
		data.setExpense(resultSet->getDouble(17));
		data.setCost(resultSet->getDouble(18));
		data.setSettleQty(resultSet->getDouble(19));
		data.setTaxRate(resultSet->getDouble(20));
		data.setPrice(resultSet->getDouble(21));
		data.setDiscountRate(resultSet->getDouble(22));
		data.setTax(resultSet->getDouble(23));
		data.setSettleAmt(resultSet->getDouble(24));
		data.setInvoicedQty(resultSet->getDouble(25));
		data.setInvoicedAmt(resultSet->getDouble(26));
		data.setRemark(resultSet->getString(27));
		data.setCustom1(resultSet->getString(28));
		data.setCustom2(resultSet->getString(29));
		data.setVersion(resultSet->getString(30));

		return data;
	}
};

#endif // !_STKIOENTRY_MAPPER_