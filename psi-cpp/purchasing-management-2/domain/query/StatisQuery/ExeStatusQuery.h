#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew
 @Date: 2023/01/14 21:30:00

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef __EXESTATUS_QUERY__
#define __EXESTATUS_QUERY__

#include "../PageQuery.h"

/**
* 采购订单执行情况Query领域模型
*/
class ExeStatusQuery : public PageQuery
{
	CC_SYNTHESIZE(std::string, column, Column); // 订单编号
	CC_SYNTHESIZE(std::string, order, Order); // 查询顺序
	CC_SYNTHESIZE(std::string, field, Field); // 查询返回参数列
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ExeStatusQuery& esq) // NOLINT
	{
		BIND_FROM_TO_ULL(j, esq, pageIndex);
		BIND_FROM_TO_ULL(j, esq, pageSize);
		BIND_FROM_TO_NORMAL(j, esq, column);
		BIND_FROM_TO_NORMAL(j, esq, order);
		BIND_FROM_TO_NORMAL(j, esq, field);
	}
};

#endif