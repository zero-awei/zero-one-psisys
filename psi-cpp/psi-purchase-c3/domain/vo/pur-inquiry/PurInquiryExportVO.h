#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/22  17:37

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
#ifndef _PUR_INQUIRY_EXPORT_VO_H_
#define _PUR_INQUIRY_EXPORT_VO_H_

#include "../../GlobalInclude.h"
#include "PurInquiryFindBillVO.h"
#include "EntryPurInquiryExportVO.h"

/**
 * 显示对象 —— 采购询价单列表
 */

 //采购询价单列表 - 基本信息
class PurInquiryExportVO
{
	// 单据编号  
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	
	CC_SYNTHESIZE(list<string>, bill_no_list, Bill_no_list);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// 源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	// 源单id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	// 源单号
	CC_SYNTHESIZE(string, src_no, Src_no);
	// 单据主题 
	CC_SYNTHESIZE(string, subject, Subject);
	// 是否红字
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	// 付款方式
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	// 交货地点
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	// 交货时间 
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	// 联系人
	CC_SYNTHESIZE(string, contact, Contact);
	// 联系电话
	CC_SYNTHESIZE(string, phone, Phone);
	// 传真
	CC_SYNTHESIZE(string, fax, Fax);
	// 电子邮件
	CC_SYNTHESIZE(string, email, Email);
	// 数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 参考金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 生效的报价单数
	CC_SYNTHESIZE(int, quot_count, Quot_count);
	// 明细列表
	CC_SYNTHESIZE(list<EntryPurInquiryExportVO>, detailslist, DetailsList);
	// 附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 是否自动生成
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// 单据阶段（公共接口）
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
	// 核批实例id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	// 核批结果类型
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	// 核批意见
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	// 是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// 生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	// 是否关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// 是否作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// 创建部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// 创建人
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
	// 修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);



public:
	BIND_TO_JSON(PurInquiryExportVO, bill_no, bill_date, src_bill_type, src_bill_id, src_no, subject,
		delivery_time, contact, phone, fax, email, qty, amt, quot_count, detailslist, attachment, remark, is_auto, bill_stage,
		approver, bpmi_instance_id, approval_result_type, approval_remark, is_effective, effective_time,
		effective_time, is_closed, is_voided, sys_org_code, create_by, create_time, update_by, update_time);
};
#endif // _PUR_INQUIRY_EXPORT_VO_H_