#pragma once


#ifndef _PAY_APPLY_CONTROLLER_
#define _PAY_APPLY_CONTROLLER_

#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/query/PaymentBillImpl/PaymentBillQuery.h"
#include "../../domain/query/PaymentBillImpl/PaymentBillDetailQuery.h"
#include "../../domain/vo/PaymentBillImpl/PaymentBillVO.h"
#include "../../domain/vo/PaymentBillImpl/PaymentBillDetailVO.h"
#include "../../domain/dto/Payment/AddPaymentDTO.h"
#include "../../domain/dto/PaymentBillImpl/ModPayApplyDTO.h"


/**
 * 采购申请功能点
 */
class PayApplyControlle
{
public:
	//查询列表
	CREATE_API_FUN_QUERY_PAYLOAD(queryPaymentBill, execQueryPayBill, PaymentBillQuery);
	//查询详细数据
	CREATE_API_FUN_QUERY_PAYLOAD(queryPaymentDetailBill, execQueryPayDetailBill, PaymentBillDetailQuery);
	//添加
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPayApply, execAddPayHandle, AddPaymentDTO);
	//修改
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modPayReqApply, execModPayHandle, ModPayApplyDTO);

private:
	//查询列表
	JsonVO<PageVO<PaymentBillVO>> execQueryPayBill(const PaymentBillQuery& query, const PayloadDTO& payload);
	//查询详细数据
	JsonVO<PaymentBillDetailVO> execQueryPayDetailBill(const PaymentBillDetailQuery& query, const PayloadDTO& payload);
	//添加
	JsonVO<uint64_t> execAddPayHandle(const AddPaymentDTO& dto, const PayloadDTO& payload);
	//修改
	JsonVO<uint64_t> execModPayHandle(const ModPayApplyDTO& dto, const PayloadDTO& payload);

};
#endif 
