#pragma once

#ifndef _PAYMENTCONTROLLER_H_
#define _PAYMENTCONTROLLER_H_
#include "../../domain/dto/payment/PaymentChangeDTO.h"
#include "../../domain/dto/payment/DePaymentDTO.h"
#include "../../domain/dto/payment/PaymentImportDTO.h"
#include "../../domain/dto/payment/AddPaymentDTO.h"

#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/payment/PaymentVO.h"

/**
 * ������
 */
class PaymentController
{
public:
	//�޸Ķ���״̬
	CREATE_API_FUN_BODY_PAYLOAD(modifyPayment, execChangePayment, PaymentChangeDTO);
	//ɾ��
	CREATE_API_FUN_BODY(deleteById, execDePayment, DePaymentDTO);
	//����
	CREATE_API_FUN_BODY_PAYLOAD(AddPayment, execAddPayment, AddPaymentDTO);
private:
	//�޸ĵ���״̬���ر�/����/���رգ�
	JsonVO<string> execChangePayment(const PaymentChangeDTO& dto, const PayloadDTO& payload);
	//ɾ������
	JsonVO<string> execDePayment(const DePaymentDTO& dto);
	//��������
	JsonVO<uint64_t> execAddPayment(const AddPaymentDTO& dto, const PayloadDTO& payload);

};
#endif // _PAYMENTCONTROLLER_H_