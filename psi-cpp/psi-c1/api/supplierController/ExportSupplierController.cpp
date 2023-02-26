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
		CharsetConvertHepler::ansiToUtf8("是否启用"),
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

			if (sub.getIsEnabled() == 1) {
				row.push_back(CharsetConvertHepler::ansiToUtf8("是"));
			}

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
