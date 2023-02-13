#pragma once
#ifndef _PUR_REQ_VO_
#define _PUR_REQ_VO_

#include "../../GlobalInclude.h"

/**
 * 显示采购订单信息
 */
class PurReqVO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurReqVO, id, name, age, sex);
};

#endif // !_PUR_REQ_VO_