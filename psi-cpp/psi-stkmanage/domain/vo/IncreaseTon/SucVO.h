#pragma once
#ifndef _SUC_VO_
#define _SUC_VO_

#include "../../GlobalInclude.h"

/**
 * 执行是否成功显示对象
 */
class SucVO
{
	// 执行是否成功
	CC_SYNTHESIZE(uint64_t, suc, Suc);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(SucVO, suc);
};

#endif