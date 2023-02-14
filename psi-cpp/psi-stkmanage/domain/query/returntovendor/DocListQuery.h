#ifndef _DOC_LIST_QUERY_
#define _DOC_LIST_QUERY_
#include "../PageQuery.h"

/**
* 采购退货出库分页查询对象
*/
class DocListQuery : public PageQuery
{
	// 单据编号
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(std::string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// 单据阶段
	CC_SYNTHESIZE(std::string, billStage, BillStage);
	// 是否生效
	CC_SYNTHESIZE(bool, isEff, IsEff);
	// 是否关闭
	CC_SYNTHESIZE(bool, isClosed, IsClosed);
	// 是否作废
	CC_SYNTHESIZE(bool, isVoided, IsVoided);
public:
	// 绑定from_json
	friend void from_json(const json& j, DocListQuery& t);
};


#endif // !_DOC_LIST_QUERY_

