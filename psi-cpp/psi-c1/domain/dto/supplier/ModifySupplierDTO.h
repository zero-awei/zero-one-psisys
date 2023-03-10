#pragma once

#ifndef _MODIFY_DTO_
#define _MODIFY_DTO_
#include "../FileDTO.h"
#include "../../GlobalInclude.h"

/**
 * 示例传输对象
 */
class ModifySupplierDTO : public FileDTO//继承FileDTO就是为了实现文件上传
{
	/*供应商信息*/
	//id
	CC_SYNTHESIZE(string, id, ID);
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
	//上传附件（在controller里面实现）
	//CC_SYNTHESIZE(string, attachment, Attachment);
	/*操作信息*/
	//创建时间
	//CC_SYNTHESIZE(string, create_time, Create_Time);
	//创建人
	//CC_SYNTHESIZE(string, create_by, Create_By);
	//修改时间
	//CC_SYNTHESIZE(string, update_time, Update_Time);
	//修改人
	//CC_SYNTHESIZE(string, update_by, Update_By);
	/*以上create_time，create_by，update_time，update_by四个字段都不需要用户输入，是系统生成的，所以dto中不需要，在service中会写*/
	//40个字段
	public:
		// 绑定JSON转换方法
		friend void from_json(const json& j, ModifySupplierDTO& t); // NOLINT
};

#endif // !_MODIFY_DTO_
