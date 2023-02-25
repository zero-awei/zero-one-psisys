#pragma once

#ifndef _ADD_DTO_
#define _ADD_DTO_
#include "../FileDTO.h"
#include "../../GlobalInclude.h"

/**
 * 示例传输对象
 */
class AddSupplierDTO : public FileDTO//继承FileDTO就是为了实现文件上传
{
	/*供应商信息*/
	//id
	CC_SYNTHESIZE(string, id, ID);
	// 编号1
	CC_SYNTHESIZE(string, code, Code);
	// 名称1
	CC_SYNTHESIZE(string, name, Name);
	//助记名----其他信息的“辅助名称”和助记名用的都是数据库中的同一个字段 3   1
	CC_SYNTHESIZE(string, aux_name, Aux_Name);//原来叫Alias
	//供应商分类 1
	CC_SYNTHESIZE(string, supplier_category, Supplier_Category);
	//供应商等级 1
	CC_SYNTHESIZE(string, supplier_level, Supplier_Level);
	//纳税规模 1
	CC_SYNTHESIZE(string, tax_scale, Tax_Scale);
	//备选供应商1
	CC_SYNTHESIZE(string, alter_suppliers, Alter_Suppliers);
	//是否启用1
	CC_SYNTHESIZE(int, is_enabled, Is_Enabled);
	//备注1
	CC_SYNTHESIZE(string, remark, Remark);

	/*发票信息*/
	//单位名称
	//单位名称1
	CC_SYNTHESIZE(string, invoice_company, Invoice_Company);
	//税号1
	CC_SYNTHESIZE(string, invoice_tax_code, Invoice_Tax_Code);
	//开户行1
	CC_SYNTHESIZE(string, invoice_bank_name, Invoice_Bank_Name);
	//行号1
	CC_SYNTHESIZE(string, invoice_bank_code, Invoice_Bank_Code);//容易漏
	//账号1
	CC_SYNTHESIZE(string, invoice_account, Invoice_Account);
	//联系电话1
	CC_SYNTHESIZE(string, invoice_phone, Invoice_Phone);
	//开票地址1
	CC_SYNTHESIZE(string, invoice_address, Invoice_Address);
	/*办款资料*/
	//单位名称Unit name1
	CC_SYNTHESIZE(string, receipt_company, Receipt_Company);
	//开户行Account bank1
	CC_SYNTHESIZE(string, receipt_bank_name, Receipt_Bank_Name);
	//行号line number1
	CC_SYNTHESIZE(string, receipt_bank_code, Receipt_Bank_Code);
	//账号Account1
	CC_SYNTHESIZE(string, receipt_account, Receipt_Account);
	/*收件信息*/
	//addressee收件人1
	CC_SYNTHESIZE(string, recv_name, Recv_Name);
	//Contact number联系电话1
	CC_SYNTHESIZE(string, recv_phone, Recv_Phone);
	//fax传真1
	CC_SYNTHESIZE(string, recv_fax, Recv_Fax);
	//Email1
	CC_SYNTHESIZE(string, recv_email, Recv_Email);
	//address地址1
	CC_SYNTHESIZE(string, recv_address, Recv_Address);
	//Zip邮编1
	CC_SYNTHESIZE(string, recv_postcode, Recv_Postcode);

	/*财务信息*/
	//财务信息联系人1
	CC_SYNTHESIZE(string, fnancial_Contacts, Financial_Contacts);
	//财务信息联系电话1
	CC_SYNTHESIZE(string, financial_phone, Financial_Phone);
	/*其他信息*/
	//简称1
	CC_SYNTHESIZE(string, short_name, Short_Name);
	//辅助名称(必填）_其他信息的“辅助名称”和助记名用的都是数据库中的同一个字段——只需要写一次就行
	//CC_SYNTHESIZE(string, aux_name2, Aux_Name2);
	//供应商网站 1
	CC_SYNTHESIZE(string, website, Website);
	//法人代表1
	CC_SYNTHESIZE(string, legal_person, Legal_Person);
	//法人电话1
	CC_SYNTHESIZE(string, legal_person_phone, Legal_Person_Phone);
	//所属总公司 1
	CC_SYNTHESIZE(string, headquarters, HeadQuarters);
	//业务区域  1
	CC_SYNTHESIZE(string, area, Area);
	//所属地区 1
	CC_SYNTHESIZE(string, biz_area, Biz_Area);
	//供应商地址 1
	CC_SYNTHESIZE(string, address, Address);
	//上传附件——》不需要，因继承了FileDTO
	//CC_SYNTHESIZE(string, attachment, Attachment);
	/*操作信息*/
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_Time);
	//创建人
	CC_SYNTHESIZE(string, create_by, Create_By);
	//修改时间
	CC_SYNTHESIZE(string, update_time, Update_Time);
	//修改人
	CC_SYNTHESIZE(string, update_by, Update_By);
	//40个字段+Filedto
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddSupplierDTO& t); // NOLINT
	AddSupplierDTO()
	{
		is_enabled = -2;//is_enabled如果等于-2代表用户没有输入is_enabled的值
	}
};

#endif // !_ADD_DTO_