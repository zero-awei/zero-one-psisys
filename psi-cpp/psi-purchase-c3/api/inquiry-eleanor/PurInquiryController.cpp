#include "stdafx.h"
#include "PurInquiryController.h"
#include "../../service/inquiry-eleanor/PurInquiryService.h"


//查询采购询价单分页列表
JsonVO<PageVO<PurInquiryFindBillVO>> PurInquiryController::execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload)
{
	return JsonVO<PageVO<PurInquiryFindBillVO>>();
}

//查看指定询价单详细信息
JsonVO<PurInquiryFindDetailBillVO> execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload)
{
	return JsonVO<PurInquiryFindDetailBillVO>();
}


