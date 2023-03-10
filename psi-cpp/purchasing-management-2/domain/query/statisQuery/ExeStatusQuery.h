#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew
 @Date: 2023/02/18 10:00:00

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
* 采购统计QUERY模型
*/
class BaseQuery : public PageQuery
{
	CC_SYNTHESIZE(string, column, Column); // 订单编号
	CC_SYNTHESIZE(string, order, Order); // 查询顺序
	CC_SYNTHESIZE(string, field, Field); // 查询返回参数列
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, BaseQuery& bq) // NOLINT
	{
		BIND_FROM_TO_ULL(j, bq, pageIndex);
		BIND_FROM_TO_ULL(j, bq, pageSize);
		BIND_FROM_TO_NORMAL(j, bq, column);
		BIND_FROM_TO_NORMAL(j, bq, order);
		BIND_FROM_TO_NORMAL(j, bq, field);
	}
};

/**
* 采购订单执行情况Query领域模型
*/
class ExeStatusQuery : public BaseQuery
{
	// 筛选条件
	CC_SYNTHESIZE(string, dept, Dept); // 业务部门ID
	CC_SYNTHESIZE(string, opName, OpName); // 业务员名
	CC_SYNTHESIZE(uint64_t, supplier, Supplier); // 供应商ID
	CC_SYNTHESIZE(string, billNo, BillNo); // 单据编号
	CC_SYNTHESIZE(bool, exeEnd, ExeEnd); // 执行结束
	CC_SYNTHESIZE(string, beginDate, BeginDate); // 单据日期开始
	CC_SYNTHESIZE(string, endDate, EndDate); // 单据日期结束
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ExeStatusQuery& esq) // NOLINT
	{
		from_json(j, static_cast<BaseQuery&>(esq));
		BIND_FROM_TO_ULL(j, esq, supplier);
		BIND_FROM_TO_B(j, esq, exeEnd);
		BIND_FROM_TO_NORMAL(j, esq, dept);
		BIND_FROM_TO_NORMAL(j, esq, opName);
		BIND_FROM_TO_NORMAL(j, esq, billNo);
		BIND_FROM_TO_NORMAL(j, esq, beginDate);
		BIND_FROM_TO_NORMAL(j, esq, endDate);
	}
};

#endif