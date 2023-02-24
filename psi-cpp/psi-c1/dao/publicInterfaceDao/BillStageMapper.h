#ifndef _BILLSTAGE_MAPPER_
#define _BILLSTAGE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/publicInterfaceDO/BillStageDO.h"


class BillStageMapper : public Mapper<BillStageDO>
{
public:
	BillStageDO mapper(ResultSet* resultSet) const override
	{
		BillStageDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(3));
		return data;
	}
};

#endif // !_BILLSTAGE_MAPPER_