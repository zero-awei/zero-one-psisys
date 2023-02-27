#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: satan
 xxxMapper在dao层。
分页查询需要用到mapper
mapper的作用是对DO领域模型中的字段做一个转换(映射)
Mapper.h的字段顺序根据分页查询时显示的字段的顺序来写
*/
#ifndef _SUPPLIER_MAPPER_2
#define _SUPPLIER_MAPPER_2

#include "Mapper.h"
#include"../../../domain/do/SupplierDO-satan/SupplierDO.h"

/**
 * 示例表字段匹配映射
 */
class SupplierSpecificMapper : public Mapper<SupplierDO>
{
public:
	SupplierDO mapper(ResultSet* resultSet) const override
	{
		SupplierDO data;
		data.setCode(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setShort_Name(resultSet->getString(3));
		data.setAux_Name(resultSet->getString(4));
		data.setSupplier_Category(resultSet->getString(5));
		data.setSupplier_Level(resultSet->getString(6));
		data.setTax_Scale(resultSet->getString(7));
		data.setHeadQuarters(resultSet->getString(8));
		data.setArea(resultSet->getString(9));
		data.setBiz_Area(resultSet->getString(10));
		data.setAddress(resultSet->getString(11));
		data.setWebsite(resultSet->getString(12));//ok
		data.setLegal_Person(resultSet->getString(13));
		data.setLegal_Person_Phone(resultSet->getString(14));
		data.setFinancial_Contacts(resultSet->getString(15));
		data.setFinancial_Phone(resultSet->getString(16));
		data.setInvoice_Company(resultSet->getString(17));
		data.setInvoice_Tax_Code(resultSet->getString(18));
		data.setInvoice_Bank_Name(resultSet->getString(19));
		data.setInvoice_Bank_Code(resultSet->getString(20));
		data.setInvoice_Account(resultSet->getString(21));
		data.setInvoice_Phone(resultSet->getString(22));
		data.setInvoice_Address(resultSet->getString(23));
		data.setReceipt_Company(resultSet->getString(24));
		data.setReceipt_Bank_Name(resultSet->getString(25));
		data.setReceipt_Bank_Code(resultSet->getString(26));
		data.setReceipt_Account(resultSet->getString(27));
		data.setRecv_Name(resultSet->getString(28));
		data.setRecv_Phone(resultSet->getString(29));
		data.setRecv_Fax(resultSet->getString(30));
		data.setRecv_Email(resultSet->getString(31));
		data.setRecv_Address(resultSet->getString(32));
		data.setRecv_Postcode(resultSet->getString(33));
		data.setAttachment(resultSet->getString(34));
		data.setIs_Enabled(resultSet->getInt64(35));
		data.setAlter_Suppliers(resultSet->getString(36));
		data.setRemark(resultSet->getString(37));
		data.setCreate_By(resultSet->getString(38));
		data.setCreate_Time(resultSet->getString(39));
		data.setUpdate_Time(resultSet->getString(40));
		return data;
	}
};

#endif // !_SUPPLIER_MAPPER_2
