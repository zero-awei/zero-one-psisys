#ifndef _TAXRATE_DAO_
#define _TAXRATE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/TaxRateDO.h"

class TaxRateDAO : public BaseDAO
{
public:

	list<TaxRateDO> selectTaxRate();
};
#endif // !_TAXRATE_DAO_