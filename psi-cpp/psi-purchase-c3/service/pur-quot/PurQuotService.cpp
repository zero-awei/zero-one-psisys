#include "stdafx.h"
#include "PurQuotService.h"
#include "../../dao/pur-quot/PurQuotDAO.h"

//获取多个PurQuotFindBillVO对象
PageVO<PurQuotFindBillVO> PurQuotService::listPurQuotFindBillVO(const PurQuotFindBillQuery& query) {
	//构建返回对象
	PageVO<PurQuotFindBillVO> pages;
	//设置返回对象的Index和Size 
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());
	
	////查询数据总条数
	//PurQuotDO obj;
	//obj.setBill_no(query.getBill_no());
	////日期存疑,暂时不搞
	//obj.setSubject(query.getSubject());
	//obj.setBill_stage(query.getBill_stage());
	//obj.setIs_effective(query.getIs_effective());
	//obj.setIs_closed(query.getIs_closed());
	//obj.setIs_voided(query.getIs_voided());
	//PurQuotDAO dao;
	//dao.selectPurQuotFindBillDO();

}

//PurQuotFindBillDO obj;
//obj.setBill_no(query.getBill_no());
//obj.setBill_date(query.getBill_no());
//
//PurQuotDAO dao;
//uint64_t count = dao.count(obj);
//if (count <= 0)
//{
//	return pages;
//}
////分页查询数据
//pages.setTotal(count);
//pages.calcPages();
//list<PurQuotFindBillDO> result = dao.selectPurQuotFindBillDO(obj, query.getPageIndex(), query.getPageSize());
//list<PurQuotFindBillVO> vr;
//for (PurQuotFindBillDO sub : result)
//{
//	PurQuotFindBillVO vo;
//	vo.setBill_no(sub.getBill_no());
//	vo.setBill_date(sub.getBill_date());
//	vo.setSubject(sub.getSubject());
//	vr.push_back(vo);
//}
//pages.setRows(vr);
//return pages;