#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/16 10:24

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
#ifndef _PUR_REQ_EXPORT_QUERY_
#define _PUR_REQ_EXPORT_QUERY_

#include "../../GlobalInclude.h"
//#include "../FileDTO.h"

/**
 * 传输对象 —— 单据编号（利用单据编号查询想导出的订单）
 */

 //导出
class PurReqExportQuery
{
	//传输对象信息 —— 利用单据编号查询想导出的订单
	CC_SYNTHESIZE(string, purReqId, PurReqId);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurReqExportQuery& t);
};

#endif // !_PUR_REQ_EXPORT_QUERY_