#pragma once

#ifndef Q_C_B_D_M
#define Q_C_B_D_M

#include "Mapper.h"
#include "../../domain/vo/Cgthck/BillEntryDetailedVO.h"
class QueryCgthckBillListDetailedMapper :public Mapper<BillEntryDetailedVO> {
public:
	BillEntryDetailedVO mapper(ResultSet* resultSet) const override
	{
		BillEntryDetailedVO data;
		data.setSrcNo(resultSet->getString(1));
		data.setMaterialId(resultSet->getString(2));
		data.setSize(resultSet->getString(3));
		data.setWarehouseId(resultSet->getString(4));
		data.setUnit(resultSet->getString(5));

		data.setSettleQty(resultSet->getDouble(6));
		data.setTaxRate(resultSet->getDouble(7));
		data.setPrice(resultSet->getDouble(8));
		data.setDiscountRate(resultSet->getDouble(9));
		data.setTax(resultSet->getDouble(10));
		data.setSettleAmt(resultSet->getDouble(11));

		data.setInNum(resultSet->getInt(12));

		data.setBuyCost(resultSet->getDouble(13));
		data.setInMoney(resultSet->getDouble(14));
		data.setInvoicedQty(resultSet->getDouble(15));
		data.setInvoicedAmt(resultSet->getDouble(16));

		data.setRemarks(resultSet->getString(17));
		data.setCustom1(resultSet->getString(18));
		data.setCustom2(resultSet->getString(19));


		return data;
	}


};


#endif // !Q_C_B_D_M

