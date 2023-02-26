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
#include "DepotService.h"
#include "../../../lib-common/include/SnowFlake.h"

const int datacenterId = 1;
const int machineId = 2;

PageVO<DepotVO> DepotService::listAll(const DepotQuery& query)
{
	//构建返回对象
	PageVO<DepotVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	DepotDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	DepotDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<DepotDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<DepotVO> vr;
	for (DepotDO sub : result)
	{
		DepotVO vo;
		vo.setId(sub.getId());
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setAuxName(sub.getAuxName());
		vo.setPhone(sub.getPhone());
		vo.setStart(to_string(sub.getStart()));
		vo.setRemarks(sub.getRemarks());
		vo.setCreationPeo(sub.getCreationPeo());
		vo.setCreationTime(sub.getCreationTime());
		vo.setModiPeo(sub.getModiPeo());
		vo.setModiTime(sub.getModiTime());
		// 剩下的属性
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

bool DepotService::getData(const DepotQuery& query, vector<vector<string>>& data)
{
	//查询数据总条数
	DepotDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	DepotDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return false;
	}

	//不分页查询数据
	list<DepotDO> result = dao.selectWithPage(obj, 0, 0);
	for (DepotDO sub : result)
	{
		vector<string> row;
		row.emplace_back(sub.getName());
		row.emplace_back(sub.getCode());
		row.emplace_back(sub.getAuxName());
		row.emplace_back(to_string(sub.getPhone()));
		row.emplace_back(to_string(sub.getStart()));
		row.emplace_back(sub.getRemarks());
		row.emplace_back(sub.getCreationPeo());
		row.emplace_back(sub.getCreationTime());
		row.emplace_back(sub.getModiPeo());
		row.emplace_back(sub.getModiTime());
		// 剩下的属性
		data.emplace_back(row);
	}
	return true;
}

bool DepotService::getDataById(const OnlyValueQuery& query, vector<vector<string>>& data)
{
	//查询数据总条数
	DepotDAO dao;
	// 分割ID
	string str = query.getId(), delimiters = " |";
	vector<string>Ids;
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	string::size_type pos = str.find_first_of(delimiters, lastPos);
	while (string::npos != pos || string::npos != lastPos)
	{
		Ids.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}
	//查询数据
	for(auto id:Ids){
		DepotDO obj;
		obj.setId(id);
		list<DepotDO> result = dao.getDataById(obj);
		DepotDO sub = result.front();
		vector<string> row;
		row.emplace_back(sub.getName());
		row.emplace_back(sub.getCode());
		row.emplace_back(sub.getAuxName());
		row.emplace_back(to_string(sub.getPhone()));
		row.emplace_back(to_string(sub.getStart()));
		row.emplace_back(sub.getRemarks());
		row.emplace_back(sub.getCreationPeo());
		row.emplace_back(sub.getCreationTime());
		row.emplace_back(sub.getModiPeo());
		row.emplace_back(sub.getModiTime());
		// 剩下的属性
		data.emplace_back(row);
	}
	return true;
}

int DepotService::saveData(const DepotDTO& dto, const string Username)
{
	//组装数据
	DepotDO data;
	SnowFlake sf(datacenterId, machineId);
	data.setId(to_string(sf.nextId()));
	// 如果pid不为空，还要修改父级的has_child
	data.setPid(dto.getPid().empty() ? "0" : dto.getPid());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setAuxName(dto.getAuxName());
	data.setPhone(dto.getPhone());
	data.setStart(dto.getStart());
	data.setCreationPeo(Username);
	data.setCreationTime(gettime());
	//执行数据添加
	DepotDAO dao;
	return dao.insertDepot(data);
}

bool DepotService::removeData(const OnlyValueQuery& query)
{
	DepotDO id;
	id.setId(query.getId());
	DepotDAO dao;
	return dao.deleteDepot(id);
}

int DepotService::modifyDepot(const DepotDTO& dto, const string Username)
{
	//组装数据
	DepotDO data;
	data.setId(dto.getId());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setAuxName(dto.getAuxName());
	data.setPhone(dto.getPhone());
	data.setStart(dto.getStart());
	data.setRemarks(dto.getRemarks());
	data.setModiPeo(Username);
	data.setModiTime(gettime());
	//执行数据添加
	DepotDAO dao;
	return dao.update(data);
}

string DepotService::gettime()
{
	time_t timep;
	time(&timep);
	char tmp[256];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	return tmp;
}
