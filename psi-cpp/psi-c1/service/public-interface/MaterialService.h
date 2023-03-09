#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/21 20:40

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

#ifndef _MATERIALSERVICE_H_
#define _MATERIALSERVICE_H_

#include "../../domain/vo/public-interface/MaterialVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/public-interface/MaterialQuery.h"

class MaterialService
{
public:
	// 分页查询所有数据
	PageVO<MaterialVO> listAll(const MaterialQuery& query);
};

#endif // _MATERIALSERVICE_H_