#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: awei
 @Date: 2022/10/25 11:34:14
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
#ifndef _QUERY_PYRK_BILL_LIST_VO_
#define _QUERY_PYRK_BILL_LIST_VO_

#include "../../GlobalInclude.h"

/**
 * ��ѯ�����б�
 */
class QueryPyrkBillListVO
{
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//�����������
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	//�޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//����Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//��������
	CC_SYNTHESIZE(string, billType, BillType);
	//������
	CC_SYNTHESIZE(string, approver, Approver);
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//�������
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//���ֵ���
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//�Ƶ���
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//Դ��id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//�汾
	CC_SYNTHESIZE(string, version, Version);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//����ʵ��id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//���������
	CC_SYNTHESIZE(string, stockIoType, StockIoType);
	//������
	CC_SYNTHESIZE(int, hasRp, HasRp);
	//�Ƿ����Ƕ�
	CC_SYNTHESIZE(int, hasSwell, HasSwell);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//�ͻ�
	CC_SYNTHESIZE(string, customerId, CustomerId);
	//��Ʊ����
	CC_SYNTHESIZE(string, invoiceType, InvoiceType);
	//ҵ����
	CC_SYNTHESIZE(string, opDept, OpDept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operator1, Operator1);
	//����⾭��
	CC_SYNTHESIZE(string, handler, Handler);
	//�ɱ�
	CC_SYNTHESIZE(double, cost, Cost);
	//������
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//�ѽ�����
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	//�ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//�Ƿ��˻���Ʊ
	CC_SYNTHESIZE(int, isReturned, IsReturned);





public:
	QueryPyrkBillListVO() {
		remark = "";
		billNo = "PYRK-230101-001";
		approvalResultType = "123";
		approvalResultType = "";
		updateBy = "psi";
		isEffective = 0;
		isVoided = 0;
		billType = "StkIo:101";
		approver = "";
		billDate = "2023-02-11";
		srcBillType = "PurOrder";
		approvalRemark = "";
		srcNo = "CGDD-230211-005";
		updateTime = "2023-02-12 11:35:31";
		isAuto = 0;
		isRubric = 0;
		sysOrgCode = "A01A05";
		createTime = "2023-02-11 14:26:56";
		createBy = "psi";
		srcBillId = "1624292548494532610";
		effectiveTime = "";
		billStage = "14";
		version = "";
		attachment = "";
		subject = u8"����";
		id = "1624293891909132289";
		isClosed = 0;
		bpmiInstanceId = "";
		stockIoType = "101";
		hasRp = 1;
		hasSwell = 0;
		supplierId = "1624286740595646466";
		customerId = "";
		invoiceType = "0";
		opDept = "A01";
		operator1 = "jeecg";
		handler = "jeecg";
		cost = 3;
		settleAmt = 3;
		settledAmt = 0;
		invoicedAmt = 0;
		isReturned = 0;




	}
	// ��JSONת������
	BIND_TO_JSON(QueryPyrkBillListVO, remark, billNo, approvalResultType, updateBy, isEffective, isVoided, billType, approver, billDate, srcBillType, approvalRemark, srcNo, updateTime, isAuto,
		isRubric, sysOrgCode, createTime, createBy, srcBillId, effectiveTime, billStage, version, attachment, subject, id, isClosed, bpmiInstanceId, stockIoType, hasRp, hasSwell, supplierId, customerId,
		invoiceType, opDept, operator1, handler, cost, settleAmt, settledAmt, invoicedAmt, isReturned);
};

#endif // !_QUERY_CGRK_BILL_LIST_VO_