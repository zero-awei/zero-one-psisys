#include "stdafx.h"
#include "ImportSupplierController.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "../../service/supplierService/ImportSupplierService.h"

JsonVO<bool> ImportSupplierController::execImportSupplier(const FileDTO& dto)
{ 
	JsonVO<bool> res;
	ImportSupplierService service;
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		res.success(id);
	}
	else
	{
		res.fail(id);
	}
	//ÏìÓ¦½á¹û
	return res;
}
