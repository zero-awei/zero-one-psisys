#pragma once
#include "stdafx.h"
#include "AddSupplierDTO.h"

void from_json(const json& j, AddSupplierDTO& t) { // NOLINT
	BIND_FROM_TO_ULL(j, t, code);
	BIND_FROM_TO_NORMAL(j, t, name);
	BIND_FROM_TO_NORMAL(j, t, alias);
	BIND_FROM_TO_NORMAL(j, t, supplierClassification);
	BIND_FROM_TO_NORMAL(j, t, supplierLevel);
	BIND_FROM_TO_NORMAL(j, t, taxScale);
	BIND_FROM_TO_NORMAL(j, t, alternativeSuppliers);
	BIND_FROM_TO_NORMAL(j, t, enable);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, unitName1);
	BIND_FROM_TO_NORMAL(j, t, TaxiD);
	BIND_FROM_TO_NORMAL(j, t, accountbank1);
	BIND_FROM_TO_NORMAL(j, t, lineNumber1);
	BIND_FROM_TO_NORMAL(j, t, account1);
	BIND_FROM_TO_NORMAL(j, t, contactNumber1);
	BIND_FROM_TO_NORMAL(j, t, invoicingAddress);
	BIND_FROM_TO_NORMAL(j, t, unitName2);
	BIND_FROM_TO_NORMAL(j, t, accountBank2);
	BIND_FROM_TO_NORMAL(j, t, lineNumber2);
	BIND_FROM_TO_NORMAL(j, t, account2);
	BIND_FROM_TO_NORMAL(j, t, addressee);
	BIND_FROM_TO_NORMAL(j, t, contactNumber2);
	BIND_FROM_TO_NORMAL(j, t, fax);
	BIND_FROM_TO_NORMAL(j, t, email);
	BIND_FROM_TO_NORMAL(j, t, address);
	BIND_FROM_TO_NORMAL(j, t, zip);
	BIND_FROM_TO_NORMAL(j, t, financial_InformationContact);
	BIND_FROM_TO_NORMAL(j, t, contactNumberOfFinancial_Information);
	BIND_FROM_TO_NORMAL(j, t, abbreviation);
	BIND_FROM_TO_NORMAL(j, t, accessibleName);
	BIND_FROM_TO_NORMAL(j, t, supplierWebsite);
	BIND_FROM_TO_NORMAL(j, t, legalRepresentative);
	BIND_FROM_TO_NORMAL(j, t, corporateTelephone);
	BIND_FROM_TO_NORMAL(j, t, headOffice);
	BIND_FROM_TO_NORMAL(j, t, businessArea);
	BIND_FROM_TO_NORMAL(j, t, region);
	BIND_FROM_TO_NORMAL(j, t, supplierAddress);
	BIND_FROM_TO_NORMAL(j, t, creationTime);
	BIND_FROM_TO_NORMAL(j, t, createdBy);
	BIND_FROM_TO_NORMAL(j, t, modificationTime);
	BIND_FROM_TO_NORMAL(j, t, modifiedBy);

}




