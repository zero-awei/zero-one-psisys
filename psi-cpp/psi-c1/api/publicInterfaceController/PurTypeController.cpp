#include "stdafx.h"
#include "PurTypeController.h"
#include "../../service/publicInterfaceService/PurTypeService.h"
/*
采购方式下拉列表
Author C1-三木
2023.2.11 21点56分
*/

JsonVO<list<PurTypeVO>> PurTypeController::executequeryPurType()
{
    PurTypeService service;
    list<PurTypeVO> data=service.listAll();
    JsonVO<list<PurTypeVO>> res;
    res.success(data);
    return res;
}
