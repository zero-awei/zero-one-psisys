#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/22 11:47:59

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
#ifndef _PUR_COM_DIVIDED_LIST_MAPPER_
#define _PUR_COM_DIVIDED_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pur-compare/PurComQuotEntryDO.h"

/**
 * 报价单分录列表字段匹配映射
 */
class PurComDividedListMapper : public Mapper<PurComQuotEntryDO>
{
public:
	PurComQuotEntryDO mapper(ResultSet* resultSet) const override
	{
		PurComQuotEntryDO data;
		data.setBillNo(resultSet->getString("bill_no"));
		data.setEntryNo(resultSet->getString("entry_no"));
		data.setMaterialName(resultSet->getString("material_name"));
		data.setSpecifications(resultSet->getString("specifications"));
		data.setUnitName(resultSet->getString("unit_name"));
		//data.setQty(resultSet->getDouble("qty"));
		data.setQty(resultSet->getString("qty"));
		data.setTaxRate(resultSet->getString("tax_rate"));
		data.setPrice(resultSet->getString("price"));
		data.setDiscountRate(resultSet->getString("discount_rate"));
		data.setAmt(resultSet->getString("amt"));
		data.setRemark(resultSet->getString("remark"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setCustom2(resultSet->getString("custom2"));
		return data;
	}
};

#endif

