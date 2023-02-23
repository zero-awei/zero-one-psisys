#include "stdafx.h"
#include "PurQuotController.h"
#include "../../service/pur-quot/PurQuotService.h"

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
	//暂未开始数据校验

	//定义一个Service
	PurQuotService service;
	//构建返回对象
	PageVO<PurQuotFindBillVO> result	= service.listPurQuotFindBillVO(query);
	//响应结果
	return JsonVO<PageVO<PurQuotFindBillVO>>(result, RS_SUCCESS);
}



//查询指定单据列表
JsonVO<PurQuotFindDetailBillVO> PurQuotController::execQueryPurQuotFindDetailBill(const PurQuotFindDetailBillQuery& query, const PayloadDTO& payload) {
	PurQuotFindDetailBillVO result;
	//暂时未进行数据校验
	if(query.getBill_no() == "") return JsonVO<PurQuotFindDetailBillVO>(result, RS_PARAMS_INVALID);
	PurQuotService service;
	result = service.getPurQuotFindDetailBillVO(query);
	//响应结果
	return JsonVO<PurQuotFindDetailBillVO>(result, RS_SUCCESS);
}

//询价单列表
JsonVO<list<PurQuotListVO>> PurQuotController::execQueryPurQuotList(const PurQuotListQuery& query, const PayloadDTO& payload)
{
	//构建返回对象
	list<PurQuotListVO> result;
	//数据校验
	if(query.getBill_no() == "") return JsonVO<list<PurQuotListVO>>(result, RS_PARAMS_INVALID);

	//数据校验成功,返回对应的对象
	PurQuotService service;	
	result = service.listPurQuotListVO(query);
	return JsonVO<list<PurQuotListVO>>(result, RS_SUCCESS);
}
//询价单分录列表
JsonVO<list<PurQuotDividedListVO>> PurQuotController::execQueryPurQuotDividedList(const PurQuotDividedListQuery& query, const PayloadDTO& payload)
{
	//构建返回对象
	list<PurQuotDividedListVO> result;
	//数据校验
	if(query.getBill_no() == "") return JsonVO<list<PurQuotDividedListVO>>(result, RS_PARAMS_INVALID);

	//数据校验成功,返回对应的对象
	PurQuotService service;
	result = service.listPurQuotDividedListVO(query);
	return JsonVO<list<PurQuotDividedListVO>>(result, RS_SUCCESS);
}

