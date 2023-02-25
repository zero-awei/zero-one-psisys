#pragma once
#include "stdafx.h"
#include"ModifySupplierDTO.h"


void from_json(const json& j, ModifySupplierDTO& t) { // NOLINT
	BIND_FROM_TO_NORMAL(j, t, id);
	BIND_FROM_TO_NORMAL(j, t, code);
	BIND_FROM_TO_NORMAL(j, t, name);
	BIND_FROM_TO_NORMAL(j, t, aux_name);
	BIND_FROM_TO_NORMAL(j, t, supplier_category);
	BIND_FROM_TO_NORMAL(j, t, supplier_level);
	BIND_FROM_TO_NORMAL(j, t, tax_scale);
	BIND_FROM_TO_NORMAL(j, t, alter_suppliers);
	BIND_FROM_TO_I(j, t, is_enabled);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, invoice_company);
	BIND_FROM_TO_NORMAL(j, t, invoice_tax_code);
	BIND_FROM_TO_NORMAL(j, t, invoice_bank_name);
	BIND_FROM_TO_NORMAL(j, t, invoice_bank_code);
	BIND_FROM_TO_NORMAL(j, t, invoice_account);
	BIND_FROM_TO_NORMAL(j, t, invoice_phone);
	BIND_FROM_TO_NORMAL(j, t, invoice_address);
	BIND_FROM_TO_NORMAL(j, t, receipt_company);
	BIND_FROM_TO_NORMAL(j, t, receipt_bank_name);
	BIND_FROM_TO_NORMAL(j, t, receipt_bank_code);
	BIND_FROM_TO_NORMAL(j, t, receipt_account);
	BIND_FROM_TO_NORMAL(j, t, recv_name);
	BIND_FROM_TO_NORMAL(j, t, recv_phone);
	BIND_FROM_TO_NORMAL(j, t, recv_fax);
	BIND_FROM_TO_NORMAL(j, t, recv_email);
	BIND_FROM_TO_NORMAL(j, t, recv_address);
	BIND_FROM_TO_NORMAL(j, t, recv_postcode);
	BIND_FROM_TO_NORMAL(j, t, fnancial_Contacts);
	BIND_FROM_TO_NORMAL(j, t, financial_phone);
	BIND_FROM_TO_NORMAL(j, t, short_name);
	BIND_FROM_TO_NORMAL(j, t, website);
	BIND_FROM_TO_NORMAL(j, t, legal_person);
	BIND_FROM_TO_NORMAL(j, t, legal_person_phone);
	BIND_FROM_TO_NORMAL(j, t, headquarters);
	BIND_FROM_TO_NORMAL(j, t, area);
	BIND_FROM_TO_NORMAL(j, t, biz_area);
	BIND_FROM_TO_NORMAL(j, t, address);
	//附件在这里不用写，我们在controller里面写了
	BIND_FROM_TO_NORMAL(j, t, create_time);
	BIND_FROM_TO_NORMAL(j, t, create_by);
	BIND_FROM_TO_NORMAL(j, t, update_time);
	BIND_FROM_TO_NORMAL(j, t, update_by);
}