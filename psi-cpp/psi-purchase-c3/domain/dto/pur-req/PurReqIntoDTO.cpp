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
#include "stdafx.h"
#include "PurReqIntoDTO.h"


void from_json(const json& j, PurReqIntoDTO& t) { // NOLINT
	
	BIND_FROM_TO_NORMAL(j, t, purReqSubject);

	// 采购类型	（公共接口）
	BIND_FROM_TO_NORMAL(j, t, purReqType);
	// 需求部门	（公共接口）
	BIND_FROM_TO_NORMAL(j, t, purReqRequestDept);
	// 需求人	（选择用户公共接口）
	BIND_FROM_TO_NORMAL(j, t, purReqRequester);
	BIND_FROM_TO_NORMAL(j, t, purReqRequestTime);
	BIND_FROM_TO_NORMAL(j, t, purReqSrcEntryNo);
	BIND_FROM_TO_NORMAL(j, t, purReqMaterialId);

	// 规格型号（公共接口）

	BIND_FROM_TO_NORMAL(j, t, purReqUnitId);
	BIND_FROM_TO_D(j, t, purReqQty);
	BIND_FROM_TO_D(j, t, purReqTaxRate);
	BIND_FROM_TO_D(j, t, purReqPrice);
	BIND_FROM_TO_D(j, t, purReqAmt);

	// 建议供应商（公共接口）
	BIND_FROM_TO_NORMAL(j, t, purReqSuggestSupplierId);
	BIND_FROM_TO_NORMAL(j, t, purReqRemark);
	BIND_FROM_TO_NORMAL(j, t, purReqCustom1);
	BIND_FROM_TO_NORMAL(j, t, purReqCustom2);
}