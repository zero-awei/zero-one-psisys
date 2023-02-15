#ifndef _BANKACCOUNTCONTROLLER_VO_
#define _BANKACCOUNTCONTROLLER_VO_

#include "domain/vo/JsonVO.h"
#include "domain/vo/BankAccountListVO.h"
#include "domain/vo/PageVO.h"
#include "domain/query/BankAccountQuery.h"
#include "api/ApiHelper.h"
/**
 *Author c1-ruizi
 * 2023/2/12  17:46
 * 银行账户列表查询接口
 */
class BankAccountController
{
public:
	CREATE_API_FUN_QUERY(queryBankAccountList, executequeryBankAccountList, BankAccountQuery);
private:
	JsonVO<PageVO<BankAccountListVO>> executequeryBankAccountList(BankAccountQuery query);
};

#endif // !_BANKACCOUNTCONTROLLER_VO_