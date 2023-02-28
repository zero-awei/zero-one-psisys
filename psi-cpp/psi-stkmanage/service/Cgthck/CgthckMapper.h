#pragma once
#ifndef _CGTHCK_MAPPER_
#define _CGTHCK_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Cgthck/CgthckDO.h"
using CgthckDO = StkIoDO;
using CgthckEntryDO = StkIoEntryDO;
/**
* 采购退货出库明细字段匹配映射类
*/
class CgthckEntryMapper : public Mapper<CgthckEntryDO>
{
public:
	CgthckEntryDO mapper(ResultSet* resultSet) const override
	{
		CgthckEntryDO data;
		data.setEntryNo(resultSet->getString("entry_no"));
		data.setSrcNo(resultSet->getString("src_no"));
		data.setMaterialId(resultSet->getString("material_id"));
		data.setBatchNo(resultSet->getString("bill_no"));
		data.setWarehouseId(resultSet->getString("warehouse_id"));
		data.setUnitId(resultSet->getString("unit_id"));
		data.setSettleQty(resultSet->getDouble("settle_qty"));
		data.setTaxRate(resultSet->getDouble("tax_rate"));
		data.setPrice(resultSet->getDouble("price"));
		data.setDiscountRate(resultSet->getDouble("discount_rate"));
		data.setTax(resultSet->getDouble("tax"));
		data.setSettleAmt(resultSet->getDouble("settle_amt"));
		data.setQty(resultSet->getDouble("qty"));
		data.setCost(resultSet->getDouble("cost"));
		data.setInvoicedQty(resultSet->getDouble("invoiced_qty"));
		data.setInvoicedAmt(resultSet->getDouble("invoiced_amt"));
		data.setRemark(resultSet->getString("remark"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setCustom2(resultSet->getString("custom2"));
		return data;
	}
};

/**
* 采购退货出库字段导出匹配映射类
*/
class CgthckSheetMapper : public Mapper<CgthckDO>
{
public:
	CgthckDO mapper(ResultSet* resultSet) const override
	{
		CgthckDO data;
		// TO DO
	}
};

/**
* 采购退货出库字段明细导出匹配映射类
*/
class CgthckSheetEntryMapper : public Mapper<CgthckEntryDO>
{
public:
	CgthckEntryDO mapper(ResultSet* resultSet) const override
	{
		CgthckEntryDO data;
		// TO DO
	}
};
#endif // !_CGTHCK_MAPPER_
