#include "stdafx.h"
#include "../../GlobalInclude.h"

#ifndef _PUR_QUOT_MOD_BILL_STATUS_VO_
#define _PUR_QUOT_MOD_BILL_STATUS_VO_


//修改单据状态
class PurQuotModBillStatusVO
{
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据阶段
	CC_SYNTHESIZE(int, billStage, BillStage);
	//是否生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//是否已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotModBillStatusVO, billNo, billStage, isEffective, isClosed, isVoided);
};


#endif // !_PUR_QUOT_MOD_BILL_STATUS_VO_
