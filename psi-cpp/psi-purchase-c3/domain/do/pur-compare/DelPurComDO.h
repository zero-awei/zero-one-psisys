#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: renqing
 @Date: 2023\02\18 13:27:49

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
#ifndef _DEL_PUR_COM_DO_H_
#define _DEL_PUR_COM_DO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class DelPurComDO
{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
public:
	DelPurComDO() {

	}
};

#endif // !_DEL_PUR_COM_DO_H_
