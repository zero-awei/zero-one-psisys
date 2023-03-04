#pragma once
#ifndef _PUR_REQ_MOD_BILL_STATUS_DTO_
#define _PUR_REQ_MOD_BILL_STATUS_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
#include <map>

//�޸Ķ���״̬��DTO ǰ����Ҫ����һ�����ݱ���Լ�״̬�޸���Ϣ
class PayModBillStatusDTO {
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ��������(�ر�/���ر�/����)
	CC_SYNTHESIZE(int, opType, OpType);
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// �Ƿ�ر�
	//CC_SYNTHESIZE(bool, is_closed, Is_closed);
	// �Ƿ�����
	//CC_SYNTHESIZE(bool, is_voided, Is_voided);
public:
	enum OPTYPE { CLOSE = 0, UNCLOSE = 1, CANCEL = 2 }; // ��������ö����
	int OPS[3] = {1, 0, 1}; // �������Ͷ�Ӧ������
	//��JSONת������
	friend void from_json(const json& j, PayModBillStatusDTO& t);
};
#endif // !_PUR_REQ_MOD_BILL_STATUS_DTO_