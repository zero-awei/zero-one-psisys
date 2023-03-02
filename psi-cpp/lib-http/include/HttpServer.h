#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 13:55:27
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
#ifndef _HTTP_SERVER_
#define _HTTP_SERVER_

#include "api/ApiHelper.h"
/**
 * 服务器控制类
 * 注意：
 *  1 使用的时候需要在外部实现api/Aspect.h中定义的类和类成员方法
 *  2 在api/ApiHelper.h里面提供了一系列数据转换处理宏
 *  3 HttpLibMacros里面定义的宏需要在对应项目属性中添加预定义
 */
class HttpServer
{
public:
	//************************************
	// Method:    startServer
	// FullName:  HttpServer::startServer
	// Access:    public static 
	// Returns:   int
	// Qualifier: 启动HTTP服务器
	// Parameter: string port 绑定端口
	// Parameter: function<void(http_server*)> bindRouterFun 初始化路由回调
	// Parameter: string host 绑定地址，默认值0.0.0.0
	//************************************
	static int startServer(string port, function<void(http_server*)> bindRouterFun, string host = "0.0.0.0");
};

#endif // _HTTP_SERVER_

