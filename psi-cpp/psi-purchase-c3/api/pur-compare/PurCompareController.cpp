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

JsonVO<PurComFindDetailBillVO> PurCompareController::execQueryPurComFindDetailBill(const string& query, const PayloadDTO& payload)
{
	////定义一个Service
	//SampleService service;
	////查询数据
	//PageVO<SampleVO> result = service.listAll(query);
	////响应结果
	PurComFindDetailBillVO result;
	return JsonVO<PurComFindDetailBillVO>(result, RS_SUCCESS);
}

JsonVO<PageVO<PurComListVO>> PurCompareController::execQueryPurComList(const string& query, const PayloadDTO& payload)
{
	////定义一个Service
	//SampleService service;
	////查询数据
	//PageVO<SampleVO> result = service.listAll(query);
	////响应结果
	PageVO<PurComListVO> result;
	return JsonVO<PageVO<PurComListVO>>(result, RS_SUCCESS);
}

JsonVO<PageVO<PurComDividedListVO>> PurCompareController::execQueryPurComDividedList(const string& query, const PayloadDTO& payload)
{
	////定义一个Service
	//SampleService service;
	////查询数据
	//PageVO<SampleVO> result = service.listAll(query);
	////响应结果
	PageVO<PurComDividedListVO> result;
	return JsonVO<PageVO<PurComDividedListVO>>(result, RS_SUCCESS);
}


