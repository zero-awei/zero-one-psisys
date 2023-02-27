#include "stdafx.h"
#include "PayApplyControlle.h"

JsonVO<PageVO<PaymentBillVO>> PayApplyControlle::execQueryPayBill(const PaymentBillQuery& query, const PayloadDTO& payload) {


	JsonVO<PageVO<PaymentBillVO>> result;

	return result;
}


JsonVO<PaymentBillDetailVO> PayApplyControlle::execQueryPayDetailBill(const PaymentBillDetailQuery& query, const PayloadDTO& payload) {
	PaymentBillDetailVO result;
	return JsonVO<PaymentBillDetailVO>(result, RS_SUCCESS);
}


JsonVO<uint64_t> PayApplyControlle::execAddPayHandle(const AddPayApplyDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}


JsonVO<uint64_t> PayApplyControlle::execModPayHandle(const ModPayApplyDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}