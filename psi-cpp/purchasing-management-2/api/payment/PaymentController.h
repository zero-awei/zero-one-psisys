#pragma once

#ifndef _PAYMENTCONTROLLER_H_
#define _PAYMENTCONTROLLER_H_
#include "../../domain/dto/payment/PaymentChangeDTO.h"
#include "../../domain/dto/payment/DepaymentDTO.h"
#include "../../domain/dto/payment/PaymentImportDTO.h"
#include "../../domain/dto/payment/AddPaymentDTO.h"

#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/payment/PaymentVO.h"

/**
 * 控制器
 */
class PaymentController
{
public:
	//修改订单状态
	 CREATE_API_FUN_BODY_PAYLOAD(modifyPayment, execChangePayment, PaymentChangeDTO);
	//删除
	CREATE_API_FUN_BODY(deleteById, execDePayment, DePaymentDTO);
	//添加
	CREATE_API_FUN_BODY_PAYLOAD(AddPayment, execAddPayment, AddPaymentDTO);
private:
	//修改单据状态（关闭/作废/反关闭）
	JsonVO<string> execChangePayment(const PaymentChangeDTO& dto, const PayloadDTO& pl);
	//删除数据
	JsonVO<string> execDePayment(const DePaymentDTO& dto);
	//添加数据
	JsonVO<uint64_t> execAddPayment(const AddPaymentDTO& dto, const PayloadDTO& payload);

};
#endif // _PAYMENTCONTROLLER_H_