#ifndef _BILLSTAGE_SERVICE_
#define _BILLSTAGE_SERVICE_

#include <list>
#include "../../domain/vo/publicInterfaceVO/BillStageVO.h"

/*
单据阶段下拉列表
Author C1-三木
*/

class BillStageService
{
public:
	list<BillStageVO> listAll();
};
#endif // !_BILLSTAGE_SERVICE_