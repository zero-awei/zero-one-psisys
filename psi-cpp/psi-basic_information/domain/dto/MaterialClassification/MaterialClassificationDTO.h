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


	// ID
	CC_SYNTHESIZE(string, id, Id);
	// 父节点
	CC_SYNTHESIZE(string, pid, Pid);
	// 是否有子节点
	CC_SYNTHESIZE(string, has_child, HasChild);
	// 编码
	CC_SYNTHESIZE(string, code, Code);
	//名称
	CC_SYNTHESIZE(string, name, Name);
	//全名
	CC_SYNTHESIZE(string, fullname, Fullname);

	//是否启用
	CC_SYNTHESIZE(int, is_enabled, IsEnabled);

	//以下为操作信息，自动生成，不可手动修改
	//创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);

	//创建人
	CC_SYNTHESIZE(string, create_by, CreateBy);

	//修改时间
	CC_SYNTHESIZE(string, update_time, UpdateTime);

	//修改人
	CC_SYNTHESIZE(string, update_by, UpdateBy);

	//版本 #在数据库中是空的，不知道有什么作用
	CC_SYNTHESIZE(int, version, Version);
	

	//子级节点的DTO对象,数据库中没有，先设置看看
	//CC_SYNTHESIZE(list<MaterialClassificationDO>, children, Children);

	
public:
	

	friend void from_json(const json& j, MaterialClassificationDTO& t) { // 
		
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, pid);
		//BIND_FR	OM_TO_OBJ(j, t, children, list<MaterialClassificationDTO>);
		BIND_FROM_TO_NORMAL(j, t, has_child);
		BIND_FROM_TO_NORMAL(j, t, code);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, fullname);
		BIND_FROM_TO_I(j, t, is_enabled);
		BIND_FROM_TO_NORMAL(j, t, create_time);
		BIND_FROM_TO_NORMAL(j, t, create_by);
		BIND_FROM_TO_NORMAL(j, t, update_time);
		BIND_FROM_TO_NORMAL(j, t, update_by);
		BIND_FROM_TO_I(j, t, version);
	}

	BIND_TO_JSON(MaterialClassificationDTO,id, pid, has_child, code, name,
		fullname, is_enabled, create_time, create_by, update_time, update_by,version);

};




#endif

