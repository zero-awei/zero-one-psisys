#include "stdafx.h"
#include "FinPaymentReqControlle.h"

JsonVO<PageVO<FinPaymentReqVO>> FinPaymentReqControlle::execQueryPayBill(const FinPaymentReqQuery& query, const PayloadDTO& payload) {


	JsonVO<PageVO<FinPaymentReqVO>> result;

	return result;
}


JsonVO<FinPaymentReqEntryVO> FinPaymentReqControlle::execQueryPayDetailBill(const FinPaymentReqEntryQuery& query, const PayloadDTO& payload) {
	FinPaymentReqEntryVO result;
	return JsonVO<FinPaymentReqEntryVO>(result, RS_SUCCESS);
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