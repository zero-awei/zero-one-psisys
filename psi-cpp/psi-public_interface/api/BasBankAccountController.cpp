#include "stdafx.h"
#include "BasBankAccountController.h"

JsonVO<std::list<BasBankAccountVO>> BasBankAccountController::execQueryBasBankAccount()
{
    list<BasBankAccountVO> data;
    BasBankAccountVO vo;
    vo.setLabel(u8"12345678901234567890");
    vo.setText(u8"12345678901234567890");
    vo.setTitle(u8"12345678901234567890");
    vo.setValue(u8"1584913699556106242");
    data.push_back(vo);
    JsonVO<list<BasBankAccountVO>> res;
    res.success(data);
    return res;
}
