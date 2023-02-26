#include "stdafx.h"
#include "PrePayService.h"
#include "../../dao/prepayment/PrepaymentDAO.h"
#include "../../api/prepayment/PrePayController.h"




// 分页查询 预付申请单所有数据(多个对象)
PageVO<PrepaymentBillVO> PrePayService::listAll(const PrepayBillQuery& query)
{
	//构建返回对象
	PageVO<PrepaymentBillVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	PrepaymentDO obj;
	obj.setBill_no(query.getBill_no());
	obj.setBill_date(query.getBill_date());
	obj.setSubject(query.getSubject());
	obj.setSupplier_id(query.getSupplier_id());
	obj.setBill_stage(query.getBill_stage());
	obj.setIs_effective(query.getIs_effective());
	obj.setIs_closed(query.getIs_closed());
	obj.setIs_voided(query.getIs_voided());

	PrepaymentDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<PrepaymentDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<PrepaymentBillVO> vr;
	for (PrepaymentDO sub : result)
	{
		PrepaymentBillVO vo;
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setSubject(sub.getSubject());
		vo.setSupplier_id(sub.getSupplier_id());
		vo.setOp_dept(sub.getOp_dept());
		vo.setOperator(sub.getOperator());
		vo.setAmt(sub.getAmt());
		vo.setPaid_amt(sub.getPaid_amt());
		vo.setBill_stage(sub.getBill_stage());
		vo.setIs_effective(sub.getIs_effective());
		vo.setIs_closed(sub.getIs_closed());
		vo.setIs_voided(sub.getIs_voided());
		vo.setRemark(sub.getRemark());
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






 //查询指定单据详细信息-通过单据编号查询数据
PrepaymentDetailBillVO PrePayService::getAll(const PrepayDetailBillQuery& query) {
	// 构建返回对象
	PrepaymentDetailBillVO detail;

	// 领域模型转换
	PrepaymentDO obj;
	obj.setBill_no(query.getBill_no());
	PrepaymentEntryDO obj2;
	obj2.setEntry_bill_no(query.getBill_no());
	

	// 查询指定询价单数据
	PrepaymentDAO dao;
	list <PrepaymentDO> result=dao.selectByBill_no(obj);
	list<PrepaymentDetailBillVO> vr;
	for (PrepaymentDO sub : result)
	{
		PrepaymentBillVO detail;
		detail.setBill_no(sub.getBill_no());
		detail.setBill_date(sub.getBill_date());
		detail.setBill_stage(sub.getBill_stage());
		detail.setIs_effective(sub.getIs_effective());
		detail.setIs_closed(sub.getIs_closed());
		detail.setIs_voided(sub.getIs_voided());
		detail.setSubject(sub.getSubject());
		detail.setOp_dept(sub.getOp_dept());
		detail.setOperator(sub.getOperator());
		detail.setSupplier_id(sub.getSupplier_id());
		detail.setPaid_amt(sub.getPaid_amt());
	}

	
	// 查询明细列表
	list<PrepaymentEntryDO> details = dao.selectBillEntry(obj2.getEntry_bill_no());
	PrepaymentDetailEntryBillVO detailsvo;
	list<PrepaymentDetailEntryBillVO> lvo;
	for (PrepaymentEntryDO ones : details)
	{
		detailsvo.setRemark(ones.getRemark());
		detailsvo.setCustom1(ones.getCustom1());
		detailsvo.setCustom2(ones.getCustom2());
		lvo.push_back(detailsvo);
	}
	detail.setDetailsList(lvo);

	return detail;
}


// 通过ID删除数据
bool PrePayService::DePrePayId(const DePayDTO& dto)
{
	PrepaymentDAO dao;
	PrepaymentDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//执行数据修改
	if (dto.getId() != "" || dto.getBill_no() != "")
	{
		data.setId(dto.getId());
		return dao.deleteById(data) == 1;
	}
}
