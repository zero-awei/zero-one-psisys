#pragma once
#pragma once
#ifndef _QUERYDOCLIST_QUERY_
#define _QUERYDOCLIST_QUERY_

#include "../PageQuery.h"

/**
 * 查询单据详细信息
 */
class QueryDocListQuery		:public PageQuery
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//已生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);


public:
	// 绑定from_json
	friend void from_json(const json& j, QueryDocListQuery& t) { // NOLINTq
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t,isVoided);
	}
};

#endif // !_QUERYDOCLIST_QUERY_