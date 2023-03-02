#pragma once
#ifndef _PUR_QUOT_ENTRY_MAPPER_H_
#define _PUR_QUOT_ENTRY_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotEntryDO.h"

//µ¼³öµÄMapper
class PurQuotEntryMapper : public Mapper<PurQuotEntryDO> {
public:
	PurQuotEntryDO mapper(ResultSet* resultSet) const override {
		PurQuotEntryDO data;
		data.setBill_no(resultSet->getString("bill_no"));
		data.setMaterial_id(resultSet->getString("material_id"));
		data.setUnit_id(resultSet->getString("unit_id"));
		data.setQty(resultSet->getDouble("qty"));
		data.setTax_rate(resultSet->getDouble("tax_rate"));
		data.setPrice(resultSet->getDouble("price"));
		data.setDiscount_rate(resultSet->getDouble("discount_rate"));
		data.setAmt(resultSet->getDouble("amt"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setSrc_no(resultSet->getString("src_no"));
		data.setEntry_no(resultSet->getInt("entry_no"));
		data.setCustom2(resultSet->getString("custom2"));
		data.setSrc_entry_id(resultSet->getString("src_entry_id"));
		data.setSrc_bill_type(resultSet->getString("src_bill_type"));
		data.setRemark(resultSet->getString("remark"));
		data.setSrc_bill_id(resultSet->getString("src_bill_id"));
		return data;
	}
};
#endif
