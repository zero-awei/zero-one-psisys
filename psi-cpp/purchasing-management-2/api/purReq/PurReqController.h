#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/16 0:23:02

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

#ifndef _PUR_REQ_CONTROLLER_
#define _PUR_REQ_CONTROLLER_

#include "../../domain/query/purReq/PurReqQuery.h"
#include "../../domain/vo/purReq/PurReqVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

/**
 * 采购请求控制器，采购请求接口的使用
 */
class PurReqController {
public:
	// 所有数据
	CREATE_API_FUN_QUERY_PAYLOAD(listPurReqList, execListPurReqList, PurReqQuery);
	// 分页数据
	CREATE_API_FUN_QUERY_PAYLOAD(listPurReq, execListPurReq, PurReqQuery);
	// 单个数据
	CREATE_API_FUN_BODY(getPurReq, execGetPurReq, PurReqQuery);

private:
	// 请求列表
	JsonVO<list<PurReqVO>> execListPurReqList(const PurReqQuery& query, const PayloadDTO& payload);
	// 请求分页数据
	JsonVO<PageVO<PurReqVO>> execListPurReq(const PurReqQuery& query, const PayloadDTO& payload);
	// 查询单个数据
	JsonVO<PurReqVO> execGetPurReq(const PurReqQuery& query);

};

#endif // ! _PUR_REQ_CONTROLLER_