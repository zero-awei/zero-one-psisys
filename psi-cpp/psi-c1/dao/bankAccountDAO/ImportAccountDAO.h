#pragma once
#ifndef _IMPORTACCOUNTDAO_H_
#define _IMPORTACCOUNTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/bankAccountDO/ImportAccountDO.h"

/*
* 账户信息导入
* @Author: Oxygen
* @Date: 2023/2/22 12:32:21
*/
class ImportAccountDAO : public BaseDAO
{
public:
	uint64_t insert(const ImportAccountDO& iObj);
};

#endif // _IMPORTACCOUNTDAO_H_