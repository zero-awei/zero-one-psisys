#pragma once

#ifndef _PYRK_SERVICE_
#define _PYRK_SERVICE_
#include <list>
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/Pyrk/QueryPyrkBillListVO.h"
#include "../../domain/query/Pyrk/QueryPyrkBillListQuery.h"
#include "../../domain/dto/Pyrk/PyrkBillDetailDTO.h"
#include "../../domain/dto/Pyrk/ImportPyrkFileDTO.h"
#include "../../domain/dto/Pyrk/ApprovalDTO.h"

/*
* 盘盈入库服务
*/
class PyrkService {
public:
	// 分页查询单据列表
	PageVO<QueryPyrkBillListVO> queryAllFitBill(const QueryPyrkBillListQuery& query);
	// 保存数据
	int saveData(const PyrkBillDetailDTO& dto, const PayloadDTO& payload);
	// 修改单据审核信息
	int updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload);
};

#endif // !_PYRK_SERVICE_