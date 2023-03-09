#pragma once

//@author: akun
//@time: 2023/2/26 22:50

#ifndef _PUR_ORDER_DIVIDED_LIST_MAPPER_H_
#define _PUR_ORDER_DIVIDED_LIST_MAPPER_H_
#include "Mapper.h"
#include "../../domain/do/PurOrder/PurOrderDividedListDO.h"

/**
 * 查询询价单分录列表Mapper
 */
class PurOrderDividedListMapper : public Mapper<PurOrderDividedListDO> {
public:
	PurOrderDividedListDO mapper(ResultSet* resultSet) const override
	{
		PurOrderDividedListDO data;
		data.setBillNo(resultSet->getString("bill_no"));
		data.setEntryNo(resultSet->getInt("entry_no"));
		data.setMaterialId(resultSet->getString("material_id"));
		data.setUnitId(resultSet->getString("unit_id"));
		data.setQty(resultSet->getDouble("qty"));
		data.setOrderedQty(resultSet->getDouble("ordered_qty"));
		data.setTaxRate(resultSet->getDouble("tax_rate"));
		data.setPrice(resultSet->getDouble("price"));
		data.setAmt(resultSet->getDouble("amt"));
		data.setSuggestSupplierId(resultSet->getString("suggest_supplier_id"));
		data.setRemark(resultSet->getString("remark"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setCustom2(resultSet->getString("custom2"));
		return data;
	}
};

#endif