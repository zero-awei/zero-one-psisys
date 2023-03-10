#pragma once
#ifndef _PREPAYMENTDETAILMAPPER_H_
#define _PREPAYMENTDETAILMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/prepayment/PrepaymentDetailDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
#define MAPPER_GETDBL(funName,x) data.set##funName(resultSet->getDouble(x))
#define MAPPER_GETINT(funName,x) data.set##funName(resultSet->getUInt64(x))
#define MAPPER_GETSTR(funName,x) data.set##funName(resultSet->getString(x))

class PrepaymentDetailMapper : public Mapper<PrepaymentDetailDO>
{
public:
	PrepaymentDetailDO mapper(ResultSet* resultSet) const override
	{
		PrepaymentDetailDO data;
		MAPPER_GETSTR(Id, 1);
		MAPPER_GETSTR(Mid, 2);
		MAPPER_GETSTR(Bill_no, 3);
		MAPPER_GETINT(Entry_no, 4);
		MAPPER_GETSTR(Src_bill_type, 5);
		MAPPER_GETSTR(Src_bill_id, 6);
		MAPPER_GETSTR(Src_entry_id, 7);
		MAPPER_GETSTR(Src_no,8);
		MAPPER_GETDBL(Amt, 9);
		MAPPER_GETDBL(Paid_amt, 10);
		MAPPER_GETSTR(Remark, 11);
		MAPPER_GETSTR(Custom1, 12);
		MAPPER_GETSTR(Custom2, 13);
		MAPPER_GETINT(Version, 14);
		return data;
	}
};



#endif // _PREPAYMENTDETAILMAPPER_H_