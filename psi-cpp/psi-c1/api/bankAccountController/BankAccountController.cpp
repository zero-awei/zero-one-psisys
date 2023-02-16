#include "stdafx.h"
#include "BankAccountController.h"

JsonVO<PageVO<SpecifiedBankAccountListVO>> BankAccountController::execSpecifiedBankAccount(SpecifiedBankAccountQuery& query)
{
    PageVO<SpecifiedBankAccountListVO> data(query.getPageIndex(), query.getPageSize(), 100, 10, { SpecifiedBankAccountListVO() });
    JsonVO<PageVO<SpecifiedBankAccountListVO>> res;
    res.success(data);
    return res;
}
JsonVO<PageVO<BankAccountListVO>> BankAccountController::executequeryBankAccountList(BankAccountQuery query)
{
	PageVO<BankAccountListVO> data;
	JsonVO<PageVO<BankAccountListVO>> res;
	res.success(data);
	return res;
}
