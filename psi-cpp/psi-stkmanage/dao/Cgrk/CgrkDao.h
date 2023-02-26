#pragma once
#ifndef C_D
#define C_D
#include "BaseDAO.h"
#include"../../domain/do/Cgrk/ModifyCgrkBillStatusDO.h"
class CgrkDao : public BaseDAO {
public:
	int updataBillStatus(const ModifyCgrkBillStatusDO& doObject);
};
#endif // !C_D
