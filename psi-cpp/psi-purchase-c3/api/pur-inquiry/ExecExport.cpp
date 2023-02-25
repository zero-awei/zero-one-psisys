#include "stdafx.h"
#include "ExecExport.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"

bool execexport(vector<std::string> head, string sheetname, PageVO<PurInquiryExportVO> pages) {
	std::string filename = u8"../../public/temporaryfile/testExportExcel.xlsx";
	vector<vector<std::string>> data;
	data.push_back(head);
	for (auto r : pages.getRows())
	{
		vector<std::string> row;
		row.push_back(r.getPayment_method());
		row.push_back(r.getDelivery_place());
		row.push_back(r.getDelivery_time());
		row.push_back(r.getContact());
		row.push_back(r.getPhone());
		row.push_back(r.getFax());
		row.push_back(r.getEmail());
		//row.push_back(r.getQty());
		//row.push_back(r.getTax_rate());
		//row.push_back(r.getPrice());
		//row.push_back(r.getAmt());
		//row.push_back(r.getCustom1());
		//row.push_back(r.getEntry_src_no());
		//row.push_back(r.getEntry_no());
		//row.push_back(r.getCustom2());
		//row.push_back(r.getEntry_src_bill_id());
		//row.push_back(r.getEntry_src_bill_type());
		//row.push_back(r.getEntry_remark());
		//row.push_back(r.getEntry_bill_no());
		row.push_back(r.getSrc_bill_id());
		//row.push_back(r.getIs_effective());
		row.push_back(r.getAttachment());
		row.push_back(r.getSrc_bill_id());
		row.push_back(r.getSubject());
		row.push_back(r.getBill_stage());
		row.push_back(r.getSrc_no());
		//row.push_back(r.getIs_auto());
		row.push_back(r.getRemark());
		row.push_back(r.getBpmi_instance_id());
		//row.push_back(r.getIs_voided());
		row.push_back(r.getBill_no());
		//row.push_back(r.getIs_rubric());
		row.push_back(r.getSrc_bill_type());
		row.push_back(r.getCreate_time());
		row.push_back(r.getEffective_time());
		row.push_back(r.getApprover());
		row.push_back(r.getUpdate_by());
		row.push_back(r.getSys_org_code());
		//row.push_back(r.getIs_closed());
		row.push_back(r.getApproval_result_type());
		row.push_back(r.getCreate_time());
		row.push_back(r.getCreate_by());
		row.push_back(r.getApproval_remark());
		data.push_back(row);
	}

	// 明细列表


	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(filename, sheetname, data);


	////定义保存数据位置和页签名称
	//std::string fileName = "./public/temporaryfile/testExportExcel.xlsx";
	//std::string sheetName = CharsetConvertHepler::ansiToUtf8("数据表");

	////保存到文件
	//ExcelComponent excel;
	//excel.writeVectorToFile(fileName, sheetName, data);


	return true;
}