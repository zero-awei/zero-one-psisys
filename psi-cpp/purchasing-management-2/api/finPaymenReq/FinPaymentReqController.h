#pragma once


#ifndef _FIN_PAYMENT_REQ_CONTROLLE_
#define _FIN_PAYMENT_REQ_CONTROLLE_

#include"api/ApiHelper.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/query/finPaymentReq/finPaymentReqQuery.h"
#include "../../domain/query/finPaymentReq/finPaymentReqEntryQuery.h"
#include "../../domain/vo/finPaymentReq/finPaymentReqVO.h"
#include "../../domain/vo/finPaymentReq/finPaymentDetailVO.h"
#include "../../domain/dto/finPaymentReq/addPaymentReqDTO.h"
#include "../../domain/dto/finPaymentReq/modPyamentReqDTO.h"


/**
 * 采购付款申请订单
 * 负责人: 巴比龙
 */
class FinPaymentReqControlle
{
public:
	//查询列表
	CREATE_API_FUN_QUERY_PAYLOAD(queryFinPaymentReq, execQueryPayBill, FinPaymentReqQuery);
	//查询单个详情
	CREATE_API_FUN_QUERY_PAYLOAD(queryFinPaymentReqEntry, execQueryPayDetailBill, FinPaymentReqEntryQuery);
	//添加订单
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPaymentReq, execAddPayHandle, AddPaymentReqDTO);
	//修改订单
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modPaymentReq, execModPayHandle, ModPyamentReqDTO);

private:
	//查询列表
	JsonVO<PageVO<FinPaymentReqVO>> execQueryPayBill(const FinPaymentReqQuery& query, const PayloadDTO& payload);
	//查询单个详情
	JsonVO<FinPaymentDetailVO> execQueryPayDetailBill(const FinPaymentReqEntryQuery& query, const PayloadDTO& payload);
	//添加订单
	JsonVO<uint64_t> execAddPayHandle(const AddPaymentReqDTO& dto, const PayloadDTO& payload);
	//添加订单
	JsonVO<uint64_t> execModPayHandle(const ModPyamentReqDTO& dto, const PayloadDTO& payload);

};
#endif  //_FIN_PAYMENT_REQ_CONTROLLE_
