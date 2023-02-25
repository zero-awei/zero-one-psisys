#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: adam
 @Date: 2023/2/24 10:24

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
#ifndef _DELETE_PUR_REQ_DTO_H_
#define _DELETE_PUR_REQ_DTO_H_

#include "../../GlobalInclude.h"

//删除订单的DTO 前端只需要传递一个单据编号给我即可进行修改
class DeletePurReqDTO {
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	//绑定JSON转换方法
	friend void from_json(const json& j, DeletePurReqDTO& t);
};

#endif // !_DELETE_PUR_REQ_DTO_