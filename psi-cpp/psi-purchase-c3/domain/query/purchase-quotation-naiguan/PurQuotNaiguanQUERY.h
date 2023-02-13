//因为有多人在同时写_PUR_QUOT_里的功能，因此这里添加NAIGUAN来进行区分，以免发生编码错误
#ifndef _PUR_QUOT_NAIGUAN_QUERY_
#define _PUR_QUOT_NAIGUAN_QUERY_


#include "../PageQuery.h"

class PurQuotNaiguanQUERY : public PageQuery
{
	
	//以下有一些字段，我不确定是否真的会用到，如果之后写代码，发现还需要其他字段，就添加上去；不需要再删除；
	// ID
	CC_SYNTHESIZE(string, id, ID);
	// 单据号/单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 分录号
	CC_SYNTHESIZE(string, entryNo, EntryNo);
	// 源单分录号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 源单单据id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	// 源单分录id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);


public:
	friend void from_json(const json& j, PurQuotNaiguanQUERY& t) {
		BIND_FROM_TO_I(j, t, id);
		BIND_FROM_TO_I(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, entryNo);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, srcBillId);
		BIND_FROM_TO_NORMAL(j, t, srcEntryId);
	}
};

#endif // !_PUR_QUOT_NAIGUAN_QUERY_