#include "stdafx.h"
#include "PaymentController.h"
#include "../../service/Payment/PaymentService.h"
#include "../lib-common/include/CharsetConvertHepler.h"

//修改单据状态
//负责人：最初
JsonVO<string> PaymentController::execChangePayment(const PaymentChangeDTO& dto, const PayloadDTO& payload)
{

	// 数据校验
	if (dto.getId().empty() || dto.getBill_no().empty()) // 如果id或者单据编号为空
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	// 如果操作类型未知
	if (dto.getOpType() != dto.CLOSE && dto.getOpType() != dto.UNCLOSE && dto.getOpType() != dto.CANCEL)
		return JsonVO<string>({}, RS_PARAMS_INVALID);

	PaymentService service;
	JsonVO<string> result;
	// 执行
	if (service.ChangePayStatus(dto, payload)) {
		result.success(dto.getId());
		switch (dto.getOpType())
		{
		case dto.CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("关闭成功"));
			break;
		case dto.UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("反关闭成功"));
			break;
		case dto.CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("作废成功"));
			break;
		}
	}
	else
	{
		result.fail(dto.getId());
		switch (dto.getOpType())
		{
		case dto.CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("关闭失败"));
			break;
		case dto.UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("反关闭失败"));
			break;
		case dto.CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("作废失败"));
			break;
		}
	}
	return result;
}

// 删除申请单
//负责人：最初
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



//添加申请
//负责人：最初
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
