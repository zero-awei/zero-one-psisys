#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/2/19 16:41:00

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
#ifndef _PUR_ORDER_DAO_
#define _PUR_ORDER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/PurOrder/PurOrderDO.h"

/**
 * �ɹ����������ݿ����ʵ��
 */
class PurOrderDAO : public BaseDAO
{
public:
	// ��������
	string insert(const PurOrderDO& iObj);
	// ɾ������
	int deleteById(string id);
};
#endif // !_PUR_ORDER_DAO_