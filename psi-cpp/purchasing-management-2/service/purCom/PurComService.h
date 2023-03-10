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
#ifndef _PUR_COM_SERVICE_
#define _PUR_COM_SERVICE_
#include <list>
#include "../../domain/vo/purCom/PurComVO.h"
#include "../../domain/vo/purCom/PurComEntryVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/purCom/PurComQuery.h"
#include "../../domain/query/purCom/PurComEntryQuery.h"
#include "../../domain/vo/purOrder/PurOrderDividedListVO.h"
#include "../../domain/query/purOrder/PurOrderDividedListQuery.h"

/**
 * 采购请求服务实现，基础采购订单服务实现
 * 负责人：J4nnA
 */
class PurComService
{
public:
	// 分页查询所有数据
	PageVO<PurComVO> listAll(const PurComQuery& query);

	// 查询指定比价单详情列表
	PageVO<PurComEntryVO>listEntry(const PurComEntryQuery& query);
	
	//获取多个PurQuotDividedListVO对象
	list<PurOrderDividedListVO> listPurOrderDividedListDO(const PurOrderDividedListQuery& query);
};

#endif // ! _PUR_COM_SERVICE_