#pragma once


#ifndef _PUR_REQ_CONTROLLER_
#define _PUR_REQ_CONTROLLER_

#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/query/PaymentBillImpl/PaymentBillQuery.h"
#include "../../domain/query/PaymentBillImpl/PaymentBillDetailQuery.h"
#include "../../domain/vo/PaymentBillImpl/PaymentBillVO.h"
#include "../../domain/dto/PaymentBillImpl/AddPayApplyDTO.h"
#include "../../domain/dto/PaymentBillImpl/ModPayApplyDTO.h"


/**
 * 采购申请功能点
 */
class PurReqController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryPaymentBill, execQueryPayBill, PaymentBillQuery);

	CREATE_API_FUN_QUERY_PAYLOAD(queryPaymentDetailBill, execQueryPayDetailBill, PaymentBillDetailQuery);

	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPayApply, execAddPayHandle , AddPayApplyDTO);
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modPayReqApply, execModPayHandle , ModPayApplyDTO);

private:
	JsonVO<PageVO<PaymentBillQuery>> execQueryPayBill(const PaymentBillQuery& query, const PayloadDTO& payload);
	JsonVO<PaymentBillDetailQuery> execQueryPayDetailBill(const PaymentBillDetailQuery& query, const PayloadDTO& payload);

	JsonVO<uint64_t> execAddPayHandle(const AddPayApplyDTO& dto, const PayloadDTO& payload);
	JsonVO<uint64_t> execModPayHandle(const ModPayApplyDTO& dto, const PayloadDTO& payload);

};
#endif 
