#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 00:36:03

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
#ifndef _PUR_RER_FIND_Detail_BILL_DTO_
#define _PUR_RER_FIND_Detail_BILL_DTO_

#include "../../GlobalInclude.h"
#include "PurReqFindBillDTO.h"
/*
查询单据列表显示对象
*/
//备注:类的宏里面的字段类型需要更改
class PurReqFindDetailBillDTO : public PurReqFindBillDTO {
	//指定的单据号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurReqFindDetailBillDTO& t) {
		//暂时还未实现
		//BIND_FROM_TO_ULL(j, t, id);
		//BIND_FROM_TO_NORMAL(j, t, name);
		//BIND_FROM_TO_I(j, t, age);
		//BIND_FROM_TO_NORMAL(j, t, sex);
	}
};
#endif // !







