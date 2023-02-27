#pragma once
#include "domain/do/bankAccountDO/ExportAccountDO.h"
#include "BaseDAO.h"
#ifndef _EXPORTACCOUNTDAO_H_
#define _EXPORTACCOUNTDAO_H_

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