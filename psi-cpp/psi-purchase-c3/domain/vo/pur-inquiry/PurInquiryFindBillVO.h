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
#ifndef _PUR_INQUIRY_FIND_BILL_VO_
#define _PUR_INQUIRY_FIND_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * 显示对象 —— 采购询价单列表
 */

//采购询价单列表 - 基本信息
class PurInquiryFindBillVO
{
	//单据编号  
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    
	//单据日期
	CC_SYNTHESIZE(string, purInquiryBillDate, PurInquiryBillDate);  
	//单据主题 
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);  
	//源单号
	CC_SYNTHESIZE(string, purInquirySrcBillId, PurInquirySrcBillId);   
	//交货日期
	CC_SYNTHESIZE(string, purInquiryDeliveryTime, purInquiryDeliveryTime);   
	//数量
	CC_SYNTHESIZE(double, purInquiryQty, purInquiryQty);   
	//参考金额
	CC_SYNTHESIZE(double, purInquiryAmt, purInquiryAmt);   
	//报价单数
	CC_SYNTHESIZE(int, purInquiryQuotCount, purInquiryQuotCount);    
	//单据阶段（公共接口）
	CC_SYNTHESIZE(string, purInquiryBillStage, purInquiryBillStage);
	//是否生效
	CC_SYNTHESIZE(int, purInquiryIsEffective, PurInquiryIsEffective);  
	//是否关闭
	CC_SYNTHESIZE(int, purInquiryIsClosed, PurInquiryIsClosed);  
	//是否作废
	CC_SYNTHESIZE(int, purInquiryIsVoided, PurInquiryIsVoided); 
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
	//备注
	CC_SYNTHESIZE(string, purInquiryRemark, PurInquiryRemark);   
	//自动单据
	CC_SYNTHESIZE(int, purInquiryIsAuto, PurInquiryIsAuto);   
	//红字单据 
	CC_SYNTHESIZE(int, purInquiryIsRubric, PurInquiryIsRubric);   
	//生效时间
	CC_SYNTHESIZE(string, purInquiryEffectiveTime, PurInquiryEffectiveTime);   
	//核批人
	CC_SYNTHESIZE(string, purInquiryApprover, PurInquiryApprover);   
	//制单时间
	CC_SYNTHESIZE(string, purInquiryCreateTime, PurInquiryCreateTime);   
	//制单人
	CC_SYNTHESIZE(string, purInquiryCreateBy, PurInquiryCreateBy);   
	//制单部门
	CC_SYNTHESIZE(string, purInquirySysOrgCode, PurInquirySysOrgCode);   
	//修改时间
	CC_SYNTHESIZE(string, purInquiryUpdateTime, PurInquiryUpdateTime);   
	//修改人
	CC_SYNTHESIZE(string, purInquiryUpdateBy, PurInquiryUpdateBy);   

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurInquiryFindBillVO, purInquiryBillNo, purInquiryBillDate, purInquirySubject, purInquirySrcBillId,
		purInquiryDeliveryTime, purInquiryQty, purInquiryAmt, purInquiryQuotCount, purInquiryBillStage,purInquiryIsEffective, purInquiryIsClosed,
		purInquiryIsVoided, purInquiryDeliveryPlace, purInquiryContact, purInquiryPhone, purInquiryFax, purInquiryEmail,
		purInquiryRemark, purInquiryIsAuto, purInquiryIsRubric, purInquiryEffectiveTime, purInquiryApprover,
		purInquiryCreateTime, purInquiryCreateBy, purInquirySysOrgCode, purInquiryUpdateTime, purInquiryUpdateBy);

};


#endif // !_PUR_INQUIRY_FIND_BILL_VO_
