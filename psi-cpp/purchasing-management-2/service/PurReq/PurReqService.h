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
#ifndef _PUR_REQ_SERVICE_
#define _PUR_REQ_SERVICE_
#include <list>
#include "../../domain/vo/PurReq/PurReqVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/PurReq/PurReqQuery.h"

/**
 * 采购请求服务实现，基础采购订单服务实现
 */
class PurReqService
{
public:
	// 分页查询所有数据
	PageVO<PurReqVO> listAll(const PurReqQuery& query);
	// 查询单个数据
	PurReqVO getData(uint64_t id);
};

#endif // ! _PUR_REQ_SERVICE_