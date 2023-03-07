#pragma once
#ifndef _PAYMENT_SERVICE_
#define _PAYMENT_SERVICE_
#include <list>
#include <time.h>
#include <cstdio> //C++

//查看预付申请单列表
#include "../../domain/query/prepaymentbill/PrepayDetailBillQuery.h"
#include "../../domain/vo/prepaymentbill/PrepaymentBillVO.h"
#include "../../domain/vo/prepaymentbill/PrepaymentDetailBillVO.h"
//增加修改删除预付申请单列表
#include "../../domain/dto/prepayment/AddPayDTO.h"
#include "../../domain/dto/prepayment/PrepaymentDTO.h"
//删除DTO
#include "../../domain/dto/payment/DePaymentDTO.h"
//修改订单状态DTO
#include "../../domain/dto/payment/PaymentChangeDTO.h"
//添加DTO
#include "../../domain/dto/payment/AddPaymentDTO.h"

#include "../../domain/vo/prepayment/PrepaymentVO.h"
//导入导出
#include "../../domain/query/prepaymentbill/PrePayExportQuery.h"
#include "../../domain/dto/prepayment/PayIntoDTO.h"
#include "../../domain/vo/prepayment_req/PrepaymentIntoVO.h"
#include "../../domain/vo/prepayment_req/PrepaymentExportVO.h"

#include "../../domain/vo/PageVO.h"

// 最后编译
#include "../../domain/query/prepaymentbill/PrepayBillQuery.h"
#include "SnowFlake.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"

/**
 * 采购付款申请单Service
 */
class PaymentService
{
public:
	//  定义删除
	bool DePayment(const  DePaymentDTO& dto);
	//  定义修改订单状态且加上用户
	bool ChangePayStatus(const PaymentChangeDTO& dto, const PayloadDTO& payload);

	//  定义添加（修改前）
	bool AddPay(const AddPaymentDTO& dto);
	//  定义添加且加上用户（修改后）
	uint64_t saveData(const AddPaymentDTO& dto, const PayloadDTO& payload);

};

#endif // !_PRE_PAY_SERVICE_
