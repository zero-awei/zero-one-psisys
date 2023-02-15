#ifndef _SUPPLIERLEVEL_VO_
#define _SUPPLIERLEVEL_VO_

#include "../../GlobalInclude.h"

/*
供应商等级下拉列表
Author C1-三木
2023.2.11 21点00分
*/
class SupplierLevelVO
{
	// 等级编号
	CC_SYNTHESIZE(int, id, Id);
	// 等级名称
	CC_SYNTHESIZE(string, name, Name);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(SupplierLevelVO, id, name);
};

#endif // _SUPPLIERLEVEL_VO_

