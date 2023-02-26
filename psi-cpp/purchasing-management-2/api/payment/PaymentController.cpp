#include "stdafx.h"
#include "PaymentController.h"
#include "../../service/Payment/PaymentService.h"
#include "../lib-common/include/CharsetConvertHepler.h"

//修改单据状态
JsonVO<string>  PaymentController::execChangePayment(const PaymentChangeDTO& dto)
{
	PaymentService service;
	JsonVO<string> result;

	// 数据校验
	if (dto.getId() == "" || dto.getBill_no() == "") // 如果ID和单据编号为空
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	if (dto.getOpType() != PaymentChangeDTO::CLOSE && dto.getOpType() != PaymentChangeDTO::UNCLOSE && dto.getOpType() != PaymentChangeDTO::CANCEL)
		return JsonVO<string>({}, RS_PARAMS_INVALID);

	// 执行
	if (service.ChangePayStatus(dto)) {
		result.success(dto.getId());
		switch (dto.getOpType())
		{
		case PaymentChangeDTO::CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("关闭成功"));
			break;
		case PaymentChangeDTO::UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("反关闭成功"));
			break;
		case PaymentChangeDTO::CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("作废成功"));
			break;
		}
	}
	else {
		result.fail(dto.getId());
		switch (dto.getOpType())
		{
		case PaymentChangeDTO::CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("关闭失败"));
			break;
		case PaymentChangeDTO::UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("反关闭失败"));
			break;
		case PaymentChangeDTO::CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("作废失败"));
			break;
		}
	}
	return result;
}

// 删除申请单
JsonVO<string> PaymentController::execDePayment(const DePaymentDTO& dto)
{
	PaymentService service;
	JsonVO<string> result;
	// 数据校验
	if (dto.getId() == "" || dto.getBill_no() == "") {// 如果ID和单据编号为空
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	}
	//执行数据删除
	if (service.DePayment(dto)) {
		result.success(dto.getId());
		result.setMessage(CharsetConvertHepler::ansiToUtf8("删除成功"));
	}
	else {
		result.fail(dto.getId());
		result.setMessage(CharsetConvertHepler::ansiToUtf8("删除失败"));
	}
	//响应结果
	return result;
}

JsonVO<std::string> PaymentController::execExportPayment(const IntIDs& query)
{
	JsonVO<std::string> result;
	result.success(u8"http://filedownload.com");
	//响应结果
	return result;
}

JsonVO<PaymentVO> PaymentController::exeImportPayment(const PaymentImportDTO& dto)
{
	//构建一个测试VO
	PaymentVO vo;
	//vo.setNickname(dto.getNickname());
	//vo.setIdCard(dto.getIdCard());
	//vo.setAge(dto.getAge());

	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}

	//响应结果
	return JsonVO<PaymentVO>(vo, RS_API_UN_IMPL);
}
