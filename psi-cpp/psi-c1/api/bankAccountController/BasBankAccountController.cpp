#include "stdafx.h"
#include "BasBankAccountController.h"

JsonVO<std::list<BasBankAccountVO>> BasBankAccountController::execQueryBasBankAccount()
{
    list<BasBankAccountVO> data;
    BasBankAccountVO vo;
    //vo.setId(1);
    //vo.setValue(u8"1584913699556106242");
    data.push_back(vo);
    JsonVO<list<BasBankAccountVO>> res;
    res.success(data);
    return res;
}
