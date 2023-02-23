#include "stdafx.h"
#include "ExportAccountController.h"
#include "domain/service/bankAccountService/ExportAccountService.h"
#include "CharsetConvertHepler.h"
#include "domain/do/bankAccountDO/ExportAccountDO.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"

/*
* 账户信息导出
* @Author: Oxygen
* @Date: 2023/2/15 11:20:02
*/
JsonVO<std::string> ExportAccountController::execExportAccountExecl(const ExportAccountQuery& query)
{
	vector<vector<std::string>> data;
	data.push_back({ CharsetConvertHepler::ansiToUtf8("银行账户报表") });
	vector<std::string> header{
		CharsetConvertHepler::ansiToUtf8("账号"),
		CharsetConvertHepler::ansiToUtf8("账户名称"),
		CharsetConvertHepler::ansiToUtf8("币种"),
		CharsetConvertHepler::ansiToUtf8("初始余额"),
		CharsetConvertHepler::ansiToUtf8("行号"),
		CharsetConvertHepler::ansiToUtf8("银行地址"),
		CharsetConvertHepler::ansiToUtf8("账户管理员"),
		CharsetConvertHepler::ansiToUtf8("备注"),
		CharsetConvertHepler::ansiToUtf8("是否启用"),
	};
	data.push_back(header);
	stringstream ss;

	ExportAccountService service;
	list<ExportAccountDO> vo = service.listAll(query);
	for (ExportAccountDO sub : vo)
	{
		vector<std::string> row;
		ss.clear();
		ss << sub.getAccountNo();
		row.push_back(ss.str());
		ss.str("");
		ss.clear();

		ss << sub.getName();
		row.push_back(ss.str());
		ss.str("");
		ss.clear();

		ss << sub.getCurrency();
		row.push_back(ss.str());
		ss.str("");
		ss.clear();

		row.push_back(to_string(sub.getInit_bal()));

		ss << sub.getBankNo();
		row.push_back(ss.str());
		ss.str("");
		ss.clear();

		ss << sub.getBankAddress();
		row.push_back(ss.str());
		ss.str("");
		ss.clear();

		ss << sub.getManager();
		row.push_back(ss.str());
		ss.str("");
		ss.clear();

		ss << sub.getRemark();
		row.push_back(ss.str());
		ss.str("");
		ss.clear();

		row.push_back(to_string(sub.getIsEnabled()));

		data.push_back(row);
	}

	//定义保存数据位置和页签名称
	std::string fileName = "../../public/excel/1.xlsx";
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("银行账户");

#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	//定义客户端对象
	FastDfsClient client("127.0.0.1");
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