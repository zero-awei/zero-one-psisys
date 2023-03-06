
/*
 Copyright Zero One Star. All rights reserved.
 @Author: ×î³õ
 @Date: 2023/02/16 22:00:00
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
#include "AddPaymentDTO.h"

void from_json(const json& j, AddPaymentDTO& apt) {
	BIND_FROM_TO_NORMAL(j, apt, bill_no);
	BIND_FROM_TO_NORMAL(j, apt, bill_date);
	BIND_FROM_TO_NORMAL(j, apt, src_bill_type);
	BIND_FROM_TO_NORMAL(j, apt, src_bill_id);
	BIND_FROM_TO_NORMAL(j, apt, src_no);
	BIND_FROM_TO_NORMAL(j, apt, subject);
	BIND_FROM_TO_NORMAL(j, apt, supplier_id);
	BIND_FROM_TO_NORMAL(j, apt, op_dept);
	BIND_FROM_TO_NORMAL(j, apt, operator1);
	BIND_FROM_TO_NORMAL(j, apt, payment_type);
	BIND_FROM_TO_NORMAL(j, apt, remark);
	BIND_FROM_TO_NORMAL(j, apt, bill_stage);
	BIND_FROM_TO_NORMAL(j, apt, effective_time);

	BIND_FROM_TO_I(j, apt, amt);
	BIND_FROM_TO_I(j, apt, is_auto);
	BIND_FROM_TO_I(j, apt, is_effective);
	BIND_FROM_TO_I(j, apt, is_closed);
	BIND_FROM_TO_I(j, apt, is_voided);
}