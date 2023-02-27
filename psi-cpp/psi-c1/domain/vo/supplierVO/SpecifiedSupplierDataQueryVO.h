#pragma once
#ifndef _SPECIFIED_VO_
#define _SPECIFIED_VO_

#include "../../GlobalInclude.h"

/**
 * 示例显示对象
 */
class SpecifiedSupplierDataQueryVO
{
	/*供应商信息*/
	// 编号
	CC_SYNTHESIZE(string, code, Code);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	//助记名----其他信息的“辅助名称”和助记名用的都是数据库中的同一个字段 3
	CC_SYNTHESIZE(string, aux_name, Aux_Name);
	//供应商分类 
	CC_SYNTHESIZE(string, supplier_category, Supplier_Category);
	//供应商等级 
	CC_SYNTHESIZE(string, supplier_level, Supplier_Level);
	//纳税规模 
	CC_SYNTHESIZE(string, tax_scale, Tax_Scale);
	//备选供应商
	CC_SYNTHESIZE(string, alter_suppliers, Alter_Suppliers);
	//是否启用
	CC_SYNTHESIZE(int, is_enabled, Is_Enabled);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);

	/*发票信息*/
	//单位名称
	//单位名称
	CC_SYNTHESIZE(string, invoice_company, Invoice_Company);
	//税号
	CC_SYNTHESIZE(string, invoice_tax_code, Invoice_Tax_Code);
	//开户行
	CC_SYNTHESIZE(string, invoice_bank_name, Invoice_Bank_Name);
	//行号
	CC_SYNTHESIZE(string, invoice_bank_code, Invoice_Bank_Code);
	//账号
	CC_SYNTHESIZE(string, invoice_account, Invoice_Account);
	//联系电话
	CC_SYNTHESIZE(string, invoice_phone, Invoice_Phone);
	//开票地址
	CC_SYNTHESIZE(string, invoice_address, Invoice_Address);
	/*办款资料*/
	//单位名称Unit name
	CC_SYNTHESIZE(string, receipt_company, Receipt_Company);
	//开户行Account bank
	CC_SYNTHESIZE(string, receipt_bank_name, Receipt_Bank_Name);
	//行号line number
	CC_SYNTHESIZE(string, receipt_bank_code, Receipt_Bank_Code);
	//账号Account
	CC_SYNTHESIZE(string, receipt_account, Receipt_Account);
	/*收件信息*/
	//addressee收件人
	CC_SYNTHESIZE(string, recv_name, Recv_Name);
	//Contact number联系电话
	CC_SYNTHESIZE(string, recv_phone, Recv_Phone);
	//fax传真
	CC_SYNTHESIZE(string, recv_fax, Recv_Fax);
	//Email
	CC_SYNTHESIZE(string, recv_email, Recv_Email);
	//address地址
	CC_SYNTHESIZE(string, recv_address, Recv_Address);
	//Zip邮编
	CC_SYNTHESIZE(string, recv_postcode, Recv_Postcode);

	/*财务信息*/
	//财务信息联系人
	CC_SYNTHESIZE(string, fnancial_Contacts, Financial_Contacts);
	//财务信息联系电话
	CC_SYNTHESIZE(string, financial_phone, Financial_Phone);
	/*其他信息*/
	//简称
	CC_SYNTHESIZE(string, short_name, Short_Name);
	//辅助名称(必填）_其他信息的“辅助名称”和助记名用的都是数据库中的同一个字段
	//CC_SYNTHESIZE(string, aux_name2, Aux_Name2);
	//供应商网站 11
	CC_SYNTHESIZE(string, website, Website);
	//法人代表
	CC_SYNTHESIZE(string, legal_person, Legal_Person);
	//法人电话
	CC_SYNTHESIZE(string, legal_person_phone, Legal_Person_Phone);
	//所属总公司 
	CC_SYNTHESIZE(string, headquarters, HeadQuarters);
	//业务区域  
	CC_SYNTHESIZE(string, area, Area);
	//所属地区 
	CC_SYNTHESIZE(string, biz_area, Biz_Area);
	//供应商地址 
	CC_SYNTHESIZE(string, address, Address);
	//上传附件（还不确定要不要）
	CC_SYNTHESIZE(string, attachment, Attachment);
	/*操作信息*/
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_Time);
	//创建人
	CC_SYNTHESIZE(string, create_by, Create_By);
	//修改时间
	CC_SYNTHESIZE(string, update_time, Update_Time);
	//修改人
	CC_SYNTHESIZE(string, update_by, Update_By);
	//41个字段
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(SpecifiedSupplierDataQueryVO, code,name, aux_name, supplier_category, supplier_level, tax_scale, alter_suppliers, is_enabled, remark, invoice_company, invoice_tax_code,
		invoice_bank_name, invoice_bank_code, invoice_account,
		invoice_phone, invoice_address, receipt_company, receipt_bank_name, receipt_bank_code,
		receipt_account, recv_name, recv_phone, recv_fax, recv_email, recv_address, recv_postcode, fnancial_Contacts,
		financial_phone, short_name, website, legal_person, legal_person_phone,
		headquarters, area, biz_area, address, attachment, create_time, create_by, update_time, update_by);
};

#endif // !_SPECIFIED_VO_

