#pragma once

#ifndef _FIN_PAYMENT_REQ_ENTRY_DO_
#define _FIN_PAYMENT_REQ_ENTRY_DO_
#include "../DoInclude.h"

/*
 *��ѯ��������
 */
class FinPaymentReqEntryDO {
	//id
	CC_SYNTHESIZE(string, id, Id);
	//���ݺ�
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��¼��
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// Դ��id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//Դ����¼id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
	//Դ����¼��
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//������
	CC_SYNTHESIZE(double, amt, Amt);
	//�Ѹ����
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	FinPaymentReqEntryDO() {
		id = "";
		billNo = "";
		entryNo = 0;
		srcBillType = "";
		srcBillId = "";
		srcEntryId = "";
		srcNo = "";
		amt = -1;
		paidAmt = -1;
		remark = "";
		custom1 = "";
		custom2 = "";
	}
};


#endif // !_FIN_PAYMENT_ENTRY_REQ_DO_