#ifndef _PURTYPE_DAO_
#define _PURTYPE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/PurTypeDO.h"

class PurTypeDAO : public BaseDAO
{
public:

	list<PurTypeDO> selectPurType();
};
#endif // !_PURTYPE_DAO_