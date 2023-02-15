#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/15 14:42

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
#ifndef _PUR_REQ_INTO_DTO_
#define _PUR_REQ_INTO_DTO_

#include "../FileDTO.h"

/**
 * 传输对象 —— 导入对象的信息（同新增申请单所需信息）
 */

//导入
class PurReqIntoDTO : public FileDTO
{
	// 单据主题
	CC_SYNTHESIZE(string, purReqSubject, PurReqSubject);

	// 采购类型	（公共接口）
	CC_SYNTHESIZE(string, purReqType, PurReqType);
	// 需求部门	（公共接口）
	CC_SYNTHESIZE(string, purReqRequestDept, PurReqRequestDept);
	// 需求人	（选择用户公共接口）
	CC_SYNTHESIZE(string, purReqRequester, PurReqRequester);
	// 需求时间 
	CC_SYNTHESIZE(string, purReqRequestTime, PurReqRequestTime);
//明细
	// 源单分录号	
	CC_SYNTHESIZE(string, purReqSrcEntryNo, PurReqSrcEntryNo);
	// 物料	
	CC_SYNTHESIZE(string, purReqMaterialId, PurReqMaterialId);

	// 规格型号（公共接口）

	// 计量单位	
	CC_SYNTHESIZE(string, purReqUnitId, PurReqUnitId);
	// 数量	
	CC_SYNTHESIZE(double, purReqQty, PurReqQty);
	// 税率% 
	CC_SYNTHESIZE(double, purReqTaxRate, PurReqTaxRate);
	//参考含税单价
	CC_SYNTHESIZE(double, purReqPrice, PurReqPrice);
	//参考含税金额
	CC_SYNTHESIZE(double, purReqAmt, PurReqAmt);

	// 建议供应商（公共接口）
	CC_SYNTHESIZE(string, purReqSuggestSupplierId, PurReqSuggestSupplierId);
	// 备注	
	CC_SYNTHESIZE(string, purReqRemark, PurReqRemark);
	// 自定义1	
	CC_SYNTHESIZE(string, purReqCustom1, PurReqCustom1);
	// 自定义2	
	CC_SYNTHESIZE(string, purReqCustom2, PurReqCustom2);


public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurReqIntoDTO& t); // NOLINT
	
	
};

#endif // !_PUR_REQ_INTO_DTO_