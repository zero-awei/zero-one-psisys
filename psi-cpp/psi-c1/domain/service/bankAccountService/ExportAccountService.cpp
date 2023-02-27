#include "stdafx.h"
#include "ExportAccountService.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"
#include "dao/bankAccountDAO/ExportAccountDAO.h"
#include "../../do/bankAccountDO/ExportAccountDO.h"

/*
* 银行账户导出
* @Author: Oxygen
* @Date: 2023/2/22 10:48:09
*/
JsonVO<std::string> ExportAccountService::listAll(const list<ExportAccountQuery>& query)
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

	ExportAccountDAO dao;
	for (auto x : query) {
		cout << x.getIds() << endl;
	}
	int size = 0;
	//如果传入ID，那么输出该ID的内容
	if (size != 0) {
		for (auto x : query) {
			//查询
			ExportAccountDO obj;
			obj.setId(x.getIds());
			list<ExportAccountDO> reslist = dao.selectAccount(obj);
			ExportAccountDO res;
			if (!reslist.empty()) {
				res = reslist.front();
			}
			reslist.clear();
			vector<std::string> row;
			//打印EXCEL内容
			row.push_back(res.getAccountNo());
			row.push_back(res.getName());
			row.push_back(res.getCurrency());
			row.push_back(to_string(res.getInit_bal()));
			row.push_back(res.getBankNo());
			row.push_back(res.getBankAddress());
			row.push_back(res.getManager());
			row.push_back(res.getRemark());
			int flag = res.getIsEnabled();
			if (flag == 1)	row.push_back(CharsetConvertHepler::ansiToUtf8("是"));
			else row.push_back(CharsetConvertHepler::ansiToUtf8("否"));
			data.push_back(row);
		}
	}
	else {
		ExportAccountDO obj;
		list<ExportAccountDO> reslist = dao.selectAllAccount(obj);
		vector<std::string> row;
		for (auto res : reslist) {
			//打印EXCEL内容
			row.push_back(res.getAccountNo());
			row.push_back(res.getName());
			row.push_back(res.getCurrency());
			row.push_back(to_string(res.getInit_bal()));
			row.push_back(res.getBankNo());
			row.push_back(res.getBankAddress());
			row.push_back(res.getManager());
			row.push_back(res.getRemark());
			int flag = res.getIsEnabled();
			if (flag == 1)	row.push_back(CharsetConvertHepler::ansiToUtf8("是"));
			else row.push_back(CharsetConvertHepler::ansiToUtf8("否"));
			data.push_back(row);
			row.clear();
		}
	}

	//定义保存数据位置和页签名称
	std::string fileName = "../../public/excel/银行账户.xlsx";
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("银行账户");

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
	if (!fieldName.empty())
		std::cout << "upload fieldname is : " << fieldName << std::endl;
	else
		std::cout << "upload fieldname false" << std::endl;

	JsonVO<std::string> res;
	res.success(fieldName);
	return res;
}
