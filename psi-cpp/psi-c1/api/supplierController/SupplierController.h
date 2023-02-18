/*Author:Satan*/
#pragma once
#ifndef _SUPPLIER_CONTROLLER_
#define _SUPPLIER_CONTROLLER_

#include "../../domain/dto/supplierDTO/AddSupplierDTO.h"
#include "../../domain/dto/supplierDTO/DeleteSupplierDTO.h"
#include "../../domain/dto/supplierDTO/ModifySupplierDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/dto/FileDTO.h"
#include "../../domain/vo/supplierVO/AdvancedQueryVO.h"
#include "../../domain/vo/supplierVO/SpecifiedSupplierDataQueryVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/query/PageQuery.h"
#include "../../domain/query/supplierQuery/AdvancedQuery.h"
#include "../../domain/query/supplierQuery/SpecifiedSupplierDataQuery.h"


class SupplierController
{
	public:                                                                                
	CREATE_API_FUN_QUERY(advancedquerySupplier,execAdvancedQuerySupplier,AdvancedQuery);//AdvancedQuery是查询时要传入的东西
	/*宏也是定义函数啊，这里面定义的函数querySample会调用executeXXX，并且规定参数类型，然后宏定义的函数querySample被Router调用*/
	CREATE_API_FUN_QUERY(specifiedquerySupplier,execSpecifiedQuerySupplier,SpecifiedSupplierDataQuery);//和这行导致的报错
	//添加供应商并上传文件
	CREATE_API_FUN_BODY_FILE(addSupplier, execAddSupplier, AddSupplierDTO);
	CREATE_API_FUN_BODY(modifySupplier, execModifySupplier, ModifySupplierDTO);
	CREATE_API_FUN_BODY(deleteSupplier, execDeleteSupplier, DeleteSupplierDTO);

private:
	//高级查询数据--分页查询
	JsonVO<PageVO<AdvancedQueryVO>> execAdvancedQuerySupplier(const AdvancedQuery& query);
	//查询指定供应商数据--不是分页查询
	JsonVO<SpecifiedSupplierDataQueryVO> execSpecifiedQuerySupplier(const SpecifiedSupplierDataQuery& query);//就是这一行
	//新增数据
	JsonVO<uint64_t> execAddSupplier(const AddSupplierDTO& dto);
	//修改数据
	JsonVO<uint64_t> execModifySupplier(const ModifySupplierDTO& dto);
	//删除数据
	JsonVO<uint64_t> execDeleteSupplier(const DeleteSupplierDTO& dto);

};

#endif // _SUPPLIER_CONTROLLER_