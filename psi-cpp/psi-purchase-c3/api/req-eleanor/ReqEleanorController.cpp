#include "stdafx.h"
#include "ReqEleanorController.h"
#include "../../service/req-eleanor/ReqEleanorService.h"



JsonVO<ReqEleanorVO> ReqEleanorController::execModifyReqEleanorInfo(const ReqEleanorDTO& dto)
{
	//构建一个测试VO
	ReqEleanorVO vo;

	//输出测试上传文件路径列表
	//for (auto file : dto.getFiles()) {
	//	std::cout << "path " << file << std::endl;
	//}

	//响应结果
	return JsonVO<ReqEleanorVO>(vo, RS_API_UN_IMPL);
}
