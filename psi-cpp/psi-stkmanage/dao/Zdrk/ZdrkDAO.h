#pragma once

#ifndef _ZDRK_DAO_
#define _ZDRK_DAO_
#include "BaseDAO.h"
#include "../psi-stkmanage/domain/do/Zdrk/QueryZdrkBillDO.h"
#include "../psi-stkmanage/domain/do/Zdrk/QueryZdrkBillListDO.h"

/**
 * 示例表数据库操作实现
 */
class ZdrkDAO : public BaseDAO
{
	// 统计数据条数
public:
	uint64_t count(const queryZdrkBillListDO& iObj);
	// 分页查询数据
	list<queryZdrkBillListDO> selectWithPage(const queryZdrkBillListDO& obj, uint64_t pageIndex, uint64_t pageSize);
	
	/*
	// 通过姓名查询数据
	list<SampleDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const SampleDO& iObj);
	// 修改数据
	int update(const SampleDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
	*/
};
#endif // _ZDRK_DAO_
