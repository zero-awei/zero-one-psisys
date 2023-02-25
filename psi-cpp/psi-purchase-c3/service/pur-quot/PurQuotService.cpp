#include "stdafx.h"
#include "PurQuotService.h"
#include "../../dao/pur-quot/PurQuotDAO.h"
#include <list>
#include "../../uselib/fastdfs/TestFastDfs.h"
#include <string>
#include <time.h> 
#include <stdio.h>
#include "../lib-common/include/SnowFlake.h"
#include <cstdlib>
#include <stdlib.h>

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
	//构建BaseVO对象
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
	//设置查询条件
	PurQuotEntryDO entry_obj;
	entry_obj.setBill_no(query.getBill_no());
	//接收查询到的DO
	list<PurQuotEntryDO> entry_result = dao.selectPurQuotDetail(entry_obj); //多个Base对象
	PurQuotDetailVO entry_vo;

	//构建DetailVO对象
	list<PurQuotDetailVO> entry_vr;
	for (PurQuotEntryDO sub : entry_result) {
		PurQuotDetailVO entry_vo;
		entry_vo.setEntry_src_no(sub.getSrc_no());
		entry_vo.setEntry_material_id(sub.getMaterial_id());
		entry_vo.setEntry_unit_id(sub.getUnit_id());
		entry_vo.setEntry_qty(sub.getQty());
		entry_vo.setEntry_tax_rate(sub.getTax_rate());
		entry_vo.setEntry_price(sub.getPrice());
		entry_vo.setEntry_discount_rate(sub.getDiscount_rate());
		entry_vo.setEntry_amt(sub.getAmt());
		entry_vo.setEntry_remark(sub.getRemark());
		entry_vo.setEntry_custom1(sub.getCustom1());
		entry_vo.setEntry_custom2(sub.getCustom2());
		entry_vr.push_back(entry_vo);
	}
	
	//构建返回对象
	PurQuotFindDetailBillVO vr(vo, entry_vr);
	return vr;
}


// 新增报价，将AddPurQuotDTO中的内容放进PurQuotDO中
uint64_t PurQuotService::saveData(const AddPurQuotDTO& dto, const PayloadDTO& payload)
{
	//TestFastDfs Test;											//附件上传测试，里面的IP要写FastDFS服务器的IP地址
	//Test.testDfs("C:\\Program Files\\architecture.jpg");

	//生成时间
	time_t t;					//将t声明为时间变量
	struct tm* p;				//struct tm是一个结构体，声明一个结构体指针
	time(&t);
	p = localtime(&t);			//获得当地的时间
	char timestr[30];
	sprintf(timestr, "%d-%d-%d %d:%d:%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
	std::cout << timestr << std::endl;

	// 雪花算法，生成id
	SnowFlake autoId(1, 1);
	std::cout << autoId.nextId() << std::endl;
	auto a = autoId.nextId();
	char autoIdStr[25];
	sprintf(autoIdStr, "%llu", autoId.nextId());

	//组装供应单据数据
	PurQuotNaiGuanDO data;

	data.setId(autoIdStr);
	data.setBillNo(dto.getBillNo());
	data.setBillDate(dto.getBillDate());
	data.setSrcBillType(dto.getSrcBillType());

	data.setSrcBillId(dto.getSrcBillId());
	data.setSrcNo(dto.getSrcNo());
	data.setSubject(dto.getSubject());
	data.setIsRubric(dto.getIsRubric());

	data.setIsTempSupplier(dto.getIsTempSupplier());
	data.setSupplierId(dto.getSupplierId());
	data.setTempSupplierName(dto.getTempSupplierName());
	data.setDeliveryMethod(dto.getDeliveryMethod());

	data.setDeliveryDate(dto.getDeliveryDate());
	data.setDeliveryAddress(dto.getDeliveryAddress());
	data.setContact(dto.getContact());
	data.setPhone(dto.getPhone());

	data.setFax(dto.getFax());
	data.setEmail(dto.getEmail());
	data.setQty(dto.getQty());
	data.setAmt(dto.getAmt());

	std::string fileAddress = "group1" + dto.getAttachment();				//拼接文件地址
	data.setAttachment(fileAddress);
	data.setRemark(dto.getRemark());
	data.setIsAuto(dto.getIsAuto());
	data.setBillStage(dto.getBillStage());

	data.setApprover(dto.getApprover());
	data.setBpmi_instance_id(dto.getBpmi_instance_id());
	data.setApprovalResultType(dto.getApprovalResultType());
	data.setApprovalRemark(dto.getApprovalRemark());

	data.setIsEffective(dto.getIsEffective());
	data.setEffectiveTime(dto.getEffectiveTime());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());

	data.setSysOrdCode(dto.getSysOrdCode());
	data.setCreateBy(payload.getUsername());
	data.setCreateTime(timestr);
	data.setUpdateBy(dto.getUpdateBy());

	data.setUpdateTime(dto.getUpdateTime());
	data.setVersion(dto.getVersion());

	//用于接收DTO中的list，传递给DO中的list
	list<PurQuotDetailDTO> Addlist;
	//组装供应单据明细数据
	for (PurQuotDetailDTO i : dto.getDetail()) {
		// 雪花算法，生成id
		SnowFlake autoIdEntry(1, 1);
		auto a = autoIdEntry.nextId();
		char autoIdStrEntry[25];
		sprintf(autoIdStrEntry, "%llu", autoIdEntry.nextId());

		PurQuotDetailDTO Addone;
		Addone.setId(autoIdStrEntry);
		Addone.setMid("pur_quot");
		Addone.setBill_no(i.getBill_no());
		Addone.setEntry_no(i.getEntry_no());						//前端自动生成

		Addone.setSrc_bill_type(i.getSrc_bill_type());
		Addone.setSrc_bill_id(i.getSrc_bill_id());
		Addone.setSrc_entry_id(i.getSrc_entry_id());
		Addone.setSrc_no(i.getSrc_no());

		Addone.setMaterial_id(i.getMaterial_id());
		Addone.setUnit_id(i.getUnit_id());
		Addone.setQty(i.getQty());
		Addone.setTax_rate(i.getTax_rate());

		Addone.setPrice(i.getPrice());
		Addone.setDiscount_rate(i.getDiscount_rate());
		Addone.setAmt(i.getAmt());
		Addone.setRemark(i.getRemark());

		Addone.setCustom1(i.getCustom1());
		Addone.setCustom2(i.getCustom2());
		Addone.setVersion(i.getVersion());
		Addlist.push_back(Addone);
	}
	//讲Addlist中的东西传递到DO中的list
	data.setDetail(Addlist);
	PurQuotDAO dao;
	return dao.insert(data);
}

// 修改报价，将ModPurQuotDTO中的数据放入PurQuotDO中
bool PurQuotService::updateData(const ModPurQuotDTO& dto, const PayloadDTO& payload)
{
	//生成时间
	time_t t;					//将t声明为时间变量
	struct tm* p;				//struct tm是一个结构体，声明一个结构体指针
	time(&t);
	p = localtime(&t);			//获得当地的时间
	char timestr[30];
	sprintf(timestr, "%d-%d-%d %d:%d:%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
	std::cout << timestr << endl;

	//组装供应单据数据
	PurQuotNaiGuanDO data;
	data.setId(dto.getId());						//修改和id无关
	data.setBillNo(dto.getBillNo());
	data.setBillDate(dto.getBillDate());
	data.setSrcBillType(dto.getSrcBillType());

	data.setSrcBillId(dto.getSrcBillId());
	data.setSrcNo(dto.getSrcNo());
	data.setSubject(dto.getSubject());
	data.setIsRubric(dto.getIsRubric());

	data.setIsTempSupplier(dto.getIsTempSupplier());
	data.setSupplierId(dto.getSupplierId());
	data.setTempSupplierName(dto.getTempSupplierName());
	data.setDeliveryMethod(dto.getDeliveryMethod());

	data.setDeliveryDate(dto.getDeliveryDate());
	data.setDeliveryAddress(dto.getDeliveryAddress());
	data.setContact(dto.getContact());
	data.setPhone(dto.getPhone());

	data.setFax(dto.getFax());
	data.setEmail(dto.getEmail());
	data.setQty(dto.getQty());
	data.setAmt(dto.getAmt());

	data.setAttachment(dto.getAttachment());
	data.setRemark(dto.getRemark());
	data.setIsAuto(dto.getIsAuto());
	data.setBillStage(dto.getBillStage());

	data.setApprover(dto.getApprover());
	data.setBpmi_instance_id(dto.getBpmi_instance_id());
	data.setApprovalResultType(dto.getApprovalResultType());
	data.setApprovalRemark(dto.getApprovalRemark());

	data.setIsEffective(dto.getIsEffective());
	data.setEffectiveTime(dto.getEffectiveTime());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());

	data.setSysOrdCode(dto.getSysOrdCode());
	//data.setCreateBy(dto.getCreateBy());						//修改单据，不需要涉及创建人和创建时间
	//data.setCreateTime(dto.getCreateTime());
	data.setUpdateBy(payload.getUsername());

	data.setUpdateTime(timestr);
	data.setVersion(dto.getVersion());

	//用于接收DTO中的list，传递给DO中的list
	list<PurQuotDetailDTO> Addlist;
	//组装供应单据明细数据
	for (PurQuotDetailDTO i : dto.getDetail()) {
		// 雪花算法，生成id
		SnowFlake autoIdEntry(1, 1);
		auto a = autoIdEntry.nextId();
		char autoIdStrEntry[25];
		sprintf(autoIdStrEntry, "%llu", autoIdEntry.nextId());

		PurQuotDetailDTO Addone;
		Addone.setId(autoIdStrEntry);
		Addone.setMid("pur_quot");
		Addone.setBill_no(i.getBill_no());
		Addone.setEntry_no(i.getEntry_no());

		Addone.setSrc_bill_type(i.getSrc_bill_type());
		Addone.setSrc_bill_id(i.getSrc_bill_id());
		Addone.setSrc_entry_id(i.getSrc_entry_id());
		Addone.setSrc_no(i.getSrc_no());

		Addone.setMaterial_id(i.getMaterial_id());
		Addone.setUnit_id(i.getUnit_id());
		Addone.setQty(i.getQty());
		Addone.setTax_rate(i.getTax_rate());

		Addone.setPrice(i.getPrice());
		Addone.setDiscount_rate(i.getDiscount_rate());
		Addone.setAmt(i.getAmt());
		Addone.setRemark(i.getRemark());

		Addone.setCustom1(i.getCustom1());
		Addone.setCustom2(i.getCustom2());
		Addone.setVersion(i.getVersion());
		Addlist.push_back(Addone);
	}
	//讲Addlist中的东西传递到DO中的list
	data.setDetail(Addlist);
	PurQuotDAO dao;
	return dao.update(data) == 1;
}

// 通过bill_no删除报价以及对应的明细，将DelPurQuotDTO中的bill_no放进PurQuotDO中
bool PurQuotService::removeData(const DelPurQuotDTO& dto)
{
	PurQuotNaiGuanDO data;
	data.setBillNo(dto.getBillNo());
	PurQuotDAO dao;
	return dao.deleteByBillNo(data) == 1;
}

// 修改报价状态，将PurQuotModBillStatusDTO中的数据放进PurQuotDO中
bool PurQuotService::UpdateDataBillStatus(const PurQuotModBillStatusDTO& dto)
{
	PurQuotNaiGuanDO data;
	data.setIsEffective(dto.getIsEffective());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());
	data.setApprovalResultType(dto.getApprovalResultType());
	data.setBillStage(dto.getBillStage());
	data.setBillNo(dto.getBillNo());
	data.setApprover(dto.getApprover());
	data.setApprovalRemark(dto.getApprovalRemark());
	data.setEffectiveTime(dto.getEffectiveTime());
	PurQuotDAO dao;
	return dao.updateBillStatus(data) == 1;

}
