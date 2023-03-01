#include "stdafx.h"
#include "PrePayController.h"
#include "../../domain/query/prepaymentbill/PrepayExportQuery.h"
#include "../../service/prepayment/PrePayService.h"
#include "../lib-common/include/CharsetConvertHepler.h"

//采购订单列表
JsonVO<PageVO<PurOrderVO>> PrePayController::execQuerypayFindBill(const PurOrderQuery& query, const PayloadDTO& payload)
{
	PrePayService service;
	PageVO<PurOrderVO> result = service.listAll(query);
	return JsonVO<PageVO<PurOrderVO>>(result, RS_SUCCESS);
}

//采购订单分列表
JsonVO<PurOrderVO> PrePayController::execQueryPayDetailBill(const PurOrderQuery& query, const PayloadDTO& payload)
{
	if (query.getBill_no() == "") {
		return JsonVO<PurOrderVO>({}, RS_PARAMS_INVALID);
}
	PrePayService service;
	PurOrderVO result = service.getAll(query);
	return JsonVO<PurOrderVO>({}, RS_SUCCESS);
}

//删除
JsonVO<string> PrePayController::execRemoveDePayId(const DePayDTO& dto)
{
	PrePayService service;
	JsonVO<string> result;
	// 数据校验
	if (dto.getId() == "" || dto.getBill_no() == "") {// 如果ID和单据编号为空
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	}
	//执行数据删除
	if (service.DePrePayId(dto)) {
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
