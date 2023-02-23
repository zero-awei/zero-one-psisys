#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _QUERY_PUR_ORDER_ENTRY_VO_
#define _QUERY_PUR_ORDER_ENTRY_VO_


class QueryPurOrderEntryVO
{
	//ID
	CC_SYNTHESIZE(string, id, ID);
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//��¼��
	CC_SYNTHESIZE(int, entryNo, EntryNO);
	//�ۿ���
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	//���������
	CC_SYNTHESIZE(double, inQty, InQty);
	//�����ɱ�
	CC_SYNTHESIZE(double, inCost, InCost);
	//�ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedAmt, InvoiceAmt);
	//�ѿ�Ʊ����
	CC_SYNTHESIZE(double, invoicedQty, InvoicedQty);
	//���ϱ���
	CC_SYNTHESIZE(string, materialCode, MaterialCode);
	//����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//����ͺ�
	CC_SYNTHESIZE(string, materialModel, MaterialModel);
	//����
	CC_SYNTHESIZE(string, mid, Mid);
	//��˰����
	CC_SYNTHESIZE(double, price, Price);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//������
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//��������
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	//Դ��id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//Դ����¼id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryType);
	//Դ����¼��
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//˰��
	CC_SYNTHESIZE(double, tax, Tax);
	// ˰��
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	//������λ
	CC_SYNTHESIZE(string, unitId, UnitId);
	//�汾
	CC_SYNTHESIZE(string, version, Version);


public:
	QueryPurOrderEntryVO()
	{
		id = "7635498";
	}
	BIND_TO_JSON(QueryPurOrderEntryVO, id, billNo, subject, custom1, custom2, entryNo, discountRate, inQty, inCost, invoicedAmt, invoicedQty, materialCode, materialId, materialModel, mid, price, qty, remark,
		settleAmt, settleQty, srcBillId, srcBillType, srcEntryId, srcNo, tax, taxRate, unitId, version);
};

#endif // !_QUERY_PUR_ORDER_ENTRY_VO_