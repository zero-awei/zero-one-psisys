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

uint64_t BasMaterialService::saveData(const BasMaterialDTO& dto)
{
	//组装数据
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
	data.setCreateTime(dto.getCreateTime());
	data.setCreateBy(dto.getCreateBy());
	data.setUpdateBy(dto.getUpdateBy());
	data.setUpdateTime(dto.getUpdateTime());
	//执行数据添加
	BasMaterialDAO dao;
	return dao.insert(data);
}

bool BasMaterialService::updateData(const BasMaterialDTO& dto)
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
	data.setCreateTime(dto.getCreateTime());
	data.setCreateBy(dto.getCreateBy());
	data.setUpdateBy(dto.getUpdateBy());
	data.setUpdateTime(dto.getUpdateTime());
	//执行数据修改
	BasMaterialDAO dao;
	return dao.update(data) == 1;
}

bool BasMaterialService::removeData(string code)
{
	BasMaterialDAO dao;
	return dao.deleteByCode(code) == 1;
}
