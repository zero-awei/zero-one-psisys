#ifndef _SUPPLIERQUERYCRITERIA_DAO_
#define _SUPPLIERQUERYCRITERIA_DAO_
#include "BaseDAO.h"
#include "../../domain/do/supplier/SupplierQueryCriteriaDO.h"

class SupplierQueryCriteriaDAO : public BaseDAO
{
public:

	list<SupplierQueryCriteriaDO> selectSupplierQueryCriteria();
};
#endif // !_SUPPLIERQUERYCRITERIA_DAO_