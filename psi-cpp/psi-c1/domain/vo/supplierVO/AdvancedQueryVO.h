#pragma once
#ifndef _ADVANCED_VO_
#define _ADVANCED_VO_

#include "../../GlobalInclude.h"
//#include"../PageVO.h"

class AdvancedQueryVO 
{
	// 编号
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
	//所属总公司
	CC_SYNTHESIZE(string, headOffice, HeadOffice);
	//所属地区
	CC_SYNTHESIZE(string, region, Region);
	//业务区域
	CC_SYNTHESIZE(string, businessArea, BusinessArea);
	//供应商地址
	CC_SYNTHESIZE(string, supplierAddress, SupplierAddress);
	//供应商网站
	CC_SYNTHESIZE(string, supplierWebsite, SupplierWebsite);
	//备选供应商
	CC_SYNTHESIZE(string, alternativeSuppliers, AlternativeSuppliers);
	//是否启用
	CC_SYNTHESIZE(string, enable, Enable);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//创建人
	CC_SYNTHESIZE(string, createdBy, CreatedBy);
	//修改时间
	CC_SYNTHESIZE(string, modificationTime, ModificationTime);
	//修改人
	CC_SYNTHESIZE(string, modifiedBy, ModifiedBy);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(AdvancedQueryVO, code, name, alias, supplierCassification, supplierLevel, taxScale, headOffice,
		region, businessArea, supplierAddress, supplierWebsite, alternativeSuppliers,
		enable, remark, createdBy, modificationTime, modifiedBy);
};

#endif // !_SAMPLE_VO_

