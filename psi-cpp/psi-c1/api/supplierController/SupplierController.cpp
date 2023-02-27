#include "stdafx.h"
#include "SupplierController.h"
#include "../../service/supplierService/service-supplier-satan/SupplierServiceSatan.h"
//高级查询
JsonVO<PageVO<AdvancedQueryVO>>  SupplierController::execAdvancedQuerySupplier(const AdvancedQuery & query, const PayloadDTO& payload)
{
	//定义一个Service
	SupplierService service;
	//查询数据
	PageVO<AdvancedQueryVO> result = service.advancedListSupplierData(query);
	//响应结果
	return JsonVO<PageVO<AdvancedQueryVO>>(result, RS_SUCCESS);

}

//查询指定供应商
JsonVO<SpecifiedSupplierDataQueryVO> SupplierController::execSpecifiedQuerySupplier(const SpecifiedSupplierDataQuery& query)
{
	//定义一个Service
	SupplierService service;
	//查询数据（核心）
	SpecifiedSupplierDataQueryVO result = service.specifiedListSupplierData(query);
	//返回结果
	return JsonVO<SpecifiedSupplierDataQueryVO>(result, RS_SUCCESS);
}

//添加供应商
JsonVO<string> SupplierController::execAddSupplier(const AddSupplierDTO& dto, const PayloadDTO& payload)//返回string类型是因为code是string类型
{
	JsonVO<string> result;//返回文件保存的路径
	SupplierService service;
	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}
	//数据库中要求非空数据的检查
	if (dto.getCode().empty()|| dto.getName().empty() || dto.getAux_Name().empty() || dto.getIs_Enabled() == -2)
	{
		result.fail(dto.getID());//使用状态码
		return result;
	}
	//执行数据插入数据库    (核心)
	uint64_t id =service.addSupplierData(dto, payload);
	cout <<"user_name"<< payload.getUsername() << endl;
	//判断插入是否成功
	if (id > 0) 
	{
		
		string file_router;
		for (auto file_segment : dto.getFiles())
		{
			file_router = file_router + file_segment;
		}
		result.success(file_router);
	}
	else
	{
		result.fail(dto.getID());
	}
	return result;
}
//修改
JsonVO<string> SupplierController::execModifySupplier(const ModifySupplierDTO& dto, const PayloadDTO& payload)//返回string类型是因为code是string类型
{
	JsonVO<string> result;//返回文件保存的路径
	SupplierService service;

	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}
	//数据库中要求非空数据的检查
	if (dto.getCode().empty()|| dto.getName().empty()|| dto.getAux_Name().empty() || dto.getIs_Enabled() == -2)
	{

		JsonVO<string> result;
		result.fail(dto.getID());//使用状态码
		return result;
	}
	//执行数据插入数据库
	uint64_t id = service.modifySupplierData(dto, payload);
	//判断插入是否成功
	if (id > 0)
	{

		string file_router;
		for (auto file_segment : dto.getFiles())
		{
			file_router = file_router + file_segment;
		}
		result.success(file_router);
	}
	else
	{
		result.fail(dto.getID());
	}
	return result;

}

JsonVO<string> SupplierController::execDeleteSupplier(const DeleteSupplierDTO& dto)//返回string类型是因为code是string类型
{
	SupplierService service;
	JsonVO<string> result;
	//执行数据删除
	DeleteSupplierDTO delete_supplier_code;
	delete_supplier_code.setID(dto.getID());
	if (service.deleteSupplierData(delete_supplier_code) )
	{
		result.success(dto.getID());
	}
	else
	{
		result.fail(dto.getID());
	}
	return result;
}








