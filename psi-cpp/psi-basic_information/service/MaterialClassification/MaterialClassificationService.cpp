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
#include "MaterialClassificationService.h"
#include "../../dao/MaterialClassification/MaterialClassificationDAO.h"


//可能vo不需要分父类子类


PageVO<MaterialClassificationBaseVO> MaterialClassificationService::listAll(const MaterialClassificationQuery& query)
{
	//构建返回对象
	PageVO<MaterialClassificationBaseVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	MaterialClassificationDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	MaterialClassificationDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据 #可能还要弄个不分页的，或者弄子类列表
	pages.setTotal(count);
	pages.calcPages();
	list<MaterialClassificationDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<MaterialClassificationBaseVO> vr;
	for (MaterialClassificationDO sub : result)
	{
		MaterialClassificationBaseVO vo;
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setFullname(sub.getFullname());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());

		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

//查询子类列表
list<MaterialClassificationChildVO> MaterialClassificationService::listChildren(const MaterialClassificationQuery& query) {
	MaterialClassificationDO obj;
	obj.setCode(query.getCode());//父类编码
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> father = dao.selectByCode(obj.getCode());//返回的是list
	MaterialClassificationDO f;
	for (MaterialClassificationDO sub : father) {
		f.setId(sub.getId());
	}
	list<MaterialClassificationDO> result = dao.selectByPid(f.getId());
	list<MaterialClassificationChildVO> vr;
	for (MaterialClassificationDO sub : result)
	{
		MaterialClassificationChildVO vo;
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setFullname(sub.getFullname());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());

		vr.push_back(vo);

	}

	return vr;

}


list<MaterialClassificationDetailVO> MaterialClassificationService::listDetail(const MaterialClassificationQuery& query) {
	MaterialClassificationDO obj;
	obj.setCode(query.getCode());
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> result = dao.selectByCode(obj.getCode());
	list<MaterialClassificationDetailVO> vr;
	for (MaterialClassificationDO sub : result)
	{
		MaterialClassificationDetailVO vo;
		vo.setPid(sub.getPid());
		vo.setHasChild(sub.getHasChild());
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setFullname(sub.getFullname());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());

		vr.push_back(vo);
	}

	return  vr;
}

int MaterialClassificationService::saveData(const MaterialClassificationDTO& dto)
{
	//组装数据
	MaterialClassificationDO data;
	//应该是在这里生成id
	SnowFlake sf(1, 2);
	data.setId(to_string(sf.nextId()));

	//添加下级的时候要获得pid，如果父类一开始没有下级，则还要修改父类的has_child,可能要另外写一个添加子类的接口
	data.setPid(dto.getPid()==""? "0":dto.getPid());
	data.setHasChild(dto.getHasChild()==""? "0":dto.getHasChild());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setFullname(dto.getFullname());
	data.setIsEnabled(dto.getIsEnabled());
	data.setCreateBy(dto.getCreateBy());
	data.setCreateTime(dto.getCreateTime());
	data.setUpdateBy(dto.getUpdateBy());
	data.setUpdateTime(dto.getUpdateTime());
	data.setVersion(dto.getVersion());
	//执行数据添加
	MaterialClassificationDAO dao;
	return dao.insert(data);
}

int MaterialClassificationService::updateData(const MaterialClassificationDTO& dto)
{

	//修改数据要先拿到id

	//组装传输数据
	MaterialClassificationDO data;
	data.setId(dto.getId());
	data.setPid(dto.getPid());
	data.setHasChild(dto.getHasChild());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setFullname(dto.getFullname());
	data.setIsEnabled(dto.getIsEnabled());
	data.setCreateBy(dto.getCreateBy());
	data.setCreateTime(dto.getCreateTime());
	data.setUpdateBy(dto.getUpdateBy());
	data.setUpdateTime(dto.getUpdateTime());
	data.setVersion(dto.getVersion());
	//执行数据修改
	MaterialClassificationDAO dao;
	return dao.update(data) == 1;
}

int MaterialClassificationService::removeData(string id)
{
	MaterialClassificationDAO dao;
	return dao.deleteById(id) == 1;
}
