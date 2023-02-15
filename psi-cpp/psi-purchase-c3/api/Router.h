#pragma once

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

private:
	

#ifdef HTTP_SERVER_DEMO
	//创建演示路由
	void createSampleRouter();
	//创建用户管理-部门管理路由
	void createUserDepartRouter();

#endif
	void createPurReqRouter();
	void createPurCompareRouter();
	void createPurInquiryRouter();
	void purReqRouter();

};


