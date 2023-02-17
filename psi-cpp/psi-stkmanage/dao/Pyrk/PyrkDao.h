#pragma once
#ifndef _PYRK_DAO_
#define _PYRK_DAO_
#include "BaseDAO.h"
#include"domain/do/Pyrk/QueryPyrkBillListDo.h"
class PyrkDao : public BaseDAO {
	// 统计数据条数
	uint64_t count(const QueryPyrkBillListDo& Obj);
};





#endif