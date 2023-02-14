#pragma once
#ifndef _DOCNO_DTO_
#define _DOCNO_DTO_

#include "../../GlobalInclude.h"

/**
 * 单据编号传输对象
 */
class DocNoDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, DocNoDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
	BIND_TO_JSON(DocNoDTO, billNo);
};

#endif // !_DOCNO_DTO_