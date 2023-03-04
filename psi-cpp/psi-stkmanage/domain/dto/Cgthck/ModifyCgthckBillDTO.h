#ifndef _MODIFY_CGTHCK_BILL_DTO_
#define _MODIFY_CGTHCK_BILL_DTO_

#include "../../GlobalInclude.h"
/**
* 采购退货出库(红入), 修改采购退货出库单(审批)数据传输对象
*/
class ModifyCgthckBillDTO
{
	// 单据编号
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// 单据阶段
	CC_SYNTHESIZE(std::string, billStage, BillStage);
	// 核批结果类型
	CC_SYNTHESIZE(std::string, approvalResultType, ApprovalResultType);
	// 核批意见
	CC_SYNTHESIZE(std::string, approvalRemark, ApprovalRemark);
	// 备注
	CC_SYNTHESIZE(std::string, remark, Remark);
public:
	friend void from_json(const json& j, ModifyCgthckBillDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_NORMAL(j, t, approvalResultType);
		BIND_FROM_TO_NORMAL(j, t, approvalRemark);
	}
};

#endif  // !_MODIFY_DOC_LIST_DTO_
