#include "stdafx.h"
#include "DepartNameService.h"
#include "../../dao/public-interface/DepartNameDAO.h"


std::list<DepartVO> DepartNameService::listAll(const DepartNameQuery& query)
{
	//构建返回对象
	list<DepartVO> rs;
	//构建查询对象
	DepartQueryDO obj;
	obj.setDepartName(query.getDepartName());
	obj.setId(query.getId());

	//定义dao层对象
	DepartNameDAO dao;
	list<DepartReturnDO> result = dao.selectDepartName(obj);
	for (DepartReturnDO sub : result)
	{
		DepartVO vo;
		vo.setDepartName(sub.getDepartName());
		vo.setId(sub.getId());
		rs.push_back(vo);
	}
	return rs;
}
