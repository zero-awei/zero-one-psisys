#include "stdafx.h"
#include "ImportSupplierService.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"

uint64_t ImportSupplierService::saveData(const FileDTO& dto)
{
	ExcelComponent excel;
	uint64_t res = 0;
	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
		//从文件中读取
		ImportSupplierDO data;
		std::string sheetName = CharsetConvertHepler::ansiToUtf8("supplier");
		auto readData = excel.readIntoVector(file, sheetName);
		for (auto row : readData)
		{
			/*for (auto cellVal : row)
			{
				cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
			}
			cout << endl;*/
			int i = 0;
			data.setCode(row.at(i++));
			data.setName(row.at(i++));
			//执行数据添加
			ImportSupplierDAO dao;
			dao.insert(data);
			res++;
		}
		
	}

	return res;
}
