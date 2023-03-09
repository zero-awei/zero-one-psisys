#pragma once
#ifndef _EXPORT_SUPPLIER_MAPPER_
#define _EXPORT_SUPPLIER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/supplier/ExportSupplierDO.h"

/**
 * ◊÷∂Œ∆•≈‰”≥…‰
 */
class ExportSupplierMapper : public Mapper<ExportSupplierDO>
{
public:
	ExportSupplierDO mapper(ResultSet* resultSet) const override
	{
		ExportSupplierDO data;
		data.setCode(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setShortName(resultSet->getString(3));
		data.setAuxName(resultSet->getString(4));
		data.setSupplierCategory(resultSet->getString(5));
		data.setSupplierLevel(resultSet->getString(6));
		data.setTaxScale(resultSet->getString(7));
		data.setHeadquarters(resultSet->getString(8));
		data.setArea(resultSet->getString(9));
		data.setBizArea(resultSet->getString(10));
		data.setAddress(resultSet->getString(11));
		data.setWebsite(resultSet->getString(12));
		data.setLegalPerson(resultSet->getString(13));
		data.setLegalPersonPhone(resultSet->getString(14));
		data.setFinancialContacts(resultSet->getString(15));
		data.setFinancialPhone(resultSet->getString(16));
		data.setInvoiceCompany(resultSet->getString(17));
		data.setInvoiceTaxCode(resultSet->getString(18));
		data.setInvoiceBankName(resultSet->getString(19));
		data.setInvoiceBankCode(resultSet->getString(20));
		data.setInvoiceAccount(resultSet->getString(21));
		data.setInvoicePhone(resultSet->getString(22));
		data.setInvoiceAddress(resultSet->getString(23));
		data.setReceiptCompany(resultSet->getString(24));
		data.setReceiptBankName(resultSet->getString(25));
		data.setReceiptBankCode(resultSet->getString(26));
		data.setReceiptAccount(resultSet->getString(27));
		data.setRecvName(resultSet->getString(28));
		data.setRecvPhone(resultSet->getString(29));
		data.setRecvFax(resultSet->getString(30));
		data.setRecvEmail(resultSet->getString(31));
		data.setRecvAddress(resultSet->getString(32));
		data.setRecvPostcode(resultSet->getString(33));
		data.setAttachment(resultSet->getString(34));
		data.setIsEnabled(resultSet->getInt(35));
		data.setAlterSuppliers (resultSet->getString(36));
		data.setRemark(resultSet->getString(37));
		data.setVersion(resultSet->getInt(38));
		return data;
	}
};

#endif // !_EXPORT_SUPPLIER_MAPPER_