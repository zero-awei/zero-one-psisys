#pragma once

#ifndef _ADD_DTO_
#define _ADD_DTO_

#include "../../GlobalInclude.h"

/**
 * 示例传输对象
 */
class AddSupplierDTO
{
	// 姓名
	CC_SYNTHESIZE(int, code, Code);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	//助记名
	CC_SYNTHESIZE(string, alias, Alias);
	//供应商分类
	CC_SYNTHESIZE(string, supplierCassification, SupplierClassification);
	//供应商等级
	CC_SYNTHESIZE(string, supplierLevel, SupplierLevel);
	//纳税规模
	CC_SYNTHESIZE(string, taxScale, TaxScale);
	//备选供应商
	CC_SYNTHESIZE(string, alternativeSuppliers, AlternativeSuppliers);
	//是否启用
	CC_SYNTHESIZE(string, enable, Enable);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddSupplierDTO& t); // NOLINT
	BIND_TO_JSON(AddSupplierDTO, code, name, alias, supplierCassification, supplierLevel, taxScale, alternativeSuppliers, enable, remark);
};

#endif // !_ADD_DTO_