#ifndef _SUPPLIERLEVEL_DO_
#define _SUPPLIERLEVEL_DO_
#include "../DoInclude.h"

/*
单据阶段下拉列表
Author C1-三木
*/

class SupplierLevelDO
{
	// 阶段编号
	CC_SYNTHESIZE(int, id, Id);
	// 阶段名称
	CC_SYNTHESIZE(string, name, Name);
public:
	SupplierLevelDO() {
		id = 0;
		name = "";
	}
};


#endif // !_SUPPLIERLEVEL_DO_