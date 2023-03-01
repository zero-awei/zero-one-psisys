#include "stdafx.h"
#include "CurrencyController.h"
#include "../../service/currency/CurrencyService.h"
#include "../../../lib-common/include/ExcelComponent.h"
#include "../../../lib-common/include/CharsetConvertHepler.h"
#include <FastDfsClient.h>

JsonVO<PageVO<CurrencyVO>> CurrencyController::execQueryCurrency(const CurrencyQuery& query, const PayloadDTO& payload)
{
    //定义一个Service
    CurrencyService service;
    //查询数据
    PageVO<CurrencyVO> result = service.listAll(query);
    if ( query.getPageSize() < 1 || query.getPageIndex() < 1)
    {
        return JsonVO<PageVO<CurrencyVO>>(result, RS_PARAMS_INVALID);
    }
    //响应结果
    return JsonVO<PageVO<CurrencyVO>>(result, RS_SUCCESS);
}

JsonVO<CurrencyVO> CurrencyController::execQueryDetail(const OnlyValueCurrencyQuery& query, const PayloadDTO& payload)
{
    CurrencyService service;
    //查询数据
    CurrencyVO result = service.listByName(query);
    if(result.getCode().size() == 0) return JsonVO<CurrencyVO>(result, RS_FAIL);
    return JsonVO<CurrencyVO>(result, RS_SUCCESS);
}

JsonVO<uint64_t> CurrencyController::execAddCurrency(const CurrencyDTO& dto, const PayloadDTO& payload)
{
    JsonVO<uint64_t> result;
    CurrencyService service;
    if (dto.getCode().size() == 0 || dto.getName().size() == 0) return JsonVO<uint64_t>(0, RS_PARAMS_INVALID);
    //执行数据新增
    uint64_t id = service.saveData(dto, payload);
    if (id > 0) {
        result.success(id);

    }
    else
    {
        result.fail(id);
    }
    //响应结果
    return result;
}

JsonVO<uint64_t> CurrencyController::execModifyCurrency(const CurrencyDTO& dto, const PayloadDTO& payload)
{
    CurrencyService service;
    JsonVO<uint64_t> result;
    if (dto.getCode().size() == 0 || dto.getName().size() == 0) return JsonVO<uint64_t>(0, RS_PARAMS_INVALID);
    bool flag = service.updateData(dto, payload);
    if (flag) {
        result.success(flag);
    }
    else
    {
        result.fail(flag);
    }
    return result;
}

JsonVO<uint64_t> CurrencyController::execRemoveCurrency(const CurrencyDTO& dto)
{
    CurrencyService service;
    JsonVO<uint64_t> result;
    bool flag = service.removeData(dto.getCode());
    //执行数据删除
    if (flag) {
        result.success(flag);
    }
    else
    {
        result.fail(flag);
    }
    //响应结果
    return result;
}

JsonVO<bool>  CurrencyController::execAddCurrencys(const CurrencyDTO& dto, const PayloadDTO& payload)
{
    JsonVO<bool> result;
    bool succeed = true;
    std::list<CurrencyDTO> vDto;
    ExcelComponent excel;

    // 获取上传文件路径列表
    for (auto file : dto.getFiles()) {
        // 读取文件到DTO
        string sheetName = CharsetConvertHepler::ansiToUtf8("currency");
        auto readData = excel.readIntoVector(file, sheetName);
        int nums = 0;
        for (auto row : readData)
        {
            if (nums++ == 0) continue;
            CurrencyDTO Dto;
            Dto.setCode(row[0]);
            Dto.setName(row[1]);
            int isFunctional;
            int isEnabled;
            stringstream ss;
            ss << row[2];
            ss >> isFunctional;
            ss.clear();
            ss << row[3];
            ss >> isEnabled;
            Dto.setIsFunctional(isFunctional);
            Dto.setIsEnabled(isEnabled);
            Dto.setRemarks(row[4]);
            vDto.push_back(Dto);
        }
    }
    CurrencyService service;
    // 新增仓库
    for (auto Dto : vDto)
    {
        if (service.saveData(Dto, payload))
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

JsonVO<string> CurrencyController::execExportExecl(const CurrencyQuery& query, const PayloadDTO& payload)
{
    CurrencyService service;
    // 创建excel表
    string filename = u8"../../test/test2.xlsx";
    vector<vector<string>> data;
    data.emplace_back(vector<std::string>({ u8"code", u8"name", u8"is_functional", u8"is_enabled",\
        u8"create_by", u8"create_time", u8"update_by",u8"update_time", u8"remark" }));
    // 查询数据
    if (!service.getData(query, data))
        return JsonVO<string>(u8"导出失败", RS_FAIL);
    string sheetname = u8"currency";
    ExcelComponent excel;
    excel.writeVectorToFile(filename, sheetname, data);
    // 上传到文件服务器
    FastDfsClient client("1.15.240.108", 22);
    filename = client.uploadFile(filename);
    if (filename == "") return JsonVO<string>(u8"导出失败", RS_FAIL);
    JsonVO<std::string> result(filename, RS_SUCCESS);
    //响应结果
    return result;
}