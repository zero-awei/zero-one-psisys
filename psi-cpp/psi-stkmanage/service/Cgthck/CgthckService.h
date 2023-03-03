#pragma once

#ifndef _CGTHRK_SERVICE_
#define _CGTHRK_SERVICE_
#include <list>
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgthckBillVO.h"
#include "../psi-stkmanage/domain/query/Cgthck/QueryCgthckBillQuery.h"
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgthrkDetailedBillVO.h"
#include"../../domain/dto/Cgthck/CgthckBillDetailedDTO.h"
#include"../../domain/do/Cgthck/QueryCgthrkBillDetailedReturnDO.h"

class CgthckService {
public:
	// 分页查询单据列表
	PageVO<QueryCgthckBillVO> queryAllFitBill(const QueryCgthckBillQuery& query);

	// 查询详细信息
	QueryCgthrkDetailedBillVO queryBillDetial(const CgthckBillDetailedDTO& query);
};



#endif
