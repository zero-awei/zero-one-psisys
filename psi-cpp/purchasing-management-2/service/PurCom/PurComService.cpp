/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/17 11:13:11

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
#include "stdafx.h"
#include "PurComService.h"
//#include "../../dao/PurCom/PurComDAO.h"

// 分页查询所有数据
PageVO<PurComVO> PurComService::listAll(const PurComQuery& query)
{
	//构建返回对象
	PageVO<PurComVO> pages;

	return pages;
}

// 查询单个数据
PurComVO PurComService::getData(uint64_t id) {
	PurComVO data;

	return data;
}