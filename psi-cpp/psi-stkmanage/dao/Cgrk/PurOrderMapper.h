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
#ifndef _PURORDER_MAPPER_
#define _PURORDER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Cgrk/PurOrderDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurOrderMapper : public Mapper<PurOrderDO>
{
public:
	PurOrderDO mapper(ResultSet* resultSet) const override
	{
		PurOrderDO  data;
		data.setId(resultSet->getString(1));
		data.setBillNo(resultSet->getString(2));
		data.setBillDate(resultSet->getString(3));
		data.setPurType(resultSet->getString(4));
		data.setPaymentMethod(resultSet->getString(5));
		data.setPrePaymentBal(resultSet->getDouble(6));
		data.setSettleMethod(resultSet->getString(7));
		data.setDeliveryTime(resultSet->getString(8));
		data.setDeliveryPlace(resultSet->getString(9));
		data.setDeliveryMethod(resultSet->getString(10));
		data.setInQty(resultSet->getDouble(11));
		data.setInCost(resultSet->getDouble(12));
		data.setInvoicedAmt(resultSet->getInt(13));
		data.setInvoiceType(resultSet->getString(14));
		data.setAmt(resultSet->getDouble (15));
		data.setIsClosed(resultSet->getInt(16));
		data.setOpDept(resultSet->getString(17));
		data.setOperator1(resultSet->getString(18));
		data.setQty(resultSet->getDouble(19));
		data.setRemark(resultSet->getString(20));
		data.setSettleAmt(resultSet->getDouble(21));
		data.setSettledAmt(resultSet->getDouble(22));
		data.setSrcNo(resultSet->getString(23));
		data.setSubject(resultSet->getString(24));
		data.setSupplierId(resultSet->getString(25));

		return data;
	}
};

#endif // !_PURORDER_MAPPER_
