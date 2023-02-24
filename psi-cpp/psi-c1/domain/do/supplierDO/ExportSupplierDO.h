#pragma once
#ifndef _EXPORT_SUPPLIER_DO_
#define _EXPORT_SUPPLIER_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class ExportSupplierDO
{
	// 编号
	CC_SYNTHESIZE(string, code, Code);
	// 供应商名字
	CC_SYNTHESIZE(string, name, Name);
public:
	ExportSupplierDO() {
		code = "1";
		name = "1";
	}
};

#endif // !_EXPORT_SUPPLIER_DO_