#pragma once

#ifndef _PUR_PAY_REQ_ENTRY_MAPPER_
#define _PUR_PAY_REQ_ENTRY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqEntryManageDO.h"

/**
 * ʾ�������ֶ�ƥ��ӳ��
 */
class FinPaymentReqEntryMapper : public Mapper<FinPaymentReqEntryManageDO>
{
public:
	FinPaymentReqEntryManageDO mapper(ResultSet* resultSet) const override
	{
		int i = 1;
		FinPaymentReqEntryManageDO data;
		data.setId(resultSet->getString(i++));
		data.setMid(resultSet->getString(i++));
		data.setBillNo(resultSet->getString(i++));
		data.setEntryNo(resultSet->getInt(i++));
		data.setSrcBillType(resultSet->getString(i++));
		data.setSrcBillId(resultSet->getString(i++));
		data.setSrcEntryId(resultSet->getString(i++));
		data.setSrcNo(resultSet->getString(i++));
		data.setAmt(resultSet->getDouble(i++));
		data.setPaidAmt(resultSet->getDouble(i++));
		data.setRemark(resultSet->getString(i++));
		data.setCustom1(resultSet->getString(i++));
		data.setCustom2(resultSet->getString(i++));
		data.setVersion(resultSet->getInt(i++));

		return data;
	}
};

#endif // _PUR_PAY_REQ_ENTRY_MAPPER_
