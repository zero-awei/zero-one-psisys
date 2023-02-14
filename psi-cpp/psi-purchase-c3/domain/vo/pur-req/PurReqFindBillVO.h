#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 10:50:01

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
#ifndef _PUR_RER_FIND_BILL_VO_
#define _PUR_RER_FIND_BILL_VO_

#include "../../GlobalInclude.h"

/*
查询单据列表显示对象
*/
//备注:类的宏里面的字段类型需要更改
class PurReqFindBillVO {
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 源单号
	CC_SYNTHESIZE(string, src_no, Src_no);
	// 采购类型
	CC_SYNTHESIZE(string, pur_type, Pur_type);
	// 需求部门
	CC_SYNTHESIZE(string, request_dept, Request_dept);
	// 需求人
	CC_SYNTHESIZE(string, requester, Requester);
	// 需求日期
	CC_SYNTHESIZE(string, request_time, Request_time);
	// 数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 已定数量
	CC_SYNTHESIZE(double, ordered_qty, Ordered_qty);
	// 参考金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//已生效			
	CC_SYNTHESIZE(int, is_effective, Is_effective);
		//已关闭			
		CC_SYNTHESIZE(int, is_closed, Is_closed);
	//已作废			
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自动单据
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// 红字单据
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	// 生效时间
	CC_SYNTHESIZE(int, effective_time, Effective_time);
	// 核批人
	CC_SYNTHESIZE(string, approver, approver);
	// 制单时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 制单人
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 制单部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// 修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	// 修改人
	CC_SYNTHESIZE(string, update_by, Update_by);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurReqFindBillVO, bill_no, bill_date, subject, src_no, pur_type,
		request_dept, requester, request_time, qty, ordered_qty, amt, bill_stage,
		is_effective, is_closed, is_voided, remark, is_auto, is_rubric, effective_time,
		approver, create_time, create_by, sys_org_code, update_time, update_by);
};
#endif // !

