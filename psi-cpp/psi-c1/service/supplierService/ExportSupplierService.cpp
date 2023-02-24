#include "stdafx.h"
#include "ExportSupplierService.h"
#include "../../dao/supplierDao/ExportSupplierDAO.h"

list<ExportSupplierDO> ExportSupplierService::listAll(const ExportSupplierQuery& query)
{
    ExportSupplierDO obj;
    obj.setCode(query.getCode());
    obj.setName(query.getName());
    ExportSupplierDAO dao;
    list<ExportSupplierDO> result = dao.selectSupplier(obj);
    return result;
}
