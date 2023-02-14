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
	public:
	CREATE_API_FUN_QUERY_PAYLOAD(advancedquerySupplier,execAdvancedQuerySupplier,AdvancedQuery);//AdvancedQuery是查询时要传入的东西
	/*宏也是定义函数啊，这里面定义的函数querySample会调用executeXXX，并且规定参数类型，然后宏定义的函数querySample被Router调用*/
	CREATE_API_FUN_QUERY_PAYLOAD(specifiedquerySupplier,exeSpecifiedexecQuerySupplier,SpecifiedSupplierDataQuery);//和这行导致的报错
	CREATE_API_FUN_BODY(addSupplier, execAddSupplier, AddSupplierDTO);
	CREATE_API_FUN_BODY(modifySupplier, execModifySupplier, ModifySupplierDTO);
	CREATE_API_FUN_BODY(deleteSupplier, execDeleteSupplier, DeleteSupplierDTO);//你是不是现在把报错的码注释了1一部分；？；对；就是要找那里有问题啊，本来有两个报错，我现在就是找到报错的地方了你看看你看不看的出来；要是不行的画就晚点阿伟下课再说吧



private:
	////演示高级查询数据
	JsonVO<PageVO<AdvancedQueryVO>> execAdvancedQuerySupplier(const AdvancedQuery& query, const PayloadDTO& payload);
	////演示查询指定供应商数据
	JsonVO<PageVO<SpecifiedSupplierDataQueryVO>> exeSpecifiedexecQuerySupplier(const SpecifiedSupplierDataQuery& query, const PayloadDTO& payload);//就是这一行
	//演示新增数据
	JsonVO<uint64_t> execAddSupplier(const AddSupplierDTO& dto);
	//演示修改数据
	JsonVO<uint64_t> execModifySupplier(const ModifySupplierDTO& dto);
	//演示删除数据
	JsonVO<uint64_t> execDeleteSupplier(const DeleteSupplierDTO& dto);


};

#endif // _SUPPLIER_CONTROLLER_