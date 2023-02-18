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
	//构建一个测试VO
	PurQuotExportVO vo;
	//响应结果
	return JsonVO<PurQuotExportVO>(vo, RS_SUCCESS);;
}

//导入
JsonVO<PurQuotIntoVO> PurQuotController::execPurQuotInto(const PurQuotIntoDTO& dto)
{
	//构建一个测试VO
	PurQuotIntoVO vo;
	//响应结果
	return JsonVO<PurQuotIntoVO>(vo, RS_SUCCESS);;
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

	//构建一个测试VO
	PurQuotFindDetailBillVO vo;
	//响应结果
	return JsonVO<PurQuotFindDetailBillVO>(vo, RS_SUCCESS);
}

//询价单列表
JsonVO<PurQuotListVO> PurQuotController::execQueryPurQuotList(const PurQuotListQuery& query, const PayloadDTO& payload)
{
	//构建一个测试VO
	PurQuotListVO vo;
	//响应结果
	return JsonVO<PurQuotListVO>(vo, RS_SUCCESS);
}
//询价单分录列表
JsonVO<PurQuotDividedListVO> PurQuotController::execQueryPurQuotDividedList(const PurQuotDividedListQuery& query, const PayloadDTO& payload)
{
	//构建一个测试VO
	PurQuotDividedListVO vo;
	//响应结果
	return JsonVO<PurQuotDividedListVO>(vo, RS_SUCCESS);
}