#include "stdafx.h"
#include "SupplierController.h"

JsonVO<PageVO<AdvancedQueryVO>> execAdvancedQuerySupplier(const AdvancedQuery& query)
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


JsonVO<SpecifiedSupplierDataQuery> exeSpecifiedexecQuerySupplier(const SpecifiedSupplierDataQuery& query)
{



	JsonVO<SpecifiedSupplierDataQuery> result;
	return result;
}


JsonVO<uint64_t> execAddSupplier(const AddSupplierDTO& dto)
{


	JsonVO<uint64_t> result;
	return result;

}

JsonVO<uint64_t> execModifySupplier(const ModifySupplierDTO& dto)
{


	JsonVO<uint64_t> result;
	return result;

}

JsonVO<uint64_t> execDeleteSupplier(const DeleteSupplierDTO& dto)
{



	JsonVO<uint64_t> result;
	return result;

}


