#ifndef _SUPPLIERLEVEL_DAO_
#define _SUPPLIERLEVEL_DAO_
#include "BaseDAO.h"
#include "../../domain/do/supplier/SupplierLevelDO.h"

class SupplierLevelDAO : public BaseDAO
{
public:

	list<SupplierLevelDO> selectSupplierLevel();
};
#endif // !_SUPPLIERLEVEL_DAO_