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
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		// 剩下的属性
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

std::list<DepotVO> DepotService::getKid(const OnlyValueQuery& query)
{
	// 获取父级id
	DepotDO id;
	id.setPid(query.getId());
	// 获取子级仓库DO
	DepotDAO dao;
	std::list<DepotDO> result =  dao.selectKid(id);
	std::list<DepotVO> vr;
	for (DepotDO sub : result)
	{
		DepotVO vo;
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		// 剩下的属性
		vr.push_back(vo);
	}
	return vr;
}

int DepotService::saveData(const DepotDTO& dto)
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

int DepotService::modifyDepot(const DepotDTO& dto)
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
	//执行数据添加
	DepotDAO dao;
	return dao.update(data);
}

bool DepotService::saveFile(const std::list<DepotDTO>& dto)
{
	bool saveSucceed = true;
	for (auto d : dto) {
		saveSucceed = saveSucceed && saveData(d);
	}
	return saveSucceed;
}
