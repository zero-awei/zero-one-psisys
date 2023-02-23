/*
 Copyright Zero One Star. All rights reserved.

 @Author: douhao
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
#include "../../../lib-common/include/SnowFlake.h"

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
	if (count <= 0 || query.getPageIndex() > count || query.getPageSize() < 1 || query.getPageIndex() < 1)
	{
		return pages;
	}

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<CurrencyDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<CurrencyVO> vr;
	for (CurrencyDO sub : result)
	{
		CurrencyVO vo;
		vo.setId(sub.getId());
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
	
	vr.setId(sub.getId());
	vr.setCode(sub.getCode());
	vr.setName(sub.getName());
	vr.setIsFunctional(sub.getIsFunctional());
	vr.setIsEnabled(sub.getIsEnabled());
	vr.setCreateBy(sub.getCreateBy());
	vr.setCreateTime(sub.getCreateTime());
	vr.setUpdateBy(sub.getUpdateBy());
	vr.setUpdateTime(sub.getUpdateTime());
	vr.setRemarks(sub.getRemarks());

	return vr;
}

uint64_t CurrencyService::saveData(const CurrencyDTO& dto, const PayloadDTO& payload)
{
	//组装数据
	CurrencyDO data;
	//使用雪花算法得到id
	SnowFlake sf(1, 2);
	uint64_t id = sf.nextId();
	//将id转为string格式
	//因为数据库中是string格式，为了后续操作方便
	string s_id;
	while (id)
	{
		s_id += '0' + id % 10;
		id /= 10;
	}
	reverse(s_id.begin(), s_id.end());

	//获得当前系统时间
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::stringstream ss;
	ss << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S");
	string str_time = ss.str();

	//组装DO对象数据
	data.setId(s_id);
	data.setCode(dto.getCode());
	data.setName(dto.getName());
	data.setIsFunctional(dto.getIsFunctional());
	data.setIsEnabled(dto.getIsEnabled());
	data.setCreateBy(payload.getUsername());
	data.setCreateTime(str_time);
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(str_time);
	//执行数据添加
	CurrencyDAO dao;
	return dao.insert(data);
}

bool CurrencyService::updateData(const CurrencyDTO& dto, const PayloadDTO& payload)
{
	//组装传输数据
	CurrencyDO data;
	
	//获得当前系统时间
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::stringstream ss;
	ss << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S");
	string str_time = ss.str();

	//组装传输数据
	data.setId(dto.getId());
	data.setCode(dto.getCode());
	data.setName(dto.getName());
	data.setIsFunctional(dto.getIsFunctional());
	data.setIsEnabled(dto.getIsEnabled());
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(str_time);

	//执行数据修改
	CurrencyDAO dao;
	return dao.update(data) == 1;
}

bool CurrencyService::removeData(string id)
{
	CurrencyDAO dao;
	return dao.deleteById(id) == 1;
}