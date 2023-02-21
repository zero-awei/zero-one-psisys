#include "stdafx.h"
#include "BankAccountController.h"
#include "../../service/bankAccountService/BankAccountService.h"

JsonVO<PageVO<SpecifiedBankAccountListVO>> BankAccountController::execSpecifiedBankAccount(SpecifiedBankAccountQuery& query)
{
    PageVO<SpecifiedBankAccountListVO> data(query.getPageIndex(), query.getPageSize(), 100, 10, { SpecifiedBankAccountListVO() });
    JsonVO<PageVO<SpecifiedBankAccountListVO>> res;
    res.success(data);
    return res;
}
/*JsonVO<PageVO<BankAccountListVO>> BankAccountController::executequeryBankAccountList(BankAccountQuery query)
{
	PageVO<BankAccountListVO> data;
	JsonVO<PageVO<BankAccountListVO>> res;
	//res.success(data);
	return res;
}
*/

JsonVO<PageVO<BankAccountListVO>> BankAccountController::executequeryBankAccountList(BankAccountQuery& query)
{
	//定义一个Service
	BankAccountService service;
	//查询数据
	PageVO<BankAccountListVO> result = service.listAll(query);
	//响应结果
	return JsonVO<PageVO<BankAccountListVO>>(result, RS_SUCCESS);
}
