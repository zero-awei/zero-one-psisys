#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/22 22:02:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef _FIN_PAYMENT_REQ_DO_
#define _FIN_PAYMENT_REQ_DO_
#include "../DoInclude.h"
#include "FinPaymentReqEntryDO.h"

/*
 *��ѯ����
 */
class FinPaymentReqDO
{
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//Դ��id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//Դ����
	CC_SYNTHESIZE(string, src_no, Src_no);
	//����
	CC_SYNTHESIZE(string, subject, Subject);
	//�Ƿ����
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//��������
	CC_SYNTHESIZE(string, payment_type, Payment_type);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//ҵ����
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operator1,Operator);
	//������
	CC_SYNTHESIZE(double, amt, Amt);
	//�Ѹ����
	CC_SYNTHESIZE(double, paid_amt, Paid_amt);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//�����
	CC_SYNTHESIZE(string, approver, Approver);
	//����ʵ��id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//�����������
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	//�������
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	//�Ƿ���Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//��Чʱ��
	CC_SYNTHESIZE(string,effective_time, Effective_time);
	//�ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//�Ƿ�����
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//��������
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//������
	CC_SYNTHESIZE(string, create_by, Create_by);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�޸���
	CC_SYNTHESIZE(string, update_by, Update_by);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	//�汾
	CC_SYNTHESIZE(int, version, Version);
	//��ϸ
	CC_SYNTHESIZE(list<FinPaymentReqEntryDO>, detail, Detail);
public:
	FinPaymentReqDO()
	{
		id = "";
		bill_no = "";
		bill_date = "";
		src_bill_type = "";
		src_bill_id = "";
		src_no = "";
		subject = "";
		is_rubric = -1;
		payment_type = "";
		supplier_id = "";
		op_dept = "";
		operator1 = "";
		amt = -1;
		paid_amt = -1;
		attachment = "";
		remark = "";
		is_auto = -1;
		bill_stage = "";
		approver = "";
		bpmi_instance_id = "";
		approval_result_type = "";
		approval_remark = "";
		is_effective = -1;
		effective_time = -1;
		is_closed = -1;
		is_voided = -1;
		sys_org_code = "";
		create_by = "";
		create_time = "";
		update_by = "";
		update_time = "";
	}

};

#endif // !_FIN_PAYMENT_REQ_DO_