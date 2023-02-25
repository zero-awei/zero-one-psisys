
#include "stdafx.h"
#include "PurInquiryService.h"
#include "../../dao/pur-inquiry/PurInquiryDAO.h"
#include "../../domain/do/pur-inquiry/AddPurInquiryDO.h"
#include "../../domain/do/pur-inquiry/AddPurInquiryEntryDO.h"

uint64_t PurInquiryService::saveData(const AddPurInquiryDTO& dto)
{
	PurInquiryDAO dao;
	AddPurInquiryDO data;
	data.setBill_Date(dto.getBill_Date());
	data.setBill_no(dto.getBill_no());
	data.setBill_stage(dto.getBill_stage());
	data.setContact(dto.getContact());
	data.setCreate_time(dto.getCreate_time());
	data.setDelivery_place(dto.getDelivery_place());
	data.setEffective_time(dto.getEffective_time());
	data.setEmail(dto.getEmail());
	data.setFax(dto.getFax());
	data.setId(dto.getId());
	data.setIs_auto(dto.getIs_auto());
	data.setIs_rubric(dto.getIs_rubric());
	data.setPayment_method(dto.getPayment_method());
	data.setPhone(dto.getPhone());
	data.setRemark(dto.getRemark());
	data.setSubject(dto.getSubject());
	data.setUpdate_by(dto.getUpdate_by());

	AddPurInquiryEntryDO datas;
	int size = dto.getDetail().size();
	uint64_t result = -1;
	if (size != 0)
	{
		for (AddPurInquiryEntryDTO& it : dto.getDetail())
		{
			datas.setBill_no(it.getBill_no());
			datas.setEntry_no(it.getEntry_no());
			datas.setMid(it.getMid());
			datas.setAmt(it.getAmt());
			datas.setCustom1(it.getCustom1());
			datas.setCustom2(it.getCustom2());
			datas.setId(it.getId());
			datas.setMaterial_id(it.getMaterial_id());
			datas.setPrice(it.getPrice());
			datas.setQty(it.getQty());
			datas.setRemark(it.getRemark());
			datas.setSrc_bill_type(it.getSrc_bill_type());
			datas.setSrc_no(it.getSrc_no());
			datas.setTax_rate(it.getTax_rate());
			datas.setUnit_id(it.getUnit_id());

			result = dao.insertByEntry(datas);
		}
	}
	return dao.insert(data);
}


bool PurInquiryService::updateData(const AddPurInquiryDTO& dto)
{
	PurInquiryDAO dao;
	AddPurInquiryDO data;

	data.setBill_Date(dto.getBill_Date());
	data.setBill_no(dto.getBill_no());
	data.setContact(dto.getContact());
	data.setDelivery_place(dto.getDelivery_place());
	data.setEmail(dto.getEmail());
	data.setFax(dto.getFax());
	data.setPayment_method(dto.getPayment_method());
	data.setPhone(dto.getPhone());
	data.setRemark(dto.getRemark());
	data.setSubject(dto.getSubject());

	AddPurInquiryEntryDO datas;
	int size = dto.getDetail().size();
	uint64_t result = -1;
	if (size != 0)
	{
		int i = 0;
		for (AddPurInquiryEntryDTO& it : dto.getDetail())
		{
			datas.setBill_no(it.getBill_no());
			if (i == 0)
			{
				dao.updateByEntry(datas);
				i++;
			}

			datas.setEntry_no(it.getEntry_no());
			datas.setMid(it.getMid());
			datas.setAmt(it.getAmt());
			datas.setCustom1(it.getCustom1());
			datas.setCustom2(it.getCustom2());
			datas.setId(it.getId());
			datas.setMaterial_id(it.getMaterial_id());
			datas.setPrice(it.getPrice());
			datas.setQty(it.getQty());
			datas.setRemark(it.getRemark());
			datas.setSrc_bill_type(it.getSrc_bill_type());
			datas.setSrc_no(it.getSrc_no());
			datas.setTax_rate(it.getTax_rate());
			datas.setUnit_id(it.getUnit_id());

			result = dao.insertByEntry(datas);
		}
	}
	return dao.update(data) == 1;
}

bool PurInquiryService::removeData(const PurInquiryRemoveDTO& dto)
{
	PurInquiryDAO dao;

	return dao.deleteById(dto.getBill_no());
}

bool PurInquiryService::updateDataByStatus(const PurInquiryModBillStatusDTO& dto)
{
	PurInquiryDAO dao;
	PurInquiryModBillStatusDO data;

	data.setIs_close(dto.getIs_close());
	data.setIs_voided(dto.getIs_voided());
	data.setBill_no(dto.getBill_no());

	return dao.updateByModBillStatus(data);
}

// 查询采购询价单列表
PageVO<PurInquiryFindBillVO> PurInquiryService::listAll(const PurInquiryFindBillQuery& query)
{
	//构建返回对象
	PageVO<PurInquiryFindBillVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	PurInquiryDO obj;
	obj.setBill_no(query.getBill_no());
	obj.setBill_date(query.getBill_date());
	obj.setSubject(query.getSubject());
	obj.setIs_effective(query.getIs_effective());
	obj.setIs_closed(query.getIs_closed());
	obj.setIs_voided(query.getIs_voided());
	PurInquiryDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<PurInquiryDO> result = dao.selectPurInquiryFindBillWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<PurInquiryFindBillVO> vr;
	for (PurInquiryDO sub : result)
	{
		PurInquiryFindBillVO vo;
		//vo.setId(sub.getId());
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setSubject(sub.getSubject());
		vo.setSrc_no(sub.getSrc_no());
		vo.setDelivery_time(sub.getDelivery_time());
		vo.setQty(sub.getQty());
		vo.setAmt(sub.getAmt());
		vo.setQuot_count(sub.getQuot_count());
		vo.setBill_stage(sub.getBill_stage());
		vo.setIs_effective(sub.getIs_effective());
		vo.setIs_closed(sub.getIs_closed());
		vo.setIs_voided(sub.getIs_voided());
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



// 查看指定采购询价单详情
PurInquiryFindDetailBillVO PurInquiryService::listPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query)
{
	// 构建返回对象
	PurInquiryFindDetailBillVO detail;

	// 领域模型转换
	PurInquiryDO obj;
	obj.setBill_no(query.getBill_no());
	PurInquiryEntryDO obj2;
	obj2.setEntry_bill_no(query.getBill_no());

	// 查询指定询价单数据
	PurInquiryDAO dao;
	list<PurInquiryDO> result = dao.selectPurInquiryFindDetailBill(obj);
	for (PurInquiryDO sub : result)
	{
		PurInquiryFindDetailBillVO detail;
		detail.setBill_no(sub.getBill_no());
		detail.setBill_date(sub.getBill_date());
		detail.setBill_stage(sub.getBill_stage());
		detail.setIs_effective(sub.getIs_effective());
		detail.setIs_closed(sub.getIs_closed());
		detail.setIs_voided(sub.getIs_voided());
		detail.setSubject(sub.getSubject());
		detail.setPayment_method(sub.getPayment_method());
		detail.setDelivery_place(sub.getDelivery_place());
		detail.setContact(sub.getContact());
		detail.setPhone(sub.getPhone());
		detail.setFax(sub.getFax());
		detail.setEmail(sub.getEmail());
		detail.setQuot_count(sub.getQuot_count());
		detail.setRemark(sub.getRemark());
		detail.setApproval_remark(sub.getApproval_remark());
		detail.setAttachment(sub.getAttachment());
		detail.setApproval_result_type(sub.getApproval_result_type());
	}

	// 查询明细列表
	list<PurInquiryEntryDO> details = dao.selectPurInquiryFindDetailBillEntry(obj2);
	EntryPurInquiryVO detailsvo;
	list<EntryPurInquiryVO> lvo;
	for (PurInquiryEntryDO ones : details)
	{
		detailsvo.setSrc_bill_type(ones.getEntry_src_bill_type());
		detailsvo.setSrc_entry_no(ones.getEntry_src_no());
		detailsvo.setMaterialid(ones.getMaterial_id());
		// 规格型号
		detailsvo.setUnit_id(ones.getUnit_id());
		detailsvo.setQty(ones.getEntry_qty());
		detailsvo.setTax_rate(ones.getTax_rate());
		detailsvo.setPrice(ones.getPrice());
		detailsvo.setAmt(ones.getEntry_Amt());
		detailsvo.setRemark(ones.getEntry_remark());
		detailsvo.setCustom1(ones.getCustom1());
		detailsvo.setCustom2(ones.getCustom2());
		lvo.push_back(detailsvo);
	}
	detail.setDetailsList(lvo);

	return detail;
}


// 导出（按单据编号批量查询后，放入xml，再下载文件）
PageVO<PurInquiryExportVO> PurInquiryService::PurInquiryExport(const PurInquiryExportQuery& query)
{
	// 构建返回对象
	PageVO<PurInquiryExportVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());
	PurInquiryExportVO exresult;
	// 领域模型转换
	PurInquiryDO obj;
	obj.setBill_no(query.getBill_no());
	PurInquiryEntryDO obj2;
	obj2.setEntry_bill_no(query.getBill_no());
	// 查询要导出的数据总条数
	PurInquiryDAO dao;
	uint64_t count = dao.countExport(obj);
	if (count <= 0)
	{
		return pages;
	}
	//查询基本信息
	//pages.setTotal(count);
	//pages.calcPages();
	list<PurInquiryDO> result = dao.selectPurInquiryExport(obj, query.getPageIndex(), query.getPageSize());
	list<PurInquiryExportVO> vr;
	for (PurInquiryDO sub : result)
	{
		PurInquiryExportVO ex;
		ex.setBill_no(sub.getBill_no());
		//ex.setBill_date(sub.getBill_date());
		//ex.setBill_stage(sub.getBill_stage());
		//ex.setIs_effective(sub.getIs_effective());
		//ex.setIs_closed(sub.getIs_closed());
		//ex.setIs_voided(sub.getIs_voided());
		//ex.setSubject(sub.getSubject());
		//ex.setPayment_method(sub.getPayment_method());
		//ex.setDelivery_place(sub.getDelivery_place());
		//ex.setContact(sub.getContact());
		//ex.setPhone(sub.getPhone());
		//ex.setFax(sub.getFax());
		//ex.setEmail(sub.getEmail());
		//ex.setQuot_count(sub.getQuot_count());
		//ex.setRemark(sub.getRemark());
		//ex.setApproval_remark(sub.getApproval_remark());
		//ex.setAttachment(sub.getAttachment());
		//ex.setApproval_result_type(sub.getApproval_result_type());
		vr.push_back(ex);
	}
	// 查询明细列表
	//list<PurInquiryEntryDO> exdetail = dao.selectPurInquiryExportEntry(obj2);
	//EntryPurInquiryVO exdetailsvo;
	//list<EntryPurInquiryVO> lvo;
	//for (PurInquiryEntryDO ones : exdetail)
	//{
	//	exdetailsvo.setSrc_bill_type(ones.getEntry_src_bill_type());
	//	exdetailsvo.setSrc_entry_no(ones.getEntry_src_no());
	//	exdetailsvo.setMaterialid(ones.getMaterial_id());
	//	// 规格型号
	//	exdetailsvo.setUnit_id(ones.getUnit_id());
	//	exdetailsvo.setQty(ones.getEntry_qty());
	//	exdetailsvo.setTax_rate(ones.getTax_rate());
	//	exdetailsvo.setPrice(ones.getPrice());
	//	exdetailsvo.setAmt(ones.getEntry_Amt());
	//	exdetailsvo.setRemark(ones.getEntry_remark());
	//	exdetailsvo.setCustom1(ones.getCustom1());
	//	exdetailsvo.setCustom2(ones.getCustom2());
	//	lvo.push_back(exdetailsvo);
	//}
	//exresult.setDetailsList(lvo);
	pages.setRows(vr);
	
	return pages;
}


// 导入（上传文件后，将xml解析成json/cpp放入数据库，保存数据）