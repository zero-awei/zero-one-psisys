#pragma once
#ifndef _DEL_PUR_QUOT_DTO_H_
#define _DEL_PUR_QUOT_DTO_H_

#include "../../GlobalInclude.h"


class DelPurQuotDTO
{
	//以下有一些字段，我不确定是否真的会用到，如果之后写代码，发现还需要其他字段，就添加上去；不需要再删除；
	// 单据id
	CC_SYNTHESIZE(long, id, Id);
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	

public:
	//绑定JSON转换方法
	friend void from_json(const json& j, DelPurQuotDTO& t) {
		BIND_FROM_TO_L(j, t, id);

		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

#endif // !_DEL_PUR_QUOT_DTO_