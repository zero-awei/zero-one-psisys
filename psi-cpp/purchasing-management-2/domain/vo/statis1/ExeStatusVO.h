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
#ifndef __EXESTATUS_VO__
#define __EXESTATUS_VO__

#include "../../GlobalInclude.h"
#include "../lib-common/include/CharsetConvertHepler.h"

/**
* 采购订单执行情况VO领域模型
*/
class ExeStatusVO
{
	CC_SYNTHESIZE(uint64_t, id, Id); // ID
	CC_SYNTHESIZE(uint16_t, quantity, Quantity); // 采购数量
	CC_SYNTHESIZE(double, price, Price); // 采购金额
	CC_SYNTHESIZE(double, incost, Incost); // 入库金额
	CC_SYNTHESIZE(uint16_t, inQty, InQty); // 入库数量
	CC_SYNTHESIZE(uint16_t, settleQty, SettleQty); // 结算数量
	CC_SYNTHESIZE(double, settlePrice, SettlePrice); // 结算金额
	CC_SYNTHESIZE(double, settledPrice, SettledPrice); // 已结算金额
	CC_SYNTHESIZE(double, invoiced, Invoiced); // 已开票金额
	CC_SYNTHESIZE(uint64_t, supplier, Supplier); // 供应商ID
	CC_SYNTHESIZE(string, supName, SupName); // 供应商名
	CC_SYNTHESIZE(string, dept, Dept); // 业务部门ID
	CC_SYNTHESIZE(string, deptName, DeptName); // 业务部门名
	CC_SYNTHESIZE(uint64_t, op, Op); // 业务员ID
	CC_SYNTHESIZE(string, opName, OpName); // 业务员名
	CC_SYNTHESIZE(string, billNo, BillNo); // 单据编号
	CC_SYNTHESIZE(string, billDate, BillDate); // 单据日期
	CC_SYNTHESIZE(bool, exeEnd, ExeEnd); // 执行结束
	CC_SYNTHESIZE(string, exeEndText, ExeEndText); // 执行结束文字
public:
	ExeStatusVO() : id(155149), quantity(2), price(996.00), incost(666.00), inQty(10), settlePrice(6.66), settledPrice(2.33), invoiced(4.55), supplier(114514), supName("Test"), dept("testDept"), deptName("department"), op(123456), opName("NO.1"), billNo("Bill-111000"), billDate("2023-02-14"), exeEnd(true), exeEndText(CharsetConvertHepler::ansiToUtf8("是")) {}
	// 绑定JSON转换方法
	BIND_TO_JSON(ExeStatusVO, id, quantity, price, incost, inQty, settlePrice, settledPrice, settleQty, invoiced, supplier, supName, dept, deptName, op, opName, billNo, billDate, exeEnd, exeEndText);
};

#endif