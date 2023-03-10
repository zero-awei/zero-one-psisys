#pragma once
#ifndef _PREPAY_BILL_QUERY_
#define _PREPAY_BILL_QUERY_

#include "../PageQuery.h"

/**
 * �ɹ�Ԥ������-��ѯԤ�����뵥���б�-��ѯʱ��������Ķ���
 */
class PrepayBillQuery : public PageQuery
{

	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ���ݿ�ʼ����
	CC_SYNTHESIZE(string, bill_begin_date, Bill_begin_date);
	// ���ݽ�������
	CC_SYNTHESIZE(string, bill_end_date, Bill_end_date);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// ����Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// �ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// ������
	CC_SYNTHESIZE(int, is_voided, Is_voided);

public:
	// ��from_json
	friend void from_json(const json& j, PrepayBillQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, bill_begin_date);
		BIND_FROM_TO_NORMAL(j, t, bill_end_date);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, supplier_id);
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		BIND_FROM_TO_I(j, t, is_effective);
		BIND_FROM_TO_I(j, t, is_closed);
		BIND_FROM_TO_I(j, t, is_voided);
	}
	PrepayBillQuery() {
		is_effective = -1;
		is_closed = -1;
		is_voided = -1;
	}
};

#endif // !_SAMPLE_QUERY_