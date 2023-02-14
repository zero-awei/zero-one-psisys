#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/14 15:57

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

#ifndef _MATERIAL_QUERY_CONTROLLER_
#define _MATERIAL_QUERY_CONTROLLER_

#include "../domain/query/MaterialQuery.h"
#include "../domain/vo/MaterialVO.h"
#include "../domain/vo/PageVO.h"
#include "../domain/vo/JsonVO.h"

class MaterialQueryController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryMaterial, execQueryMaterial, MaterialQuery);
private:
	JsonVO<PageVO<MaterialVO>>execQueryMaterial(const MaterialQuery& query, const PayloadDTO& payload);
};

#endif //!_MATERIAL_QUERY_CONTROLLER_