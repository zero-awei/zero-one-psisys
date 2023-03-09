#include "stdafx.h"
#include "ImportAccountService.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "SnowFlake.h"
#include "../../domain/do/bank-account/ImportAccountDO.h"
#include "../../dao/bank-account/ImportAccountDAO.h"

/*
* 账户信息导入
* @Author: Oxygen
* @Date: 2023/2/22 12:27:33
*/
const int datacenterId = 1;
const int machineId = 1;
uint64_t ImportAccountService::saveData(const FileDTO& dto)
{
	ExcelComponent excel;
	uint64_t res = 0;
	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
		//从文件中读取
		ImportAccountDO data;
		std::string sheetName = CharsetConvertHepler::ansiToUtf8("银行账户");
		auto readData = excel.readIntoVector(file, sheetName);
		int rows = 0;
		for (auto row : readData)
		{
			rows++;
			if (rows <= 3)	continue;
			/*for (auto cellVal : row)
			{
				cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
			}
			cout << endl;*/
			//生成随机id
			SnowFlake sf(datacenterId, machineId);
			uint64_t ID = sf.nextId();
			data.setId(to_string(ID));
			int i = 0;
			data.setAccountNo(row.at(i++));
			data.setName(row.at(i++));
			data.setCurrency(row.at(i++));
			//cout << "Init_bal" << CharsetConvertHepler::utf8ToAnsi(row.at(i)) << endl;
			data.setInit_bal(stod(row.at(i++)));
			data.setBankNo(row.at(i++));
			data.setBankAddress(row.at(i++));
			data.setManager(row.at(i++));
			data.setRemark(row.at(i++));
			i++;
			string is_enabled = row.at(i++);
			int flag = 0;
			if (is_enabled == "是")	flag = 1;
			data.setIsEnabled(flag);
			// 执行数据添加
			ImportAccountDAO dao;
			dao.insert(data);
			res++;
		}
	}
	cout << "res" << res << endl;
	return res;
}
