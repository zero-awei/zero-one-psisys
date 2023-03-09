#pragma once

#ifndef _ISENABLEDVO_H_
#define _ISENABLEDVO_H_
#include "../../GlobalInclude.h"

/*
* 是否启用选项
* @Author: Oxygen
* @Date: 2023/2/13 20:24:33
*/
class IsEnabledVO
{
	// 类型编号
	CC_SYNTHESIZE(int, id, Id);
	// 类型名称
	CC_SYNTHESIZE(string, name, Name);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(IsEnabledVO, id, name);
};

#endif // _ISENABLED_H_
