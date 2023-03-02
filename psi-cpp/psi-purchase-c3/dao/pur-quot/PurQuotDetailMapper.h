#pragma once
#ifndef _PUR_QUOT_FIND_DETAIL_BILL_MAPPER_H_
#define _PUR_QUOT_FIND_DETAIL_BILL_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotDO.h"
#include "../../domain/do/pur-quot/PurQuotEntryDO.h"

/**
 * 示例表字段匹配映射
 */
class PurQuotDetailMapper : public Mapper<PurQuotEntryDO>
{
public:
	PurQuotEntryDO mapper(ResultSet* resultSet) const override
	{
		PurQuotEntryDO data;
		data.setSrc_no(resultSet->getString("src_no"));
		data.setMaterial_id(resultSet->getString("material_id"));
		data.setUnit_id(resultSet->getString("unit_id"));
		data.setQty(resultSet->getDouble("qty"));
		data.setTax_rate(resultSet->getDouble("tax_rate"));
		data.setPrice(resultSet->getDouble("price"));
		data.setDiscount_rate(resultSet->getDouble("discount_rate"));
		data.setAmt(resultSet->getDouble("amt"));
		data.setRemark(resultSet->getString("remark"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setCustom2(resultSet->getString("custom2"));
//明细字段
		return data;
	}
};

#endif


