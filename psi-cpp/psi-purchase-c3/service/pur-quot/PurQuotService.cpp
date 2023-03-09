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
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"


#define PUR_QUOT_I_TO_STRING(t) (t==1 ?CharsetConvertHepler::ansiToUtf8("是"):CharsetConvertHepler::ansiToUtf8("否"))
#define PUR_QUOT_STRING_TO_I(s) (s==CharsetConvertHepler::ansiToUtf8("是")? 1 : -1)

//导入
uint64_t PurQuotService::updatePurQuotInto(const PurQuotIntoDTO& dto) {
	//解析excel中的数据
	ExcelComponent excel;
	std::string file_name = dto.getFiles().front();
	std::string sheet_name = CharsetConvertHepler::ansiToUtf8("供应报价单");
	std::string entry_sheet_name = CharsetConvertHepler::ansiToUtf8("明细");
	//将文件的数据转换成二维数组, 谨记:二维数组的第一行是header(文字), 不需要载入数据库
	auto data = excel.readIntoVector(file_name, sheet_name);
	auto entry_data = excel.readIntoVector(file_name, entry_sheet_name);

	//将二维数组转换为DO模型
	list<PurQuotDO> pur_quot_do;
	if (data.size() > 1) {
		for (size_t i = 1; i < data.size(); ++i) {
			//str是一个字符串,是二维数组中的每一个元素
			PurQuotDO tmp_do;
			int j = 0;
			auto tmp_data = data[i];
			auto t = tmp_do.getBill_no();
			tmp_do.setBill_no(tmp_data[j++]);
			t = tmp_do.getBill_no();
			tmp_do.setSupplier_name(tmp_data[j++]);
			tmp_do.setSupplier_id(tmp_data[j++]);
			tmp_do.setPayment_method(tmp_data[j++]);
			tmp_do.setDelivery_place(tmp_data[j++]);
			tmp_do.setDelivery_time(tmp_data[j++]);
			tmp_do.setContact(tmp_data[j++]);
			tmp_do.setPhone(tmp_data[j++]);
			tmp_do.setFax(tmp_data[j++]);
			tmp_do.setEmail(tmp_data[j++]);
			tmp_do.setQty(stod(tmp_data[j++]));
			tmp_do.setAmt(stod(tmp_data[j++]));
			tmp_do.setIs_effective(stoi(tmp_data[j++]));
			tmp_do.setAttachment(tmp_data[j++]);
			tmp_do.setSrc_bill_type(tmp_data[j++]);
			tmp_do.setSubject(tmp_data[j++]);
			tmp_do.setBill_stage(tmp_data[j++]);
			tmp_do.setSrc_no(tmp_data[j++]);
			tmp_do.setIs_auto(stoi(tmp_data[j++]));
			tmp_do.setRemark(tmp_data[j++]);
			tmp_do.setBpmi_instance_id(tmp_data[j++]);
			tmp_do.setIs_voided(stoi(tmp_data[j++]));
			tmp_do.setIs_rubric(stoi(tmp_data[j++]));
			tmp_do.setSrc_bill_type(tmp_data[j++]);
			tmp_do.setCreate_time(tmp_data[j++]);
			tmp_do.setEffective_time(tmp_data[j++]);
			tmp_do.setApprover(tmp_data[j++]);
			tmp_do.setUpdate_by(tmp_data[j++]);
			tmp_do.setSys_org_code(tmp_data[j++]);
			tmp_do.setIs_closed(stoi(tmp_data[j++]));
			tmp_do.setApproval_result_type(tmp_data[j++]);
			tmp_do.setBill_date(tmp_data[j++]);
			tmp_do.setCreate_by(tmp_data[j++]);
			tmp_do.setApproval_remark(tmp_data[j++]);
			pur_quot_do.push_back(tmp_do);
		}
	}

	list<PurQuotEntryDO> pur_quot_entry_do;
	if (entry_data.size() > 1) {
		for (size_t i = 1; i < entry_data.size(); ++i) {
			//str是一个字符串,是二维数组中的每一个元素
			PurQuotEntryDO tmp_entry_do;
			int j = 0;
			auto tmp_data = entry_data[i];
			tmp_entry_do.setBill_no(tmp_data[j++]);
			tmp_entry_do.setMaterial_id(tmp_data[j++]);
			tmp_entry_do.setUnit_id(tmp_data[j++]);
			tmp_entry_do.setQty(stod(tmp_data[j++]));
			tmp_entry_do.setTax_rate(stod(tmp_data[j++]));
			tmp_entry_do.setPrice(stod(tmp_data[j++]));
			tmp_entry_do.setDiscount_rate(stod(tmp_data[j++]));
			tmp_entry_do.setAmt(stod(tmp_data[j++]));
			tmp_entry_do.setCustom1(tmp_data[j++]);
			tmp_entry_do.setSrc_no(tmp_data[j++]);
			tmp_entry_do.setEntry_no(stoi(tmp_data[j++]));
			tmp_entry_do.setCustom2(tmp_data[j++]);
			tmp_entry_do.setSrc_entry_id(tmp_data[j++]);
			tmp_entry_do.setSrc_bill_type(tmp_data[j++]);
			tmp_entry_do.setRemark(tmp_data[j++]);
			tmp_entry_do.setSrc_bill_id(tmp_data[j++]);
			pur_quot_entry_do.push_back(tmp_entry_do);
		}
	}
	//处理list<PurQuotDO>中的pur_quot_do;
	uint64_t result = 0;
	for (auto sub : pur_quot_do) {
		PurQuotDAO dao;
		result = dao.insertPurQuotInto(sub);
	}
	//处理list<PurQuotEntryDO>中的pur_quot_entry_do;
	for (auto sub : pur_quot_entry_do) {
		PurQuotDAO dao;
		result = dao.insertPurQuotInto(sub);
	}
	return result;
}
//导出: 获取多个PurQuotExportVO对象
//导出的思路是: 先通过编号查询对应的pur_quot, 然后通过这个编号查询对应的明细, 这样可以保证: 导出的数据顺序
PurQuotExportVO PurQuotService::listPurQuotExportVO(const PurQuotExportQuery& query) {
	//创建查询对象
	PurQuotDAO dao;
	PurQuotDO pur_quot_do;
	PurQuotEntryDO pur_quot_entry_do;
	//设置sql语句的查询条件
	pur_quot_do.setBill_no(query.getBill_no());
	//返回正确的查询对象
	list<PurQuotDO> list_do = dao.selectPurQuotExport(pur_quot_do);
	//报表的抽象-->二维数组																			
	vector<vector<std::string>> data;
	vector<vector<std::string>> entry_data;
	//表头, 用于填充报表的第一行数据
	vector<string> header{
		CharsetConvertHepler::ansiToUtf8("单据编号"),
		CharsetConvertHepler::ansiToUtf8("是否临时供应商"),
		CharsetConvertHepler::ansiToUtf8("供应商名称"),
		CharsetConvertHepler::ansiToUtf8("供应商"),
		CharsetConvertHepler::ansiToUtf8("付款方式"),
		CharsetConvertHepler::ansiToUtf8("交货地点"),
		CharsetConvertHepler::ansiToUtf8("交货时间"),
		CharsetConvertHepler::ansiToUtf8("联系人"),
		CharsetConvertHepler::ansiToUtf8("联系电话"),
		CharsetConvertHepler::ansiToUtf8("传真"),
		CharsetConvertHepler::ansiToUtf8("电子邮件"),
		CharsetConvertHepler::ansiToUtf8("数量"),
		CharsetConvertHepler::ansiToUtf8("金额"),
		CharsetConvertHepler::ansiToUtf8("是否生效"),
		CharsetConvertHepler::ansiToUtf8("附件"),
		CharsetConvertHepler::ansiToUtf8("源单id"),
		CharsetConvertHepler::ansiToUtf8("单据主题"),
		CharsetConvertHepler::ansiToUtf8("单据阶段"),
		CharsetConvertHepler::ansiToUtf8("源单号"),
		CharsetConvertHepler::ansiToUtf8("是否自动生成"),
		CharsetConvertHepler::ansiToUtf8("备注"),
		CharsetConvertHepler::ansiToUtf8("审批实例id"),
		CharsetConvertHepler::ansiToUtf8("已作废"),
		CharsetConvertHepler::ansiToUtf8("是否红字"),
		CharsetConvertHepler::ansiToUtf8("源单类型"),
		CharsetConvertHepler::ansiToUtf8("制单时间"),
		CharsetConvertHepler::ansiToUtf8("生效时间"),
		CharsetConvertHepler::ansiToUtf8("核批人"),
		CharsetConvertHepler::ansiToUtf8("修改人"),
		CharsetConvertHepler::ansiToUtf8("制单部门"),
		CharsetConvertHepler::ansiToUtf8("已关闭"),
		CharsetConvertHepler::ansiToUtf8("核批结果类型"),
		CharsetConvertHepler::ansiToUtf8("单据日期"),
		CharsetConvertHepler::ansiToUtf8("制单人"),
		CharsetConvertHepler::ansiToUtf8("核批意见"),
	};
	data.push_back(header);
	vector<string> entry_header{
		CharsetConvertHepler::ansiToUtf8("单据编号"),
		CharsetConvertHepler::ansiToUtf8("物料"),
		CharsetConvertHepler::ansiToUtf8("计量单位"),
		CharsetConvertHepler::ansiToUtf8("数量"),
		CharsetConvertHepler::ansiToUtf8("税率%"),
		CharsetConvertHepler::ansiToUtf8("含税单价"),
		CharsetConvertHepler::ansiToUtf8("折扣率%"),
		CharsetConvertHepler::ansiToUtf8("含税金额"),
		CharsetConvertHepler::ansiToUtf8("自定义1"),
		CharsetConvertHepler::ansiToUtf8("源单分录号"),
		CharsetConvertHepler::ansiToUtf8("分录号"),
		CharsetConvertHepler::ansiToUtf8("自定义2"),
		CharsetConvertHepler::ansiToUtf8("源单分录id"),
		CharsetConvertHepler::ansiToUtf8("源单类型"),
		CharsetConvertHepler::ansiToUtf8("备注"),
		CharsetConvertHepler::ansiToUtf8("单据编号"),
		CharsetConvertHepler::ansiToUtf8("源单id"),
	};
	entry_data.push_back(entry_header);
	//如果查询对象不为空
	if (!list_do.empty()) {
		for (auto tmp_do : list_do) {
			vector<string> sub{
				tmp_do.getBill_no(),
				to_string(tmp_do.getIs_temp_supplier()),
				tmp_do.getSupplier_name(),
				tmp_do.getSupplier_id(),
				tmp_do.getPayment_method(),
				tmp_do.getDelivery_place(),
				tmp_do.getDelivery_time(),
				tmp_do.getContact(),
				tmp_do.getPhone(),
				tmp_do.getFax(),
				tmp_do.getEmail(),
				to_string(tmp_do.getQty()),
				to_string(tmp_do.getAmt()),
				to_string(tmp_do.getIs_effective()),
				tmp_do.getAttachment(),
				tmp_do.getSrc_bill_type(),
				tmp_do.getSubject(),
				tmp_do.getBill_stage(),
				tmp_do.getSrc_no(),
				to_string(tmp_do.getIs_auto()),
				tmp_do.getRemark(),
				tmp_do.getBpmi_instance_id(),
				to_string(tmp_do.getIs_voided()),
				to_string(tmp_do.getIs_rubric()),
				tmp_do.getSrc_bill_type(),
				tmp_do.getCreate_time(),
				tmp_do.getEffective_time(),
				tmp_do.getApprover(),
				tmp_do.getUpdate_by(),
				tmp_do.getSys_org_code(),
				to_string(tmp_do.getIs_closed()),
				tmp_do.getApproval_result_type(),
				tmp_do.getBill_date(),
				tmp_do.getCreate_by(),
				tmp_do.getApproval_remark()
			};
			data.push_back(sub);
			//根据编号去查明细	
			pur_quot_entry_do.setBill_no(tmp_do.getBill_no());
			//返回此编号对应的明细
			list<PurQuotEntryDO> list_entry_do = dao.selectPurQuotEntryExport(pur_quot_entry_do);
			if (!list_entry_do.empty()) {
				for (auto tmp_entry_do : list_entry_do) {
					vector<string> entry_sub{
								tmp_entry_do.getBill_no(),
								tmp_entry_do.getMaterial_id(),
								tmp_entry_do.getUnit_id(),
								to_string(tmp_entry_do.getQty()),
								to_string(tmp_entry_do.getTax_rate()),
								to_string(tmp_entry_do.getPrice()),
								to_string(tmp_entry_do.getDiscount_rate()),
								to_string(tmp_entry_do.getAmt()),
								tmp_entry_do.getCustom1(),
								tmp_entry_do.getSrc_no(),
								to_string(tmp_entry_do.getEntry_no()),
								tmp_entry_do.getCustom2(),
								tmp_entry_do.getSrc_entry_id(),
								tmp_entry_do.getSrc_bill_type(),
								tmp_entry_do.getRemark(),
								tmp_entry_do.getSrc_bill_id(),
					};
					entry_data.push_back(entry_sub);
				}
			}
		}
	}
	//定义保存数据位置和页签名称
	std::string file_name = "./public/excel/c3_pur_quot.xlsx";
	std::string sheet_name = CharsetConvertHepler::ansiToUtf8("供应报价单");
	std::string entry_sheet_name = CharsetConvertHepler::ansiToUtf8("明细");

	//保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(file_name, sheet_name, data);
	excel.writeVectorToFile(file_name, entry_sheet_name, entry_data);


	//定义fastdfs客户端对象
#ifdef LINUX
	FastDfsClient client("conf/client.conf", 3);
#else
	FastDfsClient client("1.15.240.108");
#endif
	//将文件上传到fastDFS
	std::string field_name = client.uploadFile(file_name);
	//删除本地文件
	std::remove(file_name.c_str());
	//返回下载地址
	field_name = "http://1.15.240.108:8888/" + field_name;
	PurQuotExportVO result(field_name);
	return result;
}

//查询单据列表
PageVO<PurQuotFindBillVO> PurQuotService::listPurQuotFindBillVO(const PurQuotFindBillQuery& query) {
	//构建返回对象
	PageVO<PurQuotFindBillVO> pages;
	//设置返回对象的Index和Size 
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());
	
	//设置查询条件
	PurQuotDO obj;
	obj.setBill_no(query.getBill_no());
	obj.setSubject(query.getSubject());
	obj.setBill_stage(query.getBill_stage());
	obj.setIs_effective(PUR_QUOT_STRING_TO_I(query.getIs_effective()));
	obj.setIs_closed(PUR_QUOT_STRING_TO_I(query.getIs_closed()));
	obj.setIs_voided(PUR_QUOT_STRING_TO_I(query.getIs_voided()));
	//单据日期开始时间
	obj.setBill_date(query.getBill_date_begin());
	//单据日期截止时间
	std::string bill_date_end = query.getBill_date_end();
	//检查查询到的数据总数

	PurQuotDAO dao;
	uint64_t count = dao.count(obj, bill_date_end);
	//数据总数小于等于0, 直接返回pages
	if (count <= 0)
	{
		return pages;
	}
	//数据总数大于0, 返回分页查询到的VO
	pages.setTotal(count);
	pages.calcPages();
	//接收查询到的DO
	list<PurQuotDO> result = dao.selectPurQuotFindBill(obj, query.getPageIndex(), query.getPageSize(), bill_date_end);
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
		vo.setIs_effective(PUR_QUOT_I_TO_STRING(sub.getIs_effective()));
		vo.setIs_closed(PUR_QUOT_I_TO_STRING(sub.getIs_closed()));
		vo.setIs_voided(PUR_QUOT_I_TO_STRING(sub.getIs_voided()));
		vo.setPayment_method(sub.getPayment_method());
		vo.setDelivery_place(sub.getDelivery_place());
		vo.setContact(sub.getContact());
		vo.setPhone(sub.getPhone());
		vo.setFax(sub.getFax());
		vo.setEmail(sub.getEmail());
		vo.setRemark(sub.getRemark());
		vo.setIs_auto(PUR_QUOT_I_TO_STRING(sub.getIs_auto()));
		vo.setIs_rubric(PUR_QUOT_I_TO_STRING(sub.getIs_rubric()));
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
		vo.setIs_effective(PUR_QUOT_I_TO_STRING(sub.getIs_effective()));
		vo.setIs_closed(PUR_QUOT_I_TO_STRING(sub.getIs_closed()));
		vo.setIs_voided(PUR_QUOT_I_TO_STRING(sub.getIs_voided()));
		vo.setSubject(sub.getSubject());
		vo.setIs_temp_supplier(PUR_QUOT_I_TO_STRING(sub.getIs_temp_supplier()));
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
		vo.setIs_auto(PUR_QUOT_I_TO_STRING(sub.getIs_auto()));
		vo.setIs_rubric(PUR_QUOT_I_TO_STRING(sub.getIs_rubric()));
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
