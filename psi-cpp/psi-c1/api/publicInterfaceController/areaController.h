#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/11 20:51

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
#ifndef _AREACONTROLLER_H_
#define _AREACONTROLLER_H_
#include "../../domain/do/publicInterfaceDO/AreaDO.h"
#include "../../domain/query/publicInterfaceQuery/AreaQuery.h"
#include "../../domain/vo/publicInterfaceVO/AreaVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

class AreaController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryArea, execQueryArea, AreaQuery);
private:
	//��ѯĳ�������Ͻ��
	JsonVO<list<AreaVO>>execQueryArea(const AreaQuery& query, const PayloadDTO& payload);
	
};

#endif // _AREACONTROLLER_H_