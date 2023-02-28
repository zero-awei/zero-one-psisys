#include "stdafx.h"
#include "ModifyAccountService.h"
#include "../../do/bankAccountDO/BankAccountFunctionDO.h"
#include "../../../dao/bankAccountDAO/BankAccountFunctionDAO.h"

/*
* 账户信息修改
* @Author: Oxygen
* @Date: 2023/2/22 14:31:16
*/
bool ModifyAccountService::updateData(const BankAccountDTO& dto, const PayloadDTO& pdto)
{
	//组装传输数据
	BankAccountFunctionDO data;
	data.setAccountNo(dto.getAccountNo());
	data.setName(dto.getName());
	data.setCurrency(dto.getCurrency());
	data.setBankNo(dto.getBankNo());
	data.setBankAddress(dto.getBankAddress());
	data.setManager(dto.getManager());
	data.setIsEnabled(dto.getIsEnabled());
	data.setRemark(dto.getRemark());
	data.setUpdateBy(pdto.getUsername());
	//执行数据修改
	BankAccountFunctionDAO dao;
	return dao.updateAccount(data) == 1;
}
