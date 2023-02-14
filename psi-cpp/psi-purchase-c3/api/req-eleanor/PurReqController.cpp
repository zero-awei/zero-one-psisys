#include "stdafx.h"
#include "PurReqController.h"
#include "../../service/req-eleanor/PurReqService.h"

//导出
nlohmann::json PurReqController::execPurReqExportInfo(const PurReqExportDTO& dto, const PayloadDTO& payload)
{
	//响应结果
	return JsonVO<std::string>();
}

//导入
JsonVO<PurReqIntoVO> PurReqController::execPurReqIntoInfo(const PurReqIntoDTO& dto)
{
	//响应结果
	return JsonVO<PurReqIntoVO>();
}
