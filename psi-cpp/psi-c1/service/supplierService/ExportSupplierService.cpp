#include "stdafx.h"
#include "ExportSupplierService.h"
#include "../../dao/supplierDao/ExportSupplierDAO.h"

list<list<ExportSupplierDO>> ExportSupplierService::listAll(const list<ExportSupplierQuery>& query)
{
    ExportSupplierDO obj;
    ExportSupplierDAO dao;
    list<list<ExportSupplierDO>> result;
    for (auto raw : query) {
        obj.setId(raw.getId());
        result.push_back(dao.selectSupplier(obj));
    }
    return result;
}
