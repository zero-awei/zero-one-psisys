#pragma once

#ifndef _ZDRK_SERVICE_
#define _ZDRK_SERVICE_
#include <list>
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/vo/Zdrk/QueryZdrkBillListVO.h"
#include "../psi-stkmanage/domain/query/Zdrk/QueryZdrkBillListQuery.h"
#include "../../domain/query/Zdrk/QueryZdrkBillDetailsQuery.h"
#include "../psi-stkmanage/domain/dto/Zdrk/AddZdrkBillDTO.h"
#include "../psi-stkmanage/domain/dto/Zdrk/ModifyZdrkBillDTO.h"
#include "../psi-stkmanage/domain/dto/Zdrk/ModifyZdrkBillStateDTO.h"
#include "../psi-stkmanage/domain/dto/Zdrk/ApprovalDTO.h"
#include "../../domain/vo/Zdrk/QueryZdrkBillDetailsVO.h"

class ZdrkService {
public:
	// 新增单据数据
	int saveBillData(const AddZdrkBillDTO& dto, const PayloadDTO& payload);
	// 修改单据
	int updateBillData(const ModifyZdrkBillDTO& dto, const PayloadDTO& payload);
	// 审核单据
	int updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload);
	// 关闭单据
	int updateStateToClose(const string& billNo, const PayloadDTO& payload);
	// 反关闭单据
	int updateStateToUnclose(const string& billNo, const PayloadDTO& payload);
	// 作废单据
	int updateStateToVoid(const string& billNo, const PayloadDTO& payload);
	// 删除单据
	int removeBillById(const string& billNo);
	
	// 分页查询所有数据
	PageVO<QueryZdrkBillListVO> listZdrkBillList(const QueryZdrkBillListQuery& query);

	//查询单据详细信息
	QueryZdrkBillDetailsVO getZdrkBillDetails(const QueryZdrkBillDetailsQuery& query);

};

#endif // !_ZDRK_SERVICE_
