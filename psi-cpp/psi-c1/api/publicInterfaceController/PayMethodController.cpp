#include "stdafx.h"
#include "PayMethodController.h"

JsonVO<std::list<PayMethodType>> PayMethodController::executeQueryPayMethod()
{
    std::list<PayMethodType> data;
    PayMethodType vo;
    vo.setId("we");
    vo.setId("123");
    vo.setName(u8"01Õº¡È");
    data.push_back(vo);
    JsonVO<std::list<PayMethodType>> res;
    res.success(data);
    return res;
}
