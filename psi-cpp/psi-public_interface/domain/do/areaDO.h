#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/11 17:51

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
#ifndef _AREADO_H_
#define _AREADO_H_
#include "./DoInclude.h"

class AreaDO
{
	CC_SYNTHESIZE(std::string, areaName, AreaName);
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	AreaDO()
	{
		areaName = "";
		id = 0;
	}
};
#endif // _AREADO_H_
