#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/2/15 17:56:19

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
#ifndef _PUR_COM_LIST_VO_
#define _PUR_COM_LIST_VO_

#include "../../GlobalInclude.h"

/**
 * 报价单列表显示对象
 */
class PurComListVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	// 付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurComListVO, billNo, billDate, subject, supplierId, \
		paymentMethod, deliveryTime, deliveryPlace, remark);
	//用于测试
	PurComListVO()
	{
		this->setBillNo("CGBJ100QZP");
		this->setSubject("测试接口");
	}
};


#endif 

