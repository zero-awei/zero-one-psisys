#include"stdafx.h"
#include "areaService.h"
#include "../../dao/publicInterfaceDao/areaDAO.h"


std::list<AreaVO> AreaService::listAll(const AreaQuery& query)
{
	//构建返回对象
	list<AreaVO> vr;
	//构建查询对象
	AreaQueryDO obj;
	obj.setAreaName(query.getAreaName());
	obj.setType(query.getType());
	//定义dao层
	AreaDAO dao;
	list<AreaReturnDO> result  = dao.selectArea(obj);
	for (AreaReturnDO sub : result)
	{
		AreaVO vo;
		vo.setName(sub.getAreaName());
		vr.push_back(vo);
	}
	return vr;
}
