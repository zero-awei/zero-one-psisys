#pragma once

#ifndef M_Q_B_S_DO
#define M_Q_B_S_DO  

#include "../../GlobalInclude.h"
class ModifyQtrkBillStatusDO {
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
};
#endif // !M_Q_B_S_DO
