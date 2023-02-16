#pragma once
#ifndef _REMOVE_CGRK_BILL_DTO_
#define _REMOVE_CGRK_BILL_DTO_

#include "../../GlobalInclude.h"


/**
 * 删除采购入库单
 */
class RemoveCgrkBillDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, RemoveCgrkBillDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}

};

#endif // !_REMOVE_CGRK_BILL_DTO_
