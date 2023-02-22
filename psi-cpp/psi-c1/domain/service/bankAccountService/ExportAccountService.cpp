#include "stdafx.h"
#include "ExportAccountService.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "dao/bankAccountDAO/ExportAccountDAO.h"
#include "../../do/bankAccountDO/ExportAccountDO.h"

/*
* 银行账户导出
* @Author: Oxygen
* @Date: 2023/2/22 10:48:09
*/
list<ExportAccountDO> ExportAccountService::listAll(const SpecifiedBankAccountQuery& query)
{
	ExportAccountDO obj;
	obj.setAccount_no(query.getAccountNo());
	obj.setName(query.getName());
	ExportAccountDAO dao;
	list<ExportAccountDO> result = dao.selectAccount(obj);
	return result;
}
