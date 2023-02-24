/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：发票类型
 */

#pragma once
#ifndef _InvoiceType_DO_
#define _InvoiceType_DO_
#include "../DoInclude.h"

 /**
  * 数据库实体类
  */
class InvoiceTypeDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 货币名
	CC_SYNTHESIZE(string, name, Name);
public:
	InvoiceTypeDO() {
		id = 0;
		name = "";
	}
};

#endif // !_InvoiceType_DO_