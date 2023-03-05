#ifndef _SETTLEMETHOD_VO_
#define _SETTLEMETHOD_VO_

#include "../../GlobalInclude.h"

/**
 *Author c1-ruizi
 * 2023/2/13  15:46
 * 接口：结算方式
 */

class SettleMethodVO
{
	// 方式编号
	CC_SYNTHESIZE(string, id, Id);
	// 方式名称
	CC_SYNTHESIZE(string, name, Name);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(SettleMethodVO, id, name);
};

#endif //_SETTLEMETHOD_VO_