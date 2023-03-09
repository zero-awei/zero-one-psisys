#pragma once
#ifndef _SUPPLIERQUERYCRITERIA_VO_
#define _SUPPLIERQUREYCRITERIA_VO_

#include "../../GlobalInclude.h"

/*
供应商高级查询条件下拉列表
Author C1-三木
2023.2.13 21点00分
*/
class SupplierQueryCriteriaVO
{
	// 查询条件编号
	CC_SYNTHESIZE(string, id, Id);
	// 查询条件名称
	CC_SYNTHESIZE(string, name, Name);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(SupplierQueryCriteriaVO, id, name);
};

#endif // _SUPPLIERQUERYCRITERIA_VO_
		