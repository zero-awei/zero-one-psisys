#include "stdafx.h"
#include "ImportSupplierController.h"

JsonVO<bool> ImportSupplierController::execImportSupplier(const FileDTO& dto)
{ 
	JsonVO<bool> res;
	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}
	//响应结果
	res.success(true);
	return res;
}
