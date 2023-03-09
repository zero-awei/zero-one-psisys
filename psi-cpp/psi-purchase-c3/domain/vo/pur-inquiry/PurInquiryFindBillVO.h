#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/15 14:42

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
#ifndef _PUR_INQUIRY_FIND_BILL_VO_H_
#define _PUR_INQUIRY_FIND_BILL_VO_H_

#include "../../GlobalInclude.h"

/**
 * 显示对象 —— 采购询价单列表
 */

//采购询价单列表 - 基本信息
class PurInquiryFindBillVO
{
	// ID
	//CC_SYNTHESIZE(string, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 源单号			
	CC_SYNTHESIZE(string, src_no, Src_no);
	// 交货日期		   
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	// 数量			 
	CC_SYNTHESIZE(double, qty, Qty);
	// 参考金额		   
	CC_SYNTHESIZE(double, amt, Amt);
	// 报价单数		   
	CC_SYNTHESIZE(int, quot_count, Quot_count);
	// 单据阶段（公共接口）
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective)
	// 是否关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// 是否作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// 交货地点
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	// 联系人
	CC_SYNTHESIZE(string, contact, Contact);
	// 联系电话
	CC_SYNTHESIZE(string, phone, Phone);
	// 传真
	CC_SYNTHESIZE(string, fax, Fax);
	// 电子邮件
	CC_SYNTHESIZE(string, email, Email);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自动单据
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// 红字单据 
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	// 生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
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
	BIND_TO_JSON(PurInquiryFindBillVO, bill_no, bill_date, subject, src_no, delivery_time, qty,
		amt, quot_count, bill_stage, is_effective, is_closed, is_voided, delivery_place, contact,
		phone, fax, email, remark, is_auto, is_rubric, effective_time, approver, create_time,
		create_by, sys_org_code, update_time, update_by);

};


#endif // !_PUR_INQUIRY_FIND_BILL_VO_
