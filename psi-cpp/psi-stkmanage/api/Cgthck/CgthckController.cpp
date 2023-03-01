#include "stdafx.h"
#include "CgthckController.h"

JsonVO<std::list<QueryCgrkBillListsVO>> CgthckController::execQueryCgrkEntryList(const QueryCgrkBillQuery& query, const PayloadDTO& payload)
{
    // 构建返回对象
    list<QueryCgrkBillListsVO> result;

    // 数据检验
    if(query.getBillNo().empty()) return JsonVO<list<QueryCgrkBillListsVO>>(result, RS_PARAMS_INVALID);

    // 查询数据
    CgthckService service;  // 定义一个service
    result = service.listAll(query);
    return JsonVO<list<QueryCgrkBillListsVO>>(result, RS_SUCCESS);
}

JsonVO<uint64_t> CgthckController::execAddCgthckBill(const AddCgthckBillDTO& dto, const PayloadDTO& payload)
{
    JsonVO<uint64_t> result;
    CgthckService service;
    // 执行数据新增
    uint64_t res = service.saveData(dto);
    if (res > 0)
    {
        result.success(res);
    }
    else if (res == -1)
    {
        result.setData(res);
        result.setStatus(RS_PARAMS_INVALID);
    }
    else
    {
        result.fail(res);
    }
    return result;
}

JsonVO<uint64_t> CgthckController::execModifyCgthckBill(const AddCgthckBillDTO& dto, const PayloadDTO& payload)
{
    JsonVO<uint64_t> result;
    CgthckService service;
    // 执行数据修改
    uint64_t res = service.updateData(dto);
    if (res > 0)
    {
        result.success(res);
    }
    else if (res == -1)
    {
        result.setData(res);
        result.setStatus(RS_PARAMS_INVALID);
    }
    else
    {
        result.fail(res);
    }
    return result;
}

JsonVO<uint64_t> CgthckController::execModifyCgthckApproval(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    JsonVO<uint64_t> result;
    CgthckService service;
    // 执行数据修改
    uint64_t res = service.updateApproval(dto, payload);
    if (res > 0)
    {
        result.success(res);
    }
    else if(res == -1)
    {
        result.setData(res);
        result.setStatus(RS_PARAMS_INVALID);
    }
    else
    {
        result.fail(res);
    }
    return result;
}

JsonVO<uint64_t> CgthckController::execModifyCgthcStatusToClose(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    JsonVO<uint64_t> result;
    // 定义service
    CgthckService service;
    // 执行关闭操作
    uint64_t res = service.closed(dto, payload);
    if (res > 0)
    {
        result.success(res);
    }
    else
    {
        result.fail(res);
    }
    return result;
}

JsonVO<uint64_t> CgthckController::execModifyCgthcStatusToUnclose(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    JsonVO<uint64_t> result;
    // 定义service
    CgthckService service;
    // 执行反关闭操作
    uint64_t res = service.unclosed(dto, payload);
    if (res > 0)
    {
        result.success(res);
    }
    else
    {
        result.fail(res);
    }
    return result;
}

JsonVO<uint64_t> CgthckController::execModifyCgthcStatusToVoided(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    JsonVO<uint64_t> result;
    // 定义service
    CgthckService service;
    // 执行作废操作
    uint64_t res = service.voided(dto, payload);
    if (res > 0)
    {
        result.success(res);
    }
    else
    {
        result.fail(res);
    }
    return result;
}

JsonVO<uint64_t> CgthckController::execDeleteCgthckBill(const DeleteCgthckBillDTO& dto, const PayloadDTO& payload)
{
    JsonVO<uint64_t> result;
    // 定义service
    CgthckService service;
    // 执行删除单据操作
    uint64_t res = service.removeData(dto);
    if (res > 0)
    {
        result.success(res);
    }
    else if (res == -1)
    {
        result.setData(res);
        result.setStatus(RS_PARAMS_INVALID);
    }
    else
    {
        result.fail(res);
    }
    return result;
}

JsonVO<uint64_t> CgthckController::execDeleteCgthckBillDetail(const DeleteCgthckBillDTO& dto, const PayloadDTO& payload)
{
    JsonVO<uint64_t> result;
    // 定义service
    CgthckService service;
    // 执行删除明细操作
    uint64_t res = service.removeEntry(dto);
    if (res > 0)
    {
        result.success(res);
    }
    else if (res == -1)
    {
        result.setData(res);
        result.setStatus(RS_PARAMS_INVALID);
    }
    else
    {
        result.fail(res);
    }
    return result;
}

JsonVO<uint64_t> CgthckController::execImportCgthckFile(const ImportCgthckFileDTO& dto)
{
    // 定义返回对象
    JsonVO<uint64_t> result;

    CgthckService service;
    uint64_t res = service.importData(dto);

    if (res > 0)
    {
        result.success(res);
    }
    else
    {
        result.fail(res);
    }
    return result;
}

JsonVO<ExportCgthckVO> CgthckController::execExportCgthckFile(const ExportCgthckFileDTO& dto, const PayloadDTO& payload)
{
    CgthckService service;
    ExportCgthckVO result = service.exportData(dto);
    std::cout << result.getFileName() << std::endl;
    return JsonVO<ExportCgthckVO>(result, RS_SUCCESS);
}
