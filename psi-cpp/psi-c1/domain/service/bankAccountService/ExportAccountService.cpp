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
list<ExportAccountDO> ExportAccountService::listAll(const ExportAccountQuery& query)
{
	ExportAccountDO obj;
	obj.setAccountNo(query.getAccountNo());
	obj.setName(query.getName());
	obj.setCurrency(query.getAccountNo());
	obj.setInit_bal(query.getInit_bal());
	obj.setBankNo(query.getBankNo());
	obj.setBankAddress(query.getBankAddress());
	obj.setManager(query.getManager());
	obj.setRemark(query.getRemark());
	obj.setIsEnabled(query.getIsEnabled());
	ExportAccountDAO dao;
	list<ExportAccountDO> result = dao.selectAccount(obj);
	return result;
}
