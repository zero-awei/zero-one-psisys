/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/19 11:13:11

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
#include "BasMaterialService.h"
#include "../../dao/BasMaterial/BasMaterialDAO.h"
#include "../../domain/query/BasMaterial/BasMaterialDetailQuery.h"
#include "../../../lib-common/include/SnowFlake.h"

PageVO<BasMaterialVO> BasMaterialService::listAll(const BasMaterialQuery& query)
{
	//构建返回对象
	PageVO<BasMaterialVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	BasMaterialDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	obj.setCategoryId(query.getCategoryId());
	obj.setTaxCode(query.getTaxCode());
	BasMaterialDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<BasMaterialDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<BasMaterialVO> vr;
	for (BasMaterialDO sub : result)
	{
		BasMaterialVO vo;
		vo.setId(sub.getId());
		vo.setCategoryId(sub.getCategoryId());
		vo.setCode(sub.getCode());
		vo.setName(sub.getName());
		vo.setAuxName(sub.getAuxName());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setModel(sub.getModel());
		vo.setUnitId(sub.getUnitId());
		vo.setSalePrice(sub.getSalePrice());
		vo.setTaxCode(sub.getTaxCode());
		vo.setRemark(sub.getRemark());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}
BasMaterialVO BasMaterialService::getData(const BasMaterialDetailQuery& query) {

	BasMaterialDAO dao;
	list<BasMaterialDO> result = dao.selectById(query.getId());
	BasMaterialVO vr;
	if (result.size() == 0) return vr;
	BasMaterialDO sub = result.front();

	vr.setId(sub.getId());
	vr.setCategoryId(sub.getCategoryId());
	vr.setCode(sub.getCode());
	vr.setName(sub.getName());
	vr.setAuxName(sub.getAuxName());
	vr.setIsEnabled(sub.getIsEnabled());
	vr.setModel(sub.getModel());
	vr.setUnitId(sub.getUnitId());
	vr.setSalePrice(sub.getSalePrice());
	vr.setTaxCode(sub.getTaxCode());
	vr.setRemark(sub.getRemark());
	vr.setCreateTime(sub.getCreateTime());
	vr.setCreateBy(sub.getCreateBy());
	vr.setUpdateBy(sub.getUpdateBy());
	vr.setUpdateTime(sub.getUpdateTime());

	return vr;
}
uint64_t BasMaterialService::saveData(const BasMaterialDTO& dto, const PayloadDTO& payload)
{
	//组装数据
	BasMaterialDO data;
	SnowFlake sf(1, 2);
	uint64_t id = sf.nextId();

	data.setId(id);
	data.setCategoryId(dto.getCategoryId());
	data.setCode(dto.getCode());
	data.setName(dto.getName());
	data.setAuxName(dto.getAuxName());
	data.setIsEnabled(dto.getIsEnabled());
	data.setModel(dto.getModel());
	data.setUnitId(dto.getUnitId());
	data.setSalePrice(dto.getSalePrice());
	data.setTaxCode(dto.getTaxCode());
	data.setRemark(dto.getRemark());
	//cout <<1<< dto.getAuxName();没有输出？？
	//创建人 ，创建时间
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string time = to_string(ltm->tm_year + 1900) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
	string currentTime = time;
	data.setCreateTime(currentTime);
	data.setCreateBy(payload.getUsername());
	data.setUpdateBy("");
	data.setUpdateTime("");

	//执行数据添加
	BasMaterialDAO dao;
	return dao.insert(data);
}

bool BasMaterialService::updateData(const BasMaterialDTO& dto, const PayloadDTO& payload)
{
	//组装传输数据
	BasMaterialDO data;
	data.setId(dto.getId());
	data.setCategoryId(dto.getCategoryId());
	data.setCode(dto.getCode());
	data.setName(dto.getName());
	data.setAuxName(dto.getAuxName());
	data.setIsEnabled(dto.getIsEnabled());
	data.setModel(dto.getModel());
	data.setUnitId(dto.getUnitId());
	data.setSalePrice(dto.getSalePrice());
	data.setTaxCode(dto.getTaxCode());
	data.setRemark(dto.getRemark());
	//data.setCreateTime(dto.getCreateTime());
	//data.setCreateBy(dto.getCreateBy());
	//修改时间，修改人
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string time = to_string(ltm->tm_year + 1900) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
	string currentTime = time;
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(currentTime);
	//执行数据修改
	BasMaterialDAO dao;
	return dao.update(data) == 1;
}

bool BasMaterialService::removeData(uint64_t  id)
{
	BasMaterialDAO dao;
	return dao.deleteById(id) == 1;
}
