#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: Papillon
 @Date: 2023/02/16 22:00:00
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
#ifndef _FIN_PAYMENT_REQ_VO
#define _FIN_PAYMENT_REQ_VO

#include "../../GlobalInclude.h"

/*
��ѯ�����б�
*/
class FinPaymentReqVO {
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId)
	// ҵ����
	CC_SYNTHESIZE(string, opDept, OpDept)
	// ҵ��Ա
	CC_SYNTHESIZE(string, operator1, Operator)
	// Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo)
	// ������
	CC_SYNTHESIZE(double, amt, Amt)
	// �Ѹ����
	CC_SYNTHESIZE(double, paidAmt, PaidAmt)
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//����Ч			
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//�ѹر�			
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������			
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// �Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	// ���ֵ���
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �Ƶ���
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// �Ƶ�����
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// �޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);

public:
	// ��JSONת������
	BIND_TO_JSON(FinPaymentReqVO, billNo, billDate, subject, supplierId, opDept,
		operator1, srcNo, amt, paidAmt, billStage, isEffective, isClosed, isVoided,
		isAuto, isRubric, remark, effectiveTime,
		approver, createTime, createBy, sysOrgCode, updateTime, updateBy);
};

#endif //_FIN_PAYMENT_REQ_VO