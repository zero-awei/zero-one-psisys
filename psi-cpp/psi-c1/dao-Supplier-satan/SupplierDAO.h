#pragma once
#pragma once
/*
 @Author: Satan
 @Date: 2023/2/17
*/
#ifndef _SUPPLIER_DAO_
#define _SUPPLIER_DAO_
#include "BaseDAO.h"
#include "../psi-c1/domain/do/SupplierDO-satan/SupplierDO.h"

/**
 * 示例表数据库操作实现
 */
class SupplierDAO : public BaseDAO
{
public:
	// 高级查询-分页查询
	list<SupplierDO> AdvancedSelectWithPage(const SupplierDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// 查询指定供应商
	list<SupplierDO> SpecifiedSelect(const uint64_t& code);
	// 插入数据
	uint64_t SupplierInsert(const SupplierDO& iObj);
	// 修改数据
	int SupplierUpdateById(const SupplierDO& uObj);
	// 通过ID删除数据
	int SupplierDeleteById(uint64_t id);
};
#endif // !_SUPPLIER_DAO_

