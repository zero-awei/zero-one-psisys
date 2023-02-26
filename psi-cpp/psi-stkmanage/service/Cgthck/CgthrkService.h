#pragma once

#ifndef _CGTHRK_SERVICE_
#define _CGTHRK_SERVICE_
#include <list>
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgthckBillVO.h"
#include "../psi-stkmanage/domain/query/Cgthck/QueryCgthckBillQuery.h"

class CgthrkService {
public:
	// 分页查询单据列表
	PageVO<QueryCgthckBillVO> queryAllFitBill(const QueryCgthckBillQuery& query);
};



#endif
