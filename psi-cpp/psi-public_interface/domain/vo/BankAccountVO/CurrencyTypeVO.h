#pragma once

#ifndef _CURRENCYTYPEVO_H_
#define _CURRENCYTYPEVO_H_
#include "../../GlobalInclude.h"

/*
* 币种选项
* @Author: Oxygen
* @Date: 2023/2/12 15:05:25
*/
class CurrencyTypeVO
{
	// 类型编号
	CC_SYNTHESIZE(int, id, Id);
	// 类型名称
	CC_SYNTHESIZE(string, name, Name);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(CurrencyTypeVO, id, name);
};

#endif // _CURRENCYTYPEVO_H_