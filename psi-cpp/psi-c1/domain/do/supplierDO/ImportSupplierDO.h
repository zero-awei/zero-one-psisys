#pragma once
#ifndef _IMPORT_SUPPLIER_DO_
#define _IMPORT_SUPPLIER_DO_
#include "../DoInclude.h"

class ImportSupplierDO
{
	// ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 编号
	CC_SYNTHESIZE(string, code, Code);
	// 供应商名字
	CC_SYNTHESIZE(string, name, Name);
	// 供应商简称
	CC_SYNTHESIZE(string, shortName, ShortName);
	// 供应商助记名
	CC_SYNTHESIZE(string, auxName, AuxName);
	// 供应商分类
	CC_SYNTHESIZE(string, supplierCategory, SupplierCategory);
	// 供应商等级
	CC_SYNTHESIZE(string, supplierLevel, SupplierLevel);
	// 供应商是否启用
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
public:
	ImportSupplierDO() {
		id = 0;
		code = "";
		name = "";
		shortName = "";
		auxName = "";
		supplierCategory = "";
		supplierLevel = "";
		isEnabled = 1;
	}
};
#endif // !_IMPORT_SUPPLIER_DO_
