#pragma once
#ifndef _PAYMENT_MAPPER_
#define _PAYMENT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/FinPayReq/FinPayReqDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PrepaymentMapper : public Mapper<FinPayReqDO>
{
public:
	FinPayReqDO mapper(ResultSet* resultSet) const override
	{
		FinPayReqDO data;
		data.setId(resultSet->getString(1));
		data.setBill_no(resultSet->getString(2));
		data.setBill_date(resultSet->getString(3));
		data.setSubject(resultSet->getString(4));
		data.setIs_closed(resultSet->getInt(5));
		data.setIs_voided(resultSet->getInt(6));
		data.setSrc_bill_id(resultSet->getString(7));
		data.setAmt(resultSet->getInt(8));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_