#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kiva
 @Date: 2023/2/18 19:53

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

#ifndef _MATERIALTYPETREEVO_H_
#define _MATERIALTYPETREEVO_H_
#include"../DoInclude.h"
#include"../../vo/publicInterfaceVO/MaterialTypeTreeListVO.h"
class MaterialTypeTreeDO {
	CC_SYNTHESIZE(std::string, code, Code);
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	CC_SYNTHESIZE(std::string, createBy_dictText, CreateBy_dictText);
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	CC_SYNTHESIZE(std::string, fullname, Fullname);
	CC_SYNTHESIZE(std::string, hasChild, HasChild);
	CC_SYNTHESIZE(std::string, hasChild_dictText, HasChild_dictText);
	CC_SYNTHESIZE(std::string, id, Id);
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
	CC_SYNTHESIZE(std::string, isEnabled_dictText, IsEnabled_dictText);
	CC_SYNTHESIZE(std::string, name, Name);
	CC_SYNTHESIZE(std::string, pid, Pid);
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
	CC_SYNTHESIZE(std::string, updateBy_dictText, UpdateBy_dictText);
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	CC_SYNTHESIZE(std::string, version, Version);
	CC_SYNTHESIZE(std::vector<MaterialTypeTreeListVO>, children, Children);

public:
	MaterialTypeTreeDO() {
		code = "";
		createBy = "";
		createBy_dictText = "";
		createTime = "";
		fullname = "";
		hasChild = "";
		hasChild_dictText = "";
		id = "";
		isEnabled = -1;
		isEnabled_dictText = "";
		name = "";
		pid = "";
		updateBy = "";
		updateBy_dictText = "";
		updateTime = "";
		version = "";
	}
};

#endif