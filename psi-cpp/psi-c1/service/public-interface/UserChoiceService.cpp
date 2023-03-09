#include "stdafx.h"
#include "UserChoiceService.h"
#include "../../domain/do/public-interface/UserChoiceQueryDO.h"
#include "../../dao/public-interface/UserChoiceDAO.h"
#include "../../domain/vo/public-interface/UserVO.h"

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
	vector<UserChoiceReturnDO> r(result.begin(), result.end());
	uint64_t time = query.getPageSize();
	//根据pageindx和pagesize放入返回的元素
	for (size_t i = (size_t)((query.getPageIndex() - 1) * query.getPageSize()); time > 0 && r.size() > i; i++, time--)
	{
		UserVO vo;
		vo.setId(r[i].getId());
		vo.setUserName(r[i].getUserName());
		vo.setRealName(r[i].getRealName());
		vo.setSex(r[i].getSex());
		vo.setPhone(r[i].getPhone());
		vo.setDepartMent(r[i].getDepartMent());
		vr.push_back(vo);
	}
	rs.setRows(vr);
	return rs;
}
