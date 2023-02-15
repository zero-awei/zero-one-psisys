#include "stdafx.h"
#include "SupplierController.h"

JsonVO<PageVO<AdvancedQueryVO>>  SupplierController::execAdvancedQuerySupplier(const AdvancedQuery& query)
{
	//定义一个Service
	//SampleService service;
	//查询数据
	//PageVO<SampleVO> result = service.listAll(query);
	//响应结果
	
	
	PageVO< AdvancedQueryVO> data;

	JsonVO<PageVO<AdvancedQueryVO>> result;
	result.success(data);
	return result;

}

//这里返回值错了，头文件的返回值也错了，就这些；ok等等我理一理
JsonVO<SpecifiedSupplierDataQueryVO> SupplierController::execSpecifiedQuerySupplier(const SpecifiedSupplierDataQuery& query)
{
	


	JsonVO<SpecifiedSupplierDataQueryVO> result;  
	return result;
}


JsonVO<uint64_t> SupplierController::execAddSupplier(const AddSupplierDTO& dto)
{
	int code = dto.getCode();
	string name = dto.getName();
	string alias = dto.getAlias();
	string enable = dto.getEnable();
	string accessibleName = dto.getAccessibleName();
	if (code == NULL||name==NULL|| alias==NULL||enable==NULL||accessibleName==NULL)
	{
		JsonVO<uint64_t> result; 
		result.fail(code);//使用状态码
		return result;
	}
	JsonVO<uint64_t> result;
	return result;

}

JsonVO<uint64_t> SupplierController::execModifySupplier(const ModifySupplierDTO& dto)
{


	JsonVO<uint64_t> result;
	return result;

}

JsonVO<uint64_t> SupplierController::execDeleteSupplier(const DeleteSupplierDTO& dto)
{



	JsonVO<uint64_t> result;
	return result;

}


