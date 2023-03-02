#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: renqing
 @Date: 2023\02\18 17:23:39

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
#ifndef _PUR_COM_MOD_BILL_STATUS_DO_H_
#define _PUR_COM_MOD_BILL_STATUS_DO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ModPurComBillStatusDO
{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
	// 已生效
	CC_SYNTHESIZE(string, isEffect, IsEffect);
	// 已关闭
	CC_SYNTHESIZE(string, isClose, IsClose);
	// 已作废
	CC_SYNTHESIZE(string, isCancelled, IsCancelled);
	// 修改时间
	CC_SYNTHESIZE(string, updateDate, UpdateDate);
	// 修改人
	CC_SYNTHESIZE(string, updatePerson, UpdatePerson);

public:
	ModPurComBillStatusDO() {

	}
};

#endif // !_PUR_COM_MOD_BILL_STATUS_DO_H_
