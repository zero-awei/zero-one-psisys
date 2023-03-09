#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Satan
 @Date: 2023/2/16 11:08:56

*/
#ifndef _SUPPLIER_SERVICE_
#define _SUPPLIER_SERVICE_
#include <list>
#include "../../../domain/dto/supplier/AddSupplierDTO.h"
#include "../../../domain/dto/supplier/DeleteSupplierDTO.h"
#include "../../../domain/dto/supplier/ModifySupplierDTO.h"
#include "../../../domain/query/supplier/AdvancedQuery.h"
#include "../../../domain/query/supplier/SpecifiedSupplierDataQuery.h"
#include "../../../domain/vo/supplier/AdvancedQueryVO.h"
#include "../../../domain/vo/supplier/SpecifiedSupplierDataQueryVO.h"
#include "../../../domain/vo/PageVO.h"

class SupplierService
{
public:
	// 高级查询
	PageVO<AdvancedQueryVO> advancedListSupplierData(const AdvancedQuery& query);
	//查询指定供应商详细数据
	SpecifiedSupplierDataQueryVO  specifiedListSupplierData(const SpecifiedSupplierDataQuery& query);
	// 添加供应商
	uint64_t addSupplierData(const AddSupplierDTO& dto, const PayloadDTO& payload);
	// 修改供应商
	uint64_t modifySupplierData(const ModifySupplierDTO& dto, const PayloadDTO& payload);
	//删除供应商
	uint64_t deleteSupplierData(const DeleteSupplierDTO& dto);
};


#endif // !_SUPPLIER_SERVICE_