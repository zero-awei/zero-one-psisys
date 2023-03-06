#ifndef _PURTYPE_DO_
#define _PURTYPE_DO_
#include "../DoInclude.h"

/*
采购类型下拉列表
Author C1-三木
*/

class PurTypeDO
{
	// 阶段编号
	CC_SYNTHESIZE(string, id, Id);
	// 阶段名称
	CC_SYNTHESIZE(string, name, Name);
public:
	PurTypeDO() {
		id = "";
		name = "";
	}
};


#endif // !_PURTYPE_DO_
