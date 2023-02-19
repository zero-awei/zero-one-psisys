#include "stdafx.h"
#include "PyrkService.h"
#include"domain/do/Pyrk/QueryPyrkBillListDo.h"
//#include "../../dao/sample/SampleDAO.h"
PageVO<QueryPyrkBillListVO> PyrkService::queryAllFitBill(const QueryPyrkBillListQuery& query) {
	//构建返回对象
	PageVO<QueryPyrkBillListVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	QueryPyrkBillListDo obj; //这是查询数据库的条件  封装成类
	obj.setId(query.getId());
	obj.setBeginData(query.getBeginData());
	obj.setEndData(query.getEndData());
	obj.setTheme(query.getTheme());
	obj.setStage(query.getStage());
	obj.setIsClosed(query.getIsClosed());
	obj.setIsEffective(query.getIsEffective());
	obj.setIsVoided(query.getIsVoided());
	//SampleDAO dao;
	return pages;
}