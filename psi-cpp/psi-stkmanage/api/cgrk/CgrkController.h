#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _CGRK_CONTROLLER_
#define _CGRK_CONTROLLER_

#include "../../domain/query/cgrk/CgrkQuery.h"
//#include "../../domain/dto/cgrk/SampleDTO.h"
//#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/cgrk/CgrkQueryVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
//#include "../../domain/dto/user/UserDTO.h"
//#include "../../domain/vo/user/UserVO.h"

/**
 * 示例控制器，演示基础接口的使用
 */
class CgrkController
{
public:
	CREATE_API_FUN_QUERY(cgrkQuery, execCgrkQuery, CgrkQuery)

	//CREATE_API_FUN_QUERY_PAYLOAD(querySample, execQuerySample, SampleQuery);
	//CREATE_API_FUN_BODY(addSample, execAddSample, SampleDTO);
	//CREATE_API_FUN_BODY(modifySample, execModifySample, SampleDTO);
	//CREATE_API_FUN_BODY(removeSample, execRemoveSample, SampleDTO);
	//CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);
	//CREATE_API_FUN_JSON(jsonSample, execJsonSample, SampleDTO);
	//CREATE_API_FUN_BODY_FILE(modifyUserInfo, execModifyUserInfo, UserDTO);
private:
	//查询采购入库表单
	JsonVO<PageVO<CgrkQueryVO>> execCgrkQuery(const CgrkQuery& query);
	////演示新增数据
	//JsonVO<uint64_t> execAddSample(const SampleDTO& dto);
	////演示修改数据
	//JsonVO<uint64_t> execModifySample(const SampleDTO& dto);
	////演示删除数据
	//JsonVO<uint64_t> execRemoveSample(const SampleDTO& dto);
	//JsonVO<uint64_t> execRemoveById(const IntID& id);
	////演示JSON提交
	//JsonVO<SampleVO> execJsonSample(const SampleDTO& dto);
	////演示文件上传
	//JsonVO<UserVO> execModifyUserInfo(const UserDTO& dto);
};

#endif // _SAMPLE_CONTROLLER_