#pragma once

#ifndef _PUR_COMPARE_QUERY_
#define _PUR_COMPARE_QUERY_

#include "../PageQuery.h"

/**
 *  比价单列表查询对象
 */
class PurCompareQuery : public PageQuery
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期_开始
	CC_SYNTHESIZE(string, billDateBegin, BillDateBegin);
	// 单据日期_结束
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	// 已生效
	CC_SYNTHESIZE(string, isEffective, IsEffective);
	// 已关闭
	CC_SYNTHESIZE(string, isClosed, IsClosed);
	// 已作废
	CC_SYNTHESIZE(string, isVoided, IsVoided);
public:
	// 绑定from_json
	friend void from_json(const json& j, PurCompareQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDateBegin);
		BIND_FROM_TO_NORMAL(j, t, billDateEnd);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_NORMAL(j, t, isEffective);
		BIND_FROM_TO_NORMAL(j, t, isClosed);
		BIND_FROM_TO_NORMAL(j, t, isVoided);
	}
};

/**
 *  指定的比价单详细信息查询对象
 */
class AssignPurCompareQuery
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);	
public:
	// 绑定from_json
	friend void from_json(const json& j, AssignPurCompareQuery& t) { // NOLINT		
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};
#endif 


