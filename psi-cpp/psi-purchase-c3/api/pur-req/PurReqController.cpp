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
