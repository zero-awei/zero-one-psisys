#ifndef _TAXSCALE_DO_
#define _TAXSCALE_DO_
#include "../DoInclude.h"

/*
纳税规模下拉列表
Author C1-三木
*/

class TaxScaleDO
{
	// 阶段编号
	CC_SYNTHESIZE(string, id, Id);
	// 阶段名称
	CC_SYNTHESIZE(string, name, Name);
public:
	TaxScaleDO() {
		id = "";
		name = "";
	}
};


#endif // !_TAXSCALE_DO_