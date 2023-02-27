#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _ZDRK_SERVICE_
#define _ZDRK_SERVICE_
#include <list>
#include "../../domain/query/Zdrk/QueryZdrkBillListQuery.h"
#include "../../domain/query/Zdrk/QueryZdrkBillDetailsQuery.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/Zdrk/QueryZdrkBillListVO.h"
#include "../../domain/vo/Zdrk/QueryZdrkBillDetailsVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"








/**
 * 采购入库服务实现
 */
class ZdrkService
{
public:
	// 分页查询所有数据
	PageVO<QueryZdrkBillListVO> listZdrkBillList(const QueryZdrkBillListQuery& query);

	//查询单据详细信息
	QueryZdrkBillDetailsVO getZdrkBillDetails(const QueryZdrkBillDetailsQuery& query);

};

#endif // !_Zdrk_SERVICE_

