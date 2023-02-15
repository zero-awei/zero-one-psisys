#include "stdafx.h"
#include "ImportSupplierController.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"

JsonVO<bool> ImportSupplierController::execImportSupplier(const FileDTO& dto)
{ 
	JsonVO<bool> res;
	ExcelComponent excel;
	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
		//从文件中读取
		std::string sheetName = CharsetConvertHepler::ansiToUtf8("数据表");
		auto readData = excel.readIntoVector(file, sheetName);
		for (auto row : readData)
		{
			for (auto cellVal : row)
			{
				cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
			}
			cout << endl;
		}
	}
	//响应结果
	res.success(true);
	return res;
}
