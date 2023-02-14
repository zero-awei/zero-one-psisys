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
	CC_SYNTHESIZE(int, code, Code);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	//助记名
	CC_SYNTHESIZE(string, alias, Alias);
	//供应商分类
	CC_SYNTHESIZE(string, supplierClassification, SupplierClassification);
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

	/*发票信息*/
	//单位名称
	CC_SYNTHESIZE(string, unitName1, UnitName1);
	//税号
	CC_SYNTHESIZE(string, TaxiD, TaxID);
	//开户行
	CC_SYNTHESIZE(string, accountbank1, AccountBank1);
	//行号
	CC_SYNTHESIZE(string, lineNumber1, LineNumber1);
	//账号
	CC_SYNTHESIZE(string, account1, Account1);
	//联系电话
	CC_SYNTHESIZE(string, contactNumber1, ContactNumber1);
	//开票地址
	CC_SYNTHESIZE(string, invoicingAddress, InvoicingAddress);
	/*办款资料*/
	//单位名称Unit name
	CC_SYNTHESIZE(string, unitName2, UnitName2);
	//开户行Account bank
	CC_SYNTHESIZE(string, accountBank2, AccountBank2);
	//行号line number
	CC_SYNTHESIZE(string, lineNumber2, LineNumber2);
	//账号Account
	CC_SYNTHESIZE(string, account2, Account2);
	/*收件信息*/
	//addressee收件人
	CC_SYNTHESIZE(string, addressee, Addressee);
	//Contact number联系电话
	CC_SYNTHESIZE(string, contactNumber2, ContactNumber2);
	//fax传真
	CC_SYNTHESIZE(string, fax, Fax);
	//Email
	CC_SYNTHESIZE(string, email, Email);
	//address地址
	CC_SYNTHESIZE(string, address, Address);
	//Zip邮编
	CC_SYNTHESIZE(string, zip, Zip);
	/*财务信息*/
	//财务信息联系人
	CC_SYNTHESIZE(string, financial_InformationContact, Financial_InformationContact);
	//财务信息联系电话
	CC_SYNTHESIZE(string, contactNumberOfFinancial_Information, ContactNumberOfFinancial_Information);
	/*其他信息*/
	//简称
	CC_SYNTHESIZE(string, abbreviation, Abbreviation);
	//辅助名称(必填）
	CC_SYNTHESIZE(string, accessibleName, AccessibleName);
	//供应商网站
	CC_SYNTHESIZE(string, supplierWebsite, SupplierWebsite);
	//法人代表
	CC_SYNTHESIZE(string, legalRepresentative, LegalRepresentative);
	//法人电话
	CC_SYNTHESIZE(string, corporateTelephone, CorporateTelephone);
	//所属总公司
	CC_SYNTHESIZE(string, headOffice, HeadOffice);
	//业务区域
	CC_SYNTHESIZE(string, businessArea, BusinessArea);
	//所属地区
	CC_SYNTHESIZE(string, region, Region);
	//供应商地址
	CC_SYNTHESIZE(string, supplierAddress, SupplierAddress);
	//上传附件
	//CC_SYNTHESIZE(string, remark, Remark);
	/*操作信息*/
	//创建时间
	CC_SYNTHESIZE(string, creationTime, CreationTime);
	//创建人
	CC_SYNTHESIZE(string, createdBy, CreatedBy);
	//修改时间
	CC_SYNTHESIZE(string, modificationTime, ModificationTime);
	//修改人
	CC_SYNTHESIZE(string, modifiedBy, ModifiedBy);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(SpecifiedSupplierDataQueryVO, code, name, alias, supplierClassification, supplierLevel, taxScale, alternativeSuppliers, enable, remark,
		unitName1, TaxiD, accountbank1, lineNumber1, account1, contactNumber1, invoicingAddress,
		unitName2, accountBank2, lineNumber2, account2,
		addressee, contactNumber2, fax, email, address, zip,
		financial_InformationContact, contactNumberOfFinancial_Information, abbreviation, accessibleName, supplierWebsite, legalRepresentative, corporateTelephone, headOffice, businessArea, region, supplierAddress,
		creationTime, createdBy, modificationTime, modifiedBy);
};

#endif // !_SPECIFIED_VO_

