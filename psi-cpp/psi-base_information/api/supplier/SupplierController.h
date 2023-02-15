/*Author:Satan*/
#pragma once
#ifndef _SUPPLIER_CONTROLLER_
#define _SUPPLIER_CONTROLLER_

#include "../../domain/dto/supplier/AddSupplierDTO.h"
#include "../../domain/dto/supplier/DeleteSupplierDTO.h"
#include "../../domain/dto/supplier/ModifySupplierDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/dto/FileDTO.h"
#include "../../domain/vo/supplier/AdvancedQueryVO.h"
#include "../../domain/vo/supplier/SpecifiedSupplierDataQueryVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/query/PageQuery.h"
#include "../../domain/query/supplier/AdvancedQuery.h"
#include "../../domain/query/supplier/SpecifiedSupplierDataQuery.h"


class SupplierController
{
	public://这里刚刚用错了函数                                                                                   
	CREATE_API_FUN_QUERY(advancedquerySupplier,execAdvancedQuerySupplier,AdvancedQuery);//AdvancedQuery是查询时要传入的东西
	/*宏也是定义函数啊，这里面定义的函数querySample会调用executeXXX，并且规定参数类型，然后宏定义的函数querySample被Router调用*/
	CREATE_API_FUN_QUERY(specifiedquerySupplier,execSpecifiedQuerySupplier,SpecifiedSupplierDataQuery);//和这行导致的报错
	CREATE_API_FUN_BODY(addSupplier, execAddSupplier, AddSupplierDTO);
	CREATE_API_FUN_BODY(modifySupplier, execModifySupplier, ModifySupplierDTO);
	CREATE_API_FUN_BODY(deleteSupplier, execDeleteSupplier, DeleteSupplierDTO);



private:
	////演示高级查询数据
	JsonVO<PageVO<AdvancedQueryVO>> execAdvancedQuerySupplier(const AdvancedQuery& query);
	////演示查询指定供应商数据
	JsonVO<PageVO<SpecifiedSupplierDataQueryVO>> execSpecifiedQuerySupplier(const SpecifiedSupplierDataQuery& query);//就是这一行
	//演示新增数据
	JsonVO<uint64_t> execAddSupplier(const AddSupplierDTO& dto);
	//演示修改数据
	JsonVO<uint64_t> execModifySupplier(const ModifySupplierDTO& dto);
	//演示删除数据
	JsonVO<uint64_t> execDeleteSupplier(const DeleteSupplierDTO& dto);


};

#endif // _SUPPLIER_CONTROLLER_