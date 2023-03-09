#include "stdafx.h"
#include "DepotController.h"
#include "../../../lib-common/include/ExcelComponent.h"
#include "../../../lib-common/include/CharsetConvertHepler.h"
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

JsonVO<list<DepotVO>> DepotController::execQueryKidDepot(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    // 数据校验
    if (query.getId() == "") {
        return JsonVO<list<DepotVO>>({}, RS_PARAMS_INVALID);
    }
    // 定义Service
    DepotService service;
    // 查询数据
    list<DepotVO> result = service.getKid(query);
    return JsonVO<list<DepotVO>>(result, RS_SUCCESS);
}

JsonVO<DepotDetailVO> DepotController::execQueryDetail(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    //定义一个Service
    DepotService service;
    //查询数据
    DepotDetailVO result = service.listDetail(query);
    //响应结果
    return JsonVO<DepotDetailVO>(result, RS_SUCCESS);
}

JsonVO<DepotActionInfoVO> DepotController::execQueryActionInfo(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    //定义一个Service
    DepotService service;
    //查询数据
    DepotActionInfoVO result = service.listInfo(query);
    //响应结果
    return JsonVO<DepotActionInfoVO>(result, RS_SUCCESS);
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

JsonVO<bool> DepotController::execAddKidDepot(const DepotDTO& dto, const PayloadDTO& payload)
{
    JsonVO<bool> result;
    //定义一个Service
    DepotService service;
    //保存数据
    if (service.saveKidData(dto, payload.getUsername())) {
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

JsonVO<bool> DepotController::execAddDepots(const DepotDTO& dto, const PayloadDTO& payload)
{
    JsonVO<bool> result;
    std::list<DepotDTO> vDto;
    ExcelComponent excel;

    // 获取上传文件路径列表
    for (auto file : dto.getFiles()) {
        // 读取文件到DTO
        string sheetName = CharsetConvertHepler::ansiToUtf8("test");
        auto readData = excel.readIntoVector(file, sheetName);
        for (auto row : readData)
        {
            DepotDTO Dto;
            Dto.setName(row[0]);
            Dto.setCode(row[1]);
            Dto.setAuxName(row[2]);
            Dto.setPhone(row[3]);
            // string转int
            auto str = row[4];
            int i = atoi(str.c_str());
            Dto.setStart(i);
            Dto.setRemarks(row[5]);
            vDto.push_back(Dto);
        }
    }
    // 批量新增仓库
    DepotService service;
    for (auto Dto : vDto) 
    { 
        if (service.saveData(Dto, payload.getUsername())) 
        {
            result.success(true);
        }
        else 
        {
            result.fail(false);
            break;
        }
    }
    return result;
}

JsonVO<string> DepotController::execExportExecl(const DepotQuery& query, const PayloadDTO& payload)
{
    DepotService service;
    // 创建excel表
    string filename = CharsetConvertHepler::ansiToUtf8("./tmp/depot.xlsx");
    vector<vector<string>> data;
    vector<std::string> head({ "名称", "编号", "助记名", "电话",\
        "启用", "备注", "创建时间","创建人", "修改时间", "修改人" });
    for (int i = 0; i < head.size(); ++i)    head[i] = CharsetConvertHepler::ansiToUtf8(head[i]);
    data.emplace_back(head);
    // 查询数据
    if (!service.getData(query, data))
        return JsonVO<string>(CharsetConvertHepler::ansiToUtf8("导出失败"), RS_FAIL);
    string sheetname = CharsetConvertHepler::ansiToUtf8("导出仓库数据表");
    ExcelComponent excel;
    excel.writeVectorToFile(filename, sheetname, data);
    // 上传到文件服务器
#ifdef LINUX
    FastDfsClient client("conf/client.conf", 3);
#else
    FastDfsClient client("1.15.240.108");

#endif // #ifdef LINUX

    filename = client.uploadFile(filename);
    JsonVO<std::string> result(filename, RS_SUCCESS);
    //响应结果
    return result;
}

JsonVO<string> DepotController::execExportExeclOnly(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    DepotService service;
    // 创建excel表
    string filename = CharsetConvertHepler::ansiToUtf8("./tmp/depot_by_ids.xlsx");
    vector<vector<string>> data;
    vector<std::string> head({ "名称", "编号", "助记名", "电话",\
        "启用", "备注", "创建时间","创建人", "修改时间", "修改人" });
    for (int i = 0; i < head.size(); ++i)    head[i] = CharsetConvertHepler::ansiToUtf8(head[i]);
    data.emplace_back(head);
    // 查询数据
    if (!service.getDataById(query, data))
        return JsonVO<string>(CharsetConvertHepler::ansiToUtf8("导出失败"), RS_FAIL);
    string sheetname = CharsetConvertHepler::ansiToUtf8("导出仓库数据表");
    ExcelComponent excel;
    excel.writeVectorToFile(filename, sheetname, data);
    // 上传到文件服务器
#ifdef LINUX
    FastDfsClient client("conf/client.conf", 3);
#else
    FastDfsClient client("1.15.240.108");

#endif // #ifdef LINUX
    filename = client.uploadFile(filename);
    JsonVO<std::string> result(filename, RS_SUCCESS);
    //响应结果
    return result;
}

