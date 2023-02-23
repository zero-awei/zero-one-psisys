#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: shiyi
 @Date: 2023/2/15 20:36:07
 
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
#ifndef _ROUTER_
#define _ROUTER_

#include "api/ApiHelper.h"

/**
 * ǰ�˷��ʷ�����·�ɰ󶨣����ڶ���ǰ�˷��ʺ�˽ӿںͷ���·����
 */
class Router
{
private:
	http_server* server;
public:
	//�����ʼ��
	explicit Router(http_server* sever);
	//���г�ʼ��
	void initRouter();

	void createDepotRouter();

	//����·��
	void createMeasurementRouter();
private:

	void createBasMaterialRouter();

	//�������Ϸ���·��
	void createMaterialClassificationRouter();

#ifdef HTTP_SERVER_DEMO
	//����·��
	//void createMeasurementRouter();
	//�����û�����-���Ź���·��
	void createUserDepartRouter();
#endif

	void createCurrencyRouter();

};

#endif // !_ROUTER_