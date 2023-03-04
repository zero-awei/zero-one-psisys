#pragma once

#ifndef Q_C_B_D_M
#define Q_C_B_D_M

#include "Mapper.h"
#include "../../domain/vo/Cgthck/BillEntryDetailedVO.h"
class QueryCgthckBillListDetailedMapper :public Mapper<StkIoEntryDO> {
public:
	StkIoEntryDO mapper(ResultSet* resultSet) const override
	{
		StkIoEntryDO data;
		data.setSrcEntryId(resultSet->getString(1));
		data.setMaterialId(resultSet->getString(2));
		data.setBatchNo(resultSet->getString(3));
		data.setWarehouseId(resultSet->getString(4));
		data.setUnitId(resultSet->getString(5));
		data.setQty(resultSet->getDouble(6));
		data.setTaxRate(resultSet->getDouble(7));
		data.setPrice(resultSet->getDouble(8));
		data.setDiscountRate(resultSet->getDouble(9));
		data.setTax(resultSet->getDouble(10));
		data.setSettleAmt(resultSet->getDouble(11));
		data.setSettleQty(resultSet->getDouble(12));
		data.setExpense(resultSet->getDouble(13));
		data.setInvoicedAmt(resultSet->getDouble(14));
		data.setInvoicedQty(resultSet->getDouble(15));
		data.setRemark(resultSet->getString(16));
		data.setCustom1(resultSet->getString(17));
		data.setCustom2(resultSet->getString(18));

		return data;
	}


};


#endif // !Q_C_B_D_M

