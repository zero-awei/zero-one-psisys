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

// 添加申请单
JsonVO<string> PaymentController::execAddPayment(const AddPaymentDTO& dto)
{
	PaymentService service;
	JsonVO<string> result;
	// 数据校验
	if ( dto.getBill_no() == "") {   // 如果单据编号为空
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	}
	//执行数据添加
	if (service.AddPay(dto)) {
		result.success(dto.getId());
		result.setMessage(CharsetConvertHepler::ansiToUtf8("添加成功"));
	}
	else {
		result.fail(dto.getId());
		result.setMessage(CharsetConvertHepler::ansiToUtf8("添加失败"));
	}
	//响应结果
	return result;
}

//添加申请
JsonVO<uint64_t> PaymentController::execAddPayment(const AddPaymentDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PaymentService service;
	//进行必填参数检验
	if (dto.getBill_no() == "" || dto.getBill_date() == "" || dto.getOperator() == ""|| dto.getOp_dept() == "" 
		|| dto.getSupplier_id() == "" ) {
		result.setStatus(RS_PARAMS_INVALID);
		result.setData(9999);
		return result;
	}
	////进行明细检验
	//if (dto.getDetail().size() != 0) {
	//	for (auto d : dto.getDetail())
	//	{
	//		if (d.getEntryNo() < 0 || d.getMaterialId() == "" || d.getUnitId() == ""
	//			|| d.getQty() < 0 || d.getOrderedQty() < 0) {
	//			result.setStatus(RS_PARAMS_INVALID);
	//			result.setData(9999);
	//			return result;
	//		}
	//	}
	//}


	//执行数据新增
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		result.success(100);
	}
	else
	{
		result.fail(9995);
	}
	//响应结果
	return result;
}
