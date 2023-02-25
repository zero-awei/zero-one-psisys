#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: renqing
 @Date: 2023\02\18 13:27:49

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
#ifndef _ADD_PUR_COM_DO_H_
#define _ADD_PUR_COM_DO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class AddPurComDO
{
	// 数据id
	CC_SYNTHESIZE(int, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 已生效
	CC_SYNTHESIZE(string, isEffect, IsEffect);
	// 已关闭
	CC_SYNTHESIZE(string, isClose, IsClose);
	// 已作废
	CC_SYNTHESIZE(string, isCancelled, IsCancelled);
	// 生效时间
	CC_SYNTHESIZE(string, effectDate, EffectDate);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
	// 审批实例
	// 制单时间
	//CC_SYNTHESIZE(string, makeBillDate, MakeBillDate);
	// 制单部门
	CC_SYNTHESIZE(string, makeBillDept, MakeBillDept);
	// 制单人
	CC_SYNTHESIZE(string, makeBillPerson, MakeBillPerson);
	// 修改时间
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// 修改人
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);
	// 自动单据
	CC_SYNTHESIZE(string, autoBill, AutoBill);
	// 红字单据
	CC_SYNTHESIZE(string, redBill, RedBill);
	// 源单类型
	CC_SYNTHESIZE(string, billType, BillType);
	// 单据主题
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// 单据阶段
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// 采购询价单（单据编号）
	CC_SYNTHESIZE(string, inqueryBill, InqueryBill);
	// 付款方式
	CC_SYNTHESIZE(string, payMethod, PayMethod);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	AddPurComDO() {
		
	}
};

#endif // !_ADD_PUR_COM_DO_H_
