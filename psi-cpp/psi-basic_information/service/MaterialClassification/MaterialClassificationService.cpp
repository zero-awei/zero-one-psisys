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
#include<ctime>
#include<stack>
//可能vo不需要分父类子类


PageVO<MaterialClassificationBaseVO> MaterialClassificationService::listAll(const MaterialClassificationQuery& query)
{
	//构建返回对象
	PageVO<MaterialClassificationBaseVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	MaterialClassificationDO obj;
	MaterialClassificationDAO dao;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	//如果名字和编码均为空，则显示所有物料分类根节点

	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	//分页查询数据 
	pages.setTotal(count);
	pages.calcPages();

	
	if (query.getCode() != "" || query.getName() != "") {//判断是不是子级，是则寻找根节点
		list<MaterialClassificationDO> father;
		if (query.getCode() != "") 
			father = dao.selectByCode(query.getCode());
		else if (query.getName() != "")
			father = dao.selectByName(query.getName());
		MaterialClassificationDO f;
		for (MaterialClassificationDO sub : father) {
			f.setId(sub.getId());
			f.setPid(sub.getPid());
		}	
		//输入的是子类的编码或者名称时，循环寻找根节点
			while (f.getPid() != "0") {
				father = dao.selectById(f.getPid());
				for (MaterialClassificationDO sub : father) {
					f.setId(sub.getId());
					f.setPid(sub.getPid());
				}
			}
			//找到根节点
			list<MaterialClassificationBaseVO> vr;
			for (MaterialClassificationDO sub : father)
			{
				MaterialClassificationBaseVO vo;
				vo.setId(sub.getId());
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
	else if (query.getCode() == "" && query.getName() == "") {//全空显示全部根节点

		list<MaterialClassificationDO> result = dao.selectWithPage( "0",query.getPageIndex(), query.getPageSize());
		list<MaterialClassificationBaseVO> vr;
		for (MaterialClassificationDO sub : result)
		{
			MaterialClassificationBaseVO vo;
			vo.setId(sub.getId());
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
		vo.setId(sub.getId());
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
		vo.setId(sub.getId());
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

int MaterialClassificationService::saveData(const MaterialClassificationDTO& dto, const PayloadDTO& payload)
{
	//新增数据应该不用管修改相关的信息

	//组装数据
	MaterialClassificationDO data;
	//应该是在这里生成id
	SnowFlake sf(1, 2);
	data.setId(to_string(sf.nextId()));

	//添加下级的时候要获得pid，如果pid的父类一开始没有下级，则还要修改父类的has_child
	data.setPid(dto.getPid()==""? "0":dto.getPid());
	data.setHasChild(dto.getHasChild()==""? "0":dto.getHasChild());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setFullname(dto.getFullname());
	data.setIsEnabled(dto.getIsEnabled());
	data.setCreateBy(payload.getUsername());

	//设置时间
	time_t nowtime;
	time(&nowtime); //获取1900年1月1日0点0分0秒到现在经过的秒数
	tm p;
	localtime_s(&p,&nowtime); //将秒数转换为本地时间,年从1900算起,需要+1900,月为0-11,所以要+1
	//printf("%04d:%02d:%02d %02d:%02d:%02d\n", p.tm_year + 1900, p.tm_mon + 1, p.tm_mday,p.tm_hour,p.tm_min,p.tm_sec);
	string nowTime = to_string(p.tm_year+1900) + "-" +to_string(p.tm_mon+1)+"-"+to_string(p.tm_mday) + " " + to_string(p.tm_hour)+":"+to_string(p.tm_min) +":"+to_string(p.tm_sec);

	data.setCreateTime(nowTime);
	data.setVersion(dto.getVersion());
	//执行数据添加
	MaterialClassificationDAO dao;

	int modify = 1;
	if (dto.getPid() != "") {//有父节点
		list<MaterialClassificationDO> father = dao.selectById(dto.getPid());
		MaterialClassificationDO f;
		for (MaterialClassificationDO sub : father) {
			f.setHasChild(sub.getHasChild());
		}
		if (f.getHasChild() == "0")
			modify = dao.updateById(dto.getPid(), "1");//通过id修改父节点的has_child
	}

	return (modify * dao.insert(data))==1;
}

int MaterialClassificationService::updateData(const MaterialClassificationDTO& dto, const PayloadDTO& payload)
{

	//修改数据要先拿到id,修改数据应该不用管创建相关的信息

	//组装传输数据
	MaterialClassificationDO data;
	data.setId(dto.getId());
	data.setPid(dto.getPid());
	data.setHasChild(dto.getHasChild());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setFullname(dto.getFullname());
	data.setIsEnabled(dto.getIsEnabled());

	time_t nowtime;
	time(&nowtime); //获取1900年1月1日0点0分0秒到现在经过的秒数
	tm p;
	localtime_s(&p, &nowtime); //将秒数转换为本地时间,年从1900算起,需要+1900,月为0-11,所以要+1
	string nowTime = to_string(p.tm_year + 1900) + "-" + to_string(p.tm_mon + 1) + "-" + to_string(p.tm_mday) + " " + to_string(p.tm_hour) + ":" + to_string(p.tm_min) + ":" + to_string(p.tm_sec);

	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(nowTime);
	data.setVersion(dto.getVersion());
	//执行数据修改
	MaterialClassificationDAO dao;
	return dao.update(data) == 1;
}

//删除子级节点的函数
void removeNode(const MaterialClassificationDO& nodeChild) {
	MaterialClassificationDAO dao;
	if (nodeChild.getHasChild() == "0") {
		dao.deleteById(nodeChild.getId());
		return;
	}
	list<MaterialClassificationDO> children = dao.selectByPid(nodeChild.getId());
	for (MaterialClassificationDO node : children) {
		removeNode(node);
	}
	return;
}


int MaterialClassificationService::removeData(const MaterialClassificationDTO& dto)
{
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> c = dao.selectById(dto.getId());//当前节点的所有子级
	
	int d = 1;
	for (MaterialClassificationDO node : c) {
		if (node.getHasChild() == "1") {//如果有子级节点则删除
			removeNode(node);
		}
	}
	d = dao.deleteByPid(dto.getId());
	return (d*dao.deleteById(dto.getId())) == 1;
}
