#pragma once

#ifndef _PUR_PAY_REQ_SERVICE_
#define _PUR_PAY_REQ_SERVICE_

#include "SnowFlake.h"
#include "FastDfsClient.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include <time.h>
#include <cstdio> 

#include "../../domain/vo/PageVO.h"
#include "../../domain/dto/PaymentBillImpl/AddPayApplyDTO.h"
#include "../../domain/dto/PaymentBillImpl/ModPayApplyDTO.h"
#include"../../domain/vo/PaymentBillImpl/PaymentBillVO.h"
#include"../../domain/vo/PaymentBillImpl/PaymentBillDetailVO.h"
#include"../../domain/query/PaymentBillImpl/PaymentBillQuery.h"
#include"../../domain/query/PaymentBillImpl/PaymentBillDetailQuery.h"


class PurPayReqService
{
public:
	//插入数据
	uint64_t addData(const AddPayApplyDTO& dto, const PayloadDTO& payload);

	//更新数据
	uint64_t updateData(const ModPayApplyDTO& dto, const PayloadDTO& payload);
	
	// 分页查询所有数据
	PageVO<PaymentBillVO> queryList(const PaymentBillQuery& query);
	//查询指定单据详细信息
	PaymentBillDetailVO detailDate(const PaymentBillDetailQuery& query);
	
};


#endif // _PUR_PAY_REQ_SERVICE_