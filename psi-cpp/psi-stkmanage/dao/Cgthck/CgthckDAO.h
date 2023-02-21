#pragma once
#ifndef _CGTHCK_DAO_
#define _CGTHCK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Cgthck/CgthckDO.h"

using CgthckDO = CgthckBillDetailDO;
 
class CgthckDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const CgthckDO& iobj);
	// 插入数据
	uint64_t insert(const CgthckDO& iobj);
	// 修改数据
	int update(const CgthckDO& iobj);
	// 删除通过单号数据
	int deleteById(const CgthckDO& iobj);
};



#endif // !_CGTHCK_DAO_