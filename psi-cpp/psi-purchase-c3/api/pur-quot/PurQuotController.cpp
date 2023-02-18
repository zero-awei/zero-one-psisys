#include "stdafx.h"
#include "PurQuotController.h"


//添加供应报价——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execAddPurQuot(const AddPurQuotDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//修改供应报价——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execModPurQuot(const ModPurQuotDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//删除供应报价——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execDelPurQuotById(const DelPurQuotDTO& id)
{
	JsonVO<uint64_t> result;
	return result;
}

//修改报价状态——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execPurQuotModBillStatus(const PurQuotModBillStatusDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}


//导出
JsonVO<PurQuotExportVO> PurQuotController::execPurQuotExport(const PurQuotExportQuery& dto, const PayloadDTO& payload)
{
	//响应结果
	return JsonVO<PurQuotExportVO>();
}

//导入
JsonVO<uint64_t> PurQuotController::execPurQuotInto(const PurQuotIntoDTO& dto)
{
	JsonVO<uint64_t> result;
	//响应结果
	return JsonVO<uint64_t>();
}

//查询单据列表
JsonVO<PageVO<PurQuotFindBillVO>> PurQuotController::execQueryPurQuotFindBill(const PurQuotFindBillQuery& query, const PayloadDTO& payload) {
	PurQuotFindBillVO test;
	list<PurQuotFindBillVO> ls;
	ls.push_back(test);
	PageVO<PurQuotFindBillVO> result(1, 2, 0, 0, ls);
	return JsonVO<PageVO<PurQuotFindBillVO>>(result, RS_SUCCESS);
}

//查询指定单据列表
JsonVO<PurQuotFindDetailBillVO> PurQuotController::execQueryPurQuotFindDetailBill(const PurQuotFindDetailBillQuery& query, const PayloadDTO& payload) {
	PurQuotFindDetailBillVO result;
	//响应结果
	return JsonVO<PurQuotFindDetailBillVO>(result, RS_SUCCESS);
}


JsonVO<PageVO<PurQuotListVO>> PurQuotController::execQueryPurQuotList(const PurQuotListQuery& query, const PayloadDTO& payload)
{
	////定义一个Service
	//SampleService service;
	////查询数据
	//PageVO<SampleVO> result = service.listAll(query);
	////响应结果
	PageVO<PurQuotListVO> result;
	return JsonVO<PageVO<PurQuotListVO>>(result, RS_SUCCESS);
}

JsonVO<PageVO<PurQuotDividedListVO>> PurQuotController::execQueryPurQuotDividedList(const PurQuotDividedListQuery& query, const PayloadDTO& payload)
{
	////定义一个Service
	//SampleService service;
	////查询数据
	//PageVO<SampleVO> result = service.listAll(query);
	////响应结果
	PageVO<PurQuotDividedListVO> result;
	return JsonVO<PageVO<PurQuotDividedListVO>>(result, RS_SUCCESS);
}