
#include "stdafx.h"
#include "PrePayController.h"
#include "../../domain/query/prepaymentbill/PrepayExportQuery.h"
#include "../../service/prepayment/PrePayService.h"
#include "../lib-common/include/CharsetConvertHepler.h"

//查询单据信息
JsonVO<PageVO<PrepaymentBillVO>> PrePayController::execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload)
{
	//todo：数据校验
	if (query.getBill_no() == "") {
		return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	}
	if (query.getBill_date() == "") {
		return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	}
	if (query.getSubject() == "") {
		return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	}
	if (query.getSupplier_id() == "") {
		return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	}
	if (query.getBill_stage() == "") {
		return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	}

	//查询成功
	PrePayService service;
	PageVO<PrepaymentBillVO> result = service.listAll(query);
	return JsonVO<PageVO<PrepaymentBillVO>>(result, RS_SUCCESS);
}

//查询指定单据详细信息
JsonVO<PrepaymentDetailBillVO> PrePayController::execQueryPayDetailBill(const PrepayDetailBillQuery& query, const PayloadDTO& payload)
{
	if (query.getBill_no() == "") {
		return JsonVO<PrepaymentDetailBillVO>({}, RS_PARAMS_INVALID);
}
	PrePayService service;
	PageVO<PrepaymentDetailBillVO> result = service.getAll(query);
	return JsonVO<PrepaymentDetailBillVO>({}, RS_SUCCESS);
}

//导入
JsonVO<uint64_t> PrePayController::execPayInto(const PayIntoDTO& dto)
{
	JsonVO<uint64_t> result;
	result.success(200);
	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}
	//响应结果
	return JsonVO<uint64_t>(result);
}

//导出
JsonVO<PrepaymentExportVO> PrePayController::execPrepayExport(const PrePayExportQuery& query, const PayloadDTO& payload)
{
	//响应结果
	JsonVO<uint64_t> result;
	result.success(200);
	return JsonVO<PrepaymentExportVO>();
}

//新增预付申请单
JsonVO<uint64_t> PrePayController::execAddPay(const  AddPayDTO& dto)
{

	JsonVO<uint64_t> result;	
	PrePayService service;
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		result.success(id);
	}
	else{
		result.fail(id);
	}
	//响应结果
	return result;
}

//修改预付申请单
JsonVO<string> PrePayController::execModifyPay(const  PrepaymentDTO& dto)
{
	PrePayService service;
	JsonVO<string> result;
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else{
		result.fail(dto.getId());
	}
	return result;
}

//修改单据状态
JsonVO<string> PrePayController::execModifyPayBillStatus(const PayModBillStatusDTO& dto, const PayloadDTO& payload)
{
	PrePayService service;
	JsonVO<string> result;

	// 数据校验
	if (dto.getId() == "" || dto.getBill_no() == "") // 如果ID和单据编号为空
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	// 如果必填项为空或者不是枚举类中元素则参数错误
	if (dto.getOpType() != dto.CLOSE && dto.getOpType() != dto.CANCEL && dto.getOpType() != dto.UNCLOSE)
		return JsonVO<string>({}, RS_PARAMS_INVALID);

	// 执行
	if (service.updateStatus(dto, payload)) {
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
	else {
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

// 删除预付申请单
JsonVO<uint64_t> PrePayController::execRemoveDePay(const DePayDTO& dto)
{
	PrePayService service;
	JsonVO<uint64_t> result;
	//执行数据删除
	if (service.removeData(dto.getId())) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	//响应结果
	return result;
}

JsonVO<uint64_t> PrePayController::execRemovePayById(const IntID& id)
{
	DePayDTO dto;
	dto.setId(id.getId());
	return execRemoveDePay(dto);
}