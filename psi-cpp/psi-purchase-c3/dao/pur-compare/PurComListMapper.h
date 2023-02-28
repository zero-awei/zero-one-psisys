#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/22 11:40:59

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
#ifndef _PUR_COM_LIST_MAPPER_
#define _PUR_COM_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pur-compare/PurComQuotDO.h"

/**
 * 报价单列表字段匹配映射
 */
class PurComListMapper : public Mapper<PurComQuotDO>
{
public:
	PurComQuotDO mapper(ResultSet* resultSet) const override
	{
		PurComQuotDO data;
		data.setBillNo(resultSet->getString("bill_no"));
		data.setBillDate(resultSet->getString("bill_date"));
		data.setSubject(resultSet->getString("subject"));
		data.setSupplierName(resultSet->getString("supplier_name"));
		data.setPaymentMethod(resultSet->getString("payment_method"));
		data.setDeliveryTime(resultSet->getString("delivery_time"));
		data.setDeliveryPlace(resultSet->getString("delivery_place"));
		data.setRemark(resultSet->getString("remark"));
		return data;
	}
};
#endif


