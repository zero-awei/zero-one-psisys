#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: Papillon
 @Date: 2023/02/16 22:00:00
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
#ifndef _PAYMENT_BILL_VO_
#define _PAYMENT_BILL_VO_

#include "../../GlobalInclude.h"

/*
查询单据列表
*/
class PaymentBillVO {
	// 单据编号
	CC_SYNTHESIZE(string, billNo, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, Bill_date);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplierId, Supplier_id)
	// 业务部门
	CC_SYNTHESIZE(string, opDept, Op_dept)
	// 业务员
	CC_SYNTHESIZE(string, operator_,Operator)
	// 源单号
	CC_SYNTHESIZE(string,srcNo,SrcNo)
	// 申请金额
	CC_SYNTHESIZE(double, amt, Amt)
	// 已付金额
	CC_SYNTHESIZE(double, paidAmt, PaidAmt)
	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//已生效			
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//已关闭			
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废			
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// 自动单据
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	// 红字单据
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 生效时间
	CC_SYNTHESIZE(int, effectiveTime, EffectiveTime);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
	// 制单时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 制单人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 制单部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// 修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PaymentBillVO, billNo, billDate, subject, supplierId, opDept,
		operator_, srcNo, amt, paidAmt, billStage, isEffective, isClosed, isVoided,
		isAuto, isRubric, remark, effectiveTime,
		approver, createTime, createBy, sysOrgCode, updateTime, updateBy);
};

#endif