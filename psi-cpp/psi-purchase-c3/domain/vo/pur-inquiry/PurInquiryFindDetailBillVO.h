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
#ifndef _PUR_INQUIRY_FIND_DETAIL_BILL_VO_
#define _PUR_INQUIRY_FIND_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * 显示对象 —— 指定采购询价单详情
 */


//指定询价单详细信息
class PurInquiryFindDetailBillVO
{
	//单据编号  
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);
	//单据日期
	CC_SYNTHESIZE(string, purInquiryBillDate, purInquiryBillDate);
	//单据阶段（公共接口）
	CC_SYNTHESIZE(string, purInquiryBillStage, purInquiryBillStage);
	//是否生效
	CC_SYNTHESIZE(int, purInquiryIsEffective, PurInquiryIsEffective);
	//是否关闭
	CC_SYNTHESIZE(int, purInquiryIsClosed, PurInquiryIsClosed);
	//是否作废
	CC_SYNTHESIZE(int, purInquiryIsVoided, PurInquiryIsVoided);
	//单据主题
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);
	//付款方式
	CC_SYNTHESIZE(string, purInquiryPaymentMethod, PurInquiryPaymentMethod);
	//交货地点
	CC_SYNTHESIZE(string, purInquiryDeliveryPlace, PurInquiryDeliveryPlace);
	//联系人
	CC_SYNTHESIZE(string, purInquiryContact, PurInquiryContact);
	//联系电话
	CC_SYNTHESIZE(string, purInquiryPhone, PurInquiryPhone);
	//传真
	CC_SYNTHESIZE(string, purInquiryFax, PurInquiryFax);
	//电子邮件
	CC_SYNTHESIZE(string, purInquiryEmail, PurInquiryEmail);
	//报价单数
	CC_SYNTHESIZE(int, purInquiryQuotCount, purInquiryQuotCount);
	//备注
	CC_SYNTHESIZE(string, purInquiryRemark, PurInquiryRemark);
	//核批意见
	CC_SYNTHESIZE(string, purInquiryApprovalRemark, PurInquiryApprovalRemark);
	//附件
	CC_SYNTHESIZE(string, purInquiryAttachment, PurInquiryAttachment);
	//核批结果
	CC_SYNTHESIZE(string, purInquiryApprovalResultType, PurInquiryApprovalResultType);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurInquiryFindDetailBillVO, purInquiryBillNo, purInquiryBillDate, purInquiryBillStage, purInquiryIsEffective, purInquiryIsClosed,
		purInquiryIsVoided, purInquirySubject, purInquiryPaymentMethod, purInquiryDeliveryPlace, purInquiryContact,
		purInquiryPhone, purInquiryFax, purInquiryEmail, purInquiryQuotCount, purInquiryRemark, purInquiryApprovalRemark,
		purInquiryApprovalResultType);

};


#endif // !_PUR_INQUIRY_FIND_DETAIL_BILL_VO_
