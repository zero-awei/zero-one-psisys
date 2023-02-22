/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：开票方式
 */

#pragma once
#ifndef _INVOICEMETHOD_DO_
#define _INVOICEMETHOD_DO_
#include "../DoInclude.h"

 /**
  * 数据库实体类
  */
class InvoiceMethodDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 货币名
	CC_SYNTHESIZE(string, name, Name);
public:
	InvoiceMethodDO() {
		id = 0;
		name = "";
	}
};

#endif // !_INVOICEMETHOD_DO_