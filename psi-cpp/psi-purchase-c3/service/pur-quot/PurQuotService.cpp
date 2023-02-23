#include "stdafx.h"
#include "PurQuotService.h"
#include "../../dao/pur-quot/PurQuotDAO.h"
#include <list>

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

//获取多个PurQuotList对象
list<PurQuotListVO> PurQuotService::listPurQuotListVO(const PurQuotListQuery& query) {
	//设置查询条件
	PurQuotEntryDO obj;
	obj.setBill_no(query.getBill_no());

	//接收查询到的DO
	PurQuotDAO dao;
	list<PurQuotEntryDO> result = dao.selectPurQuotList(obj);
	//构建返回对象
	list<PurQuotListVO> vr;
	for (PurQuotEntryDO sub : result) {
		PurQuotListVO vo;
		vo.setSrc_no(sub.getSrc_no());
		vo.setMaterial_id(sub.getMaterial_id());
		vo.setUnit_id(sub.getUnit_id());
		vo.setQty(sub.getQty());
		vo.setTax_rate(sub.getTax_rate());
		vo.setPrice(sub.getPrice());
		vo.setDiscount_rate(sub.getDiscount_rate());
		vo.setAmt(sub.getAmt());
		vo.setRemark(sub.getRemark());
		vo.setCustom1(sub.getCustom1());
		vo.setCustom2(sub.getCustom2());
		vr.push_back(vo);
	}
	return vr;
}

//获取多个PurQuotDividedListVO对象
list<PurQuotDividedListVO> PurQuotService::listPurQuotDividedListVO(const PurQuotDividedListQuery& query) {

	//设置查询条件
	PurQuotEntryDO obj;
	obj.setBill_no(query.getBill_no());

	//接收查询到的DO
	PurQuotDAO dao;
	list<PurQuotEntryDO> result = dao.selectPurQuotDividedList(obj);

	//构建返回对象vo
	list<PurQuotDividedListVO> vr;
	for (PurQuotEntryDO sub : result) {
		PurQuotDividedListVO vo;
		vo.setBill_no(sub.getBill_no());
		vo.setMaterial_id(sub.getMaterial_id());
		vo.setUnit_id(sub.getUnit_id());
		vo.setQty(sub.getQty());
		vo.setTax_rate(sub.getTax_rate());
		vo.setPrice(sub.getPrice());
		vo.setAmt(sub.getAmt());
		vo.setRemark(sub.getRemark());
		vo.setCustom1(sub.getCustom1());
		vo.setCustom2(sub.getCustom2());
		vr.push_back(vo);
	}
	return vr;
}

//获取一个PurQuotFindDetailBillVO对象
PurQuotFindDetailBillVO PurQuotService::getPurQuotFindDetailBillVO(const PurQuotFindDetailBillQuery& query) {

//----------对于BaseVO
	//设置查询条件
	PurQuotDO obj;
	obj.setBill_no(query.getBill_no());

	//接收查询到的DO
	PurQuotDAO dao;
	list<PurQuotDO> result = dao.selectPurQuotBase(obj); //一个Base对象
	
	PurQuotBaseVO vo;
	if (!result.empty()) {
		auto sub = result.front();
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setBill_stage(sub.getBill_stage());
		vo.setIs_effective(sub.getIs_effective());
		vo.setIs_closed(sub.getIs_closed());
		vo.setIs_voided(sub.getIs_voided());
		vo.setSubject(sub.getSubject());
		vo.setIs_temp_supplier(sub.getIs_temp_supplier());
		vo.setSupplier_id(sub.getSupplier_id());
		vo.setSupplier_name(sub.getSupplier_name());
		vo.setPayment_method(sub.getPayment_method());
		vo.setDelivery_time(sub.getDelivery_time());
		vo.setDelivery_place(sub.getDelivery_place());
		vo.setContact(sub.getContact());
		vo.setPhone(sub.getPhone());
		vo.setFax(sub.getFax());
		vo.setEmail(sub.getEmail());
		vo.setRemark(sub.getRemark());
		vo.setApproval_remark(sub.getApproval_remark());
		vo.setAttachment(sub.getAttachment());
		vo.setApproval_result_type(sub.getApproval_result_type());
		vo.setEffective_time(sub.getEffective_time());
		vo.setApprover(sub.getApprover());
		vo.setBpmi_instance_id(sub.getBpmi_instance_id());
		vo.setSys_org_code(sub.getSys_org_code());
		vo.setCreate_by(sub.getCreate_by());
		vo.setUpdate_time(sub.getUpdate_time());
		vo.setUpdate_by(sub.getUpdate_by());
		vo.setIs_auto(sub.getIs_auto());
		vo.setIs_rubric(sub.getIs_rubric());
		vo.setSrc_bill_type(sub.getSrc_bill_type());
	}



//---------对于DetailVO
	PurQuotEntryDO entry_obj;
	entry_obj.setBill_no(query.getBill_no());
	list<PurQuotEntryDO> entry_result = dao.selectPurQuotDetail(entry_obj); //多个Base对象
	PurQuotDetailVO entry_vo;

	
	
	//构建返回对象
	PurQuotFindDetailBillVO vr;
	


}

