#pragma once
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/PurQuot/PurQuotDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PurQuotMapper : public Mapper<PurQuotDO>
{
public:
	PurQuotDO mapper(ResultSet* resultSet) const override
	{
		PurQuotDO data;
		data.setId(resultSet->getString(1));
		data.setBill_no(resultSet->getString(2));
		data.setBill_date(resultSet->getString(3));
		data.setSubject(resultSet->getString(4));
		data.setSupplier_id(resultSet->getString(5));
		/*data.setOp_dept(resultSet->getString(6));
		data.setOperator(resultSet->getString(7));
		data.setAmt(resultSet->getInt(8));*/
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_