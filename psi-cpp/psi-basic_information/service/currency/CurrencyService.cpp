/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "CurrencyService.h"
#include "../../dao/currency/CurrencyDAO.h"

PageVO<CurrencyVO> CurrencyService::listAll(const CurrencyQuery& query)
{
	//构建返回对象
	PageVO<CurrencyVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	CurrencyDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	CurrencyDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	cout << count << endl;

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<CurrencyDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<CurrencyVO> vr;
	for (CurrencyDO sub : result)
	{
		cout << sub.getCode() << endl;
		CurrencyVO vo;
		vo.setCode(sub.getCode());
		vo.setName(sub.getName());
		vo.setIsFunctional(sub.getIsFunctional());
		vo.setIsEnabled(sub.getIsEnabled());
		
		vo.setCreateBy(sub.getCreateBy());
		vo.setCreateTime(sub.getCreateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setRemarks(sub.getRemarks());

		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}
CurrencyVO CurrencyService::listByName(const OnlyValueCurrencyQuery& query)
{
	CurrencyDAO dao;
	list<CurrencyDO> result = dao.selectByName(query.getName());
	CurrencyVO vr;
	if (result.size() == 0) return vr;
	CurrencyDO sub = result.front();
	

	//cout << sub.getId() << endl;
	vr.setCode(sub.getCode());
	vr.setName(sub.getName());
	vr.setIsFunctional(sub.getIsFunctional());
	vr.setIsEnabled(sub.getIsEnabled());
	vr.setCreateBy(sub.getCreateBy());
	vr.setCreateTime(sub.getCreateTime());
	vr.setUpdateBy(sub.getUpdateBy());
	vr.setUpdateTime(sub.getUpdateTime());
	vr.setRemarks(sub.getRemarks());
	//pages.setRows(vr);
	return vr;
}