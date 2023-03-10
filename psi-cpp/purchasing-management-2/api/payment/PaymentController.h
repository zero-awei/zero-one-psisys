#pragma once

#ifndef _PAYMENTCONTROLLER_H_
#define _PAYMENTCONTROLLER_H_
#include "../../domain/dto/payment/PaymentChangeDTO.h"
#include "../../domain/dto/payment/DePaymentDTO.h"
#include "../../domain/dto/payment/PaymentImportDTO.h"
#include "../../domain/dto/payment/AddPaymentDTO.h"

#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/payment/PaymentVO.h"

/**
 * 采购付款申请订单
 * 负责人：最初
 */
class PaymentController
{
public:
	//修改单据状态
	CREATE_API_FUN_BODY_PAYLOAD(modifyPayment, execChangePayment, PaymentChangeDTO);
	//删除指定单据
	CREATE_API_FUN_BODY(deleteById, execDePayment, DePaymentDTO);
	//添加单据
	CREATE_API_FUN_BODY_PAYLOAD(AddPayment, execAddPayment, AddPaymentDTO);
private:
	//修改单据状态
	JsonVO<string> execChangePayment(const PaymentChangeDTO& dto, const PayloadDTO& payload);
	//删除单据
	JsonVO<string> execDePayment(const DePaymentDTO& dto);
	//添加单据
	JsonVO<uint64_t> execAddPayment(const AddPaymentDTO& dto, const PayloadDTO& payload);

};
#endif // _PAYMENTCONTROLLER_H_