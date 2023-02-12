#pragma once

#ifndef _USERVO_H_
#define _USERVO_H_

#include "../../GlobalInclude.h"

/**
 * 定义一个修改用户信息结果显示对象
 */
class UserVO
{
	//// 昵称
	//CC_SYNTHESIZE(std::string, nickname, Nickname);
	//// 年龄
	//CC_SYNTHESIZE(int, age, Age);
	//// 身份证号
	//CC_SYNTHESIZE(std::string, idCard, IdCard);
public:
	// 绑定JSON转换方法
	//BIND_TO_JSON(UserVO, nickname, age, idCard);
};

#endif // _USERVO_H_