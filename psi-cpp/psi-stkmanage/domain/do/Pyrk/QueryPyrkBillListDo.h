#pragma once
#ifndef _Q_P_B_L_DO
#define _Q_P_B_L_DO

#include "../../GlobalInclude.h"
/*
* 用于单据列表查询的条件封装类
*/
class QueryPyrkBillListDo {
	// 单据编号
	CC_SYNTHESIZE(string, id, Id);
	// 单据起始日期
	CC_SYNTHESIZE(string, beginData, BeginData);
	// 单据结束日期
	CC_SYNTHESIZE(string, endData, EndData);
	// 单据主题
	CC_SYNTHESIZE(string, theme, Theme);
	// 单据阶段
	CC_SYNTHESIZE(int, stage, Stage);
	// 已生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	// 已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	// 已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
};
#endif
