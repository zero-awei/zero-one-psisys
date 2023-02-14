#pragma once
#ifndef _DOCSTAT_DTO_
#define _DOCSTAT_DTO_

#include "../../GlobalInclude.h"

/**
 * 单据编号传输对象
 */
class DocStatDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, DocStatDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
	}
	BIND_TO_JSON(DocStatDTO, billNo,isClosed,isVoided);
};

#endif // !_QueryDoc_DTO_
