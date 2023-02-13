#ifndef _TAXSCALE_VO_
#define _TAXSCALE_VO_

#include "../GlobalInclude.h"

/*
纳税规模
Author C1-三木
2023.2.11 18点36分
*/
class TaxScaleVO
{
	// 模式编号
	CC_SYNTHESIZE(int, id, Id);
	// 模式名称
	CC_SYNTHESIZE(string, name, Name);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(TaxScaleVO, id, name);
};

#endif // _TAXSCALE_VO_
