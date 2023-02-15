/*
 Copyright Zero One Star. All rights reserved.

 @Author: renqing
 @Date: 2023/2/15 16:58:10

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
#include "stdafx.h"
#include "PurCompareDTO.h"

// 新增比价
void from_json(const json& j, AddPurComDTO& t) { 
	BIND_FROM_TO_NORMAL(j, t, billId);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_I(j, t, isEffect);
	BIND_FROM_TO_I(j, t, isClose);
	BIND_FROM_TO_I(j, t, isCancelled);
	BIND_FROM_TO_NORMAL(j, t, effectDate);
	BIND_FROM_TO_NORMAL(j, t, approver);
	BIND_FROM_TO_NORMAL(j, t, makeBillDate);
	BIND_FROM_TO_NORMAL(j, t, makeBillDept);
	BIND_FROM_TO_NORMAL(j, t, makeBillPerson);
	BIND_FROM_TO_NORMAL(j, t, updateDate);
	BIND_FROM_TO_NORMAL(j, t, updatePerson);
	BIND_FROM_TO_I(j, t, autoBill);
	BIND_FROM_TO_I(j, t, redBill);
	BIND_FROM_TO_NORMAL(j, t, billTheme);
	BIND_FROM_TO_NORMAL(j, t, billStatus);
	BIND_FROM_TO_NORMAL(j, t, inquiryBill);
	BIND_FROM_TO_NORMAL(j, t, payMethod);
	BIND_FROM_TO_NORMAL(j, t, deliveryDate);
	BIND_FROM_TO_NORMAL(j, t, deliveryPlace);
	BIND_FROM_TO_NORMAL(j, t, remark);
}

// 修改比价
void from_json(const json& j, ModPurComDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, billId);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_I(j, t, isEffect);
	BIND_FROM_TO_I(j, t, isClose);
	BIND_FROM_TO_I(j, t, isCancelled);
	BIND_FROM_TO_NORMAL(j, t, effectDate);
	BIND_FROM_TO_NORMAL(j, t, approver);
	BIND_FROM_TO_NORMAL(j, t, makeBillDate);
	BIND_FROM_TO_NORMAL(j, t, makeBillDept);
	BIND_FROM_TO_NORMAL(j, t, makeBillPerson);
	BIND_FROM_TO_NORMAL(j, t, updateDate);
	BIND_FROM_TO_NORMAL(j, t, updatePerson);
	BIND_FROM_TO_I(j, t, autoBill);
	BIND_FROM_TO_I(j, t, redBill);
	BIND_FROM_TO_NORMAL(j, t, billTheme);
	BIND_FROM_TO_NORMAL(j, t, billStatus);
	BIND_FROM_TO_NORMAL(j, t, inquiryBill);
	BIND_FROM_TO_NORMAL(j, t, payMethod);
	BIND_FROM_TO_NORMAL(j, t, deliveryDate);
	BIND_FROM_TO_NORMAL(j, t, deliveryPlace);
	BIND_FROM_TO_NORMAL(j, t, remark);
}

// 删除比价
void from_json(const json& j, DelPurComDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, billId);
}

// 修改单据状态
void from_json(const json& j, PurComModBillStatusDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, billId);
	BIND_FROM_TO_I(j, t, isEffect);
	BIND_FROM_TO_I(j, t, isClose);
	BIND_FROM_TO_I(j, t, isCancelled);
}