/*
 Copyright Zero One Star. All rights reserved.

 @Author: renqing
 @Date: 2023/2/15 16:58:10

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
#pragma once
#ifndef _PUR_COMPARE_DTO_
#define _PUR_COMPARE_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//新增比价
class AddPurComDTO : public FileDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 已生效
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// 已关闭
	CC_SYNTHESIZE(int, isClose, Isclose);
	// 已作废
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);
	// 生效时间
	CC_SYNTHESIZE(string, effectDate, EffectDate);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
	// 审批实例
	// 制单时间
	CC_SYNTHESIZE(string, makeBillDate, MakeBillDate);
	// 制单部门
	CC_SYNTHESIZE(string, makeBillDept, MakeBillDept);
	// 制单人
	CC_SYNTHESIZE(string, makeBillPerson, MakeBillPerson);
	// 修改时间
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// 修改人
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);
	// 自动单据
	CC_SYNTHESIZE(int, autoBill, AutoBill);
	// 红字单据
	CC_SYNTHESIZE(int, redBill, RedBill);
	// 源单类型
	CC_SYNTHESIZE(string, billType, BillType);
	// 单据主题
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// 单据阶段
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// 采购询价单（单据编号）
	CC_SYNTHESIZE(string, inquiryBill, InquiryBill);
	// 付款方式
	CC_SYNTHESIZE(string, payMethod, PayMethod);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddPurComDTO& t);// NOLINT	
};

// 修改比价
class ModPurComDTO : public FileDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 已生效
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// 已关闭
	CC_SYNTHESIZE(int, isClose, Isclose);
	// 已作废
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);
	// 生效时间
	CC_SYNTHESIZE(string, effectDate, EffectDate);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
	// 审批实例
	// 制单时间
	CC_SYNTHESIZE(string, makeBillDate, MakeBillDate);
	// 制单部门
	CC_SYNTHESIZE(string, makeBillDept, MakeBillDept);
	// 制单人
	CC_SYNTHESIZE(string, makeBillPerson, MakeBillPerson);
	// 修改时间
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// 修改人
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);
	// 自动单据
	CC_SYNTHESIZE(int, autoBill, AutoBill);
	// 红字单据
	CC_SYNTHESIZE(int, redBill, RedBill);
	// 源单类型
	CC_SYNTHESIZE(string, billType, BillType);
	// 单据主题
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// 单据阶段
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// 采购询价单（单据编号）
	CC_SYNTHESIZE(string, inquiryBill, InquiryBill);
	// 付款方式
	CC_SYNTHESIZE(string, payMethod, PayMethod);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ModPurComDTO& t);// NOLINT	
};

// 删除比价，前端传递单据编号，后端进行删除
class DelPurComDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, DelPurComDTO& t);// NOLINT	
};

// 修改单据的状态，前端传递编号以及变化的状态
class PurComModBillStatusDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
	// 已生效
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// 已关闭
	CC_SYNTHESIZE(int, isClose, Isclose);
	// 已作废
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurComModBillStatusDTO& t);// NOLINT	
};
#endif // !_PUR_COMPARE_DTO_