#pragma once

#ifndef _PAYMENTCONTROLLER_H_
#define _PAYMENTCONTROLLER_H_
#include "../../domain/dto/payment/PaymentChangeDTO.h"
#include "../../domain/dto/payment/DepaymentDTO.h"
#include "../../domain/dto/payment/PaymentImportDTO.h"

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
	CREATE_API_FUN_BODY(changePayment, execChangePayment, PaymentChangeDTO);
	//删除
	CREATE_API_FUN_BODY(deleteById, execDePayment, DePaymentDTO);
	CREATE_API_FUN_JSON(exportPayment, execExportPayment, IntIDs);
	CREATE_API_FUN_BODY_FILE(importPayment, exeImportPayment, PaymentImportDTO);
private:
	//修改单据状态（关闭/作废/反关闭）
	JsonVO<string> execChangePayment(const PaymentChangeDTO& dto);
	//删除数据
	JsonVO<string> execDePayment(const DePaymentDTO& dto);
	//批量导出数据
	JsonVO<std::string> execExportPayment(const IntIDs& query);
	//导入数据
	JsonVO<PaymentVO> exeImportPayment(const PaymentImportDTO& dto);
};







#endif // _PAYMENTCONTROLLER_H_