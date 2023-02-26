#pragma once
#ifndef CGRK_SERVERICE
#define CGRK_SERVERICE
#include"api/../domain/dto/Cgrk/ModifyCgrkBillStateDTO.h"

class CgrkService {
public:
	bool updataBillStatus(const ModifyCgrkBillStateDTO& dto);
};
#endif // !CGRK_SERVERICE

