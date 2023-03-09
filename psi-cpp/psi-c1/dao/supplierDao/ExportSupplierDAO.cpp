#include "stdafx.h"
#include "ExportSupplierDAO.h"
#include "ExportSupplierMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getId().empty()) { \
	sql << " AND `id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getId()); \
} 

list<ExportSupplierDO> ExportSupplierDAO::selectSupplier(const ExportSupplierDO& obj)
{
	stringstream sql;
	sql << "SELECT code, name, short_name, aux_name, supplier_category, supplier_level, \
		tax_scale, headquarters, area, biz_area, address, website, legal_person, legal_person_phone, \
		financial_contacts, financial_phone, invoice_company, invoice_tax_code, invoice_bank_name, \
		invoice_bank_code, invoice_account, invoice_phone, invoice_address, receipt_company, receipt_bank_name,\
		receipt_bank_code, receipt_account, recv_name, recv_phone, recv_fax, recv_email, recv_address, recv_postcode, \
		attachment, is_enabled, alter_suppliers, remark, version FROM bas_supplier";
	SAMPLE_TERAM_PARSE(obj, sql);
	ExportSupplierMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ExportSupplierDO, ExportSupplierMapper>(sqlStr, mapper, params);
}
