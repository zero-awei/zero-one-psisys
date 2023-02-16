
#include "stdafx.h"
#include "PurCompareController.h"
//#include "../../service/sample/SampleService.h"
JsonVO<PageVO<PurComFindBillVO>> PurCompareController::execQueryPurComFindBill(const PurComFindBillQuery& query, const PayloadDTO& payload)
{
	////定义一个Service
	//SampleService service;
	////查询数据
	//PageVO<SampleVO> result = service.listAll(query);
	////响应结果
	//以下三行用于测试Apipost
	PurComFindBillVO test1;
	list<PurComFindBillVO> ls; ls.push_back(test1);
	PageVO<PurComFindBillVO> result(1,2,0,0,ls);
	//PageVO<PurComFindBillVO> result;
	return JsonVO<PageVO<PurComFindBillVO>>(result, RS_SUCCESS);
}

JsonVO<PurComFindDetailBillVO> PurCompareController::execQueryPurComFindDetailBill(const PurComFindDetailBillQuery& query, const PayloadDTO& payload)
{
	////定义一个Service
	//SampleService service;
	////查询数据
	//PageVO<SampleVO> result = service.listAll(query);
	////响应结果

	PurComFindDetailBillVO result;
	return JsonVO<PurComFindDetailBillVO>(result, RS_SUCCESS);
}

JsonVO<PageVO<PurComListVO>> PurCompareController::execQueryPurComList(const PurComListQuery& query, const PayloadDTO& payload)
{
	////定义一个Service
	//SampleService service;
	////查询数据
	//PageVO<SampleVO> result = service.listAll(query);
	////响应结果
	PageVO<PurComListVO> result;
	return JsonVO<PageVO<PurComListVO>>(result, RS_SUCCESS);
}

JsonVO<PageVO<PurComDividedListVO>> PurCompareController::execQueryPurComDividedList(const PurComDividedListQuery& query, const PayloadDTO& payload)
{
	////定义一个Service
	//SampleService service;
	////查询数据
	//PageVO<SampleVO> result = service.listAll(query);
	////响应结果
	PageVO<PurComDividedListVO> result;
	return JsonVO<PageVO<PurComDividedListVO>>(result, RS_SUCCESS);
}

//演示新增比价
JsonVO<uint64_t> PurCompareController::execAddPurCom(const AddPurComDTO& dto)
{
	JsonVO<uint64_t> result;
	// 接口测试
	/*result.success(1);*/
	return result;
}
//演示修改比价
JsonVO<uint64_t> PurCompareController::execModifyPurCom(const ModPurComDTO& dto) {
	JsonVO<uint64_t> result;
	return result;
}
//演示删除比价
JsonVO<uint64_t> PurCompareController::execRemovePurCom(const DelPurComDTO& dto) {
	JsonVO<uint64_t> result;
	return result;
}
//演示修改单据状态
JsonVO<uint64_t> PurCompareController::execPurComModBillStatus(const PurComModBillStatusDTO& dto) {
	JsonVO<uint64_t> result;
	return result;
}


//导出
nlohmann::json PurCompareController::execPurComExport(const PurComExportQuery& dto, const PayloadDTO& payload)
{
	//响应结果
	return nlohmann::json(JsonVO<std::string>());
}

//导入
JsonVO<uint64_t> PurCompareController::execPurComInto(const PurComIntoDTO& dto)
{
	//响应结果
	return JsonVO<uint64_t>();
}