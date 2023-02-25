#include "stdafx.h"
#include "PurReqController.h"
#include "../../service/pur-req/PurReqService.h"



//查询单据信息
JsonVO<PageVO<PurReqFindBillVO>> PurReqController::execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload) {
	PurReqService service;
	PageVO<PurReqFindBillVO> result = service.listAll(query);

	return JsonVO<PageVO<PurReqFindBillVO>>(result, RS_SUCCESS);
}

//查询指定单据详细信息
JsonVO<PurReqFindDetailBillVO> PurReqController::execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload) {
	PurReqService service;
	PurReqFindDetailBillVO result = service.detailsOne(query);
	JsonVO<PurReqFindDetailBillVO> jResult;
	if (result.getBill_no().empty())
	{
		jResult.setStatus(RS_PARAMS_INVALID);
		return jResult;
	}
	jResult.success(result);
	return jResult;
}



//添加申请
JsonVO<uint64_t> PurReqController::execAddPurReq(const AddPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PurReqService service;
	//进行必填参数检验
	if (dto.getBillNo() == "" || dto.getBillDate() == "" || dto.getRequestDept() == "" 
		|| dto.getRequester()=="" || dto.getRequestTime() == "" ||dto.getBillStage() == "") {
		result.setStatus(RS_PARAMS_INVALID);
		result.setData(9999);
		return result;
	}
	//进行明细检验
	if (dto.getDetail().size() != 0) {
		for (auto d : dto.getDetail())
		{
			if (d.getEntryNo() < 0  || d.getMaterialId() == "" || d.getUnitId() == ""
				|| d.getQty() < 0 || d.getOrderedQty() < 0) {
				result.setStatus(RS_PARAMS_INVALID);
				result.setData(9999);
				return result;
			}
		}
	}


	//执行数据新增
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		result.success(100);
	}
	else
	{
		result.fail(9995);
	}
	//响应结果
	return result;
}

//修改申请
JsonVO<uint64_t> PurReqController::execModifyPurReq(const ModifyPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PurReqService service;
	//进行必填参数检验
	if (dto.getBillNo() == "" || dto.getBillDate() == "" || dto.getRequestDept() == ""
		|| dto.getRequester() == "" || dto.getRequestTime() == "" || dto.getBillStage() == ""
		|| dto.getSysOrgCode() == "" || dto.getCreateBy() == "" || dto.getCreateTime() == "") {
		result.setStatus(RS_PARAMS_INVALID);
		result.setData(9999);
		return result;
	}
	//进行明细检验
	if (dto.getDetail().size() != 0) {
		for (auto d : dto.getDetail())
		{
			if (d.getEntryNo() < 0 || d.getMaterialId() == "" || d.getUnitId() == ""
				|| d.getQty() < 0 || d.getOrderedQty() < 0) {
				result.setStatus(RS_PARAMS_INVALID);
				result.setData(9999);
				return result;
			}
		}
	}
	//进行格式检验 暂时不会
	
	//执行数据删除
	if (!service.removeData(dto.getBillNo())) //如果删除失败
	{
		result.fail(9995);
	}
	//执行数据添加
	uint64_t id = service.updateData(dto, payload);
	if (id > 0) {
		result.success(100);
	}
	else
	{
		result.fail(9995);
	}
	//响应结果
	return result;
}

//删除申请 完成
JsonVO<uint64_t> PurReqController::execRemovePurReqById(const DeletePurReqDTO& dto)
{
	PurReqService service;
	JsonVO<uint64_t> result;
	//进行必填参数检验
	if (dto.getBillNo() == "") {
		result.setStatus(RS_PARAMS_INVALID);
		result.setData(9999);
		return result;
	}
	//执行数据删除
	if (service.removeData(dto.getBillNo())) {
		result.success(100);
	}
	else
	{
		result.fail(9995);
	}
	//响应结果
	return result;
}

//修改单据状态 完成
JsonVO<uint64_t> PurReqController::execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PurReqService service;

	//进行必填参数检验
	if (dto.getBillNo() == "") {
		result.setStatus(RS_PARAMS_INVALID);
		result.setData(9999);
		return result;
	}

	//执行数据状态修改
	uint64_t id = service.updateBillStatus(dto, payload);
	if (id > 0) {
		result.success(100);
	}
	else
	{
		result.fail(9995);
	}
	//响应结果
	return result;
}

//导入
JsonVO<uint64_t> PurReqController::execPurReqInto(const PurReqIntoDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	//下载文件并且进行execl解析
	PurReqService service;
	uint64_t ret = 1;
	for (string file : dto.getFiles()) {
		ret = service.getFromExecl(file, payload);
		if (ret == 0)
		{
			result.fail(9995);
			break;
		}
	}
	//响应结果
	if (ret)
	{
		result.success(100);
	}	
	return result;
}

//导出
JsonVO<string> PurReqController::execPurReqExport(const PurReqExportDTO& dto, const PayloadDTO& payload)
{
	JsonVO<string> result;
	PurReqService service;
	string url = service.getToExecl(dto.getBillNoList());
	if (url == "")
	{
		result.fail("");
	}
	else {
		result.success(url);
	}
	//响应结果
	return result;
}

