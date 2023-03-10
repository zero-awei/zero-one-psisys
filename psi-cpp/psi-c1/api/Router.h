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
	//公共接口的供应商资金账户
	void createBasBankAccount();
	//物料分类树状结构列表
	void createMaterialTypeTreeList();
	//仓库树状结构列表
	void createBasWareHouseTreeList();
	//银行账户
	void createBankAccount();
	//创建单据编号
	void createCreateReceipt();
	void initAreaSetting();
	void initUserChoiceSetting();
	void initMaterialQuerySetting();
	void initDepartChioceSetting();
	void initSupplierSetting();
	void initBankAccount();
	void initSuppliersSetting();
	void initInvoiceMethodSetting();
	void initInvoiceTypeSetting();
	void initSettleMethodSetting();
	void initTransportMethodSetting();
	//单据阶段下拉列表
	void initBillStage();
	//采购类型下拉列表
	void initPurType();
	//税率下拉列表
	void initTaxRate();
	//纳税规模下拉列表
	void initTaxScale();
	void initCurrencyType();
	void initDeliveryType();
	void initWarehouse();
	void initbaSetting();
	//下面开始是自己写的
	void initSupplier();
};

#endif // !_ROUTER_