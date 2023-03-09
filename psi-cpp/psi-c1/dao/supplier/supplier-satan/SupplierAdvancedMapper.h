#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: satan
 xxxMapper在dao层。
分页查询需要用到mapper
mapper的作用是对DO领域模型中的字段做一个转换(映射)
Mapper.h的字段顺序根据分页查询时显示的字段的顺序来写——》让自己看着舒服
class SupplierAdvancedMapper里面的字段的（）里面的序号是DO中对应字段的序号，比如data.setCode(resultSet->getString(2));---》
因为Code在DO类里面的是从上到下的第二个，所以在这个mapper里面，code后面写(2)
注意，这个标号不是看数据库中对应字段在数据库字段中的顺序！！！
*/
#ifndef _SUPPLIER_MAPPER_
#define _SUPPLIER_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/supplier/SupplierDO.h"

/**
 * 示例表字段匹配映射
 */
class SupplierAdvancedMapper : public Mapper<SupplierDO>
{
public:
	SupplierDO mapper(ResultSet* resultSet) const override
	{
		SupplierDO data;
		data.setID(resultSet->getString(1));
		data.setCode(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		data.setAux_Name(resultSet->getString(4));
		data.setSupplier_Category(resultSet->getString(5));
		data.setSupplier_Level(resultSet->getString(6));
		data.setTax_Scale(resultSet->getString(7));
		data.setHeadQuarters(resultSet->getString(8));
		data.setArea(resultSet->getString(9));
		data.setBiz_Area(resultSet->getString(10));
		data.setAddress(resultSet->getString(11));
		data.setWebsite(resultSet->getString(12));
		data.setAlter_Suppliers(resultSet->getString(13));
		data.setIs_Enabled(resultSet->getInt(14));
		data.setRemark(resultSet->getString(15));
		data.setCreate_By(resultSet->getString(16));
		data.setUpdate_Time(resultSet->getString(17));
		data.setUpdate_By(resultSet->getString(18));
		return data;
	}
};

#endif // !_SUPPLIER_MAPPER_