#include "stdafx.h"
#include "SampleService.h"
#include "../../dao/sample/SampleDAO.h"

PageVO<SampleVO> SampleService::listAll(const SampleQuery& query)
{
	//构建返回对象
	PageVO<SampleVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());
	//查询数据总条数
	SampleDO obj;
	obj.setName(query.getName());
	obj.setSex(query.getSex());
	SampleDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<SampleDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());

	list<SampleVO> vr;
	for (SampleDO sub : result)
	{
		SampleVO vo;
		vo.setId(sub.getId());
		vo.setName(sub.getName());
		vo.setSex(sub.getSex());
		vo.setAge(sub.getAge());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

