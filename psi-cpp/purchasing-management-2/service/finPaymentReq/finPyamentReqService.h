#pragma once

#ifndef _FIN_PAYMENT_REQ_SERVICE_
#define _FIN_PAYMENT_REQ_SERVICE_

#include "SnowFlake.h"
#include "FastDfsClient.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include <time.h>
#include <cstdio> 

#include "../../domain/vo/PageVO.h"
#include "../../domain/dto/finPaymentReq/AddPaymentReqDTO.h"
#include "../../domain/dto/finPaymentReq/ModPyamentReqDTO.h"
#include"../../domain/vo/finPaymentReq/finPaymentReqVO.h"
#include"../../domain/vo/finPaymentReq/FinPaymentDetailVO.h"
#include"../../domain/query/finPaymentReq/FinPaymentReqQuery.h"
#include"../../domain/query/finPaymentReq/finPaymentReqEntryQuery.h"


class FinPyamentReqService
{
public:
	//插入数据
	uint64_t saveData(const AddPaymentReqDTO& dto, const PayloadDTO& payload);

	//更新数据
	uint64_t updateData(const ModPyamentReqDTO& dto, const PayloadDTO& payload);

	// 通过主目录billNo删除数据
	bool removeData(string billNo);
	
	// 分页查询所有数据
	PageVO<FinPaymentReqVO> queryList(const FinPaymentReqQuery& query);
	//查询指定单据详细信息
	FinPaymentDetailVO detailDate(const FinPaymentReqEntryQuery& query);
	
};


#endif // _FIN_PAYMENT_REQ_SERVICE_