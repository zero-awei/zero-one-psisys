/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/20 15:07:42

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
#include "PurCompareService.h"
#include "../../dao/pur-compare/PurCompareDAO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"

#include "../../dao/pur-compare/PurCompareDAO.h"
#include "../../domain/do/pur-compare/AddPurComDO.h"
#include "../../domain/do/pur-compare/ModPurComDO.h"
#include "../../domain/do/pur-compare/DelPurComDO.h"
#include "../../domain/do/pur-compare/PurComModBillStatusDO.h"



// 分页查询比价单单据列表
PageVO<PurComFindBillVO> PurCompareService::listPurComFindBill(const PurComFindBillQuery& query)
{
	//构建返回对象
	PageVO<PurComFindBillVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	PurCompareDO obj;
	obj.setBillNo(query.getBillNo());
	obj.setSubject(query.getSubject());
	obj.setBillDateBegin(query.getBillDateBegin());
	obj.setBillDateEnd(query.getBillDateEnd());
	obj.setBillStage(query.getBillStage());
	obj.setIsEffective(query.getIsEffective());
	obj.setIsClosed(query.getIsClosed());
	obj.setIsVoided(query.getIsVoided());
	PurCompareDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<PurCompareDO> result = dao.selectPurComFindBill(obj, query.getPageIndex(), query.getPageSize());
	list<PurComFindBillVO> vr;
	for (PurCompareDO sub : result)
	{
		PurComFindBillVO vo;
		vo.setId(sub.getId());
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setSubject(sub.getSubject());
		vo.setSrcNo(sub.getSrcNo());
		vo.setPaymentMethod(sub.getPaymentMethod());
		vo.setDeliveryTime(sub.getDeliveryTime());
		vo.setBillStage(sub.getBillStage());
		vo.setIsEffective(sub.getIsEffective());
		vo.setIsClosed(sub.getIsClosed());
		vo.setIsVoided(sub.getIsVoided());
		vo.setDeliveryPlace(sub.getDeliveryPlace());
		vo.setRemark(sub.getRemark());
		vo.setIsAuto(sub.getIsAuto());
		vo.setIsRubric(sub.getIsRubric());
		vo.setEffectiveTime(sub.getEffectiveTime());
		vo.setApprover(sub.getApprover());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setSysOrgCode(sub.getSysOrgCode());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}
// 查询指定比价单详细信息
PurComFindDetailBillVO PurCompareService::getPurComFindDetailBill(const PurComFindDetailBillQuery& query)
{
	// 领域模型转换
	PurCompareDO obj;
	obj.setBillNo(query.getBillNo());
	PurCompareEntryDO obj2;
	obj2.setBillNo(query.getBillNo());
	// 查询数据：比价单信息
	PurCompareDAO dao;
	list<PurCompareDO> result = dao.selectPurComFindDetailBill(obj);
	PurComFindDetailBillVO vo;
	if(!result.empty())
	{
		auto sub = result.front();
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setBillStage(sub.getBillStage());
		vo.setIsEffective(sub.getIsEffective());
		vo.setIsClosed(sub.getIsClosed());
		vo.setIsVoided(sub.getIsVoided());
		vo.setEffectiveTime(sub.getEffectiveTime());
		vo.setApprover(sub.getApprover());
		vo.setBpmiInstanceId(sub.getBpmiInstanceId());
		vo.setCreateTime(sub.getCreateTime());
		vo.setSysOrgCode(sub.getSysOrgCode());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setIsAuto(sub.getIsAuto());
		vo.setIsRubric(sub.getIsRubric());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSubject(sub.getSubject());
		vo.setSrcNo(sub.getSrcNo());
		vo.setPaymentMethod(sub.getPaymentMethod());
		vo.setDeliveryTime(sub.getDeliveryTime());
		vo.setDeliveryPlace(sub.getDeliveryPlace());
		vo.setRemark(sub.getRemark());
		vo.setAttachment(sub.getAttachment());
		vo.setApprovalRemark(sub.getApprovalRemark());
		vo.setApprovalResultType(sub.getApprovalResultType());
	}
	// 查询数据：明细列表
	list<PurCompareEntryDO> details = dao.selectPurComFindDetailBillEntry(obj2);
	PurComDetailsVO detailsvo;
	list<PurComDetailsVO> lvo;
	for (PurCompareEntryDO ones : details)
	{
		detailsvo.setEntryNo(ones.getEntryNo());
		detailsvo.setSupplierName(ones.getSupplierName());
		detailsvo.setSrcNo(ones.getSrcNo());
		detailsvo.setMaterialName(ones.getMaterialName());
		detailsvo.setSpecifications(ones.getSpecifications());
		detailsvo.setUnitName(ones.getUnitName());
		detailsvo.setQty(ones.getQty());
		detailsvo.setTaxRate(ones.getTaxRate());
		detailsvo.setPrice(ones.getPrice());
		detailsvo.setDiscountRate(ones.getDiscountRate());
		detailsvo.setAmt(ones.getAmt());
		detailsvo.setRanking(ones.getRanking());
		detailsvo.setRemark(ones.getRemark());
		detailsvo.setCustom1(ones.getCustom1());
		detailsvo.setCustom2(ones.getCustom2());
		lvo.push_back(detailsvo);
	}
	vo.setDetailsList(lvo);
	return vo;
}
// 报价单列表
std::list<PurComListVO> PurCompareService::listPurComList(const PurComListQuery& query)
{
	// 构建返回对象
	list<PurComListVO> lvo;
	// 领域模型转换
	PurCompareDO obj,obj2;
	obj.setBillNo(query.getBillNo());
	// 查询候选报价单ids
	PurCompareDAO dao;
	list<PurCompareDO> CanIds = dao.selectCandidateQuot(obj);
	if (CanIds.empty()) return lvo;
	else obj2.setCandidateQuotIds(CanIds.front().getCandidateQuotIds());
	// 查询报价单列表
	list<PurComQuotDO> result = dao.selectPurComList(obj2);
	PurComListVO vo;
	for (PurComQuotDO ones : result)
	{
		vo.setBillNo(ones.getBillNo());
		vo.setBillDate(ones.getBillDate());
		vo.setSubject(ones.getSubject());
		vo.setSupplierName(ones.getSupplierName());
		vo.setPaymentMethod(ones.getPaymentMethod());
		vo.setDeliveryTime(ones.getDeliveryTime());
		vo.setDeliveryPlace(ones.getDeliveryPlace());
		vo.setRemark(ones.getRemark());
		lvo.push_back(vo);
	}
	return lvo;
}
// 报价单分录列表
std::list<PurComDividedListVO> PurCompareService::listPurComDividedList(const PurComDividedListQuery& query)
{
	// 构建返回对象
	list<PurComDividedListVO> lvo;
	// 领域模型转换
	PurComQuotEntryDO obj;
	obj.setBillNo(query.getBillNo());
	// 查询报价单分录列表
	PurCompareDAO dao;
	list<PurComQuotEntryDO> result = dao.selectPurComDividedList(obj);
	PurComDividedListVO vo;
	for (PurComQuotEntryDO ones : result)
	{
		vo.setBillNo(ones.getBillNo());
		vo.setEntryNo(ones.getEntryNo());
		vo.setMaterialName(ones.getMaterialName());
		vo.setSpecifications(ones.getSpecifications());
		vo.setUnitName(ones.getUnitName());
		vo.setQty(stod(ones.getQty()));
		vo.setTaxRate(stod(ones.getTaxRate()));
		vo.setPrice(stod(ones.getPrice()));
		vo.setDiscountRate(stod(ones.getDiscountRate()));
		vo.setAmt(stod(ones.getAmt()));
		vo.setRemark(ones.getRemark());
		vo.setCustom1(ones.getCustom1());
		vo.setCustom2(ones.getCustom2());
		lvo.push_back(vo);
	}
	return lvo;
}
// 导出比价单及分录
string PurCompareService::getPurComExport(const PurComExportQuery& query)
{
	//定义fastdfs客户端对象
	#ifdef LINUX
		FastDfsClient client("conf/client.conf", 3);
	#else
		FastDfsClient client("1.15.240.108");
	#endif
	// 判断是否有上传参数，并用lsAll记录
	bool lsAll = false;
	if (query.getBillNo().size() == 0) lsAll = true;
	// 定义保存数据位置
	ExcelComponent excel;
	std::string fileName = "./public/excel/export.xlsx";
	// 导出采购比价单主表
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("采购比价单");
	vector<vector<std::string>> data;
	vector<string> headers{
		CharsetConvertHepler::ansiToUtf8("单据编号"),
		CharsetConvertHepler::ansiToUtf8("单据日期"),
		CharsetConvertHepler::ansiToUtf8("源单类型"),
		CharsetConvertHepler::ansiToUtf8("源单id"),
		CharsetConvertHepler::ansiToUtf8("源单号"),
		CharsetConvertHepler::ansiToUtf8("主题"),
		CharsetConvertHepler::ansiToUtf8("是否红字"),
		CharsetConvertHepler::ansiToUtf8("候选报价单ids"),
		CharsetConvertHepler::ansiToUtf8("付款方式"),
		CharsetConvertHepler::ansiToUtf8("交货地点"),
		CharsetConvertHepler::ansiToUtf8("交货时间"),
		CharsetConvertHepler::ansiToUtf8("附件"),
		CharsetConvertHepler::ansiToUtf8("备注"),
		CharsetConvertHepler::ansiToUtf8("是否自动生成"),
		CharsetConvertHepler::ansiToUtf8("单据阶段"),
		CharsetConvertHepler::ansiToUtf8("审核人"),
		CharsetConvertHepler::ansiToUtf8("审批实例id"),
		CharsetConvertHepler::ansiToUtf8("核批结果类型"),
		CharsetConvertHepler::ansiToUtf8("核批意见"),
		CharsetConvertHepler::ansiToUtf8("是否生效"),
		CharsetConvertHepler::ansiToUtf8("生效时间"),
		CharsetConvertHepler::ansiToUtf8("已关闭"),
		CharsetConvertHepler::ansiToUtf8("是否作废"),
		CharsetConvertHepler::ansiToUtf8("创建部门"),
		CharsetConvertHepler::ansiToUtf8("创建人"),
		CharsetConvertHepler::ansiToUtf8("创建时间"),
		CharsetConvertHepler::ansiToUtf8("修改人"),
		//CharsetConvertHepler::ansiToUtf8("修改时间")
	};
	data.push_back(headers);
	// 判断是否有上传参数，若没有则导出所有单据，否则根据单据编号导出
	if (lsAll) {
		PurCompareDO obj;
		PurCompareDAO dao;
		list<PurCompareDO> result = dao.selectPurComExport(obj,lsAll);
		vector<string> vec;
		for (PurCompareDO ls : result)
		{
			vec = ls.purCompareDOToVecStr();
			data.push_back(vec);
		}
		excel.writeVectorToFile(fileName, sheetName, data);
	}
	else {
		for (string ones : query.getBillNo())
		{
			// 领域模型转换
			PurCompareDO obj;
			obj.setBillNo(ones);
			// 查询结果
			PurCompareDAO dao;
			list<PurCompareDO> result = dao.selectPurComExport(obj,lsAll);
			vector<string> vec;
			if (!result.empty())
			{
				vec = result.front().purCompareDOToVecStr();
				data.push_back(vec);
			}
		}
		excel.writeVectorToFile(fileName, sheetName, data);
	}
	

	//导出采购比价单分录
	sheetName = CharsetConvertHepler::ansiToUtf8("采购比价单分录");
	data.clear();
	headers.clear();
	headers={
		CharsetConvertHepler::ansiToUtf8("单据号"),
		CharsetConvertHepler::ansiToUtf8("分录号"),
		CharsetConvertHepler::ansiToUtf8("源单类型"),
		CharsetConvertHepler::ansiToUtf8("源单id"),
		CharsetConvertHepler::ansiToUtf8("源单分录id"),
		CharsetConvertHepler::ansiToUtf8("源单分录号"),
		CharsetConvertHepler::ansiToUtf8("供应商"),
		CharsetConvertHepler::ansiToUtf8("物料"),
		CharsetConvertHepler::ansiToUtf8("计量单位"),
		CharsetConvertHepler::ansiToUtf8("数量"),
		CharsetConvertHepler::ansiToUtf8("税率%"),
		CharsetConvertHepler::ansiToUtf8("含税单价"),
		CharsetConvertHepler::ansiToUtf8("折扣率"),
		CharsetConvertHepler::ansiToUtf8("含税金额"),
		CharsetConvertHepler::ansiToUtf8("排名"),
		CharsetConvertHepler::ansiToUtf8("备注"),
		CharsetConvertHepler::ansiToUtf8("自定义1"),
		CharsetConvertHepler::ansiToUtf8("自定义2")
	};
	data.push_back(headers);
	// 判断是否有上传参数，若没有则导出所有单据，否则根据单据编号导出
	if (lsAll) {
		PurCompareEntryDO obj2;
		PurCompareDAO dao;
		list<PurCompareEntryDO> result = dao.selectPurComEntryExport(obj2, lsAll);
		vector<string> vec;
		for (PurCompareEntryDO ls : result)
		{
			vec = ls.purCompareEntryDOToVecStr();
			data.push_back(vec);
		}
		excel.writeVectorToFile(fileName, sheetName, data);
	}
	else {
		for (string ones : query.getBillNo())
		{
			// 领域模型转换
			PurCompareEntryDO obj2;
			obj2.setBillNo(ones);
			// 查询结果
			PurCompareDAO dao;
			list<PurCompareEntryDO> result = dao.selectPurComEntryExport(obj2,lsAll);
			vector<string> vec;
			for (PurCompareEntryDO ls : result)
			{
				vec = ls.purCompareEntryDOToVecStr();
				data.push_back(vec);
			}
		}
		excel.writeVectorToFile(fileName, sheetName, data);
	}
	//上传到fastDfs并删除本地文件
	std::string fieldName = client.uploadFile(fileName);
	std::remove(fileName.c_str());
	//返回下载地址
	fieldName = "http://1.15.240.108:8888/" + fieldName;
	return fieldName;
}
// 导入比价单及分录
uint64_t PurCompareService::savePurComInto(const PurComIntoDTO& dto,const PayloadDTO& payload)
{
	//雪花生成器
	SnowFlake sf(1, 13);
	PurCompareDAO dao;
	// 获取数据:加载主表数据和分录数据
	ExcelComponent excel;
	string fileName = dto.getFiles().front();
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("采购比价单");
	vector<vector<string>> readData = excel.readIntoVector(fileName, sheetName);
	sheetName = CharsetConvertHepler::ansiToUtf8("采购比价单分录");
	vector<vector<string>> readEntryData = excel.readIntoVector(fileName, sheetName);
	// 导入数据
	int row1 = 1, row2 = 1;//row1代表主表行号， row2代表明细表行号
	for (; row1 < readData.size(); ++row1)
	{
		//每个行数据的数组
		vector<string> r1 = readData[row1];
		PurCompareDO data(r1);
		data.setId(to_string(sf.nextId())); //随机生成id
		//获取时间
		SimpleDateTimeFormat time;
		data.setCreateTime(time.format());
		data.setUpdateTime(time.format());
		//获取身份
		data.setSysOrgCode(payload.getDepartment());
		data.setCreateBy(payload.getUsername());
		data.setUpdateBy(payload.getUsername());
		// todo：进行权限验证
		// 进行数据验证
		//进行必填参数检验
		if (data.getBillNo() == "" || data.getBillDate() == "") {return 9999;}
		//将其加载进数据库
		dao.insertPurCom(data);
	
		//开始导入对应的分录
		string billNo = data.getBillNo(); //主表单号
		string mid = data.getId(); //主表id
		for (; row2 < readEntryData.size() && readEntryData[row2][0] == billNo; ++row2)
		{
			//每个行数据的数组
			vector<string> r2 = readEntryData[row2];
			PurCompareEntryDO data(r2);
			data.setMid(mid);  
			data.setId(to_string(sf.nextId())); //随机生成id
			//数据检验
			if (data.getEntryNo() == -1 || data.getSupplierName() == ""|| data.getMaterialName() == "" || data.getUnitName() == ""
				|| data.getQty() == -1 || data.getTaxRate() == -1 || data.getPrice() == -1 || data.getAmt() == -1) 
			{
				return 9999;
			}
			//将其加载进数据库
			dao.insertPurComEntry(data);
		}
	}
	return 10000;
}



uint64_t PurCompareService::savePurCom(const AddPurComDTO& dto, const PayloadDTO& payload)
{
	//组装数据
	AddPurComDO data;
	// 雪花算法生成id
	SnowFlake randomId(1, 3);
	data.setId(to_string(randomId.nextId()));

	data.setBillNo(dto.getBillNo());
	data.setBillDate(dto.getBillDate());
	data.setSrcBillType(dto.getSrcBillType());
	data.setSrcBillId(dto.getSrcBillId());

	data.setSrcNo(dto.getSrcNo());
	data.setSubject(dto.getSubject());
	data.setIsRubric(dto.getIsRubric());
	data.setCandidateQuotIds(dto.getCandidateQuotIds());
	data.setPaymentMethod(dto.getPaymentMethod());

	data.setDeliveryPlace(dto.getDeliveryPlace());
	data.setDeliveryTime(dto.getDeliveryTime());
	data.setAttachment(dto.getAttachment());
	data.setRemark(dto.getRemark());
	data.setIsAuto(dto.getIsAuto());

	data.setBillStage(dto.getBillStage());
	data.setApprover(dto.getApprover());
	data.setBpmiInstanceId(dto.getBpmiInstanceId());
	data.setApprovalResultType(dto.getApprovalResultType());
	data.setApprovalRemark(dto.getApprovalRemark());

	data.setIsEffective(dto.getIsEffective());
	data.setEffectiveTime(dto.getEffectiveTime());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());
	// 创建部门，从payload获取
	data.setSysOrgCode(payload.getUserDept());

	// 创建人，从payload获取
	data.setCreateBy(payload.getUsername());
	// 创建时间，由后端生成
	data.setCreateTime(SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"));
	data.setUpdateBy(dto.getUpdateBy());
	data.setUpdateTime(dto.getUpdateTime());
	data.setVersion(dto.getVersion());

	list<PurComDetailDTO> Addlist;
	for (PurComDetailDTO i : dto.getDetail())
	{
		// bill_no和entry_no都不能重复
		PurComDetailDTO detail;
		detail.setId(to_string(randomId.nextId()));
		detail.setMid("pur_compare");

		detail.setBill_no(i.getBill_no());
		detail.setEntry_no(i.getEntry_no());
		detail.setSrc_bill_type(i.getSrc_bill_type());
		detail.setSrc_bill_id(i.getSrc_bill_id());
		detail.setSrc_entry_id(i.getSrc_entry_id());
		detail.setSrc_no(i.getSrc_no());
		detail.setSupplier_id(i.getSupplier_id());
		detail.setMaterial_id(i.getMaterial_id());
		detail.setUnit_id(i.getUnit_id());
		detail.setQty(i.getQty());
		detail.setTax_rate(i.getTax_rate());
		detail.setPrice(i.getPrice());
		detail.setDiscount_rate(i.getDiscount_rate());
		detail.setAmt(i.getAmt());
		detail.setRanking(i.getRanking());
		detail.setRemark(i.getRemark());
		detail.setCustom1(i.getCustom1());
		detail.setCustom2(i.getCustom2());
		detail.setVersion(i.getVersion());

		Addlist.push_back(detail);
	}
	data.setDetail(Addlist);
	//执行数据添加
	PurCompareDAO dao;
	return dao.insertPurCom(data);
}

bool PurCompareService::updatePurCom(const ModPurComDTO& dto, PayloadDTO payload)
{
	//组装传输数据
	ModPurComDO data;

	// 雪花算法生成id
	//SnowFlake randomId(1, 3);
	//data.setId(to_string(randomId.nextId()));

	data.setBillNo(dto.getBillNo());
	data.setBillDate(dto.getBillDate());
	data.setSrcBillType(dto.getSrcBillType());
	data.setSrcBillId(dto.getSrcBillId());

	data.setSrcNo(dto.getSrcNo());
	data.setSubject(dto.getSubject());
	data.setIsRubric(dto.getIsRubric());
	data.setCandidateQuotIds(dto.getCandidateQuotIds());
	data.setPaymentMethod(dto.getPaymentMethod());

	data.setDeliveryPlace(dto.getDeliveryPlace());
	data.setDeliveryTime(dto.getDeliveryTime());
	data.setAttachment(dto.getAttachment());
	data.setRemark(dto.getRemark());
	data.setIsAuto(dto.getIsAuto());

	data.setBillStage(dto.getBillStage());
	data.setApprover(dto.getApprover());
	data.setBpmiInstanceId(dto.getBpmiInstanceId());
	data.setApprovalResultType(dto.getApprovalResultType());
	data.setApprovalRemark(dto.getApprovalRemark());

	data.setIsEffective(dto.getIsEffective());
	data.setEffectiveTime(dto.getEffectiveTime());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());
	// 创建部门，不变
	//data.setSysOrgCode(payload.getUserDept());

	// 创建人，不变
	//data.setCreateBy(payload.getUsername());
	// 创建时间，不变
	//data.setCreateTime(SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"));
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"));
	data.setVersion(dto.getVersion());

	list<PurComDetailDTO> Addlist;
	for (PurComDetailDTO i : dto.getDetail())
	{
		// bill_no和entry_no都不能重复
		PurComDetailDTO detail;
		//detail.setId(to_string(randomId.nextId()));
		//detail.setMid("pur_compare");

		detail.setBill_no(i.getBill_no());
		//detail.setEntry_no(i.getEntry_no());
		//detail.setSrc_bill_type(i.getSrc_bill_type());

		//detail.setSrc_bill_id(i.getSrc_bill_id());
		//detail.setSrc_entry_id(i.getSrc_entry_id());
		//detail.setSrc_no(i.getSrc_no());
		//detail.setSupplier_id(i.getSupplier_id());
		//detail.setMaterial_id(i.getMaterial_id());

		detail.setUnit_id(i.getUnit_id());
		//detail.setQty(i.getQty());
		//detail.setTax_rate(i.getTax_rate());
		//detail.setPrice(i.getPrice());
		//detail.setDiscount_rate(i.getDiscount_rate());

		//detail.setAmt(i.getAmt());
		detail.setRanking(i.getRanking());
		detail.setRemark(i.getRemark());
		detail.setCustom1(i.getCustom1());
		detail.setCustom2(i.getCustom2());
		detail.setVersion(i.getVersion());

		Addlist.push_back(detail);
	}
	data.setDetail(Addlist);

	//执行数据修改
	PurCompareDAO dao;
	return dao.updatePurCom(data) == 1;
}

bool PurCompareService::removePurCom(const DelPurComDTO& dto)
{
	DelPurComDO data;
	data.setBillId(dto.getBillId());

	PurCompareDAO dao;
	return dao.deletePurCom(data) == 1;
}

bool PurCompareService::updatePurComBillStatus(const PurComModBillStatusDTO& dto, PayloadDTO payload)
{
	ModPurComBillStatusDO data;
	data.setBillId(dto.getBillId());
	data.setIsEffect(dto.getIsEffect());
	data.setIsClose(dto.getIsClose());
	data.setIsCancelled(dto.getIsCancelled());

	data.setUpdatePerson(payload.getUsername());

	PurCompareDAO dao;
	return dao.updatePurComBillStatus(data) == 1;
}
