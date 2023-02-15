#include "stdafx.h"
#include "SuppliersNameController.h"

JsonVO<std::list<SuppliersName>> SuppliersNameController::executeQuerySuppliersName()
{
    SuppliersName vo;
    vo.setID("111");
    vo.setName("qwyed");
    std::list<SuppliersName> data;
    data.push_back(vo);
    JsonVO<std::list<SuppliersName>> res;
    res.success(data);
    return res;
}
