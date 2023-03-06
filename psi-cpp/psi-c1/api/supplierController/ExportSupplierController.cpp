#include "stdafx.h"
#include "ExportSupplierController.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"
#include "../../service/supplierService/ExportSupplierService.h"
using namespace std;

JsonVO<std::string> ExportSupplierController::execExportSupplier(const list<ExportSupplierQuery>& query, const PayloadDTO& payload)
{
	vector<vector<std::string>> data;
	data.push_back({ CharsetConvertHepler::ansiToUtf8("供应商报表") });
	vector<std::string> header{
		CharsetConvertHepler::ansiToUtf8("编码"),
		CharsetConvertHepler::ansiToUtf8("名称"),
		CharsetConvertHepler::ansiToUtf8("简称"),
		CharsetConvertHepler::ansiToUtf8("助记名"),
		CharsetConvertHepler::ansiToUtf8("供应商分类"),
		CharsetConvertHepler::ansiToUtf8("供应商等级"),
		CharsetConvertHepler::ansiToUtf8("纳税规模"),
		CharsetConvertHepler::ansiToUtf8("所属总公司"),
		CharsetConvertHepler::ansiToUtf8("所属地区"),
		CharsetConvertHepler::ansiToUtf8("业务区域"),
		CharsetConvertHepler::ansiToUtf8("客户地址"),
		CharsetConvertHepler::ansiToUtf8("客户网站"),
		CharsetConvertHepler::ansiToUtf8("法人代表"),
		CharsetConvertHepler::ansiToUtf8("法人电话"),
		CharsetConvertHepler::ansiToUtf8("财务信息联系人"),
		CharsetConvertHepler::ansiToUtf8("财务信息联系电话"),
		CharsetConvertHepler::ansiToUtf8("开票信息单位名称"),
		CharsetConvertHepler::ansiToUtf8("开票信息税号"),
		CharsetConvertHepler::ansiToUtf8("开票信息开户行"),
		CharsetConvertHepler::ansiToUtf8("开票信息银行账号"),
		CharsetConvertHepler::ansiToUtf8("开票信息账号"),
		CharsetConvertHepler::ansiToUtf8("开票信息联系电话"),
		CharsetConvertHepler::ansiToUtf8("开票地址"),
		CharsetConvertHepler::ansiToUtf8("办款资料单位名称"),
		CharsetConvertHepler::ansiToUtf8("办款资料开户行"),
		CharsetConvertHepler::ansiToUtf8("办款资料行号"),
		CharsetConvertHepler::ansiToUtf8("办款资料账号"),
		CharsetConvertHepler::ansiToUtf8("收件信息收件人"),
		CharsetConvertHepler::ansiToUtf8("收件信息联系电话"),
		CharsetConvertHepler::ansiToUtf8("收件信息传真"),
		CharsetConvertHepler::ansiToUtf8("recvEmail"),
		CharsetConvertHepler::ansiToUtf8("收件信息地址"),
		CharsetConvertHepler::ansiToUtf8("收件信息邮编"),
		CharsetConvertHepler::ansiToUtf8("附件"),
		CharsetConvertHepler::ansiToUtf8("是否启用"),
		CharsetConvertHepler::ansiToUtf8("备选供应商"),
		CharsetConvertHepler::ansiToUtf8("备注"),
		CharsetConvertHepler::ansiToUtf8("版本"),
	};
	data.push_back(header);
	stringstream ss;

	ExportSupplierService service;
	list<list<ExportSupplierDO>> vo = service.listAll(query);
	for (list<ExportSupplierDO> i : vo)
	{
		for (ExportSupplierDO sub : i) {
			vector<std::string> row;
			ss.clear();
			ss << sub.getCode();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getName();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getShortName();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getAuxName();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getSupplierCategory();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getSupplierLevel();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getTaxScale();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getHeadquarters();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getArea();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getBizArea();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getAddress();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getWebsite();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getLegalPerson();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getLegalPersonPhone();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getFinancialContacts();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getFinancialPhone();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoiceCompany();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoiceTaxCode();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoiceBankName();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoiceBankCode();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoiceAccount();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoicePhone();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoiceAddress();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getReceiptCompany();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getReceiptBankName();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getReceiptBankCode();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getReceiptAccount();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRecvName();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRecvPhone();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRecvFax();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRecvEmail();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRecvAddress();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRecvPostcode();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getAttachment();
			row.push_back(ss.str());
			ss.str("");

			if (sub.getIsEnabled() == 1) {
				row.push_back(CharsetConvertHepler::ansiToUtf8("是"));
			}

			ss.clear();
			ss << sub.getAlterSuppliers();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRemark();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getVersion();
			row.push_back(ss.str());
			ss.str("");

			data.push_back(row);
		}
	}
	/*for (int i = 1; i <= 10; i++)
	{
		vector<std::string> row;
		for (int j = 1; j <= 5; j++)
		{
			ss.clear();
			ss
				<< CharsetConvertHepler::ansiToUtf8("单元格坐标：(") << i
				<< CharsetConvertHepler::ansiToUtf8(",") << j << ")";
			row.push_back(ss.str());
			ss.str("");
		}
		data.push_back(row);
	}*/

	//定义保存数据位置和页签名称
	std::string fileName = "./public/excel/1.xlsx";
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("supplier");

	//保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	

#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	//定义客户端对象
	FastDfsClient client("1.15.240.108");
#endif

	//上传到FastDFS
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;

	//从FastDFS下载到本地
	/*if (!fieldName.empty())
	{
		std::string path = "./public/fastdfs";
		fileName = client.downloadFile(fieldName, &path);
		std::cout << "download savepath is : " << fileName << std::endl;
	}*/
	//测试删除文件
	/*if (!fieldName.empty())
	{
		std::cout << "delete file result is : " << client.deleteFile(fieldName) << std::endl;
	}*/
	//返回下载地址
	JsonVO<std::string> res;
	res.success("http://1.15.240.108:8888/" + fieldName);
	
    return res;
}
