#include "stdafx.h"
#include "PaymentService.h"
#include "../../dao/payment/PaymentDAO.h"

// ͨ��IDɾ������
bool PaymentService::DePayment(const DePaymentDTO& dto)
{
	//��װ��������
	PaymentDAO dao;
	FinPayReqDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//ִ�������޸�
	if (dto.getId() != "" || dto.getBill_no() != "")
	{
		data.setId(dto.getId());
		return dao.deleteById(data) == 1;
	}
}

string getPayTime()
{
	time_t now = time(0);
	struct tm t;

	localtime_s(&t, &now);

	// ����Ϣ������ַ�����
	stringstream ss;
	ss << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec;
	return ss.str();
}

// �޸ĵ���״̬
bool PaymentService::ChangePayStatus(const PaymentChangeDTO& dto, const PayloadDTO& payload)
{
	FinPayReqDO data;

	string time = getPayTime();

	// �����û�����
	data.setUpdate_by(payload.getUsername());
	data.setCreate_by(payload.getUsername());
	data.setUpdate_time(time);
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());

	PaymentDAO dao;
	if (dto.getOpType() == dto.CLOSE || dto.getOpType() == dto.UNCLOSE)
	{
		data.setIs_closed(dto.OPS[dto.getOpType()]);
		return dao.ChangeStatusClose(data) == 1;
	}
	else if (dto.getOpType() == dto.CANCEL)
	{
		data.setIs_voided(dto.OPS[dto.getOpType()]);
		return dao.ChangeStatusCancel(data) == 1;
	}
}



//����һ������������ֵ���޸�
#define MODIFY(name) data.set##name(dto.get##name());
//����һ������������Ĭ��ֵ���޸�
#define MODIFY_DEFAULT(name) if (dto.get##name() != data.get##name()) {data.set##name(dto.get##name());}
// ��������
uint64_t PaymentService::saveData(const AddPaymentDTO& dto, const PayloadDTO& payload)
{
	//���Ƚ������������ӽ����ݿ�
	//��װ��������
	FinPayReqDO data;
	SnowFlake sf(1, 4);
	string id = to_string(sf.nextId());
	string Bill_no = dto.getBill_no();
	string time = getPayTime();
	//�����ǽ���id����ʹ��ѩ���㷨
	data.setId(id);
	//��ȡ������Ϣ
	data.setBill_no(Bill_no);
	MODIFY(Bill_date);
	MODIFY(Operator);
	MODIFY(Op_dept);
	MODIFY(Supplier_id);
	//��ȡ�û�����Ϣ���˴�Ϊ���Ӷ�������Ϣ
	data.setOp_dept(payload.getDepartment());
	data.setOperator(payload.getUsername());
	data.setCreate_time(time);
	data.setUpdate_by(payload.getUsername());
	data.setCreate_by(payload.getUsername());
	data.setUpdate_time(time);
	//����Ĭ��ֵʱ�Ĵ���
	MODIFY_DEFAULT(Src_bill_type);
	MODIFY_DEFAULT(Src_bill_id);
	MODIFY_DEFAULT(Src_no);
	MODIFY_DEFAULT(Subject);
	MODIFY_DEFAULT(Payment_type);
	MODIFY_DEFAULT(Amt);
	MODIFY_DEFAULT(Remark);
	//ִ�������޸�
	PaymentDAO dao;
	//Ȼ�󽫶�����ϸ���ӽ����ݿ�
	return dao.insertPayment(data);
}