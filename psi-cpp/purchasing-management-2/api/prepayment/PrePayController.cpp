#include "stdafx.h"
#include "PrePayController.h"
#include "../../service/prepayment/PrePayService.h"
#include "../../domain/query/prepaymentbill/PrePayExportQuery.h"
#include "../lib-common/include/CharsetConvertHepler.h"
#include "../../domain/vo/PurOrder/PurOrderVO.h"


//查询单据信息
//负责人：Qi
JsonVO<PageVO<PrepaymentBillVO>> PrePayController::execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload)
{
	//数据校验
	if (query.getPageIndex() <= 0 || query.getPageSize() <= 0) {
		return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	}
	PrePayService service;
	//查询成功
	PageVO<PrepaymentBillVO> result = service.listAll(query);
	return JsonVO<PageVO<PrepaymentBillVO>>(result, RS_SUCCESS);
}

//查询指定单据详细信息
//负责人：Qi
JsonVO<PageVO<PrepaymentDetailBillVO>> PrePayController::execQueryPayDetailBill(const PrepayDetailBillQuery& query, const PayloadDTO& payload)
{
	//数据校验
	if (query.getBill_no() == "") {
		return JsonVO<PageVO<PrepaymentDetailBillVO>>({}, RS_PARAMS_INVALID);
	}
	PrePayService service;
	PageVO<PrepaymentDetailBillVO> result = service.getAll(query);
	if (result.getTotal() > 0) {
		//查询成功
		return JsonVO<PageVO<PrepaymentDetailBillVO>>(result, RS_SUCCESS);
	}
	else {
		//查询失败（单据不存在）
		return JsonVO<PageVO<PrepaymentDetailBillVO>>(result, RS_PARAMS_INVALID);
	}
}

//新增预付申请单
//负责人：Qi
JsonVO<uint64_t> PrePayController::execAddPay(const AddPayDTO& dto, const PayloadDTO& payload)
{
	//数据校验(单据编号、单据日期、业务员、业务部门、供应商、采购订单明细不可以为空，是否自动和是否红字不能为非0和非1)
	if (dto.getBill_no()==""|| dto.getBill_date()==""|| 
		dto.getOperator()==""|| dto.getOp_dept() == ""|| dto.getSupplier_id()==""||
		!(dto.getIs_auto()==0||dto.getIs_auto()==1) ||!(dto.getIs_rubric()==0||dto.getIs_rubric()==1)||
		dto.getDetail().empty()) 
		return JsonVO<uint64_t>({}, RS_PARAMS_INVALID);
	//数据校验(源单号不应为空，明细金额不可为负值)
	for (AddPayDetailDTO x : dto.getDetail()) {
		if (x.getSrc_no()==""|| x.getSrc_bill_id()=="") return JsonVO<uint64_t>({}, RS_PARAMS_INVALID);
		if (dto.getIs_rubric()==0) {
			if (x.getAmt() < 0 || x.getPaid_amt() < 0) return JsonVO<uint64_t>({}, RS_PARAMS_INVALID);
		}
	}
	//响应结果
	PrePayService service;
	JsonVO<uint64_t> result;
	uint64_t id = service.saveData(dto, payload);
	if (id != 0) {
		result.success(id);
	}
	else {
		result.fail(id);
	}
	return result;
}

//修改预付申请单
//负责人：Qi
JsonVO<uint64_t> PrePayController::execModifyPay(const AddPayDTO& dto, const PayloadDTO& payload)
{
	//数据校验(ID、单据编号、单据日期、业务员、业务部门、供应商以及采购订单明细不可以为空)
	if (dto.getId() == "" || dto.getBill_date() == "" ||
		dto.getOperator() == "" || dto.getOp_dept() == "" || dto.getSupplier_id() == "" ||
		!(dto.getIs_auto() == 0 || dto.getIs_auto() == 1) || !(dto.getIs_rubric() == 0 || dto.getIs_rubric() == 1) ||
		dto.getDetail().empty())
		return JsonVO<uint64_t>({}, RS_PARAMS_INVALID);
	//数据校验(源单号不应为空，明细金额不可为负值)
	for (AddPayDetailDTO x : dto.getDetail()) {
		if (x.getSrc_no() == "" || x.getSrc_bill_id() == "") return JsonVO<uint64_t>({}, RS_PARAMS_INVALID);
		if (dto.getIs_rubric() == 0) {
			if (x.getAmt() < 0 || x.getPaid_amt() < 0) return JsonVO<uint64_t>({}, RS_PARAMS_INVALID);
		}
	}
	PrePayService service;
	JsonVO<uint64_t> result;
	if (service.updateData(dto, payload)) {
		result.success(1);
	}
	else {
		result.fail(0);
	}
	return result;
}

// 修改单据状态(关闭、作废、反关闭)
// 负责人：Andrew
JsonVO<string> PrePayController::execModifyPayBillStatus(const PayModBillStatusDTO& dto, const PayloadDTO& payload)
{
	PrePayService service;
	JsonVO<string> result;

	// 数据校验
	if (dto.getId() == "" || dto.getBill_no() == "") // 如果ID和单据编号为空
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	// 如果必填项为空或者不是枚举类中元素则参数错误
	if (dto.getOpType() != dto.CLOSE && dto.getOpType() != dto.CANCEL && dto.getOpType() != dto.UNCLOSE)
		return JsonVO<string>({}, RS_PARAMS_INVALID);

	// 执行
	if (service.updateStatus(dto, payload)) {
		result.success(dto.getId());
		switch (dto.getOpType())
		{
		case dto.CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("Close Successfully"));
			break;
		case dto.UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("Anti-Close Successfully"));
			break;
		case dto.CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("Cancel Successfully"));
			break;
		}
	}
	else {
		result.fail(dto.getId());
		switch (dto.getOpType())
		{
		case dto.CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("Close Successfully"));
			break;
		case dto.UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("Anti-Close Successfully"));
			break;
		case dto.CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("Cancel Successfully"));
			break;
		}
	}
	return result;
}
//查询
//负责人：徐不洗
JsonVO<PageVO<PurOrderVO>> PrePayController::execQuerypayFindBill(const PurOrderQuery& query, const PayloadDTO& payload)
{
	PrePayService service;
	PageVO<PurOrderVO> result = service.listAll(query);
	return JsonVO<PageVO<PurOrderVO>>(result, RS_SUCCESS);
}

//查询指定单据详细信息
//负责人：徐不洗
JsonVO<PurOrderVO> PrePayController::execQueryPayDetailBill(const PurOrderQuery& query, const PayloadDTO& payload)
{
	if (query.getBill_no() == "") {
		return JsonVO<PurOrderVO>({}, RS_PARAMS_INVALID);
	}
	PrePayService service;
	PurOrderVO result = service.getAll(query);
	return JsonVO<PurOrderVO>({}, RS_SUCCESS);
}

//删除订单
//负责人：徐不洗
JsonVO<string> PrePayController::execRemoveDePayId(const DePayDTO& dto)
{
	PrePayService service;
	JsonVO<string> result;
	// 数据校验
	if (dto.getId() == "" || dto.getBill_no() == "") {// 如果ID和单据编号为空
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	}
	//执行订单删除
	if (service.DePrePayId(dto)) {
		result.success(dto.getId());
		result.setMessage(CharsetConvertHepler::ansiToUtf8("Delete Successfully"));
	}
	else {
		result.fail(dto.getId());
		result.setMessage(CharsetConvertHepler::ansiToUtf8("Delete Failure"));
	}
	//结果返回
	return result;
}