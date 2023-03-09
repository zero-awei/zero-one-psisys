#ifndef _BILLSTAGE_DO_
#define _BILLSTAGE_DO_
#include "../DoInclude.h"

/*
单据阶段下拉列表
Author C1-三木
*/

class BillStageDO
{
	// 阶段编号
	CC_SYNTHESIZE(string, id, Id);
	// 阶段名称
	CC_SYNTHESIZE(string, name, Name);
public:
	BillStageDO() {
		id = "";
		name = "";
	}
};


#endif // !_BILLSTAGE_DO_
