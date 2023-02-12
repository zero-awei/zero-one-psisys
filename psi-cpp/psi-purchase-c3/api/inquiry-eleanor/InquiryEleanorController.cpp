#include "stdafx.h"
#include "InquiryEleanorController.h"
#include "../../service/inquiry-eleanor/InquiryEleanorService.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

//查询采购询价单分页列表
json InquiryEleanorController::execQueryInquiryEleanor(const InquiryEleanorQuery& query, const PayloadDTO& payload)
{
	return JsonVO<PageVO<InquiryEleanorVO>>();
}

//查看指定询价单详细信息
json execQueryAssignInquiryEleanor(const AssignInquiryEleanorQuery& query, const PayloadDTO& payload)
{
	return JsonVO<PageVO<AssignInquiryEleanorVO>>();
}

//演示JSON提交
json InquiryEleanorController::execJsonInquiryEleanor(const InquiryEleanorDTO& dto)
{
	return JsonVO<InquiryEleanorVO>();
}


