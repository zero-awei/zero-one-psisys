/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/15 14:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

		https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "PurInquiryService.h"
#include "ExcelComponent.h"
#include "SnowFlake.h"
#include "CharsetConvertHepler.h"
#include "../../dao/pur-inquiry/PurInquiryDAO.h"
#include "../../api/pur-inquiry/PurInquiryController.h"
#include "SimpleDateTimeFormat.h"

//定义一个宏用来进行值从导入主的数据表进入DO中
#define GET_VALUE1(name, stox) data.set##name(stox(CharsetConvertHepler::utf8ToAnsi(r1[i++])));
//定义一个宏用来进行值从导入主的数据表进入DO中
#define GET_VALUE2(name, stox) data.set##name(stox(CharsetConvertHepler::utf8ToAnsi(r2[i++])));


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
	list<PurInquiryEntryDO> details = dao.selectPurInquiryExportEntry(obj2.getEntry_bill_no());
	EntryPurInquiryVO detailsvo;
	list<EntryPurInquiryVO> lvo;
	for (PurInquiryEntryDO ones : details)
	{
		detailsvo.setSrc_bill_type(ones.getEntry_src_bill_type());
		detailsvo.setSrc_entry_no(ones.getEntry_src_no());
		detailsvo.setMaterial_id(ones.getMaterial_id());
		// 规格型号
		detailsvo.setUnit_id(ones.getUnit_id());
		detailsvo.setEntry_qty(ones.getEntry_qty());
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

// 导入
uint64_t PurInquiryService::PurInquiryInto(string fileName, const PayloadDTO& payload)
{
	//对一些值进行初始化
		//excel对象
	ExcelComponent excel;
	//雪花生成器
	SnowFlake sf(1, 3);
	//计数器
	int i = 0;
	PurInquiryDAO dao;
	//首先加载主表数据
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("采购询价单");
	auto readData = excel.readIntoVector(fileName, sheetName);
	//然后加载明细数据
	std::string sheetName2 = CharsetConvertHepler::ansiToUtf8("采购询价单明细");
	auto readEntryData = excel.readIntoVector(fileName, sheetName2);
	int row1 = 1, row2 = 1;//row1代表主表行号， row2代表明细表行号
	for (; row1 < readData.size(); ++row1)
	{
		//每个行数据的数组
		vector<string> r1 = readData[row1];
		PurInquiryDO data;
		i = 0;
		//首先生成id
		string id = to_string(sf.nextId());
		data.setId(id);
		//获取时间
		SimpleDateTimeFormat time;
		data.setCreate_time(time.format());
		data.setUpdate_time(time.format());
		//获取身份
		data.setSys_org_code(payload.getOrgCode());
		data.setCreate_by(payload.getUsername());
		data.setUpdate_by(payload.getUsername());
		//获取数据表的信息
		GET_VALUE1(Bill_no, );
		GET_VALUE1(Bill_date, );
		GET_VALUE1(Src_bill_type, );
		GET_VALUE1(Src_bill_id, );
		GET_VALUE1(Src_no, );
		GET_VALUE1(Subject, );
		GET_VALUE1(Is_rubric, stoi);
		GET_VALUE1(Payment_method, );
		GET_VALUE1(Delivery_place, );
		GET_VALUE1(Delivery_time, );
		GET_VALUE1(Contact, );
		GET_VALUE1(Phone, );
		GET_VALUE1(Fax, );
		GET_VALUE1(Email, );
		GET_VALUE1(Qty, stod);
		GET_VALUE1(Amt, stod);
		GET_VALUE1(Quot_count, stoi);
		GET_VALUE1(Attachment, );
		GET_VALUE1(Remark, );
		GET_VALUE1(Is_auto, stoi);
		GET_VALUE1(Bill_stage, );
		GET_VALUE1(Approver, );
		GET_VALUE1(Bpmi_instance_id, );
		GET_VALUE1(Approval_result_type, );
		GET_VALUE1(Approval_remark, );
		GET_VALUE1(Is_effective, stoi);
		GET_VALUE1(Effective_time, );
		GET_VALUE1(Is_closed, stoi);
		GET_VALUE1(Is_voided, stoi);
		GET_VALUE1(Sys_org_code, );
		GET_VALUE1(Create_by, );
		GET_VALUE1(Create_time, );
		GET_VALUE1(Update_by, );


		//进行数据验证
		//进行必填参数检验
		if (data.getBill_no() == "" || data.getBill_date() == "" || data.getSubject() == "") {
			return 0;
		}
		//将其加载进数据库
		if (dao.input(data) == 0)
		{
			return  0;
		}
		string billNo = data.getBill_no();

		// 明细 sheet
		for (; row2 < readEntryData.size() && readEntryData[row2][0] == billNo; ++row2)
		{
			PurInquiryEntryDO data;
			//每个行数据的数组
			vector<string> r2 = readEntryData[row2];
			i = 0;
			//首先生成id
			string id1 = to_string(sf.nextId());
			data.setEntry_id(id1);
			data.setMid(id);
			//获取数据表的信息
			GET_VALUE2(Entry_bill_no, );
			GET_VALUE2(Entry_no, stoi);
			GET_VALUE2(Entry_src_bill_type, );
			GET_VALUE2(Entry_src_bill_id, );
			GET_VALUE2(Src_entry_id, );
			GET_VALUE2(Entry_src_no, );
			GET_VALUE2(Material_id, );
			GET_VALUE2(Unit_id, );
			GET_VALUE2(Entry_qty, stod);
			GET_VALUE2(Tax_rate, stod);
			GET_VALUE2(Price, stod);
			GET_VALUE2(Entry_Amt, stod);
			GET_VALUE2(Entry_remark, );
			GET_VALUE2(Custom1, );
			GET_VALUE2(Custom2, );

			//数据检验
			//进行明细检验
			if (data.getEntry_no() < 0 || data.getMaterial_id() == "" || data.getUnit_id() == ""
				|| data.getEntry_qty() < 0) {
				return 0;
			}
			//将其加载进数据库
			if (dao.inputEntry(data) == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}


uint64_t PurInquiryService::saveData(const AddPurInquiryDTO& dto, const PayloadDTO& pdto)
{
	PurInquiryDAO dao;
	AddPurInquiryDO data;
	data.setBill_Date(dto.getBill_Date());
	data.setBill_no(dto.getBill_no());
	data.setBill_stage(dto.getBill_stage());
	data.setContact(dto.getContact());
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
	data.setSys_org_code(dto.getSys_org_code());
	data.setCreate_time(SimpleDateTimeFormat::format());
	data.setCreate_by(pdto.getUsername());

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


bool PurInquiryService::updateData(const AddPurInquiryDTO& dto, const PayloadDTO& pdto)
{
	PurInquiryDAO dao;
	AddPurInquiryDO data;

	data.setApprover(pdto.getUsername());
	data.setApproval_result_type(dto.getApproval_result_type());
	data.setApproval_remark(dto.getApproval_remark());
	data.setUpdate_by(pdto.getUsername());
	data.setupdate_time(SimpleDateTimeFormat::format());
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