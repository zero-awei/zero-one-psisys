#ifndef _BILLSTAGE_CONTROLLER_
#define _BILLSTAGE_CONTROLLER_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/public-interface/BillStageVO.h"

/*
单据阶段下拉列表
Author C1-三木
2023.2.11 20点45分
*/
class BillStageController
{
public:
	CREATE_API_FUN_QUERY3(queryBillStage, executequeryBillStage);
private:
	JsonVO<list<BillStageVO>> executequeryBillStage();
};

#endif //_BILLSTAGE_CONTROLLER_