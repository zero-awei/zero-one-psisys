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
#include "../../domain/dto/finPaymentReq/addPaymentReqDTO.h"
#include "../../domain/dto/finPaymentReq/modPyamentReqDTO.h"
#include"../../domain/vo/finPaymentReq/finPaymentReqVO.h"
#include"../../domain/vo/finPaymentReq/finPaymentDetailVO.h"
#include"../../domain/query/finPaymentReq/finPaymentReqQuery.h"
#include"../../domain/query/finPaymentReq/finPaymentReqEntryQuery.h"


class FinPyamentReqService
{
public:
	//��������
	uint64_t saveData(const AddPaymentReqDTO& dto, const PayloadDTO& payload);

	//��������
	uint64_t updateData(const ModPyamentReqDTO& dto, const PayloadDTO& payload);

	// ͨ����Ŀ¼billNoɾ������
	bool removeData(string billNo);
	
	// ��ҳ��ѯ��������
	PageVO<FinPaymentReqVO> queryList(const FinPaymentReqQuery& query);
	//��ѯָ��������ϸ��Ϣ
	FinPaymentDetailVO detailDate(const FinPaymentReqEntryQuery& query);
	
};


#endif // _FIN_PAYMENT_REQ_SERVICE_