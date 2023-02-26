
#include "stdafx.h"
#include "PrePayController.h"
#include "../../domain/query/prepaymentbill/PrepayExportQuery.h"
#include "../../service/prepayment/PrePayService.h"
#include "../lib-common/include/CharsetConvertHepler.h"

//查询单据信息
JsonVO<PageVO<PrepaymentBillVO>> PrePayController::execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload)
{
	//todo：数据校验
	//if (query.getBill_no() == "") {
	//	return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	//}
	//if (query.getBill_date() == "") {
	//	return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	//}
	//if (query.getSubject() == "") {
	//	return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	//}
	//if (query.getSupplier_id() == "") {
	//	return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	//}
	//if (query.getBill_stage() == "") {
	//	return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	//}

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
