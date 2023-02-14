#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: shiyi
 @Date: 2023/2/13 15:40:04

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
#ifndef _MATERIALCLASSIFICATION_QUERY_
#define _MATERIALCLASSIFICATION_QUERY_
#include "../PageQuery.h"

/**
* 基础资料分类模块查询对象
*/
class MaterialClassificationQuery : public PageQuery {

	//名称
	CC_SYNTHESIZE(string, name, Name);

	//编码
	CC_SYNTHESIZE(uint64_t, id, Id);

public:
	// 绑定from_json
	friend void from_json(const json& j, MaterialClassificationQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_ULL(j, t, id);
	}
};


class MaterialClassificationChildQuery  {

	//名称
	CC_SYNTHESIZE(string, name, Name);

	//编码
	CC_SYNTHESIZE(uint64_t, id, Id);

public:
	// 绑定from_json
	friend void from_json(const json& j, MaterialClassificationChildQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_ULL(j, t, id);
	}
};

class MaterialClassificationDetailQuery {

	//创建时间
	CC_SYNTHESIZE(string, creationTime, CreationTime);

	//创建人
	CC_SYNTHESIZE(string, creatorName, CreatorName);

	//修改时间
	CC_SYNTHESIZE(string, modifyTime, ModifyTime);

	//修改人
	CC_SYNTHESIZE(string, modifyName, ModifyName);

public:
	// 绑定from_json
	friend void from_json(const json& j, MaterialClassificationDetailQuery& t) { // NOLINT

		BIND_FROM_TO_NORMAL(j, t, creationTime);
		BIND_FROM_TO_NORMAL(j, t, creatorName);
		BIND_FROM_TO_NORMAL(j, t, modifyTime);
		BIND_FROM_TO_NORMAL(j, t, modifyName);

	}
};

#endif

