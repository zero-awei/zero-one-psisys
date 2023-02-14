#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef __STATIS_VO__
#define __STATIS_VO__

#include "../../GlobalInclude.h"

/**
* 采购订单执行情况VO领域模型
*/
class StatisVO
{
	CC_SYNTHESIZE(uint64_t, id, Id); // ID
	CC_SYNTHESIZE(int, quantity, Quantity); // 采购数量
	CC_SYNTHESIZE(double, price, Price); // 采购金额
	CC_SYNTHESIZE(double, inPost, InCost); // 入库金额
	CC_SYNTHESIZE(int, inQty, InQty); // 入库数量
	CC_SYNTHESIZE(double, settlePrice, SettlePrice); // 结算金额
	CC_SYNTHESIZE(int, settleQty, SettleQty); // 结算数量
	CC_SYNTHESIZE(uint64_t, supplier, Supplier); // 供应商ID
	CC_SYNTHESIZE(std::string, supName, SupName); // 供应商ID
	CC_SYNTHESIZE(uint64_t, dept, Dept); // 业务部门ID
	CC_SYNTHESIZE(std::string, deptName, DeptName); // 业务部门名
	CC_SYNTHESIZE(uint64_t, op, Op); // 业务员ID
	CC_SYNTHESIZE(std::string, opName, OpName); // 业务员名
	CC_SYNTHESIZE(std::string, billNo, BillNo); // 单据编号
	CC_SYNTHESIZE(std::string, billDate, BillDate); // 单据日期
	CC_SYNTHESIZE(bool, exeEnd, ExeEnd); // 执行结束
	CC_SYNTHESIZE(std::string, exeEndText, ExeEndText); // 执行结束文字
	CC_SYNTHESIZE(double, invoidced, Invoidced); // 已结算金额
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(StatisVO, id, quantity, price, inPost, inQty, settlePrice, settleQty, supplier, supName, dept, deptName, op, opName, billNo, billDate, exeEnd, exeEndText, invoidced);
};

#endif