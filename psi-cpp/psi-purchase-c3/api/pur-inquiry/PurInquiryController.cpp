

#include "stdafx.h"
#include "PurInquiryController.h"
#include "../../service/pur-inquiry/PurInquiryService.h"


//查询采购询价单分页列表
JsonVO<PageVO<PurInquiryFindBillVO>> PurInquiryController::execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload)
{
	//测试Apipost
	PurInquiryFindBillVO test;
	list<PurInquiryFindBillVO> ls; 
	ls.push_back(test);
	PageVO<PurInquiryFindBillVO> result(1, 2, 0, 0, ls);
	//PageVO<PurInquiryFindBillVO> result;

	return JsonVO<PageVO<PurInquiryFindBillVO>>(result, RS_SUCCESS);
}

//查看指定询价单详细信息
JsonVO<PurInquiryFindDetailBillVO> PurInquiryController::execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload)
{
	PurInquiryFindDetailBillVO result;
	//响应结果
	return JsonVO<PurInquiryFindDetailBillVO>(result, RS_SUCCESS);
}

//PurInquiryFindDetailBillVO result(1, 2, 0, 0, ls1);


//JsonVO<uint64_t> PurInquiryController::execAddPurInquiry(const InquiryDTO& dto)
//{
//	JsonVO<uint64_t> result;
//
//	return result;
//}
//
//JsonVO<uint64_t> PurInquiryController::execModifyPurInquiry(const InquiryDTO& dto)
//{
//	JsonVO<uint64_t> result;
//
//
//	return result;
//}
//
//JsonVO<uint64_t> PurInquiryController::execRemovePurInquiry(const PurInquiryRemoveDTO& dto)
//{
//	JsonVO<uint64_t> result;
//
//	return result;
//}
//
//JsonVO<PurInquiryVO> PurInquiryController::execPurInquiryInto(const PurInquiryDTO& dto)
//{
//	JsonVO<PurInquiryVO> result;
//
//	return result;
//}
//
//JsonVO<std::string> PurInquiryController::execPurInquiryExport(const PurInquiryQurey& query)
//{
//
//	JsonVO<std::string> result;
//
//	return result;
//}

