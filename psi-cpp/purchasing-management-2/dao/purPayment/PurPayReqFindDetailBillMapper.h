#pragma once

#ifndef _PUR_PAY_REQ_FIND_DETAIL_BILL_MAPPER_
#define _PUR_PAY_REQ_FIND_DETAIL_BILL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/FinPaymentReq/FinPaymentEntryReqDO.h"

class PurPayReqFindDetailBillMapper : public Mapper<FinPaymentEntryReqDO>
{
public:
	FinPaymentEntryReqDO mapper(ResultSet* resultSet) const override
	{
		FinPaymentEntryReqDO data;
		data.setId(resultSet->getString(1));
		data.setBillNo(resultSet->getString(2));
		data.setEntryNo(resultSet->getInt(3));
		data.setSrcBillType(resultSet->getString(4));
		data.setSrcBillId(resultSet->getString(5));
		data.setSrcEntryId(resultSet->getString(6));
		data.setSrcNo(resultSet->getString(7));
		data.setAmt(resultSet->getDouble(13));
		data.setPaidAmt(resultSet->getDouble(15));
		data.setRemark(resultSet->getString(16));
		data.setCustom1(resultSet->getString(17));
		data.setCustom2(resultSet->getString(18));
		return data;
	}
};
#endif //_PUR_PAY_REQ_FIND_DETAIL_BILL_MAPPER_
