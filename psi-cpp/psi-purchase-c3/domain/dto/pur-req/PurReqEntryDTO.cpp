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
#include "stdafx.h"
#include "PurReqEntryDTO.h"

void from_json(const json& j, PurReqEntryDTO& t) {
	BIND_FROM_TO_I(j, t, version);
	BIND_FROM_TO_I(j, t, entryNo);

	BIND_FROM_TO_D(j, t, qty);
	BIND_FROM_TO_D(j, t, amt);
	BIND_FROM_TO_D(j, t, taxRate);
	BIND_FROM_TO_D(j, t, price);
	BIND_FROM_TO_D(j, t, orderedQty);

	BIND_FROM_TO_NORMAL(j, t, unitId);
	BIND_FROM_TO_NORMAL(j, t, srcNo);
	BIND_FROM_TO_NORMAL(j, t, srcBillType);
	BIND_FROM_TO_NORMAL(j, t, srcBillId);
	BIND_FROM_TO_NORMAL(j, t, srcEntryId);
	BIND_FROM_TO_NORMAL(j, t, materialId);
	BIND_FROM_TO_NORMAL(j, t, custom1);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, custom1);
	BIND_FROM_TO_NORMAL(j, t, suggestSupplierId);
}


