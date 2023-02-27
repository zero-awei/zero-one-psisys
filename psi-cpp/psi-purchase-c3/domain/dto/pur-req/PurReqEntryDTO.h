#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: adam
 @Date: 2023/2/24 10:24

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
#ifndef _PUR_REQ_ENTRY_DTO_
#define _PUR_REQ_ENTRY_DTO_

#include "../../GlobalInclude.h"

//������ϸ�б���Ҫ������
class PurReqEntryDTO
{
	//��¼��
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//Դ��id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//Դ����¼id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
	//Դ����¼��
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//������λ
	CC_SYNTHESIZE(string, unitId, UnitId);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//˰��%
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	//��˰����
	CC_SYNTHESIZE(double, price, Price);
	//��˰���
	CC_SYNTHESIZE(double, amt, Amt);
	//���鹩Ӧ��
	CC_SYNTHESIZE(string, suggestSupplierId, SuggestSupplierId);
	//�Ѷ�������
	CC_SYNTHESIZE(double, orderedQty, OrderedQty);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//�汾
	CC_SYNTHESIZE(int, version, Version);
public:
	//��JSONת������
	friend void from_json(const json& j, PurReqEntryDTO& t);
};

#endif // !_PUR_REQ_ENTRY_DTO_