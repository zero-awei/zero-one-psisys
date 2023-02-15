#pragma once
#ifndef _ADVANCED_VO_
#define _ADVANCED_VO_

#include "../../GlobalInclude.h"
#include"../PageVO.h"

class AdvancedQueryVO 
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
	BIND_TO_JSON(AdvancedQueryVO, code, name, alias, supplierCassification, 
		supplierLevel, taxScale, alternativeSuppliers, enable, remark);
};

#endif // !_SAMPLE_VO_

