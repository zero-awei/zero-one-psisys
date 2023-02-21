#include "stdafx.h"
#include "DepotController.h"

/*
* 流程大约是：这里->Service->dao 然后 Service要用到Do,dao的实现要用到Mapper
* 其中Service的功能大概就是不同对象之间数据的绑定和调用DAO和数据库交互
* DAO负责直接和数据库交互，但要依靠Mapper将字段和对象属性关联起来
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

JsonVO<PageVO<DepotVO>> DepotController::execAddDepot(const DepotDTO& dto)
{
    //定义一个Service
    DepotService service;
    //保存数据
    cout << service.saveData(dto) << endl;
    //查询数据
    DepotQuery query;
    PageVO<DepotVO> result = service.listAll(query);
    //响应结果
    return JsonVO<PageVO<DepotVO>>(result, RS_SUCCESS);
}

JsonVO<PageVO<DepotVO>> DepotController::execModifyDepot(const DepotDTO& dto)
{
    return JsonVO<PageVO<DepotVO>>();
}

JsonVO<PageVO<DepotVO>> DepotController::execRemoveDepot(const OnlyValueQuery& query)
{
    //定义一个Service
    DepotService service;
    //删除数据
    service.removeData(query);
    //查询数据
    DepotQuery q;
    q.setPageIndex(query.getPageIndex());
    q.setPageSize(query.getPageSize());
    PageVO<DepotVO> result = service.listAll(q);
    //响应结果
    return JsonVO<PageVO<DepotVO>>(result, RS_SUCCESS);
}

JsonVO<PageVO<DepotVO>> DepotController::execAddDepots(const DepotDTO& dto)
{
    return JsonVO<PageVO<DepotVO>>();
}

JsonVO<string> DepotController::execExportExecl(const DepotQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

JsonVO<string> DepotController::execExportExeclOnly(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

