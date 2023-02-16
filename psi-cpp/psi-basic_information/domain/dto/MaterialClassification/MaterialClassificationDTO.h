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



#ifndef _MATERIALCLASSIFICATION_DTO_
#define _MATERIALCLASSIFICATION_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
/*
* 基础资料物料分类模块
*/

class MaterialClassificationDTO :public FileDTO {


	//数据库中有，可用来
	CC_SYNTHESIZE(uint64_t, id, Id);

	//父节点，用编码表示
	CC_SYNTHESIZE(uint64_t, pid, pid);
	

	//子级节点,数据库中没有，先设置看看
	CC_SYNTHESIZE(list<MaterialClassificationDTO>, children, Children);

	//是否有子节点
	CC_SYNTHESIZE(bool, has_child, HasChild);

	//名称
	CC_SYNTHESIZE(string, name, Name);

	//编号
	CC_SYNTHESIZE(uint64_t, code, Code);

	//全名
	CC_SYNTHESIZE(string, fullname, FuLLname);

	//是否启用
	CC_SYNTHESIZE(bool, is_enabled, IsEnabled);


	//以下为操作信息，自动生成，不可手动修改
	//创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);

	//创建人
	CC_SYNTHESIZE(string, create_by, CreateBy);

	//修改时间
	CC_SYNTHESIZE(string, update_time, updateTime);

	//修改人
	CC_SYNTHESIZE(string, update_by, updateBy);

public:
	

	friend void from_json(const json& j, MaterialClassificationDTO& t) { // NOLINT
		BIND_FROM_TO_LL(j, t, pid);
		BIND_FROM_TO_I(j, t, id);
		BIND_FROM_TO_OBJ(j, t, children, list<MaterialClassificationDTO>);
		BIND_FROM_TO_B(j, t, has_child);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_ULL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, fullname);
		BIND_FROM_TO_B(j, t, is_enabled);
		BIND_FROM_TO_NORMAL(j, t, create_time);
		BIND_FROM_TO_NORMAL(j, t, create_by);
		BIND_FROM_TO_NORMAL(j, t, update_time);
		BIND_FROM_TO_NORMAL(j, t, update_by);

	}

	BIND_TO_JSON(MaterialClassificationDTO,id, pid, has_child, name, code,
		fullname, is_enabled, create_time, create_by, update_time, update_by);

};


/*class MaterialClassificationDTO {
	
	//父/根节点，用编码表示
	CC_SYNTHESIZE(long long, base, Base);

	//子级节点，用编码表示子级实体
	CC_SYNTHESIZE(list<MaterialClassification1DTO>, children, Children);

	//是否有子节点
	CC_SYNTHESIZE(bool, hasChild, HasChild);

	//名称
	CC_SYNTHESIZE(string, name, Name);

	//编号
	CC_SYNTHESIZE(uint64_t, id, Id);

	//全名
	CC_SYNTHESIZE(string, fullName, FuLLName);

	//是否启用
	CC_SYNTHESIZE(bool, enable, Enable);


	//以下为操作信息，自动生成，不可手动修改
	//创建时间
	CC_SYNTHESIZE(string, creationTime, CreationTime);

	//创建人
	CC_SYNTHESIZE(string, creatorName, CreatorName);

	//修改时间
	CC_SYNTHESIZE(string, modifyTime, ModifyTime);

	//修改人
	CC_SYNTHESIZE(string, modifyName, ModifyName);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, MaterialClassificationDTO& t) { // NOLINT

		BIND_FROM_TO_LL(j, t, base);
		BIND_FROM_TO_OBJ(j, t, children, list<MaterialClassificationDTO>)
		BIND_FROM_TO_B(j, t, hasChild);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_ULL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, fullName);
		BIND_FROM_TO_B(j, t, enable);
		BIND_FROM_TO_NORMAL(j, t, creationTime);
		BIND_FROM_TO_NORMAL(j, t, creatorName);
		BIND_FROM_TO_NORMAL(j, t, modifyTime);
		BIND_FROM_TO_NORMAL(j, t, modifyName);

	}

	BIND_TO_JSON(MaterialClassificationDTO, base,hasChild, name, id,
						fullName, enable, creationTime, creatorName, modifyTime, modifyName);
};
*/

#endif

