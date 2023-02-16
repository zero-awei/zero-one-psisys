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

#ifndef _MaterialClassification_VO_
#define _MaterialClassification_VO_
#include "../../GlobalInclude.h"

/*
* 基础资料物料分类模块
*/

//普通查询（根节点列表）对象
class MaterialClassificationVO{
	

	//名称
	CC_SYNTHESIZE(string, name, Name);

	//编码
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

	MaterialClassificationVO() : name("nanan"), id(11) {}
	

	// 绑定JSON转换方法
	BIND_TO_JSON(MaterialClassificationVO, name,id, 
								fullName, enable, creationTime, creatorName, modifyTime, modifyName);
};


//查询指定分类子级列表对象
class MaterialClassificationNextListVO {

	//父节点
	CC_SYNTHESIZE(string, base, Base);

	//是否有下级
	CC_SYNTHESIZE(bool, hasChild, HasChild);

	//名称
	CC_SYNTHESIZE(string, name, Name);

	//编码
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
	BIND_TO_JSON(MaterialClassificationNextListVO,base,hasChild, name, id,
		fullName, enable, creationTime, creatorName, modifyTime, modifyName);
};

//查询指定分类详细信息对象
class MaterialClassificationDetailVO {

	
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
	BIND_TO_JSON(MaterialClassificationDetailVO,creationTime, creatorName, modifyTime, modifyName);
};
#endif
