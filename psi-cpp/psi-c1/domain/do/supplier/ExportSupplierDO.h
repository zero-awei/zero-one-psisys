#pragma once
#ifndef _EXPORT_SUPPLIER_DO_
#define _EXPORT_SUPPLIER_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class ExportSupplierDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// 编号
	CC_SYNTHESIZE(string, code, Code);
	// 供应商名字
	CC_SYNTHESIZE(string, name, Name);
	// 简称
	CC_SYNTHESIZE(string, shortName, ShortName);
	// 助记名
	CC_SYNTHESIZE(string, auxName, AuxName);
	// 供应商分类
	CC_SYNTHESIZE(string, supplierCategory, SupplierCategory);
	// 供应商等级
	CC_SYNTHESIZE(string, supplierLevel, SupplierLevel);
	// 纳税规模
	CC_SYNTHESIZE(string, taxScale, TaxScale);
	// 所属总公司
	CC_SYNTHESIZE(string, headquarters, Headquarters);
	// 所属地区
	CC_SYNTHESIZE(string, area, Area);
	// 业务区域
	CC_SYNTHESIZE(string, bizArea, BizArea);
	// 客户地址
	CC_SYNTHESIZE(string, address, Address);
	// 客户网站
	CC_SYNTHESIZE(string, website, Website);
	// 法人代表
	CC_SYNTHESIZE(string, legalPerson, LegalPerson);
	// 法人电话
	CC_SYNTHESIZE(string, legalPersonPhone, LegalPersonPhone);
	// 财务信息联系人
	CC_SYNTHESIZE(string, financialContacts, FinancialContacts);
	// 财务信息联系电话
	CC_SYNTHESIZE(string, financialPhone, FinancialPhone);
	// 开票信息单位名称
	CC_SYNTHESIZE(string, invoiceCompany, InvoiceCompany);
	// 开票信息税号
	CC_SYNTHESIZE(string, invoiceTaxCode, InvoiceTaxCode);
	// 开票信息开户行
	CC_SYNTHESIZE(string, invoiceBankName, InvoiceBankName);
	// 开票信息银行账号
	CC_SYNTHESIZE(string, invoiceBankCode, InvoiceBankCode);
	// 开票信息账号
	CC_SYNTHESIZE(string, invoiceAccount, InvoiceAccount);
	// 开票信息联系电话
	CC_SYNTHESIZE(string, invoicePhone, InvoicePhone);
	// 开票地址
	CC_SYNTHESIZE(string, invoiceAddress, InvoiceAddress);
	// 办款资料单位名称
	CC_SYNTHESIZE(string, receiptCompany, ReceiptCompany);
	// 办款资料开户行
	CC_SYNTHESIZE(string, receiptBankName, ReceiptBankName);
	// 办款资料行号
	CC_SYNTHESIZE(string, receiptBankCode, ReceiptBankCode);
	// 办款资料账号
	CC_SYNTHESIZE(string, receiptAccount, ReceiptAccount);
	// 收件信息收件人
	CC_SYNTHESIZE(string, recvName, RecvName);
	// 收件信息联系电话
	CC_SYNTHESIZE(string, recvPhone, RecvPhone);
	// 收件信息传真
	CC_SYNTHESIZE(string, recvFax, RecvFax);
	// 收件信息邮箱
	CC_SYNTHESIZE(string, recvEmail, RecvEmail);
	// 收件信息地址
	CC_SYNTHESIZE(string, recvAddress, RecvAddress);
	// 收件信息邮编
	CC_SYNTHESIZE(string, recvPostcode, RecvPostcode);
	// 附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	// 供应商是否启用
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
	// 备选供应商
	CC_SYNTHESIZE(string, alterSuppliers, AlterSuppliers);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 版本
	CC_SYNTHESIZE(int, version, Version);
public:
	ExportSupplierDO() {
		id = "";
		code = "";
		name = "";
		shortName = "";
		auxName = "";
		supplierCategory = "";
		supplierLevel = "";
		isEnabled = 1;
	}
};

#endif // !_EXPORT_SUPPLIER_DO_