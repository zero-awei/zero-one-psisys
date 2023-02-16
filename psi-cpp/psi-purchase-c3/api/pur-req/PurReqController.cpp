
#include "stdafx.h"
#include "PurReqController.h"
#include "../../domain/query/pur-req/PurReqExportQuery.h"

#include "service/pur-req/PurReqService.h" //这个头文件是干嘛的?--阿坤

//查询单据信息
JsonVO<PageVO<PurReqFindBillVO>> PurReqController::execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload){
	JsonVO<PageVO<PurReqFindBillVO>> rs;

	PageVO<PurReqFindBillVO> data;
	std::list<PurReqFindBillVO> rows;
	rows.push_back(PurReqFindBillVO());
	rows.push_back(PurReqFindBillVO());
	rows.push_back(PurReqFindBillVO());
	data.setRows(rows);
	return rs;
}

//查询指定单据详细信息
JsonVO<PurReqFindDetailBillVO> PurReqController::execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload){
	PurReqFindDetailBillVO result;
	return JsonVO<PurReqFindDetailBillVO>(result, RS_SUCCESS);
}


//添加申请
JsonVO<uint64_t> PurReqController::execAddPurReq(const AddPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	result.success(200);
	return result;
}

//修改申请
JsonVO<uint64_t> PurReqController::execModifyPurReq(const ModifyPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	result.success(200);
	return result;
}

//删除申请
JsonVO<uint64_t> PurReqController::execRemovePurReqById(const DeletePurReqDTO& dto)
{
	JsonVO<uint64_t> result;
	result.success(200);
	return result;
}

//修改单据状态
JsonVO<uint64_t> PurReqController::execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	result.success(200);
	return result;
}

//导入
JsonVO<uint64_t> PurReqController::execPurReqInto(const PurReqIntoDTO& dto)
{
	//响应结果
	return JsonVO<uint64_t>();
}

//导出
JsonVO<PurReqExportVO> PurReqController::execPurReqExport(const PurReqExportQuery& query, const PayloadDTO& payload)
{
	//响应结果
	return JsonVO<PurReqExportVO>();
}

