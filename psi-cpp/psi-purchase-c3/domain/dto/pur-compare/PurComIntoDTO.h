#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: QZP
 @Date: 2023/2/24 23:29
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

#ifndef _PUR_COM_INTO_DTO_H_
#define _PUR_COM_INTO_DTO_H_

#include "../FileDTO.h"

/**
 * 导入的传入DTO
 */

class PurComIntoDTO : public FileDTO
{
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurComIntoDTO& t)
	{
	}; // NOLINT
};

#endif // !_PUR_COM_INTO_DTO_