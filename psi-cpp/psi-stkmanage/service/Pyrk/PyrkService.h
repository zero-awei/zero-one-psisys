#pragma once

#ifndef _PYRK_SERVICE_
#define _PYRK_SERVICE_
#include <list>
#include "../../domain/dto/Pyrk/PyrkBillDetailDTO.h"
#include "../../domain/dto/Pyrk/ImportPyrkFileDTO.h"
#include "../../domain/dto/Pyrk/ApprovalDTO.h"

/*
* 盘盈入库服务
*/
class PyrkService {
public:
	// 新增单据数据
	int saveBillData(const PyrkBillDetailDTO& dto, const PayloadDTO& payload);
	// 审核单据
	int updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload);
	// 修改单据
	int updateBillData(const PyrkBillDetailDTO& dto, const PayloadDTO& payload);
	// 关闭单据
	int updateStateToClose(const string& billNo, const PayloadDTO& payload);
	// 反关闭单据
	int updateStateToUnclose(const string& billNo, const PayloadDTO& payload);
	// 作废单据
	int updateStateToVoid(const string& billNo, const PayloadDTO& payload);
	// 删除单据
	int removeBillById(const string& billNo);
};

#endif // !_PYRK_SERVICE_