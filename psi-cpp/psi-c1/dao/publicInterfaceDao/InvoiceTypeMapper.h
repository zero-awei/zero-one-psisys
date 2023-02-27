/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：发票类型
 */

#pragma once
#ifndef _INVOICETYPE_MAPPER_
#define _INVOICETYPE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/publicInterfaceDO/InvoiceTypeDo.h"

class InvoiceTypeMapper : public Mapper<InvoiceTypeDO>
{
public:
	InvoiceTypeDO mapper(ResultSet* resultSet) const override
	{
		InvoiceTypeDO data;
		data.setId(resultSet->getInt(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

#endif // !_INVOICETYPE_MAPPER_