#ifndef _BILLSTAGE_DAO_
#define _BILLSTAGE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/public-interface/BillStageDO.h"

class BillStageDAO : public BaseDAO
{
public:
	
	list<BillStageDO> selectBillStage();
};
#endif // !_BILLSTAGE_DAO_