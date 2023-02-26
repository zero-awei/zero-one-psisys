#pragma once
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/PurReq/PurReqDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PrepaymentMapper : public Mapper<PurReqDO>
{
public:
	PurReqDO mapper(ResultSet* resultSet) const override
	{
		PurReqDO data;
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