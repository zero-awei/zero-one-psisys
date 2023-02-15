#ifndef _BILLSTAGE_VO_
#define _BILLSTAGE_VO_

#include "../GlobalInclude.h"

/*
单据阶段下拉列表
Author C1-三木
2023.2.11 18点11分
*/
	class BillStageVO
{
	// 阶段编号
	CC_SYNTHESIZE(int, id, Id);
	// 阶段名称
	CC_SYNTHESIZE(string, name, Name);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(BillStageVO, id, name);
};

#endif //_BILLSTAGE_VO_