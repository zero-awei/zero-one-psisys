#include "stdafx.h"
#include "DepotController.h"

/*
* 数据校验
* 改接口返回值
* 操作信息后台 PayloadDTO获得创建人，修改人
* ID生成器在com-雪花
* 成功示例，失败示例
* 
*/

JsonVO<PageVO<DepotVO>> DepotController::execQueryDepot(const DepotQuery& query, const PayloadDTO& payload)
{
    //定义一个Service
    DepotService service;
    //查询数据
    PageVO<DepotVO> result = service.listAll(query);
    //响应结果
    return JsonVO<PageVO<DepotVO>>(result, RS_SUCCESS);
}

JsonVO<std::list<DepotVO>> DepotController::execQueryKidDepot(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    // 数据校验
    if (query.getId() == "") {
        return JsonVO<std::list<DepotVO>>({}, RS_PARAMS_INVALID);
    }
    // 定义Service
    DepotService service;
    // 查询数据
    std::list<DepotVO> result = service.getKid(query);
    return JsonVO<std::list<DepotVO>>(result, RS_SUCCESS);
}

JsonVO<DepotDetailVO> DepotController::execQueryDetail(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotDetailVO>();
}

JsonVO<DepotActionInfoVO> DepotController::execQueryActionInfo(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotActionInfoVO>();
}

JsonVO<bool> DepotController::execAddDepot(const DepotDTO& dto)
{
    JsonVO<bool> result;
    //定义一个Service
    DepotService service;
    //保存数据
    if (service.saveData(dto)) {
        result.success(true);
    }
    else {
        result.fail(false);
    }
    return result;
}

JsonVO<bool> DepotController::execModifyDepot(const DepotDTO& dto)
{
    JsonVO<bool> result;
    //定义一个Service
    DepotService service;
    if (service.modifyDepot(dto)) {
        result.success(true);
    }
    else
    {
        result.fail(false);
    }
    return result;
}

JsonVO<bool> DepotController::execRemoveDepot(const OnlyValueQuery& query)
{
    JsonVO<bool> result;
    //定义一个Service
    DepotService service;
    //删除数据
    if (service.removeData(query)) {
        result.success(true);
    }
    else
    {
        result.fail(false);
    }
    return result;
}

JsonVO<int> DepotController::execAddDepots(const DepotDTO& dto)
{
    return JsonVO<int>();
}

JsonVO<string> DepotController::execExportExecl(const DepotQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

JsonVO<string> DepotController::execExportExeclOnly(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

