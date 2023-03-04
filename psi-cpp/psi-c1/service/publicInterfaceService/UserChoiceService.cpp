#include "stdafx.h"
#include "UserChoiceService.h"
#include "../../domain/do/publicInterfaceDO/UserChoiceQueryDO.h"
#include "../../dao/publicInterfaceDao/UserChoiceDAO.h"
#include "../../domain/vo/publicInterfaceVO/UserVO.h"

PageVO<UserVO> UserChoiceService::listAll(const UserQuery& query)
{
	//构建返回对象
	PageVO<UserVO> rs;
	rs.setPageIndex(query.getPageIndex());
	rs.setPageSize(query.getPageSize());

	UserChoiceQueryDO obj;
	obj.setUserName(query.getUserName());

	UserChoiceDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return rs;
	}

	//分页查询数据
	rs.setTotal(count);
	rs.calcPages();
	list<UserChoiceReturnDO> result = dao.selecUserWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<UserVO> vr;
	for (UserChoiceReturnDO sub : result)
	{
		UserVO vo;
		vo.setId(sub.getId());
		vo.setUserName(sub.getUserName());
		vo.setRealName(sub.getRealName());
		vo.setSex(sub.getSex());
		vo.setPhone(sub.getPhone());
		vo.setDepartMent(sub.getDepartMent());
		vr.push_back(vo);
	}
	rs.setRows(vr);
	return rs;
}
