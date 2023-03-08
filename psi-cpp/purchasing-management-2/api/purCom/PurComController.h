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

#ifndef _PUR_COM_CONTROLLER_
#define _PUR_COM_CONTROLLER_

#include "../../domain/query/purCom/PurComQuery.h"
#include "../../domain/query/purCom/PurComEntryQuery.h"
#include "../../domain/vo/purCom/PurComVO.h"
#include "../../domain/vo/purCom/PurComEntryVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

/**
 * 采购请求控制器，采购请求接口的使用
 * 负责人：J4nnA
 */
class PurComController {
public:
	// 分页数据
	CREATE_API_FUN_QUERY_PAYLOAD(listPurCom, execListPurCom, PurComQuery);
	// 单个数据
	CREATE_API_FUN_BODY(getPurCom, execGetPurCom, PurComQuery);
	// 明细列表
	CREATE_API_FUN_QUERY_PAYLOAD(listPurComEntrys, execListPurComEntrys, PurComEntryQuery);
private:
	// 请求分页数据
	JsonVO<PageVO<PurComVO>> execListPurCom(const PurComQuery& query, const PayloadDTO& payload);
	// 查询单个数据
	JsonVO<PurComVO> execGetPurCom(const PurComQuery& query);
	// 查询指定比价单的明细列表
	JsonVO<PageVO<PurComEntryVO>> execListPurComEntrys(const PurComEntryQuery& query, const PayloadDTO& payload);
};

#endif // ! _PUR_COM_CONTROLLER_