/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/02/19 14:42:15

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
#ifndef _ADD_PUR_INQUIRY_DO_H_
#define _ADD_PUR_INQUIRY_DO_H_
#include "../../GlobalInclude.h"
#include <list>

//修改和删除DO
class AddPurInquiryDO
{
	//1ID
	CC_SYNTHESIZE(string, id, Id);
	//2单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//3单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//4付款方式
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	//5交货地点
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	////6联系人			;
	CC_SYNTHESIZE(string, contact, Contact);
	////7联系电话	   ;
	CC_SYNTHESIZE(string, phone, Phone);
	////8传真			 ;
	CC_SYNTHESIZE(string, fax, Fax);
	////9电子邮箱	   ;
	CC_SYNTHESIZE(string, email, Email);
	////10备注			 ;
	CC_SYNTHESIZE(string, remark, Remark);
	//11红字单据(是否红字)
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	////12自动单据	   ;
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//13修改时间		   ;
	CC_SYNTHESIZE(string, create_time, Create_time);
	//14修改人			;
	CC_SYNTHESIZE(string, update_by, Update_by);
	////15生效时间	   ;
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//16单据阶段		   ;
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//17单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_Date);
public:
	AddPurInquiryDO()
	{

	}

};

#endif // !_ADD_PUR_INQUIRY_DO_H_
