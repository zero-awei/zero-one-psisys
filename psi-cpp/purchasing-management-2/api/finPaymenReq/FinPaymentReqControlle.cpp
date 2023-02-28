#include "stdafx.h"
#include "FinPaymentReqControlle.h"
#include "../../service/finPaymentReq/finPyamentReqService.h"

JsonVO<PageVO<FinPaymentReqVO>> FinPaymentReqControlle::execQueryPayBill(const FinPaymentReqQuery& query, const PayloadDTO& payload) {
	FinPyamentReqService service;
	PageVO<FinPaymentReqVO> result = service.queryList(query);

	return JsonVO<PageVO<FinPaymentReqVO>>(result, RS_SUCCESS);
}

JsonVO<FinPaymentDetailVO> FinPaymentReqControlle::execQueryPayDetailBill(const FinPaymentReqEntryQuery& query, const PayloadDTO& payload) {
	FinPyamentReqService service;
	FinPaymentDetailVO result = service.detailDate(query);
	JsonVO<FinPaymentDetailVO> jResult;
	if (result.getBillNo().empty())
	{
		jResult.setStatus(RS_PARAMS_INVALID);
		return jResult;
	}
	jResult.success(result);
	return jResult;
}


JsonVO<uint64_t> FinPaymentReqControlle::execAddPayHandle(const AddPaymentReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}


JsonVO<uint64_t> FinPaymentReqControlle::execModPayHandle(const ModPyamentReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}