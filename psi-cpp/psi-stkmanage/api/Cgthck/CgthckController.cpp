#include "stdafx.h"
#include "CgthckController.h"
#include"../../service/Cgthck/CgthckService.h"
#include"domain/dto/Cgthck/CgthckBillDetailedDTO.h"
JsonVO<PageVO<QueryCgthckBillVO>> CgthckController::execQueryCgthckBill(const QueryCgthckBillQuery& query)
{
    //定义一个Service
    CgthckService service;
    //查询结果
    PageVO<QueryCgthckBillVO> result = service.queryAllFitBill(query);
    //响应结果
    return JsonVO<PageVO<QueryCgthckBillVO>>(result, RS_SUCCESS);
}

JsonVO<QueryCgthrkDetailedBillVO> CgthckController::execQueryCgthckBillDetail(const CgthckBillDetailedDTO& query)
{
    //定义一个Service
    CgthckService service;

    //查询结果
    QueryCgthrkDetailedBillVO result = service.queryBillDetial(query);

    //响应结果
    return JsonVO<QueryCgthrkDetailedBillVO>(result, RS_SUCCESS);
}

JsonVO<uint64_t> CgthckController::execAddCgthckBill(const AddCgthckBillDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> CgthckController::execModifyCgthckBill(const ModifyCgthckBillDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> CgthckController::execDeleteCgthckBill(const DeleteCgthckBillDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> CgthckController::execImportCgthckFile(const ImportCgthckFileDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> CgthckController::execExportCgthckFile(const ExportCgthckFileDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}
