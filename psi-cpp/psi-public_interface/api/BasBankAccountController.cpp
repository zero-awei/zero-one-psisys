#include "stdafx.h"
#include "BasBankAccountController.h"

JsonVO<std::list<BasBankAccountVO>> BasBankAccountController::execQueryBasBankAccount()
{
    std::list<BasBankAccountVO> data;
    data.push_back(BasBankAccountVO());
    JsonVO<std::list<BasBankAccountVO>> res;
    res.success(data);
    return res;
}
