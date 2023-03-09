#pragma once
#ifndef _EXPORTACCOUNTDAO_H_
#define _EXPORTACCOUNTDAO_H_
#include "BaseDAO.h"
#include "domain/do/bank-account/ExportAccountDO.h"

/*
* 账户信息导出
* @Author: Oxygen
* @Date: 2023/2/22 10:51:56
*/
class ExportAccountDAO : public BaseDAO
{
public:
	list<ExportAccountDO> selectAccount(const ExportAccountDO& obj);
	list<ExportAccountDO> selectAllAccount(const ExportAccountDO& obj);
};

#endif // _EXPORTACCOUNTDAO_H_