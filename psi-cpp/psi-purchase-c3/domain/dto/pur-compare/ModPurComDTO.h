#ifndef _MOD_PUR_COM_DTO_
#define _MOD_PUR_COM_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
class ModPurComDTO : public FileDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ����Ч
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// �ѹر�
	CC_SYNTHESIZE(int, isClose, Isclose);
	// ������
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectDate, EffectDate);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// ����ʵ��
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, makeBillDate, MakeBillDate);
	// �Ƶ�����
	CC_SYNTHESIZE(string, makeBillDept, MakeBillDept);
	// �Ƶ���
	CC_SYNTHESIZE(string, makeBillPerson, MakeBillPerson);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// �޸���
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);
	// �Զ�����
	CC_SYNTHESIZE(int, autoBill, AutoBill);
	// ���ֵ���
	CC_SYNTHESIZE(int, redBill, RedBill);
	// Դ������
	CC_SYNTHESIZE(string, billType, BillType);
	// ��������
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// �ɹ�ѯ�۵������ݱ�ţ�
	CC_SYNTHESIZE(string, inquiryBill, InquiryBill);
	// ���ʽ
	CC_SYNTHESIZE(string, payMethod, PayMethod);
	// ��������
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);

public:
	// ��JSONת������
	friend void from_json(const json& j, ModPurComDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billId);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_I(j, t, isEffect);
		BIND_FROM_TO_I(j, t, isClose);
		BIND_FROM_TO_I(j, t, isCancelled);
		BIND_FROM_TO_NORMAL(j, t, effectDate);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_NORMAL(j, t, makeBillDate);
		BIND_FROM_TO_NORMAL(j, t, makeBillDept);
		BIND_FROM_TO_NORMAL(j, t, makeBillPerson);
		BIND_FROM_TO_NORMAL(j, t, updateDate);
		BIND_FROM_TO_NORMAL(j, t, updatePerson);
		BIND_FROM_TO_I(j, t, autoBill);
		BIND_FROM_TO_I(j, t, redBill);
		BIND_FROM_TO_NORMAL(j, t, billTheme);
		BIND_FROM_TO_NORMAL(j, t, billStatus);
		BIND_FROM_TO_NORMAL(j, t, inquiryBill);
		BIND_FROM_TO_NORMAL(j, t, payMethod);
		BIND_FROM_TO_NORMAL(j, t, deliveryDate);
		BIND_FROM_TO_NORMAL(j, t, deliveryPlace);
		BIND_FROM_TO_NORMAL(j, t, remark);
	}
};


#endif 
