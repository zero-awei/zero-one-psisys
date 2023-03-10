#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/2/19 16:41:00

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
#ifndef _PUR_COM_DAO_
#define _PUR_COM_DAO_

#include "BaseDAO.h"
#include "../../domain/do/PurCom/PurComDO.h"
#include "../../domain/do/PurCom/PurComEntryDO.h"

#include "../../domain/do/PurOrder/PurOrderDividedListDO.h"

/*
*	数据库操作实现 
*/
class PurComDAO : public BaseDAO {
public:
	// 统计数据条数
	uint64_t count(const PurComDO& obj);
	// 统计明细条数
	uint64_t countEntrys(const PurComEntryDO& obj);
	// 分页查询数据
	list<PurComDO> selectPurCom(const PurComDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// 查询指定比价单明细列表
	list<PurComEntryDO> selectPurComEntry(const PurComEntryDO& obj, uint64_t pageIndex, uint64_t pageSize);

	// 查询询价单分录列表
	list<PurOrderDividedListDO> selectPurOrderDividedListDO(const PurOrderDividedListDO& obj);
};

#endif // ! _PUR_COM_DAO_