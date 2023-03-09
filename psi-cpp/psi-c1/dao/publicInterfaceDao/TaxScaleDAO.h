#ifndef _TAXSCALE_DAO_
#define _TAXSCALE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/TaxScaleDO.h"

class TaxScaleDAO : public BaseDAO
{
public:

	list<TaxScaleDO> selectTaxScale();
};
#endif // !_TAXSCALE_DAO_