#include "stdafx.h"
#include "DepotController.h"
#include <FastDfsClient.h>

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

JsonVO<bool> DepotController::execAddDepot(const DepotDTO& dto, const PayloadDTO& payload)
{
    JsonVO<bool> result;
    //定义一个Service
    DepotService service;
    //保存数据
    if (service.saveData(dto, payload.getUsername())){
        result.success(true);
    }
    else {
        result.fail(false);
    }
    return result;
}

JsonVO<bool> DepotController::execModifyDepot(const DepotDTO& dto, const PayloadDTO& payload)
{
    JsonVO<bool> result;
    //定义一个Service
    DepotService service;
    if (service.modifyDepot(dto, payload.getUsername())) {
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
    DepotService service;
    // 创建excel表
    string filename = u8"../../test/test.xlsx";
    vector<vector<string>> data;
    data.emplace_back(vector<std::string>({ u8"名称", u8"编号", u8"助记名", u8"电话",\
        u8"启用", u8"备注", u8"创建时间",u8"创建人", u8"修改时间", u8"修改人" }));
    // 查询数据
    if (!service.getData(query, data))
        return JsonVO<string>(u8"导出失败", RS_FAIL);
    string sheetname = u8"test";
    ExcelComponent excel;
    excel.writeVectorToFile(filename, sheetname, data);
    // 上传到文件服务器
    FastDfsClient client("1.15.240.108");
    filename = client.uploadFile(filename);
    JsonVO<std::string> result(filename, RS_SUCCESS);
    //响应结果
    return result;
}

JsonVO<string> DepotController::execExportExeclOnly(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

