#pragma once
#ifndef _PRE_PAY_CONTROLLER_
#define _PRE_PAY_CONTROLLER_

#include"api/ApiHelper.h"

#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
//查询

#include "../../domain/query/prepaymentbill/PrepayBillQuery.h"
#include "../../domain/query/prepaymentbill/PrepayDetailBillQuery.h"
#include "../../domain/query/prepaymentbill/PrePayExportQuery.h"
//vo
#include "../../domain/vo/prepaymentbill/PrepaymentBillVO.h"
#include "../../domain/vo/prepaymentbill/PrepaymentDetailBillVO.h"
#include "../../domain/vo/prepayment_req/PrepaymentExportVO.h"
#include "../../domain/vo/prepayment_req/PrepaymentIntoVO.h"
#include "../../domain/vo/prepayment/PrepaymentVO.h"
//dto
#include "../../domain/dto/prepayment/PayModBillStatusDTO.h"
#include "../../domain/dto/prepayment/AddPayDTO.h"
#include "../../domain/dto/prepayment/PrepaymentDTO.h"
#include "../../domain/dto/prepayment/DePayDTO.h"
#include "../../domain/dto/prepayment/PayIntoDTO.h"


/**
 * 示例控制器，演示基础接口的使用
 */
class PrePayController
{
public:
	//导入
	CREATE_API_FUN_BODY(modifyPayInto, execPayInto, PayIntoDTO);
	//查询
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFindBill, execQueryPrepayFindBill, PrepayBillQuery);
	//查询指定单据详细信息
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFinDetailBill, execQueryPayDetailBill, PrepayDetailBillQuery);
	//导出申请单
	CREATE_API_FUN_BODY_PAYLOAD(queryPayExport, execPrepayExport, PrePayExportQuery);
	//添加订单
	CREATE_API_FUN_BODY(addPay, execAddPay, AddPayDTO);
	//修改订单
	CREATE_API_FUN_BODY(modifyPay, execModifyPay, PrepaymentDTO);
	//删除订单
	CREATE_API_FUN_BODY(removePayById, execRemovePayById, DePayDTO);
	//修改单据状态(关闭、作废、反关闭)
	CREATE_API_FUN_BODY(modifyPurReqBillStatus, execModifyPayBillStatus, PayModBillStatusDTO);

private:
	//修改单据状态(关闭、作废、反关闭)
	JsonVO<uint64_t> execModifyPayBillStatus(const PayModBillStatusDTO& dto);
	//查询
	JsonVO<PageVO<PrepaymentBillVO>> execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload);
	//查询指定单据详细信息
	JsonVO<PrepaymentDetailBillVO> execQueryPayDetailBill(const PrepayDetailBillQuery& query, const PayloadDTO& payload);
	//导出
	JsonVO<PrepaymentExportVO> execPrepayExport(const PrePayExportQuery& query, const PayloadDTO& payload);
	//新增订单
	JsonVO<uint64_t> execAddPay(const AddPayDTO& dto);
	//修改订单
	JsonVO<uint64_t> execModifyPay(const PrepaymentDTO& dto);
	//删除订单
	JsonVO<uint64_t> execRemovePayById(const DePayDTO& id);
	//导入
	JsonVO<uint64_t> execPayInto(const PayIntoDTO& dto);
};

#endif // _SAMPLE_CONTROLLER_