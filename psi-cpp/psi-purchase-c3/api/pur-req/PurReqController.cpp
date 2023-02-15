
#include "stdafx.h"
#include "PurReqController.h"
#include "service/pur-req/PurReqService.h"
#include "domain/dto/pur-req/PurReqExportDTO.h"

//查询单据信息
JsonVO<PageVO<PurReqFindBillVO>> PurReqController::execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload){
	PurReqFindBillVO test1;
	list<PurReqFindBillVO> ls; 
	ls.push_back(test1);
	PageVO<PurReqFindBillVO> result(1, 2, 0, 0, ls);
	return JsonVO<PageVO<PurReqFindBillVO>>(result, RS_SUCCESS);
}

//查询指定单据详细信息
JsonVO<PurReqFindDetailBillVO> PurReqController::execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload){
	PurReqFindDetailBillVO result;
	return JsonVO<PurReqFindDetailBillVO>(result, RS_SUCCESS);
}


//导出
nlohmann::json PurReqController::execPurReqExport(const PurReqExportDTO& dto, const PayloadDTO& payload)
{
	//响应结果
	return nlohmann::json(JsonVO<std::string>());
}

//导入
JsonVO<PurReqIntoVO> PurReqController::execPurReqInto(const PurReqIntoDTO& dto)
{
	//响应结果
	return JsonVO<PurReqIntoVO>();
}



//新增订单
JsonVO<uint64_t> PurReqController::execAddPurReq(const AddPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//修改订单
JsonVO<uint64_t> PurReqController::execModifyPurReq(const ModifyPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//修改订单状态
JsonVO<uint64_t> PurReqController::execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto,  const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//删除订单
JsonVO<uint64_t> PurReqController::execRemovePurReqById(const DeletePurReqDTO& id)
{
	JsonVO<uint64_t> result;
	return result;
}

