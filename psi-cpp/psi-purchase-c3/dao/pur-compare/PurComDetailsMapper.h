#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/21 10:13:28

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
#ifndef _PUR_COM_DETAILS_MAPPER_
#define _PUR_COM_DETAILS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pur-compare/PurCompareEntryDO.h"

//#define ITOWORD(t) (t==1 ? u8"是":u8"否")
/**
 * 比价单明细表字段匹配映射
 */
class PurComDetailsMapper : public Mapper<PurCompareEntryDO>
{
public:
	PurCompareEntryDO mapper(ResultSet* resultSet) const override
	{
		PurCompareEntryDO data;
		data.setEntryNo(resultSet->getInt("entry_no"));
		//data.setSupplierId(resultSet->getString("supplier_id"));
		data.setSupplierName(resultSet->getString("supplier_name"));
		data.setSrcNo(resultSet->getString("src_no"));
		//data.setMaterialId(resultSet->getString("material_id"));
		data.setMaterialName(resultSet->getString("material_name"));
		data.setSpecifications(resultSet->getString("specifications"));
		//data.setUnitId(resultSet->getString("unit_id"));
		data.setUnitName(resultSet->getString("unit_name"));
		data.setQty(resultSet->getDouble("qty"));
		data.setTaxRate(resultSet->getDouble("tax_rate"));
		data.setPrice(resultSet->getDouble("price"));
		data.setDiscountRate(resultSet->getDouble("discount_rate"));
		data.setAmt(resultSet->getDouble("amt"));
		data.setRanking(resultSet->getInt("ranking"));
		data.setRemark(resultSet->getString("remark"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setCustom2(resultSet->getString("custom2"));
		return data;
	}
};
#endif

