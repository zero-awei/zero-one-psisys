#pragma once

#ifndef _FIN_PAYMENT_REQ_ENTRY_BILL_MAPPER_
#define _FIN_PAYMENT_REQ_ENTRY_BILL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqEntryDO.h"

class FinPaymentReqEntryBillMapper : public Mapper<FinPaymentReqEntryDO>
{
public:
	FinPaymentReqEntryDO mapper(ResultSet* resultSet) const override
	{
		FinPaymentReqEntryDO data;
		data.setId(resultSet->getString(1));
		data.setBillNo(resultSet->getString(2));
		data.setEntryNo(resultSet->getInt(3));
		data.setSrcBillType(resultSet->getString(4));
		data.setSrcBillId(resultSet->getString(5));
		data.setSrcEntryId(resultSet->getString(6));
		data.setSrcNo(resultSet->getString(7));
		data.setAmt(resultSet->getDouble(8));
		data.setPaidAmt(resultSet->getDouble(9));
		data.setRemark(resultSet->getString(10));
		data.setCustom1(resultSet->getString(11));
		data.setCustom2(resultSet->getString(12));
		return data;
	}
};
#endif //_FIN_PAYMENT_REQ_ENTRY_BILL_MAPPER_
