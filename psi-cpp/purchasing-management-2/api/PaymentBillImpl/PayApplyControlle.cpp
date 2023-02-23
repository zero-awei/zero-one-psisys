#include "stdafx.h"
#include "./PayApplyControlle.h"

JsonVO<PageVO<PaymentBillVO>> execQueryPayBill(const PaymentBillQuery& query, const PayloadDTO& payload) {
	PaymentBillVO pay;
	list<PaymentBillVO> list;
	list.push_back(pay);
	PageVO<PaymentBillVO> result(1,1,1,1, list);
	return JsonVO<PageVO<PaymentBillVO>>(result, RS_SUCCESS);
}

JsonVO<PaymentBillDetailQuery> execQueryPayDetailBill(const PaymentBillDetailQuery& query, const PayloadDTO& payload) {
	PaymentBillDetailQuery result;
	return JsonVO<PaymentBillDetailQuery>(result, RS_SUCCESS);
}

JsonVO<uint64_t> execAddPayHandle(const AddPayApplyDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

JsonVO<uint64_t> execModPayHandle(const ModPayApplyDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}
