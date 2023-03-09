#pragma once
#pragma once
#ifndef _QUERYQTRKBILLLIST_QUERY_
#define _QUERYQTRKBILLLIST_QUERY_

#include "../PageQuery.h"

/**
 * 查询单据详细信息
 */
class QueryQtrkBillListQuery :public PageQuery
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期(开始)
	CC_SYNTHESIZE(string, billDateStart, BillDateStart);
	//单据日期(结束)
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//已生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);


public:
	QueryQtrkBillListQuery()
	{
		billNo = "";
		billDateStart = "";
		billDateEnd = "";
		subject = "";
		billStage = "";
		supplierId = "";
		isEffective = -1;
		isVoided = -1;
		isClosed = -1;
	}
	// 绑定from_json
	friend void from_json(const json& j, QueryQtrkBillListQuery& t) { // NOLINTq
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDateStart);
		BIND_FROM_TO_NORMAL(j, t, billDateEnd);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
	}
};

#endif // !_QUERYZDRKBILLLIST_QUERY_