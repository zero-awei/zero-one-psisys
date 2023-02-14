#pragma once


#ifndef _PURINQUIRY_CONTROLLER_
#define _PURINQUIRY_CONTROLLER_

#include "../../domain/query/inquiry-eleanor/PurInquiryFindBillQuery.h"
#include "../../domain/query/inquiry-eleanor/PurInquiryFindDetailBillQuery.h"
#include "../../domain/dto/inquiry-eleanor/PurInquiryFindBillDTO.h"
#include "../../domain/dto/inquiry-eleanor/PurInquiryFindDetailBillDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/inquiry-eleanor/PurInquiryFindBillVO.h"
#include "../../domain/vo/inquiry-eleanor/PurInquiryFindDetailBillVO.h"
#include "../../domain/vo/inquiry-eleanor/EntryPurInquiryVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


/**
 * 示例控制器，演示接口的使用
 */
class PurInquiryController
{
public:
	//接口1 查询采购询价单分页列表
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurInquiry, execQueryPurInquiryFindBill, PurInquiryFindBillQuery);
	//接口2 查看指定询价单详细信息
	CREATE_API_FUN_QUERY_PAYLOAD(queryAssignPurInquiry, execQueryPurInquiryFindDetailBill, PurInquiryFindDetailBillQuery);


private:
	//查询采购询价单分页列表
	JsonVO<PageVO<PurInquiryFindBillVO>> execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload);
	//查看指定询价单详细信息
	JsonVO<PurInquiryFindDetailBillVO> execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload);

};

#endif // _PURINQUIRY__CONTROLLER_
