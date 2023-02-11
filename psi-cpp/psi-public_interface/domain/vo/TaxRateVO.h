#ifndef _TAXRATE_VO_
#define _TAXRATE_VO_

#include "../GlobalInclude.h"

/*
税率
Author C1-三木
2023.2.11 18点34分
*/
class TaxRateVO
{
	// 税率编号
	CC_SYNTHESIZE(int, id, Id);
	// 税率等级
	CC_SYNTHESIZE(string, rate, Rate);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(TaxRateVO, id, rate);
};

#endif // _TAXRATE_VO_
