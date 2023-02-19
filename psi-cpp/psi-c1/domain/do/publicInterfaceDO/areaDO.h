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
#include "../DoInclude.h"

class AreaDO
{
	//可能要查询的省份名称
	CC_SYNTHESIZE(std::string, provincename, ProvinceName);
	//可能要查询的城市名称
	CC_SYNTHESIZE(std::string, cityname, CityName);
	//可能要查询的区域名称
	CC_SYNTHESIZE(std::string, areaname, AreaName);
	//需要查询下辖区的区域id
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	AreaDO()
	{
		areaname = "";
		cityname = "";
		provincename = "";
		id = 0;
	}
	string getName()
	{
		if (!areaname.empty())return areaname;
		if (!cityname.empty())return cityname;
		if (!provincename.empty())return provincename;
	}
};
#endif // _AREADO_H_
