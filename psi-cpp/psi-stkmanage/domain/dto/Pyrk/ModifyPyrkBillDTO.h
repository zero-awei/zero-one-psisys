#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _MODIFY_PYRK_BILL_DTO_H_
#define _MODIFY_PYRK_BILL_DTO_H_

#include "../psi-stkmanage/domain/GlobalInclude.h"

/**
 * ʾ���������
 */
class ModifyPyrkBillDTO {
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// ���ݽ׶�
	CC_SYNTHESIZE(std::string, billStage, BillStage);
	// ��������
	CC_SYNTHESIZE(std::string, billDate, BillDate);
public:
	// ��JSONת������
	friend void from_json(const json& j, ModifyPyrkBillDTO& t); // NOLINT
	BIND_TO_JSON(ModifyPyrkBillDTO, billNo, billStage, billDate);
};

#endif // !_MODIFY_PYRK_BILL_DTO_H_