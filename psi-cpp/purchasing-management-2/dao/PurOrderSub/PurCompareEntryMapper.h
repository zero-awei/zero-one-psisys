#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/26 14:21:55

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
#ifndef _PUR_COMPARE_ENTRY_MAPPER_
#define _PUR_COMPARE_ENTRY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/PurCom/PurComEntryDO.h"

/**
 * ≤…π∫∂©µ•entry±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class PurCompareEntryMapper : public Mapper<PurComEntryDO>
{
public:
	PurComEntryDO mapper(ResultSet* resultSet) const override
	{
		PurComEntryDO data;
		data.setId(resultSet->getString(1));
		data.setMid(resultSet->getString(2));
		data.setBill_no(resultSet->getString(3));
		data.setEntry_no(resultSet->getInt(4));
		data.setSrc_bill_type(resultSet->getString(5));
		data.setSrc_bill_id(resultSet->getString(6));
		data.setSrc_entry_id(resultSet->getString(7));
		data.setSrc_no(resultSet->getString(8));
		data.setSupplier_id(resultSet->getString(9));
		data.setMaterial_id(resultSet->getString(10));
		data.setUnit_id(resultSet->getString(11));
		data.setQty(resultSet->getDouble(12));
		data.setTax_rate(resultSet->getDouble(13));
		data.setPrice(resultSet->getDouble(14));
		data.setDiscount_rate(resultSet->getDouble(15));
		data.setAmt(resultSet->getDouble(16));
		data.setRanking(resultSet->getInt(17));
		data.setRemark(resultSet->getString(18));
		data.setCustom1(resultSet->getString(19));
		data.setCustom2(resultSet->getString(20));
		data.setVersion(resultSet->getInt(21));
		return data;
	}
};

#endif //_PUR_COMPARE_ENTRY_MAPPER_