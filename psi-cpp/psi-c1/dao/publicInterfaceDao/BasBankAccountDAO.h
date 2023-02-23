#pragma once
/*
@Author: kiva
@Date : 2022 / 10 / 25 11 : 17 : 48
*/

#ifndef _BASBANKACCOUNTDAO_H_
#define _BASBANKACCOUNTDAO_H_
#include"./BaseDAO.h"
#include"../../domain/do/publicInterfaceDO/BasBankAccountDO.h"

class BasBankAccountDAO :public BaseDAO {
public:
	list<BasBankAccountDO> selectAccount();
};

#endif