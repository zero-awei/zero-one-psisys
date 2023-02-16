#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:50:26

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

#ifndef _UPDATE_DEPART_MORE_DTO_
#define _UPDATE_DEPART_MORE_DTO_

#include "AddDepartDTO.h"

 /**
  * ʾ����Ӳ��Ÿ������ݴ������
 */

class AddDepartMoreDTO
{
	// ���
	CC_SYNTHESIZE(int, id, Id);
	// ������Ϣ
	CC_SYNTHESIZE(list<AddDepartDTO>, other, Other);
public:
	// ��JSONת������
	friend void from_json(const json& j, AddDepartMoreDTO& t) { // NOLINT
		BIND_FROM_TO_I(j, t, id);
		BIND_FROM_TO_OBJ(j, t, other, list<AddDepartDTO>);
	}
};

#endif // !_UPDATE_DEPART_DTO_