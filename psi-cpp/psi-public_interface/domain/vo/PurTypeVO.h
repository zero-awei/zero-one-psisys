#ifndef _PURTYPE_VO_
#define _PURTYPE_VO_

#include "../GlobalInclude.h"

/*
采购类型
Author C1-三木
2023.2.11 18点40分
*/
class PurTypeVO
{
	// 类型编号
	CC_SYNTHESIZE(int, id, Id);
	// 类型名称
	CC_SYNTHESIZE(string, name, Name);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurTypeVO, id, name);
};

#endif // _PurTYPE_VO_
