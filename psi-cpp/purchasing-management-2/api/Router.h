#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:36:43

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
private:
#ifdef HTTP_SERVER_DEMO
	//创建演示路由
	void createSampleRouter();
	//创建用户管理-部门管理路由
	void createUserDepartRouter();
#endif
	/**
	* 负责人：Andrew
	* 1. 采购订单-修改单据状态(关闭/反关闭/作废)
	* 2. 采购订单-删除采购订单(通过id)
	* ...
	* 备注：包含采购统计接口
	*/
	void createStatisRouter();
	/**
	* 负责人：最初, 巴比龙
	* 1. 删除采购付款申请单
	* 2. 修改单据状态(关闭/作废/反关闭)
	* 3. 添加采购付款申请单(保存/提交)
	*/
	void createPaymentRouter();
	/**
	* 负责人：Qi, Andrew
	* 1. 查询单据列表
	* 2. 查看指定单据详细信息
	* 3. 添加采购预付申请单(保存/提交)
	* 4. 修改采购预付申请单(保存/提交/审核)
	* 5. 采购预付申请单-修改单据状态(关闭/反关闭/作废)
	*/
	void createPrePayRouter();
	/**
	* 负责人：J4nnA
	* 1. 采购申请单列表
	* 2. 采购申请单分录列表 (c3阿坤)
	* 3. 比价单列表
	* 4. 比价单分录列表
	*/
	void createPurComRouter();
	/**
	* 负责人：青羽, Andrew
	* 1. 查询单据列表
	* 2. 查看指定单据详细信息
	* 3. 添加采购订单（保存/提交）
	* 4. 修改采购订单（保存/提交/审核）
	* 5. 删除采购订单
	* 6. 修改单据状态（关闭/作废/反关闭）
	*/
	void createPurOrderRouter();
};

#endif // !_ROUTER_