#include "stdafx.h"
#include "ImportSupplierDAO.h"
#include <sstream>

uint64_t ImportSupplierDAO::insert(const ImportSupplierDO& iObj)
{
    string sql = "INSERT INTO `bas_supplier` (`id`, `code`, `name`, `short_name`, `aux_name`, `supplier_category`, `supplier_level`, \
`tax_scale`, `headquarters`, `area`, `biz_area`, `address`, `website`, `legal_person`, `legal_person_phone`, `financial_contacts`, `financial_phone`, \
`invoice_company`, `invoice_tax_code`, `invoice_bank_name`, `invoice_bank_code`, `invoice_account`, `invoice_phone`, `invoice_address`, \
`receipt_company`, `receipt_bank_name`, `receipt_bank_code`, `receipt_account`, `recv_name`, `recv_phone`, `recv_fax`, `recv_email`, \
`recv_address`, `recv_postcode`, `attachment`, `is_enabled`, `alter_suppliers`, `remark`, `version`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, \
?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    return sqlSession->executeUpdate(sql, "%ull%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s%i", 
        iObj.getId(), iObj.getCode(), iObj.getName(), 
        iObj.getShortName(), iObj.getAuxName(), iObj.getSupplierCategory(), iObj.getSupplierLevel(), iObj.getTaxScale(),
        iObj.getHeadquarters(), iObj.getArea(), iObj.getBizArea(), iObj.getAddress(), iObj.getWebsite(), iObj.getLegalPerson(),
        iObj.getLegalPersonPhone(), iObj.getFinancialContacts(), iObj.getFinancialPhone(), iObj.getInvoiceCompany(),
        iObj.getInvoiceTaxCode(), iObj.getInvoiceBankName(), iObj.getInvoiceBankCode(), iObj.getInvoiceAccount(), iObj.getInvoicePhone(),
        iObj.getInvoiceAddress(), iObj.getReceiptCompany(), iObj.getReceiptBankName(), iObj.getReceiptBankCode(), iObj.getReceiptAccount(),
        iObj.getRecvName(), iObj.getRecvPhone(), iObj.getRecvFax(), iObj.getRecvEmail(), iObj.getRecvAddress(), iObj.getRecvPostcode(),
        iObj.getAttachment(), iObj.getIsEnabled(), iObj.getAlterSuppliers() ,iObj.getRemark(), iObj.getVersion());
}
