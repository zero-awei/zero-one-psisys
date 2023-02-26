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
#include "../../dao/PurCom/PurComDAO.h"

// 分页查询所有数据
PageVO<PurComVO> PurComService::listAll(const PurComQuery& query)
{
	// 构建返回对象
	PageVO<PurComVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	// 构造DO
	PurComDO obj;
	obj.setBill_no(query.getBill_no());
	obj.setBill_date(query.getBill_date());
	obj.setSubject(query.getSubject());
	obj.setIs_effective(query.getIs_effective());
	obj.setIs_closed(query.getIs_closed());
	obj.setIs_voided(query.getIs_voided());
	
	// 生成DAO层对象
	PurComDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	// 调用DAO层功能,传入DO
	pages.setTotal(count);
	pages.calcPages();
	list<PurComDO> result = dao.selectPurCom(obj, query.getPageIndex(), query.getPageSize());
	list<PurComVO> vr;		//分页查询返回的VO列表
	// 根据DAO层返回的DO，对VO成员进行赋值
	for (PurComDO sub : result)
	{
		// 构造用于返回的VO
		PurComVO vo;
		
	}
	// 返回VO
	return pages;
}

// 查询单个数据
PurComVO PurComService::getData(uint64_t id) {
	PurComVO data;

	return data;
}