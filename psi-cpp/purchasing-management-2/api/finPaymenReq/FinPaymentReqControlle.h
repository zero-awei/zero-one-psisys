#pragma once


#ifndef _FIN_PAYMENT_REQ_CONTROLLE_
#define _FIN_PAYMENT_REQ_CONTROLLE_

#include"api/ApiHelper.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/query/finPaymentReq/finPaymentReqQuery.h"
#include "../../domain/query/finPaymentReq/finPaymentReqEntryQuery.h"
#include "../../domain/vo/finPaymentReq/finPaymentReqVO.h"
#include "../../domain/vo/finPaymentReq/finPaymentDetailVO.h"
#include "../../domain/dto/finPaymentReq/addPaymentReqDTO.h"
#include "../../domain/dto/finPaymentReq/modPyamentReqDTO.h"


/**
 * �ɹ����빦�ܵ�
 */
class FinPaymentReqControlle
{
public:
	//��ѯ�б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryFinPaymentReq, execQueryPayBill, FinPaymentReqQuery);
	//��ѯ��ϸ����
	CREATE_API_FUN_QUERY_PAYLOAD(queryFinPaymentReqEntry, execQueryPayDetailBill, FinPaymentReqEntryQuery);
	//����
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPaymentReq, execAddPayHandle, AddPaymentReqDTO);
	//�޸�
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modPaymentReq, execModPayHandle, ModPyamentReqDTO);

private:
	//��ѯ�б�
	JsonVO<PageVO<FinPaymentReqVO>> execQueryPayBill(const FinPaymentReqQuery& query, const PayloadDTO& payload);
	//��ѯ��ϸ����
	JsonVO<FinPaymentDetailVO> execQueryPayDetailBill(const FinPaymentReqEntryQuery& query, const PayloadDTO& payload);
	//����
	JsonVO<uint64_t> execAddPayHandle(const AddPaymentReqDTO& dto, const PayloadDTO& payload);
	//�޸�
	JsonVO<uint64_t> execModPayHandle(const ModPyamentReqDTO& dto, const PayloadDTO& payload);

};
#endif  //_FIN_PAYMENT_REQ_CONTROLLE_
