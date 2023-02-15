#include "stdafx.h"
#include "SupplierController.h"

JsonVO<PageVO<AdvancedQueryVO>>  SupplierController::execAdvancedQuerySupplier(const AdvancedQuery& query)//1知道啦
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
JsonVO<PageVO<SpecifiedSupplierDataQueryVO>> SupplierController::execSpecifiedQuerySupplier(const SpecifiedSupplierDataQuery& query)
{



	JsonVO<PageVO<SpecifiedSupplierDataQueryVO>> result;   //好了okok谢啦
	return result;
}


JsonVO<uint64_t> SupplierController::execAddSupplier(const AddSupplierDTO& dto)
{


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


