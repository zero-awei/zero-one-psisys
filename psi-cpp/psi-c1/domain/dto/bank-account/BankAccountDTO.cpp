#include "stdafx.h"
#include "BankAccountDTO.h"

/*
* 银行账户信息
* @Author: Oxygen
* @Date: 2023/2/13 21:21:17
*/
void from_json(const json& j, BankAccountDTO& t) { // NOLINT
	BIND_FROM_TO_NORMAL(j, t, accountNo);
	BIND_FROM_TO_NORMAL(j, t, name);
	BIND_FROM_TO_NORMAL(j, t, currency);
	BIND_FROM_TO_NORMAL(j, t, bankNo);
	BIND_FROM_TO_NORMAL(j, t, bankAddress);
	BIND_FROM_TO_NORMAL(j, t, manager);
	BIND_FROM_TO_I(j, t, isEnabled);
	BIND_FROM_TO_NORMAL(j, t, remark);
	BIND_FROM_TO_NORMAL(j, t, createBy);
	BIND_FROM_TO_NORMAL(j, t, updateBy);
}

