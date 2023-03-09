#pragma once
#pragma once
/*
 @Author: Satan
 @Date: 2023/2/17
*/
#ifndef _SUPPLIER_DAO_
#define _SUPPLIER_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/SupplierDO-satan/SupplierDO.h"
#include "../../../domain/query/supplierQuery/AdvancedQuery.h"
/**
 * 示例表数据库操作实现
 */
class SupplierDAO : public BaseDAO
{
public:
	// 统计数据条数————service中写分页查询的时候需要用到
	uint64_t count(const  AdvancedQuery condition);
	// 高级查询-分页查询
	list<SupplierDO> AdvancedSelectWithPage(uint64_t pageIndex, uint64_t pageSize, const AdvancedQuery &condition);
	// 查询指定供应商——不是根据id
	SupplierDO SpecifiedSelect(const string& id);//实际上是没有必要使用list，因为同一个code只能查出一个供应商，但是你看DAO.cpp就发现我们需要的函数的返回值就是list类型的没办法
	// 插入数据
	uint64_t SupplierInsert(const SupplierDO& iObj);
	// 修改数据
	int SupplierUpdateByCode(const SupplierDO& uObj);
	// 通过编号来删除数据——不是根据id
	int SupplierDeleteByCode(string code);
};
#endif // !_SUPPLIER_DAO_

