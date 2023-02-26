#pragma once
#ifndef _EXPORT_SUPPLIER_DO_
#define _EXPORT_SUPPLIER_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class ExportSupplierDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// 编号
	CC_SYNTHESIZE(string, code, Code);
	// 供应商名字
	CC_SYNTHESIZE(string, name, Name);
	// 简称
	CC_SYNTHESIZE(string, shortName, ShortName);
	// 助记名
	CC_SYNTHESIZE(string, auxName, AuxName);
	// 供应商分类
	CC_SYNTHESIZE(string, supplierCategory, SupplierCategory);
	// 供应商等级
	CC_SYNTHESIZE(string, supplierLevel, SupplierLevel);
	// 供应商是否启用
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
public:
	ExportSupplierDO() {
		id = "";
		code = "";
		name = "";
		shortName = "";
		auxName = "";
		supplierCategory = "";
		supplierLevel = "";
		isEnabled = 1;
	}
};

#endif // !_EXPORT_SUPPLIER_DO_