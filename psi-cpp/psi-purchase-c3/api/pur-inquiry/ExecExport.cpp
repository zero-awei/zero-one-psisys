#include "stdafx.h"
#include "ExecExport.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include <xlnt/cell/cell_reference.hpp>
#include <xlnt/xlnt_config.hpp>
#include <xlnt/cell/index_types.hpp>
#include "CharsetConvertHepler.h"


std::string execexport(vector<std::string> head, string sheetname, list<std::string>& bill_list) 
{
	PurInquiryDAO dao;
	// 创建文件
	ExcelComponent excel;
	std::vector<std::vector<std::string>> data;
	std::vector<std::string> row;
	std::vector<std::string> row_entry;
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	//定义客户端对象
	FastDfsClient client("1.15.240.108");
#endif
	// 单元格索引
	xlnt::cell_reference A1("A1");
	xlnt::cell_reference AV1("AV1");
	xlnt::cell_reference A2("A2");
	xlnt::cell_reference AV2("AV2");
	// 合并单元格
	excel.mergeCell(sheetname, A1, AV1);
	row.push_back(sheetname);
	data.push_back(row);
	row.clear();
	excel.mergeCell(sheetname, A2, AV2);
	row.push_back(CharsetConvertHepler::ansiToUtf8("导出人：管理员"));
	data.push_back(row);
	row.clear();
	// 读入表头
	data.push_back(head);

	// 打印excel文件
	for (auto exbill_no : bill_list)
	{
		list<PurInquiryDO> exbillnolist = dao.selectPurInquiryExport(exbill_no);
		//如果返回的不是只有一条数据的话就报错
		if (exbillnolist.size() != 1) {
			return "";
		}
		PurInquiryDO ex = exbillnolist.front();
		row.clear();
		row.emplace_back(ex.getBill_no());
		row.emplace_back(ex.getBill_date());
		row.emplace_back(ex.getBill_stage());
		row.emplace_back(ex.getSubject());
		row.emplace_back(ex.getSrc_no());
		row.emplace_back(ex.getSrc_bill_id());
		row.emplace_back(ex.getSrc_bill_type());
		row.emplace_back(ex.getPayment_method());
		row.emplace_back(ex.getDelivery_place());
		row.emplace_back(ex.getDelivery_time());
		row.emplace_back(ex.getContact());
;		row.emplace_back(ex.getPhone());
		row.emplace_back(ex.getFax());
		row.emplace_back(ex.getEmail());
		row.emplace_back(to_string(ex.getQty()));
		row.emplace_back(to_string(ex.getAmt()));
		row.emplace_back(to_string(ex.getQuot_count()));
		row.emplace_back(ex.getRemark());
		row.emplace_back(to_string(ex.getIs_effective()));
		row.emplace_back(ex.getEffective_time());
		row.emplace_back(to_string(ex.getIs_closed()));
		row.emplace_back(to_string(ex.getIs_voided()));
		row.emplace_back(to_string(ex.getIs_auto()));
		row.emplace_back(to_string(ex.getIs_rubric()));
		row.emplace_back(ex.getCreate_by());
		row.emplace_back(ex.getCreate_time());
		row.emplace_back(ex.getSys_org_code());
		row.emplace_back(ex.getUpdate_by());
		row.emplace_back(ex.getAttachment());
		row.emplace_back(ex.getBpmi_instance_id());
		row.emplace_back(ex.getApprover());
		row.emplace_back(ex.getApproval_result_type());
		row.emplace_back(ex.getApproval_remark());
		
		// 明细
		int count = 0;  // 记录明细条数 
		list<PurInquiryEntryDO> exdat = dao.selectPurInquiryExportEntry(exbill_no);
		for (PurInquiryEntryDO ex_entry : exdat)
		{
			//PurInquiryEntryDO ex_entry = exdat.front();
			// 如果当前明细的单据编号和当前单据编号不匹配，则跳过该条明细
			if (exbill_no != ex_entry.getEntry_bill_no())
			{
				continue;
			}
			count++;  
			// 如果不是第一条明细，就换行
			if (count > 1)
			{
				// 重设基础信息容器大小并填入空值，保证明细信息对齐
				row.resize(33);
				std::fill(row.begin(), row.end(), "");
			}
			row_entry.clear();
			row_entry.emplace_back(ex_entry.getEntry_bill_no());
			row_entry.emplace_back(to_string(ex_entry.getEntry_no()));
			row_entry.emplace_back(ex_entry.getEntry_src_bill_id());
			row_entry.emplace_back(ex_entry.getEntry_src_no());
			row_entry.emplace_back(ex_entry.getSrc_entry_id());
			row_entry.emplace_back(ex_entry.getEntry_src_bill_type());
			row_entry.emplace_back(ex_entry.getMaterial_id());
			row_entry.emplace_back(ex_entry.getUnit_id());
			row_entry.emplace_back(to_string(ex_entry.getEntry_qty()));
			row_entry.emplace_back(to_string(ex_entry.getTax_rate()));
			row_entry.emplace_back(to_string(ex_entry.getPrice()));
			row_entry.emplace_back(to_string(ex_entry.getEntry_Amt()));
			row_entry.emplace_back(ex_entry.getCustom1());
			row_entry.emplace_back(ex_entry.getCustom2());
			row_entry.emplace_back(ex_entry.getEntry_remark());
			// 把明细信息放在基础信息后面
			row.insert(row.end(), row_entry.begin(), row_entry.end());
			// 压入当前行
			data.emplace_back(row);
			// 清空基础信息
			row.clear();
		}
	}
	
	//定义保存数据位置（到本地，方便调试）
	std::string filename = CharsetConvertHepler::ansiToUtf8("../../public/temporaryfile/testExportExcel.xlsx");
	// 工作表命名 —— 待完善
	//excel.makeName("采购询价单");
	//设置行高，写入数据
	excel.setRowHeight(38);
	excel.writeVectorToFile(filename, sheetname, data);
	//将文件上传到fastdfs
	std::string fieldName = client.uploadFile(filename);
	//删除本地文件 —— 待完善
	//std::cout << "当前目录为" << std::filesystem::current_path() << endl;
	//_rmdir(filename.c_str());
	//组装下载地址
	fieldName = "http://1.15.240.108:8888/" + fieldName;

	return fieldName;
}