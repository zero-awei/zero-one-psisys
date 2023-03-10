#pragma once
#ifndef _PRE_PAY_CONTROLLER_
#define _PRE_PAY_CONTROLLER_

#include"api/ApiHelper.h"

#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
//查看预付申请单列表
#include "../../domain/query/prepaymentbill/PrepayBillQuery.h"
#include "../../domain/query/prepaymentbill/PrepayDetailBillQuery.h"
#include "../../domain/query/prepaymentbill/PrePayExportQuery.h"
//vo
#include "../../domain/vo/prepaymentbill/PrepaymentBillVO.h"
#include "../../domain/vo/prepaymentbill/PrepaymentDetailBillVO.h"
//增加修改删除预付申请单列表
#include "../../domain/dto/prepayment/AddPayDTO.h"
#include "../../domain/dto/prepayment/PrepaymentDTO.h"
#include "../../domain/dto/prepayment/DePayDTO.h"
#include "../../domain/dto/prepayment/PayModBillStatusDTO.h"
#include "../../domain/vo/prepayment/PrepaymentVO.h"
//导入导出
#include "../../domain/query/prepaymentbill/PrePayExportQuery.h"
#include "../../domain/vo/prepayment_req/PrepaymentExportVO.h"
#include "../../domain/vo/prepayment_req/PrepaymentIntoVO.h"
#include "../../domain/dto/prepayment/PayIntoDTO.h"
//删除
#include "../../domain/dto/prepayment/DePayDTO.h"
#include "../../domain/vo/prepayment/PrepaymentVO.h"
// 采购订单列表
#include "../../domain/query/purOrder/PurOrderQuery.h"
#include "../../domain/vo/purOrder/PurOrderVO.h"


/**
 * 采购预付申请控制器
 */
class PrePayController
{
public:
	//修改单据状态(关闭、作废、反关闭)
	// 负责人：Andrew
	CREATE_API_FUN_BODY_PAYLOAD(modifyPurReqBillStatus, execModifyPayBillStatus, PayModBillStatusDTO);
	//查询
	// 负责人：Qi
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFindBill1, execQueryPrepayFindBill, PrepayBillQuery);
	//查询指定单据详细信息
	// 负责人：Qi
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFinDetailBill1, execQueryPayDetailBill, PrepayDetailBillQuery);
	//添加订单
	// 负责人：Qi
	CREATE_API_FUN_JSON_PAYLOAD(addPay, execAddPay, AddPayDTO);
	//修改订单
	// 负责人：Qi
	CREATE_API_FUN_JSON_PAYLOAD(modifyPay, execModifyPay, AddPayDTO);
	//查询
	//负责人：徐不洗
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFindBill2, execQuerypayFindBill, PurOrderQuery);
	//查询指定单据详细信息
	//负责人：徐不洗
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFinDetailBill2, execQueryPayDetailBill, PurOrderQuery);
	//删除订单
	//负责人：徐不洗
	CREATE_API_FUN_BODY(removeDePayId, execRemoveDePayId, DePayDTO);
private:
	//修改单据状态(关闭、作废、反关闭)
	// 负责人：Andrew
	JsonVO<string> execModifyPayBillStatus(const PayModBillStatusDTO& dto, const PayloadDTO& pl);
	//查询
	// 负责人：Qi
	JsonVO<PageVO<PrepaymentBillVO>> execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload);
	//查询指定单据详细信息
	// 负责人：Qi
	JsonVO<PageVO<PrepaymentDetailBillVO>> execQueryPayDetailBill(const PrepayDetailBillQuery& query, const PayloadDTO& payload);
	//新增订单
	// 负责人：Qi
	JsonVO<uint64_t> execAddPay(const AddPayDTO& dto, const PayloadDTO& payload);
	//修改订单
	// 负责人：Qi
	JsonVO<uint64_t> execModifyPay(const AddPayDTO& dto, const PayloadDTO& payload);
	//查询
	//负责人：徐不洗
	JsonVO<PageVO<PurOrderVO>> execQuerypayFindBill(const PurOrderQuery& query, const PayloadDTO& payload);
	//查询指定单据详细信息
	//负责人：徐不洗
	JsonVO<PurOrderVO> execQueryPayDetailBill(const PurOrderQuery& query, const PayloadDTO& payload);
	//删除订单
	//负责人：徐不洗
	JsonVO<string> execRemoveDePayId(const DePayDTO& dto);
};

#endif // _SAMPLE_CONTROLLER_