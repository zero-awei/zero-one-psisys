#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: luoluo
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
#ifndef _PUR_REQ_FIND_DETAIL_BILL_MAPPER_
#define _PUR_REQ_FIND_DETAIL_BILL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pur-req/PurReqDO.h"
#include "../../domain/do/pur-req/PurReqEntryDO.h"

class PurReqFindDetailBillMapper : public Mapper<PurReqEntryDO>
{
public:
	PurReqEntryDO mapper(ResultSet* resultSet) const override
	{
		PurReqEntryDO data;
		data.setId(resultSet->getString(1));
		data.setBill_no(resultSet->getString(2));
		data.setEntry_no(resultSet->getInt(3));
		data.setSrc_bill_type(resultSet->getString(4));
		data.setSrc_bill_id(resultSet->getString(5));
		data.setSrc_entry_id(resultSet->getString(6));
		data.setSrc_no(resultSet->getString(7));
		data.setMaterial_id(resultSet->getString(8));
		data.setUnit_id(resultSet->getString(9));
		data.setQty(resultSet->getDouble(10));
		data.setTax_rate(resultSet->getDouble(11));
		data.setPrice(resultSet->getInt(12));
		data.setAmt(resultSet->getInt(13));
		data.setSuggest_supplier_id(resultSet->getString(14));
		data.setOrdered_qty(resultSet->getDouble(15));
		data.setRemark(resultSet->getString(16));
		data.setCustom1(resultSet->getString(17));
		data.setCustom2(resultSet->getString(18));
		return data;
	}
};
#endif 
