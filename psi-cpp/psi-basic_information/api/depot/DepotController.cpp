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

JsonVO<bool> DepotController::execAddKidDepot(const DepotDTO& dto)
{
    JsonVO<bool> result;
    //定义一个Service
    DepotService service;
    //保存数据
    if (service.saveKidData(dto), payload.getUsername())) {
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
    bool succeed = true;
    std::list<DepotDTO> vDto;
    ExcelComponent excel;

    // 获取上传文件路径列表
    for (auto file : dto.getFiles()) {
        // 读取文件到DTO
        string sheetName = u8"test";
        auto readData = excel.readIntoVector(file, sheetName);
        for (auto row : readData)
        {
            DepotDTO Dto;
            Dto.setName(row[0]);
            Dto.setCode(row[1]);
            Dto.setAuxName(row[2]);
            int phone = 0;
            istringstream ss(row[3]);
            ss >> phone;
            Dto.setPhone(phone);
            Dto.setStart(row[4]);
            Dto.setRemarks(row[5]);
            vDto.push_back(Dto);
        }
    }
    DepotService service;
    // 新增仓库
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
    DepotService service;
    // 创建excel表
    string filename = u8"../../test/testids.xlsx";
    vector<vector<string>> data;
    data.emplace_back(vector<std::string>({ u8"名称", u8"编号", u8"助记名", u8"电话",\
        u8"启用", u8"备注", u8"创建时间",u8"创建人", u8"修改时间", u8"修改人" }));
    // 查询数据
    if (!service.getDataById(query, data))
        return JsonVO<string>(u8"导出失败", RS_FAIL);
    string sheetname = u8"testids";
    ExcelComponent excel;
    excel.writeVectorToFile(filename, sheetname, data);
    // 上传到文件服务器
    FastDfsClient client("1.15.240.108");
    filename = client.uploadFile(filename);
    JsonVO<std::string> result(filename, RS_SUCCESS);
    //响应结果
    return result;
}

