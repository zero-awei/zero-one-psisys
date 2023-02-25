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
#ifndef _PUR_INQUIRY_FIND_DETAIL_BILL_VO_H_
#define _PUR_INQUIRY_FIND_DETAIL_BILL_VO_H_

#include "../../GlobalInclude.h"
#include "EntryPurInquiryVO.h"
#include<list>

/**
 * 显示对象 —— 指定采购询价单详情
 */


//指定询价单详细信息
class PurInquiryFindDetailBillVO
{
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//单据阶段（公共接口）
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective)
	// 是否关闭
	CC_SYNTHESIZE(int,  is_closed, Is_closed);
	// 是否作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 付款方式
	CC_SYNTHESIZE(string, payment_method, Payment_method);
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
	// 报价单数
	CC_SYNTHESIZE(int, quot_count, Quot_count);
	// 明细列表
	CC_SYNTHESIZE(list<EntryPurInquiryVO>, detailslist, DetailsList);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 核批意见
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	// 附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	// 核批结果
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurInquiryFindDetailBillVO, bill_no, bill_date, bill_stage, is_effective, is_closed, is_voided,
		subject, payment_method, delivery_place, contact, phone, fax, email, quot_count, detailslist, remark, 
		approval_remark,attachment, approval_result_type);

};


#endif // !_PUR_INQUIRY_FIND_DETAIL_BILL_VO_
