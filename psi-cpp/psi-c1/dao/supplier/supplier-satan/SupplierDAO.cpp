#include "stdafx.h"
#include "SupplierDAO.h"
#include <sstream>
#include "SupplierAdvancedMapper.h"
#include "SupplierSpecificMapper.h"


//查询数据条数——分页查询的service中的高级查询需要使用！！！！！！！！！！！！
uint64_t SupplierDAO::count(const  AdvancedQuery condition)//原来函数参数放的是const SupplierDO & iObj
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `bas_supplier`"<<" ";
	SqlParams params;//定义一个“没有用的，空的”承装填充参数容器
	/*在sql中添加用户输入的查询条件*/
	list<AdvancedQuerySQLCondition> list = condition.getAdvancedQueryCondition();
	//计算list中字段数量——然后使用for循环将字段条件放入sql中
	size_t size = list.size();
	//第一个条件需要用到where打头
	//sql << " WHERE 1=1"<<" ";
	string rule = condition.getRule();
	if (rule == "and")
	{
		sql << " WHERE 1=1" << " ";
	}
	else
	{
		sql << " WHERE 1=2" << " ";
	}
	while (size > 0)
	{
		string relational_symbol;
		if (list.front().getCondition() == "<=" || list.front().getCondition() == "<" || list.front().getCondition() == ">="
			|| list.front().getCondition() == ">" || list.front().getCondition() == "=" || list.front().getCondition() == "!=")
		{
			relational_symbol = list.front().getCondition();
			sql << rule << " " << list.front().getField() << relational_symbol << '\'' << list.front().getValue() << '\'' << " ";
		}
		else if (list.front().getCondition() == "Include")//要写告诉前端
		{
			relational_symbol = "like";
			sql << rule << " " << list.front().getField() << " " << relational_symbol << " " << '\'' << "%" << list.front().getValue() << "%" << '\'' << " ";
		}
		else if (list.front().getCondition() == "Begin")
		{
			relational_symbol = "like";
			sql << rule << " " << list.front().getField() << " " << relational_symbol << " " << '\'' << list.front().getValue() << "%" << '\'' << " ";
		}
		else if (list.front().getCondition() == "End")
		{
			relational_symbol = "like";
			sql << rule << " " << list.front().getField() << " " << relational_symbol << " " << '\'' << "%" << list.front().getValue() << '\'' << " ";
		}
		else if (list.front().getCondition() == "Among")
		{
			relational_symbol = "like";
			sql << rule << " " << list.front().getField() << " " << relational_symbol << " " << '\'' << "%_" << list.front().getValue() << "_%" << '\'' << " ";
		}
		list.pop_front();
		size--;
	}
	string sqlStr = sql.str();
	cout << "dao.count:  " << sqlStr << endl;
	return sqlSession->executeQueryNumerical(sqlStr, params);//params是宏SAMPLE_TERAM_PARSE中定义的
}

// 高级查询-分页查询！！！！
std::list<SupplierDO> SupplierDAO::AdvancedSelectWithPage(uint64_t pageIndex, uint64_t pageSize,const  AdvancedQuery &condition)//service层会传入页数
{
	stringstream sql;
	sql << "SELECT `id`,`code`,`name`,`aux_name` ,`supplier_category`,`supplier_level`,`tax_scale`,\
		`headquarters` ,`area` ,`biz_area` ,`address` ,`website` , `alter_suppliers`,\
		`is_enabled`, `remark`,`create_by`,`update_time`,`update_by`  FROM `bas_supplier`"<<" ";
	SqlParams params;//没有用的，空的填充参数容器
	/*在sql中添加用户输入的查询条件*/
	list<AdvancedQuerySQLCondition> list = condition.getAdvancedQueryCondition();
	//计算list中字段数量——然后使用for循环将字段条件放入sql中
	size_t size = list.size();
	//第一个条件需要用到where打头
	//sql << " WHERE 1=1"<<" ";
	string rule = condition.getRule();
	if (rule == "and")
	{
		sql << " WHERE 1=1" << " ";
	}
	else
	{
		sql << " WHERE 1=2" << " ";
	}
	while (size > 0)
	{
		string relational_symbol;
		if (list.front().getCondition() == "<=" || list.front().getCondition() == "<" || list.front().getCondition() == ">="
			|| list.front().getCondition() == ">" || list.front().getCondition() == "=" || list.front().getCondition() == "!=")
		{
			relational_symbol = list.front().getCondition();
			sql << rule << " " << list.front().getField() << relational_symbol << '\'' << list.front().getValue() << '\'' << " ";
		}
		else if (list.front().getCondition() == "Include")//要写告诉前端
		{
			relational_symbol = "like";
			sql << rule << " " << list.front().getField() << " " << relational_symbol << " " << '\'' << "%" << list.front().getValue() << "%" << '\'' << " ";
		}
		else if (list.front().getCondition() == "Begin")
		{
			relational_symbol = "like";
			sql << rule << " " << list.front().getField() << " " << relational_symbol << " " << '\'' << list.front().getValue() << "%" << '\'' << " ";
		}
		else if (list.front().getCondition() == "End")
		{
			relational_symbol = "like";
			sql << rule << " " << list.front().getField() << " " << relational_symbol << " " << '\'' << "%" << list.front().getValue() << '\'' << " ";
		}
		else if (list.front().getCondition() == "Among")
		{
			relational_symbol = "like";
			sql << rule << " " << list.front().getField() << " " << relational_symbol << " " << '\'' << "%_" << list.front().getValue() << "_%" << '\'' << " ";
		}
		list.pop_front();
		size--;
	}
	//向sql变量中加入分页限制
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize << " ";//pageSize是每页的数据的条目数；pageindex是显示的页数
	SupplierAdvancedMapper mapper;
	string sqlStr = sql.str();
	//test
	cout << "dao.supplier:  " << sqlStr << endl;
	return sqlSession->executeQuery<SupplierDO, SupplierAdvancedMapper>(sqlStr, mapper, params);
}

// 查询指定供应商——根据id
SupplierDO SupplierDAO::SpecifiedSelect(const string& id)
{
	string sql = "SELECT `code`,`name`, `short_name` ,`aux_name` ,`supplier_category`,`supplier_level`,`tax_scale`\
		,`headquarters` ,`area` ,`biz_area` ,`address` ,`website` ,`legal_person` ,`legal_person_phone` ,`financial_contacts` ,\
		`financial_phone`, `invoice_company`, `invoice_tax_code`, `invoice_bank_name`, `invoice_bank_code`, `invoice_account`, \
		`invoice_phone`, `invoice_address`, `receipt_company`, `receipt_bank_name`, `receipt_bank_code`, `receipt_account`, \
		`recv_name`, `recv_phone`, `recv_fax`, `recv_email`, `recv_address`, `recv_postcode`, `attachment`, \
		`is_enabled`, `alter_suppliers`,`remark`,`create_by`,`create_time`,`update_time`,`update_by` FROM `bas_supplier` WHERE `id` =?";//需要'?'来做占位符
	SupplierSpecificMapper mapper;
	list<SupplierDO>res= sqlSession->executeQuery<SupplierDO, SupplierSpecificMapper>(sql, mapper, "%s", id);
	if (!res.empty())
	{
		return res.front();
	}
	else
	{
		SupplierDO temp;
		return temp;
	}
}


// 插入数据——已检查：字段，?，%s
uint64_t SupplierDAO::SupplierInsert(const SupplierDO& iObj)
{
	string sql = "INSERT INTO `bas_supplier` (`id`,`code`,`name`, `short_name` ,`aux_name` ,`supplier_category`,`supplier_level`,`tax_scale`\
		,`headquarters` ,`area` ,`biz_area` ,`address` ,`website` ,`legal_person` ,`legal_person_phone` ,`financial_contacts` ,\
		`financial_phone`, `invoice_company`, `invoice_tax_code`, `invoice_bank_name`, `invoice_bank_code`, `invoice_account`, \
		`invoice_phone`, `invoice_address`, `receipt_company`, `receipt_bank_name`, `receipt_bank_code`, `receipt_account`, \
		`recv_name`, `recv_phone`, `recv_fax`, `recv_email`, `recv_address`, `recv_postcode`, `attachment`, `alter_suppliers`,\
		`is_enabled`, `remark`,`create_by`,`create_time`,`update_time`,`update_by`) VALUES (?, ?, ?, ?, ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? ,\
		? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ?)";//已检查：?有42个;insert的字段也有42个(已经算上id的份)
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s\
		%s%s%s%s%s\
		%s%s%s%s%s\
		%s%s%s%s%s\
		%s%s%s%s%s\
		%s%s%s%s%s\
		%s%s%s%s%s\
		%s%i%s%s%s%s%s", iObj.getID(), iObj.getCode(), iObj.getName(), iObj.getShort_Name(), iObj.getAux_Name()
		, iObj.getSupplier_Category(), iObj.getSupplier_Level(), iObj.getTax_Scale(), iObj.getHeadQuarters(), iObj.getArea(), iObj.getBiz_Area()
		, iObj.getAddress(), iObj.getWebsite(), iObj.getLegal_Person(), iObj.getLegal_Person_Phone(), iObj.getFinancial_Contacts(), iObj.getFinancial_Phone()
		, iObj.getInvoice_Company(), iObj.getInvoice_Tax_Code(), iObj.getInvoice_Bank_Name(), iObj.getInvoice_Bank_Code(), 
		iObj.getInvoice_Account(), iObj.getInvoice_Phone(), iObj.getInvoice_Address(), iObj.getReceipt_Company(), iObj.getReceipt_Bank_Name(),
		iObj.getReceipt_Bank_Code(), iObj.getReceipt_Account(), iObj.getRecv_Name(), iObj.getRecv_Phone(),
		iObj.getRecv_Fax(), iObj.getRecv_Email(), iObj.getRecv_Address(), iObj.getRecv_Postcode(), iObj.getAttachment(),
		iObj.getAlter_Suppliers(), iObj.getIs_Enabled(), iObj.getRemark(), iObj.getCreate_By(), iObj.getCreate_Time(), iObj.getUpdate_Time(),
		iObj.getUpdate_By());  //41个字段-修改过后已经正确了，%s在41个的基础上多加了一个(现在42个%s)，iObj的id还没有加
}

// 修改数据
int SupplierDAO::SupplierUpdateByCode(const SupplierDO& uObj)
{
	stringstream sql;
	sql <<"UPDATE `bas_supplier` SET"<<" ";
	if (uObj.getCode() != "")
	{
		sql << " `code`" << "=" << '\'' << uObj.getCode() << '\'' << "," << " ";
	}
	if (uObj.getName() != "")
	{
		sql << " `name`" << "=" << '\'' << uObj.getName() << '\'' << "," << " ";
	}
	if (uObj.getShort_Name() != "")
	{
		sql << " `short_name`" << "=" << '\'' << uObj.getShort_Name() << '\'' << "," << " ";
	}
	if (uObj.getAux_Name() != "")
	{
		sql << " `aux_name`" << "=" << '\'' << uObj.getAux_Name() << '\'' << "," << " ";
	}
	if (uObj.getSupplier_Category() != "")
	{
		sql << " `supplier_category`" << "=" << '\'' << uObj.getSupplier_Category() << '\'' << "," << " ";
	}
	if (uObj.getSupplier_Level() != "")
	{
		sql << " `supplier_level`" << "=" << '\'' << uObj.getSupplier_Level() << '\'' << "," << " ";
	}
	if (uObj.getTax_Scale() != "")
	{
		sql << " `tax_scale`" << "=" << '\'' << uObj.getTax_Scale() << '\'' << "," << " ";
	}
	if (uObj.getHeadQuarters() != "")
	{
		sql << " `headquarters`" << "=" << '\'' << uObj.getHeadQuarters() << '\'' << "," << " ";
	}
	if (uObj.getArea() != "")
	{
		sql << " `area`" << "=" << '\'' << uObj.getArea() << '\'' << "," << " ";
	}
	if (uObj.getBiz_Area() != "")
	{
		sql << " `biz_area`" << "=" << '\'' << uObj.getBiz_Area() << '\'' << "," << " ";
	}
	if (uObj.getAddress() != "")
	{
		sql << " `address`" << "=" << '\'' << uObj.getAddress() << '\'' << "," << " ";
	}
	if (uObj.getWebsite() != "")
	{
		sql << " `website`" << "=" << '\'' << uObj.getWebsite() << '\'' << "," << " ";
	}
	if (uObj.getLegal_Person() != "")
	{
		sql << " `legal_person`" << "=" << '\'' << uObj.getLegal_Person() << '\'' << "," << " ";
	}
	if (uObj.getLegal_Person_Phone() != "")
	{
		sql << " `legal_person_phone`" << "=" << '\'' << uObj.getLegal_Person_Phone() << '\'' << "," << " ";
	}
	if (uObj.getFinancial_Contacts() != "")
	{
		sql << " `financial_contacts`" << "=" << '\'' << uObj.getFinancial_Contacts() << '\'' << "," << " ";
	}
	if (uObj.getFinancial_Phone() != "")
	{
		sql << " `financial_phone`" << "=" << '\'' << uObj.getFinancial_Phone() << '\'' << "," << " ";
	}
	if (uObj.getInvoice_Company() != "")
	{
		sql << " `invoice_company`" << "=" << '\'' << uObj.getInvoice_Company() << '\'' << "," << " ";
	}
	if (uObj.getInvoice_Tax_Code() != "")
	{
		sql << " `invoice_tax_code`" << "=" << '\'' << uObj.getInvoice_Tax_Code() << '\'' << "," << " ";
	}
	if (uObj.getInvoice_Bank_Name() != "")
	{
		sql << " `invoice_bank_name`" << "=" << '\'' << uObj.getInvoice_Bank_Name() << '\'' << "," << " ";
	}
	if (uObj.getInvoice_Bank_Code() != "")
	{
		sql << " `invoice_bank_code`" << "=" << '\'' << uObj.getInvoice_Bank_Code() << '\'' << "," << " ";
	}
	if (uObj.getInvoice_Account() != "")
	{
		sql << " `invoice_account`" << "=" << '\'' << uObj.getInvoice_Account() << '\'' << "," << " ";
	}
	if (uObj.getInvoice_Phone() != "")
	{
		sql << " `invoice_phone`" << "=" << '\'' << uObj.getInvoice_Phone() << '\'' << "," << " ";
	}
	if (uObj.getInvoice_Address() != "")
	{
		sql << " `invoice_address`" << "=" << '\'' << uObj.getInvoice_Address() << '\'' << "," << " ";
	}
	if (uObj.getReceipt_Company() != "")
	{
		sql << " `receipt_company`" << "=" << '\'' << uObj.getReceipt_Company() << '\'' << "," << " ";
	}
	if (uObj.getReceipt_Bank_Name() != "")
	{
		sql << " `receipt_bank_name`" << "=" << '\'' << uObj.getReceipt_Bank_Name() << '\'' << "," << " ";
	}
	if (uObj.getReceipt_Bank_Code() != "")
	{
		sql << " `receipt_bank_code`" << "=" << '\'' << uObj.getReceipt_Bank_Code() << '\'' << "," << " ";
	}
	if (uObj.getReceipt_Account() != "")
	{
		sql << " `receipt_account`" << "=" << '\'' << uObj.getReceipt_Account() << '\'' << "," << " ";
	}
	if (uObj.getRecv_Name() != "")
	{
		sql << " `recv_name`" << "=" << '\'' << uObj.getRecv_Name() << '\'' << "," << " ";
	}
	if (uObj.getRecv_Phone() != "")
	{
		sql << " `recv_phone`" << "=" << '\'' << uObj.getRecv_Phone() << '\'' << "," << " ";
	}
	if (uObj.getRecv_Fax() != "")
	{
		sql << " `recv_fax`" << "=" << '\'' << uObj.getRecv_Fax() << '\'' << "," << " ";
	}
	if (uObj.getRecv_Email() != "")
	{
		sql << " `recv_email`" << "=" << '\'' << uObj.getRecv_Email() << '\'' << "," << " ";
	}
	if (uObj.getRecv_Address() != "")
	{
		sql << " `recv_address`" << "=" << '\'' << uObj.getRecv_Address() << '\'' << "," << " ";
	}
	if (uObj.getRecv_Postcode() != "")
	{
		sql << " `recv_postcode`" << "=" << '\'' << uObj.getRecv_Postcode() << '\'' << "," << " ";
	}
	if (uObj.getAttachment() != "")
	{
		sql << " `attachment`" << "=" << '\'' << uObj.getAttachment() << '\'' << "," << " ";
	}
	if (uObj.getAlter_Suppliers() != "")
	{
		sql << " `alter_suppliers`" << "=" << '\'' << uObj.getAlter_Suppliers() << '\'' << "," << " ";
	}
	if (uObj.getIs_Enabled() != -1)
	{
		sql << " `is_enabled`" << "=" <<  uObj.getIs_Enabled()  << "," << " ";
	}
	if (uObj.getRemark() != "")
	{
		sql << " `remark`" << "=" << '\'' << uObj.getRemark() << '\'' << "," << " ";
	}
	if (uObj.getUpdate_Time() != "")
	{
		sql << " `update_time`" << "=" << '\'' << uObj.getUpdate_Time() << '\'' << "," << " ";
	}
	if (uObj.getUpdate_By() != "")
	{
		sql << " `update_by`" << "=" << '\'' << uObj.getUpdate_By() << '\'' << " ";
	}
	sql << "WHERE `id`=" << '\''<< uObj.getID()<< '\'';
	string sqlStr = sql.str();
	cout << "modify_dao:  " << sqlStr << endl;
	SqlParams params;//没有用的，空的填充参数容器
	return sqlSession->executeUpdate(sqlStr, params);
}


// 通过编号来删除数据——根据code
int SupplierDAO::SupplierDeleteByCode(string id)
{
	string sql = "DELETE FROM `bas_supplier` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

