#ifndef _TAXRATE_DO_
#define _TAXRATE_DO_
#include "../DoInclude.h"

/*
采购类型下拉列表
Author C1-三木
*/

class TaxRateDO
{
	// 阶段编号
	CC_SYNTHESIZE(string, id, Id);
	// 阶段名称
	CC_SYNTHESIZE(string, name, Name);
public:
	TaxRateDO() {
		id = "";
		name = "";
	}
};


#endif // !_TAXRATE_DO_