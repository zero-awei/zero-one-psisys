#ifndef _QUERY_CGTHCK_BILL_QUERY_
#define _QUERY_CGTHCK_BILL_QUERY_
#include "../PageQuery.h"

/**
* 采购退货出库分页查询对象
*/
class QueryCgthckBillQuery : public PageQuery
{
	// 单据编号
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// 单据起始日期
	CC_SYNTHESIZE(string, beginData, BeginData);
	// 单据结束日期
	CC_SYNTHESIZE(string, endData, EndData);
	// 单据主题
	CC_SYNTHESIZE(std::string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	// 是否生效
	CC_SYNTHESIZE(int, isEff, IsEff);
	// 是否关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	// 是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	// 绑定from_json
	friend void from_json(const json& j, QueryCgthckBillQuery& t)
	{
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, beginData);
		BIND_FROM_TO_NORMAL(j, t, endData);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_I(j, t, isEff);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
	}
};


#endif // !_QUERY_CGTHCK_BILL_QUERY_

