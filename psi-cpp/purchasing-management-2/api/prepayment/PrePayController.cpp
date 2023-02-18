
#include "stdafx.h"
#include "PrePayController.h"
#include "../../domain/query/prepaymentbill/PrepayExportQuery.h"

//查询单据信息
JsonVO<PageVO<PrepaymentBillVO>> PrePayController::execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<PrepaymentBillVO>> rs;

	PageVO<PrepaymentBillVO> data;
	std::list<PrepaymentBillVO> rows;
	rows.push_back(PrepaymentBillVO());
	rows.push_back(PrepaymentBillVO());
	rows.push_back(PrepaymentBillVO());
	data.setRows(rows);
	return rs;
}

//查询指定单据详细信息
JsonVO<PrepaymentDetailBillVO> PrePayController::execQueryPayDetailBill(const PrepayDetailBillQuery& query, const PayloadDTO& payload)
{
		PrepaymentDetailBillVO result;
		return JsonVO<PrepaymentDetailBillVO>(result, RS_SUCCESS);
}

//导入
JsonVO<uint64_t> PrePayController::execPayInto(const PayIntoDTO& dto)
{
	JsonVO<uint64_t> result;
	//响应结果
	return JsonVO<uint64_t>();
}

//导出
	JsonVO<PrepaymentExportVO> PrePayController::execPrepayExport(const PrePayExportQuery & query, const PayloadDTO & payload)
{
	//响应结果
	return JsonVO<PrepaymentExportVO>();
}

//新增订单
JsonVO<uint64_t> PrePayController::execAddPay(const  AddPayDTO& dto)
{
	JsonVO<uint64_t> result;	
	return result;
}
//修改订单
JsonVO<uint64_t> PrePayController::execModifyPay(const  PrepaymentDTO& dto)
{
	JsonVO<uint64_t> result;
	result.success(200);
	return result;
}
//修改单据状态
JsonVO<uint64_t> PrePayController::execModifyPayBillStatus(const PayModBillStatusDTO& dto)
{
	JsonVO<uint64_t> result;
	result.success(200);
	return result;
}

// 删除订单
JsonVO<uint64_t> PrePayController::execRemovePayById(const DePayDTO& id)
{
	JsonVO<uint64_t> result;
	return result;
}


