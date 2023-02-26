#include "stdafx.h"
#include "CgthrkService.h"
#include"domain/do/Cgthck/QueryCgthrkBillListDO.h"
#include"../../dao/Cgthrk/CgthrkDao.h"

PageVO<QueryCgthckBillVO> CgthrkService::queryAllFitBill(const QueryCgthckBillQuery& query) {
	//构建返回对象
	PageVO<QueryCgthckBillVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	QueryCgthrkBillListDO obj; //这是查询数据库的条件  封装成类
	obj.setId(query.getBillNo());
	obj.setBeginData(query.getBeginData());
	obj.setEndData(query.getEndData());
	obj.setTheme(query.getSubject());
	obj.setStage(query.getBillStage());
	obj.setIsClosed(query.getIsClosed());
	obj.setIsEffective(query.getIsEff());
	obj.setIsVoided(query.getIsVoided());
	//SampleDAO dao;
	CgthrkDao dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<QueryCgthrkBillListReturnDO> result = dao.selectCgthckBillList(obj, query.getPageIndex(), query.getPageSize());
	list<QueryCgthckBillVO> vr;
	for (QueryCgthrkBillListReturnDO sub : result)
	{
		QueryCgthckBillVO vo;
		vo.setBillNo(sub.getBillNo());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}