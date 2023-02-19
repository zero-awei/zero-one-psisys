#include"stdafx.h"
#include "AreaService.h"
#include "../../dao/publicInterfaceDAO/AreaDAO.h"


std::list<AreaVO> AreaService::listAll(const AreaQuery& query)
{
	//构建返回对象
	list<AreaVO>rs;
	//构建查询对象
	AreaQueryDO obj;
	obj.setAreaName(query.getAreaName());
	obj.setType(query.getType());
	//定义dao层
	AreaDAO dao;
	list<AreaReturnDO> result  = dao.selectArea(obj);
	list<AreaVO> vr;
	for (AreaReturnDO sub : result)
	{
		AreaVO vo;
		vo.setName(sub.getAreaName());
		vr.push_back(vo);
	}
	return vr;
}
