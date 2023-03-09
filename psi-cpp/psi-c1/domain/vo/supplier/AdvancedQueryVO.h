#pragma once
#ifndef _ADVANCED_VO_
#define _ADVANCED_VO_

#include "../../GlobalInclude.h"

class AdvancedQueryVO 
{
	// 编号
	CC_SYNTHESIZE(string, code, Code);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	//助记名
	CC_SYNTHESIZE(string, aux_name, Aux_Name);
	//供应商分类 
	CC_SYNTHESIZE(string, supplier_category, Supplier_Category);
	//供应商等级 
	CC_SYNTHESIZE(string, supplier_level, Supplier_Level);
	//纳税规模 
	CC_SYNTHESIZE(string, tax_scale, Tax_Scale);
	//所属总公司 
	CC_SYNTHESIZE(string, headquarters, HeadQuarters);
	//所属地区 
	CC_SYNTHESIZE(string, biz_area, Biz_Area);
	//业务区域  
	CC_SYNTHESIZE(string, area, Area);
	//供应商地址 
	CC_SYNTHESIZE(string, address, Address);
	//供应商网站 
	CC_SYNTHESIZE(string, website, Website);
	//备选供应商
	CC_SYNTHESIZE(string, alter_suppliers, Alter_Suppliers);
	//是否启用
	CC_SYNTHESIZE(int, is_enabled, Is_Enabled);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//创建人
	CC_SYNTHESIZE(string, create_by, Create_By);
	//修改时间
	CC_SYNTHESIZE(string, update_time,Update_Time);
	//修改人
	CC_SYNTHESIZE(string, update_by, Update_By);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(AdvancedQueryVO, code,name, aux_name, supplier_category, supplier_level, tax_scale,
		headquarters, biz_area, area, address, website, alter_suppliers,
		is_enabled, remark, create_by, update_time, update_by);
};

#endif // !_SAMPLE_VO_

