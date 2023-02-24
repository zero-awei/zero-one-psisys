#pragma once
#ifndef _IMPORT_SUPPLIER_DO_
#define _IMPORT_SUPPLIER_DO_
#include "../DoInclude.h"

class ImportSupplierDO
{
	// 编号
	CC_SYNTHESIZE(string, code, Code);
	// 供应商名字
	CC_SYNTHESIZE(string, name, Name);
public:
	ImportSupplierDO() {
		code = "1";
		name = "1";
	}
};
#endif // !_IMPORT_SUPPLIER_DO_
