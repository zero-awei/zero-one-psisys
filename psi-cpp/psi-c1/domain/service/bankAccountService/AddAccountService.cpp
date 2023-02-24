#include "stdafx.h"
#include "AddAccountService.h"
#include "../../do/bankAccountDO/BankAccountDO.h"
#include "../../../dao/bankAccountDAO/BankAccountDAO.h"
#include "SnowFlake.h"


/*
* 账户添加
* @Author: Oxygen
* @Date: 2023/2/22 12:56:30
*/
const int datacenterId = 1;
const int machineId = 2;
int AddAccountService::saveData(const BankAccountDTO& dto, const PayloadDTO& pdto)
{
	//组装数据
	BankAccountDO data;
	data.setAccountNo(dto.getAccountNo());
	data.setName(dto.getName());
	data.setCurrency(dto.getCurrency());
	data.setBankNo(dto.getBankNo());
	data.setBankAddress(dto.getBankAddress());
	data.setManager(dto.getManager());
	data.setIsEnabled(dto.getIsEnabled());
	data.setRemark(dto.getRemark());
	data.setCreateBy(pdto.getUsername());
	//生成随机id
	SnowFlake sf(datacenterId, machineId);
	uint64_t ID = sf.nextId();
	//执行数据添加
	BankAccountDAO dao;
	return dao.insertAccount(data, ID);
}
