#include "stdafx.h"
#include "ImportAccountService.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "../../do/bankAccountDO/ImportAccountDO.h"
#include "dao/bankAccountDAO/ImportAccountDAO.h"

/*
* 账户信息导入
* @Author: Oxygen
* @Date: 2023/2/22 12:27:33
*/

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
			if (rows < 3)	continue;
			/*for (auto cellVal : row)
			{
				cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
			}
			cout << endl;*/
			int i = 0;
			data.setAccountNo(row.at(i++));
			data.setName(row.at(i++));
			// 执行数据添加
			ImportAccountDAO dao;
			dao.insert(data);
			res++;
		}
	}

	return res;
}
