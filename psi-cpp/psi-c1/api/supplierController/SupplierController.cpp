#include "stdafx.h"
#include "SupplierController.h"

JsonVO<PageVO<AdvancedQueryVO>>  SupplierController::execAdvancedQuerySupplier(const AdvancedQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	//SampleService service;
	//查询数据
	//PageVO<SampleVO> result = service.listAll(query);
	//响应结果
	PageVO< AdvancedQueryVO> data;
	JsonVO<PageVO<AdvancedQueryVO>> result;
	list< AdvancedQueryVO> rows;
	rows.push_back(AdvancedQueryVO());
	rows.push_back(AdvancedQueryVO());
	rows.push_back(AdvancedQueryVO());
	data.setRows(rows);
	result.success(data);
	return result;

}


JsonVO<SpecifiedSupplierDataQueryVO> SupplierController::execSpecifiedQuerySupplier(const SpecifiedSupplierDataQuery& query)
{
	SpecifiedSupplierDataQueryVO a;


	JsonVO<SpecifiedSupplierDataQueryVO> result;
	result.success(a);
	return result;
}


JsonVO<string> SupplierController::execAddSupplier(const AddSupplierDTO& dto)
{
	string code = dto.getCode();
	string name = dto.getName();
	string alias = dto.getAux_Name();

	int enable = dto.getIs_Enabled();
	
	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}
	if (code == NULL||name==NULL|| alias==NULL||enable==NULL)
	{
		JsonVO<string> result;
		result.fail(code);//使用状态码
		return result;
	}
	JsonVO<string> result;
	return result;

}

JsonVO<string> SupplierController::execModifySupplier(const ModifySupplierDTO& dto)
{


	JsonVO<string> result;
	return result;

}

JsonVO<string> SupplierController::execDeleteSupplier(const DeleteSupplierDTO& dto)
{



	JsonVO<string> result;
	return result;

}

//JsonVO<bool> SupplierController::execAddSupplierImportFile(const FileDTO& dto)
//{
//
//
//
//
//
//	JsonVO <bool> res;
//	res.success(true);
//	return res;
//}
//
//
//JsonVO<std::string> SupplierController::execExportSupplierExecl(const SpecifiedSupplierDataQuery& query)
//{
//	JsonVO <string> res;
//	res.success(u8"123");
//	return res;
//}







