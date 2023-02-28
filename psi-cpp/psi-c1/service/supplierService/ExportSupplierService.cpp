#include "stdafx.h"
#include "ExportSupplierService.h"
#include "../../dao/supplierDAO/ExportSupplierDAO.h"

list<ExportSupplierDO> ExportSupplierService::listAll(const ExportSupplierQuery& query)
{
    ExportSupplierDO obj;
    obj.setId(query.getId());
    ExportSupplierDAO dao;
    list<ExportSupplierDO> result = dao.selectSupplier(obj);
    return result;
}
