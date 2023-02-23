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
	
	//设置查询条件
	PurQuotDO obj;
	obj.setBill_no(query.getBill_no());
	//日期存疑,暂时不搞
	obj.setSubject(query.getSubject());
	obj.setBill_stage(query.getBill_stage());
	obj.setIs_effective(query.getIs_effective());
	obj.setIs_closed(query.getIs_closed());
	obj.setIs_voided(query.getIs_voided());
	
	//检查查询到的数据总数
	PurQuotDAO dao;
	uint64_t count = dao.count(obj);
	//数据总数小于等于0, 直接返回pages
	if (count <= 0)
	{
		return pages;
	}
	//数据总数大于0, 返回分页查询到的VO
	pages.setTotal(count);
	pages.calcPages();
	//接收查询到的DO
	list<PurQuotDO> result = dao.selectPurQuotFindBill(obj, query.getPageIndex(), query.getPageSize());
	//vr是接收DO的VO对象
	list<PurQuotFindBillVO> vr; 
	for (PurQuotDO sub : result) {
		PurQuotFindBillVO vo;
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setSubject(sub.getSrc_no());
		vo.setSupplier_id(sub.getSupplier_id());
		vo.setSupplier_name(sub.getSupplier_name());
		vo.setDelivery_time(sub.getDelivery_time());
		vo.setQty(sub.getQty());
		vo.setAmt(sub.getAmt());
		vo.setBill_stage(sub.getBill_stage());
		vo.setIs_effective(sub.getIs_effective());
		vo.setIs_closed(sub.getIs_closed());
		vo.setIs_voided(sub.getIs_voided());
		vo.setPayment_method(sub.getPayment_method());
		vo.setDelivery_place(sub.getDelivery_place());
		vo.setContact(sub.getContact());
		vo.setPhone(sub.getPhone());
		vo.setFax(sub.getFax());
		vo.setEmail(sub.getEmail());
		vo.setRemark(sub.getRemark());
		vo.setIs_auto(sub.getIs_auto());
		vo.setIs_rubric(sub.getIs_rubric());
		vo.setEffective_time(sub.getEffective_time());
		vo.setApprover(sub.getApprover());
		vo.setCreate_time(sub.getCreate_time());
		vo.setCreate_by(sub.getCreate_by());
		vo.setSys_org_code(sub.getSys_org_code());
		vo.setUpdate_time(sub.getUpdate_time());
		vo.setUpdate_by(sub.getUpdate_by());
		vr.push_back(vo);
	}	
	pages.setRows(vr);
	return pages;
}






