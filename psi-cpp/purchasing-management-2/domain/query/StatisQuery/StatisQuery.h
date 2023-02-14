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
#ifndef __STATIS_QUERY__
#define __STATIS_QUERY__

#include "../PageQuery.h"

/**
* 采购订单汇总Query领域模型
*/
class StatisQuery : public ExeStatusQuery
{
	CC_SYNTHESIZE(int, year, Year); // 年份
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, StatisQuery& sq)
	{
		from_json(j, static_cast<ExeStatusQuery&>(sq));
		BIND_FROM_TO_I(j, sq, year);
	}
};

/**
* 采购订单汇总-部门/业务员/供应商/物料Query领域模型
*/
class ByQuery : public StatisQuery
{
	CC_SYNTHESIZE(int, month, Month); // 月份
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ByQuery& bq)
	{
		from_json(j, static_cast<StatisQuery&>(bq));
		BIND_FROM_TO_I(j, bq, month);
	}
};

#endif