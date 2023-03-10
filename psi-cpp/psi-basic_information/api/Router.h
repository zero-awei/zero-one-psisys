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
 * 前端访问服务器路由绑定，用于定义前端访问后端接口和访问路径绑定
 */
class Router
{
private:
	http_server* server;
public:
	//构造初始化
	explicit Router(http_server* sever);
	//呼叫初始化
	void initRouter();

	void createDepotRouter();

	//创建路由
	void createMeasurementRouter();
private:

	void createBasMaterialRouter();

	//创建物料分类路由
	void createMaterialClassificationRouter();

#ifdef HTTP_SERVER_DEMO
	//创建路由
	//void createMeasurementRouter();
	//创建用户管理-部门管理路由
	void createUserDepartRouter();
#endif

	void createCurrencyRouter();

};

#endif // !_ROUTER_
