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

JsonVO<DepotVO> DepotController::execQueryKidDepot(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotVO>();
}

JsonVO<DepotDetailVO> DepotController::execQueryDetail(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotDetailVO>();
}

JsonVO<DepotActionInfoVO> DepotController::execQueryActionInfo(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotActionInfoVO>();
}

JsonVO<string> DepotController::execAddDepot(const DepotDTO& dto)
{
    JsonVO<string> result;
    //定义一个Service
    DepotService service;
    //保存数据
    uint64_t id = service.saveData(dto);
    if (id > 0) {
        result.success(to_string(id));
    }
    else {
        result.fail(to_string(id));
    }
    return result;
}

JsonVO<string> DepotController::execModifyDepot(const DepotDTO& dto)
{
    //定义一个Service
    DepotService service;
    return JsonVO<string>();
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

