#pragma once

#ifndef _DeleteQtrkBill_DTO_
#define _DeleteQtrkBill_DTO_
#include "../../GlobalInclude.h"
/**
 * 删除单据传输对象
 */
class DeleteQtrkBillDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, id, Id);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, DeleteQtrkBillDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, id);
	}// NOLINT
};

#endif // !_DeleteQtrkBill_DTO_