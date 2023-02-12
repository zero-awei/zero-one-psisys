#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:46:50

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
#ifndef _DEPART_CONTROLLER_
#define _DEPART_CONTROLLER_

#include "../../domain/dto/user/depart/AddDepartDTO.h"
#include "../../domain/dto/user/depart/AddDepartMoreDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/user/depart/AddDepartVO.h"
#include "../../domain/vo/user/depart/AddDepartMoreVO.h"

/**
 * 示例部门数据控制器，用于演示复杂的数据上传
 */
class DepartController
{
public:
	CREATE_API_FUN_BODY(addDepart, execAddDepart, AddDepartDTO);
	CREATE_API_FUN_JSON(addDepartMore, execAddDepartMore, AddDepartMoreDTO);
private:
	//执行部门添加
	JsonVO<AddDepartVO> execAddDepart(const AddDepartDTO& dto);
	JsonVO<AddDepartMoreVO> execAddDepartMore(const AddDepartMoreDTO& dto);
};

#endif // _DEPART_CONTROLLER_