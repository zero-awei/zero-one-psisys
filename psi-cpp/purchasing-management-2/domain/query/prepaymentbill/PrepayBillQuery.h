#pragma once
#ifndef _PREPAY_BILL_QUERY_
#define _PREPAY_BILL_QUERY_

#include "../PageQuery.h"

/**
 * 采购预付申请-查询预付申请单据列表-查询时可以输入的对象
 */
class PrepayBillQuery : public PageQuery
{

	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据开始日期
	CC_SYNTHESIZE(string, bill_begin_date, Bill_begin_date);
	// 单据结束日期
	CC_SYNTHESIZE(string, bill_end_date, Bill_end_date);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	// 单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 已生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// 已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// 已作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);

public:
	// 绑定from_json
	friend void from_json(const json& j, PrepayBillQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, bill_begin_date);
		BIND_FROM_TO_NORMAL(j, t, bill_end_date);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, supplier_id);
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		BIND_FROM_TO_I(j, t, is_effective);
		BIND_FROM_TO_I(j, t, is_closed);
		BIND_FROM_TO_I(j, t, is_voided);
	}
	PrepayBillQuery() {
		is_effective = -1;
		is_closed = -1;
		is_voided = -1;
	}
};

#endif // !_SAMPLE_QUERY_
