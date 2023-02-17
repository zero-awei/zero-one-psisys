/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:38:49

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

#include "stdafx.h"

#include "../arch-demo/domain/do/DoInclude.h"

#ifndef _PYRK_DO_
#define _PYRK_DO_

// ��ӯ��� �������� �����б�ʵ����
class PyrqBillListDO {
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
};

// ��ӯ��� �������� ������ϸ����ʵ����
class PyrqBillDetailDO {
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// ���ݽ׶�
	CC_SYNTHESIZE(std::string, billStage, BillStage);
	// ��������
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	

	//������
};

#endif // _PYRK_DO_
