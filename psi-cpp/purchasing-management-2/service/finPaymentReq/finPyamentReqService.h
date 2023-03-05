#pragma once

#ifndef _FIN_PAYMENT_REQ_SERVICE_
#define _FIN_PAYMENT_REQ_SERVICE_

#include <time.h>
#include <cstdio> 

#include "../../domain/dto/finPaymentReq/addPaymentReqDTO.h"
#include "../../domain/dto/finPaymentReq/modPyamentReqDTO.h"
#include"../../domain/vo/finPaymentReq/finPaymentReqVO.h"
#include"../../domain/vo/finPaymentReq/finPaymentDetailVO.h"
#include"../../domain/query/finPaymentReq/finPaymentReqQuery.h"
#include"../../domain/query/finPaymentReq/finPaymentReqEntryQuery.h"

// ×îºó±àÒë
#include "../../domain/vo/PageVO.h"
#include "SnowFlake.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"


class FinPyamentReqService
{
public:
	//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	uint64_t saveData(const AddPaymentReqDTO& dto, const PayloadDTO& payload);

	//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	uint64_t updateData(const ModPyamentReqDTO& dto, const PayloadDTO& payload);

	// Í¨ï¿½ï¿½ï¿½ï¿½Ä¿Â¼billNoÉ¾ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	bool removeData(string billNo);
	
	// ï¿½ï¿½Ò³ï¿½ï¿½Ñ¯ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	PageVO<FinPaymentReqVO> queryList(const FinPaymentReqQuery& query);
	//ï¿½ï¿½Ñ¯Ö¸ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ï¸ï¿½ï¿½Ï¢
	FinPaymentDetailVO detailDate(const FinPaymentReqEntryQuery& query);
	
};


#endif // _FIN_PAYMENT_REQ_SERVICE_