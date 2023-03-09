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


#ifndef _MATERIALCLASSIFICATION_DO_
#define _MATERIALCLASSIFICATION_DO_
#include "../DoInclude.h"

/**
 * 物料分类数据库实体类
 */
class MaterialClassificationDO  {

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

	//版本
	CC_SYNTHESIZE(int, version, Version);
public:
	
};

#endif 


