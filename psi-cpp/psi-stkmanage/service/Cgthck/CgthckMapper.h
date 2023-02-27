#pragma once
#ifndef _CGTHCK_MAPPER_
#define _CGTHCK_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Cgthck/CgthckDO.h"
using CgthckDO = StkIoDO;
using CgthckEntryDO = StkIoEntryDO;
/**
* 采购退货出库字段匹配映射类
*/
class CgthckMapper : public Mapper<CgthckEntryDO>
{
public:
	CgthckEntryDO mapper(ResultSet* resultSet) const override
	{
		CgthckEntryDO data;
		data.setEntryNo(resultSet->getString(1));
		data.setSrcNo(resultSet->getString(2));
		data.setMaterialId(resultSet->getString(3));
		data.setBatchNo(resultSet->getString(4));
		data.setWarehouseId(resultSet->getString(5));
		data.setUnitId(resultSet->getString(6));
		data.setSettleQty(resultSet->getDouble(7));
		data.setTaxRate(resultSet->getDouble(8));
		data.setPrice(resultSet->getDouble(9));
		data.setDiscountRate(resultSet->getDouble(10));
		data.setTax(resultSet->getDouble(11));
		data.setSettleAmt(resultSet->getDouble(12));
		data.setQty(resultSet->getDouble(13));
		data.setCost(resultSet->getDouble(14));
		data.setInvoicedQty(resultSet->getDouble(15));
		data.setInvoicedAmt(resultSet->getDouble(16));
		data.setRemark(resultSet->getString(17));
		data.setCustom1(resultSet->getString(18));
		data.setCustom2(resultSet->getString(19));
		return data;
	}
};
#endif // !_CGTHCK_MAPPER_
