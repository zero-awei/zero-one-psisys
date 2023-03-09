#pragma once

#ifndef _SYSUSERVO_H_
#define _SYSUSERVO_H_
#include "../../GlobalInclude.h"

/*
* 账户管理员选项
* @Author: Oxygen
* @Date: 2023/2/12 18:59:32
*/
class SysUserVO
{
	// 类型编号
	CC_SYNTHESIZE(int, id, Id);
	// 类型名称
	CC_SYNTHESIZE(string, name, Name);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(SysUserVO, id, name);
};

#endif // _SYSUSERVO_H_