#include "stdafx.h"
#include "PurReqController.h"
#include "../../service/req-eleanor/PurReqService.h"

//导出
nlohmann::json PurReqController::execPurReqExportInfo(const PurReqExportDTO& dto, const PayloadDTO& payload)
{
	PurReqService service;
	std::string result = service.purReqExportData(dto);

	//响应结果
	return JsonVO<std::string>(result, RS_SUCCESS);
}

//导入
nlohmann::json PurReqController::execPurReqIntoInfo(const PurReqIntoDTO& dto)
{
	//构建一个测试VO
	UserVO vo;


	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}

	//响应结果
	return JsonVO<UserVO>(vo, RS_SUCCESS);
}
