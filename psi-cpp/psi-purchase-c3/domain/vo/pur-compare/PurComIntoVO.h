#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 00:15:01

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
#ifndef _PUR_COM_INTO_VO_
#define _PUR_COM_INTO_VO_

#include "../../GlobalInclude.h"
class PurComIntoVO  {
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	////单据日期
	//CC_SYNTHESIZE(string, bill_date, Bill_date);
	////已生效
	//CC_SYNTHESIZE(int, is_effective, Is_effective);
	////已关闭
	//CC_SYNTHESIZE(int, is_closed, Is_closed);
	////已作废
	//CC_SYNTHESIZE(int, is_voided, Ss_voided);
	////单据主题
	//CC_SYNTHESIZE(string, subject, Subject);
	////采购询价单编号
	//CC_SYNTHESIZE(string, bill_no, Bill_no);
	////付款方式
	//CC_SYNTHESIZE(string, payment_method, Payment_method);
	////交货日期
	//CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	////需求地点
	//CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	////备注
	//CC_SYNTHESIZE(string, remark, Remark);
	////附件
	//CC_SYNTHESIZE(string, attachment, Attachment);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurComIntoVO, bill_no);
	//BIND_TO_JSON(PurComIntoDTO, bill_no, bill_date, is_effective, is_closed, 
	//is_voided,subject, bill_no, payment_method, delivery_time, delivery_place, remark, attachment);
	
};

#endif // !




