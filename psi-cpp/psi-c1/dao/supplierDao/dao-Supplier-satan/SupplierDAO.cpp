#include "stdafx.h"
#include "SupplierDAO.h"
#include <sstream>
#include"SupplierMapper.h"



//查询数据条数——分页查询的service中的高级查询需要使用！！！！！！！！！！！！
uint64_t SupplierDAO::count(const  AdvancedQuery condition)//原来函数参数放的是const SupplierDO & iObj
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM bas_supplier";
	SqlParams params;//定义一个“没有用的，空的”承装填充参数容器
	/*在sql中添加用户输入的查询条件*/
	list<AdvancedQuerySQLCondition> list = condition.getAdvancedQueryCondition();
	//计算list中字段数量——然后使用for循环将字段条件放入sql中
	int size = list.size();
	//第一个条件需要用到where打头
	sql << " WHERE 1=1";
	string rule = condition.getRule();
	while (size > 0)
	{
		sql << rule;//rule不是and就是or
		string relational_symbol;
		if (list.front().getCondition() == "<=" || "<" || ">=" || ">" || "=" || "!=")
		{
			relational_symbol = list.front().getCondition();
			sql << rule << list.front().getField() << relational_symbol << list.front().getValue();
		}
		else if (list.front().getCondition() == "Include")//要写告诉前端
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << "%" << list.front().getValue() << "%";
		}
		else if (list.front().getCondition() == "Begin")
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << list.front().getValue() << "%";
		}
		else if (list.front().getCondition() == "End")
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << "%" << list.front().getValue();
		}
		else if (list.front().getCondition() == "Among")
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << "%_" << list.front().getValue() << "_%";
		}
		list.pop_front();
		size--;
	}
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);//params是宏SAMPLE_TERAM_PARSE中定义的
}

// 高级查询-分页查询！！！！！！！！！！！！
std::list<SupplierDO> SupplierDAO::AdvancedSelectWithPage(uint64_t pageIndex, uint64_t pageSize,const  AdvancedQuery &condition)//service层会传入页数
{
	stringstream sql;
	sql << "SELECT * FROM bas_supplier";
	SqlParams params;//没有用的，空的填充参数容器
	/*在sql中添加用户输入的查询条件*/
	list<AdvancedQuerySQLCondition> list = condition.getAdvancedQueryCondition();
	//计算list中字段数量——然后使用for循环将字段条件放入sql中
	int size = list.size();
	//第一个条件需要用到where打头
	sql << " WHERE 1=1";
	string rule = condition.getRule();
	while (size > 0) 
	{
		sql << rule;//rule不是and就是or
		string relational_symbol;
		if (list.front().getCondition() == "<=" || "<" || ">=" || ">" || "=" || "!=")
		{
			relational_symbol = list.front().getCondition();
			sql << rule << list.front().getField() << relational_symbol << list.front().getValue();
		}
		else if (list.front().getCondition() == "Include")//要写告诉前端
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << "%" << list.front().getValue() << "%";
		}
		else if (list.front().getCondition() == "Begin")
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << list.front().getValue() << "%";
		}
		else if (list.front().getCondition() == "End")
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << "%" << list.front().getValue();
		}
		else if (list.front().getCondition() == "Among")
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << "%_" << list.front().getValue() << "_%";
		}
		list.pop_front();
		size--;
	}
	//向sql变量中加入分页限制
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;//pageSize是每页的数据的条目数；pageindex是显示的页数
	SupplierMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SupplierDO, SupplierMapper>(sqlStr, mapper, params);
}

// 查询指定供应商——根据code
list<SupplierDO> SupplierDAO::SpecifiedSelect(const string& code)
{
	string sql = "SELECT * FROM bas_supplier WHERE `code` LIKE CONCAT('%',?,'%')";//需要'?'来做占位符
	SupplierMapper mapper;
	return sqlSession->executeQuery<SupplierDO, SupplierMapper>(sql, mapper, "%s", code);
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
// 修改数据——已检查：字段，%s，
int SupplierDAO::SupplierUpdateByCode(const SupplierDO& uObj)
{
	string sql = "UPDATE `bas_supplier` SET `code`=?,`name`=? , `short_name`=? ,`aux_name`=? ,`supplier_category`=?,\
		`supplier_level` =?,`tax_scale`=?,`headquarters`=?,`area`=? ,`biz_area`=? ,`address`=? ,`website` =?,\
		`legal_person`=?,`legal_person_phone`=? ,`financial_contacts`=? ,`financial_phone`=? , `invoice_company`=?, \
		`invoice_tax_code`=?, `invoice_bank_name`=? , `invoice_bank_code`=? , `invoice_account`=?, \
		`invoice_phone`=?, `invoice_address`=?, `receipt_company`=?, `receipt_bank_name`=?, `receipt_bank_code`=?, \
		`receipt_account`=?, `recv_name`=? , `recv_phone`=? , `recv_fax`=?, `recv_email`=?, `recv_address`=?, \
		`recv_postcode`=?, `attachment`=?, `alter_suppliers`=?,`is_enabled`=? , `remark`=? ,`create_by`=? ,\
		`create_time`=? ,`update_time`=? ,`update_by`=? WHERE `id`=?" ;//41个字段+WHERE `id`=?
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s\
        %s%s%s%s%s\
        %s%s%s%s%s\
        %s%s%s%s%s\
		%s%s%s%s%s\
        %s%s%s%s%s\
        %s%s%s%s%s%i\
		%s%s%s%s%s%s", uObj.getCode(),uObj.getName(),uObj.getShort_Name(), uObj.getAux_Name()
		, uObj.getSupplier_Category(), uObj.getSupplier_Level(), uObj.getTax_Scale(), uObj.getHeadQuarters(), uObj.getArea(), uObj.getBiz_Area()
		, uObj.getAddress(), uObj.getWebsite(), uObj.getLegal_Person(), uObj.getLegal_Person_Phone(), uObj.getFinancial_Contacts(), uObj.getFinancial_Phone()
		, uObj.getInvoice_Company(), uObj.getInvoice_Tax_Code(), uObj.getInvoice_Bank_Name(), uObj.getInvoice_Bank_Code(),
		uObj.getInvoice_Account(), uObj.getInvoice_Phone(), uObj.getInvoice_Address(), uObj.getReceipt_Company(), uObj.getReceipt_Bank_Name(),
		uObj.getReceipt_Bank_Code(), uObj.getReceipt_Account(), uObj.getRecv_Name(), uObj.getRecv_Phone(),
		uObj.getRecv_Fax(),uObj.getRecv_Email(), uObj.getRecv_Address(), uObj.getRecv_Postcode(), uObj.getAttachment(),
		uObj.getAlter_Suppliers(), uObj.getIs_Enabled(), uObj.getRemark(), uObj.getCreate_By(), uObj.getCreate_Time(), uObj.getUpdate_Time(),
		uObj.getUpdate_By(), uObj.getID());  
}
// 通过编号来删除数据——根据code
int SupplierDAO::SupplierDeleteByCode(string id)
{
	string sql = "DELETE FROM `bas_supplier` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

