#pragma once


#ifndef _FIN_PAYMENT_REQ_CONTROLLE_
#define _FIN_PAYMENT_REQ_CONTROLLE_

#include"api/ApiHelper.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/query/finPaymentReq/FinPaymentReqQuery.h"
#include "../../domain/query/finPaymentReq/FinPaymentReqEntryQuery.h"
#include "../../domain/vo/finPaymentReq/FinPaymentReqVO.h"
#include "../../domain/vo/finPaymentReq/FinPaymentDetailVO.h"
#include "../../domain/dto/finPaymentReq/AddPaymentReqDTO.h"
#include "../../domain/dto/finPaymentReq/ModPyamentReqDTO.h"


/**
 * 采购申请功能点
 */
class FinPaymentReqControlle
{
public:
	//查询列表
	CREATE_API_FUN_QUERY_PAYLOAD(queryFinPaymentReq, execQueryPayBill, FinPaymentReqQuery);
	//查询详细数据
	CREATE_API_FUN_QUERY_PAYLOAD(queryFinPaymentReqEntry, execQueryPayDetailBill, FinPaymentReqEntryQuery);
	//添加
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPaymentReq, execAddPayHandle, AddPaymentReqDTO);
	//修改
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modPaymentReq, execModPayHandle, ModPyamentReqDTO);

private:
	//查询列表
	JsonVO<PageVO<FinPaymentReqVO>> execQueryPayBill(const FinPaymentReqQuery& query, const PayloadDTO& payload);
	//查询详细数据
	JsonVO<FinPaymentDetailVO> execQueryPayDetailBill(const FinPaymentReqEntryQuery& query, const PayloadDTO& payload);
	//添加
	JsonVO<uint64_t> execAddPayHandle(const AddPaymentReqDTO& dto, const PayloadDTO& payload);
	//修改
	JsonVO<uint64_t> execModPayHandle(const ModPyamentReqDTO& dto, const PayloadDTO& payload);

};
#endif  //_FIN_PAYMENT_REQ_CONTROLLE_
