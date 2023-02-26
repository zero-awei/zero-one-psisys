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
#ifndef _ADD_PAYMENT_DTO_
#define _ADD_PAYMENT_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

class AddPaymentDTO :public FileDTO
{
	//编号id
	CC_SYNTHESIZE(string,	id, Id);
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//源单id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//源单号
	CC_SYNTHESIZE(string, src_no, Src_no);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//业务部门
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	//业务员
	CC_SYNTHESIZE(string, operator1, Operator);
	//付款类型
	CC_SYNTHESIZE(string, payment_type, Payment_type);
	//申请金额
	CC_SYNTHESIZE(int, amt, Amt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//是否自动生成
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//是否已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//是否作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
public:
	//绑定JSON转换方法
	friend void from_json(const json& j, AddPaymentDTO& apt);
};

#endif
