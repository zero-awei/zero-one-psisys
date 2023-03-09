/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:38:25

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

/**
 *Author c1-ruizi
 * 2023/2/12  17:46
 * 接口：开票方式
 */

#include "stdafx.h"
#include "Router.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"

#include "supplier/SuppliersNomalQueryController.h"
#include "supplier/SupplierController.h"
#include "supplier/SupplierLevelController.h"
#include "supplier/SupplierQueryCriteriaController.h"
#include "supplier/ImportSupplierController.h"
#include "supplier/ExportSupplierController.h"
#include "supplier/SuppliersNameController.h"
#include "supplier/SupplierCategoryController.h"

#include "public-interface/MaterialTypeController.h"
#include "public-interface/DeliveryMethodController.h"
#include "public-interface/PayMethodController.h"
#include "public-interface/InvoiceTypeController.h"
#include "public-interface/InvoiceMethodController.h"
#include "public-interface/SettleMethodController.h"
#include "public-interface/TransportMethodController.h"
#include "public-interface/BillStageController.h"
#include "public-interface/PurTypeController.h"
#include "public-interface/TaxRateController.h"
#include "public-interface/TaxScaleController.h"
#include "public-interface/CurrencyTypeController.h"
#include "public-interface/DeliveryTypeController.h"
#include "public-interface/WarehouseController.h"
#include "public-interface/CurrencyTypeController.h"
#include "public-interface/DeliveryTypeController.h"
#include "public-interface/WarehouseController.h"
#include "public-interface/areaController.h"
#include "public-interface/UserChoiceController.h"
#include "public-interface/MaterialQueryController.h"
#include "public-interface/DepartChoiceController.h"
#include "public-interface/MaterialTypeTreeListController.h"
#include "public-interface/BasWareHouseTreeListController.h"
#include "public-interface/CreateReceiptController.h"

#include "bank-account/AddAccountController.h"
#include "bank-account/EditAccountController.h"
#include "bank-account/DeleteAccountController.h"
#include "bank-account/ImportAccountController.h"
#include "bank-account/ExportAccountController.h"
#include "bank-account/BankAccountController.h"
#include "bank-account/BasBankAccountController.h"

Router::Router(http_server* sever)
{
	this->server = sever;
}

void Router::initRouter()
{
	//设置静态文件目录
	server->set_public_root_directory("public");
	server->set_static_dir("static/file");
	
	initAreaSetting();
	initUserChoiceSetting();
	initMaterialQuerySetting();
	initSupplierSetting();
	initDepartChioceSetting();

	//公共接口的供应商资金账户
	createBasBankAccount();

	//物料分类树状结构列表
	createMaterialTypeTreeList();

	//仓库树状结构列表
	createBasWareHouseTreeList();
	createBankAccount();
	createCreateReceipt();
	initInvoiceMethodSetting();
	initInvoiceTypeSetting();
	initSettleMethodSetting();
	initTransportMethodSetting();
	//单据阶段下拉列表
	initBillStage();
	//采购类型下拉列表
	initPurType();
	//税率下拉列表
	initTaxRate();
	//纳税规模下拉列表
	initTaxScale();
	//银行账户
	initbaSetting();
	initSuppliersSetting();
	//#TIP :系统扩展路由定义，写在这个后面
	initBankAccount();
	initCurrencyType();
	initDeliveryType();
	initWarehouse();
	initSupplier();
}

void Router::initAreaSetting()
{
	BIND_GET_ROUTER(server, "/get-area", &AreaController::queryArea, nullptr);
}

void Router::initUserChoiceSetting()
{
	BIND_GET_ROUTER(server, "/get-user", &UserChoiceController::queryUser, nullptr);
}

void Router::initMaterialQuerySetting()
{
	BIND_GET_ROUTER(server, "/get-material", &MaterialQueryController::queryMaterial, nullptr);
}

void Router::initDepartChioceSetting()
{
	BIND_GET_ROUTER(server, "/get-depart", &DepartChoiceController::queryDepart, nullptr);
}

void Router::initSupplierSetting()
{
	BIND_GET_ROUTER(server, "/get-supplier", &SupplierCategoryController::querySupplierCategory, nullptr);
}

void Router::createBasBankAccount()
{
	BIND_GET_ROUTER(server, "/query-bas-bank-account", &BasBankAccountController::queryBasBankAccount, nullptr);
}
void Router::createMaterialTypeTreeList()
{                                            
	BIND_GET_ROUTER(server, "/query-material-type-tree-list", &MaterialTypeTreeListController::queryMaterialTypeTreeList, nullptr);
}
void Router::createBasWareHouseTreeList()
{
	BIND_GET_ROUTER(server, "/query-bas-ware-house-tree-list", &BasWareHouseTreeListController::queryBasWareHouseTreeList, nullptr);
}

void Router::createBankAccount() {
	BIND_GET_ROUTER(server, "/query-specified-bank-account", &BankAccountController::querySpecifiedBankAccount, nullptr);
}

void Router::createCreateReceipt() {
	BIND_PUT_ROUTER(server, "/create-receipt", &CreateReceiptController::createReceipt, nullptr);
}

void Router::initBankAccount()
{
	BIND_POST_ROUTER(server, "/post-account", &AddAccountController::addBankAccount, nullptr);
	BIND_PUT_ROUTER(server, "/put-account", &EditAccountController::modifyBankAccount, nullptr);
	BIND_DEL_ROUTER(server, "/delete-account", &DeleteAccountController::removeBankAccount, nullptr);
	BIND_POST_ROUTER(server, "/import-account", &ImportAccountController::modifyAccountInfo, nullptr);
	BIND_POST_ROUTER(server, "/export-account", &ExportAccountController::exportAccountExecl, nullptr);
}

void Router::initSuppliersSetting()
{
	BIND_GET_ROUTER(server, "/query-suppliers-name", &SuppliersNameController::querySuppliersName, nullptr);
	BIND_GET_ROUTER(server, "/query-material-type", &MaterialTypeController::queryMaterialType, nullptr);
	BIND_GET_ROUTER(server, "/query-paymethod-type", &PayMethodController::queryPayMethod, nullptr);
	BIND_GET_ROUTER(server, "/query-deliverymothod-type", &DeliveryMethodController::queryDeliveryMethod, nullptr);
	BIND_GET_ROUTER(server, "/query-suppliernomal-type", &SuppliersNomalQueryController::querySuppliersNomal, nullptr);
}


void Router::initInvoiceMethodSetting()
{
	BIND_GET_ROUTER(server, "/query-invoice-method", &InvoiceMethodController::queryInvoiceMethod, nullptr);
}
void Router::initInvoiceTypeSetting()
{
	BIND_GET_ROUTER(server, "/query-invoice-type", &InvoiceTypeController::queryInvoiceType, nullptr);
}
void Router::initSettleMethodSetting()
{
	BIND_GET_ROUTER(server, "/query-settle-method", &SettleMethodController::querySettleMethod, nullptr);
}
void Router::initTransportMethodSetting()
{
	BIND_GET_ROUTER(server, "/query-transport-method", &TransportMethodController::queryTransportMethod, nullptr);
}

//单据阶段
void Router::initBillStage()
{
	BIND_GET_ROUTER(server, "/query-bill-stage", &BillStageController::queryBillStage, nullptr);
}
//采购类型
void Router::initPurType()
{
	BIND_GET_ROUTER(server, "/query-purchase-type", &PurTypeController::queryPurType, nullptr);
}
//税率
void Router::initTaxRate()
{
	BIND_GET_ROUTER(server, "/query-tax-rate", &TaxRateController::queryTaxRate, nullptr);
}
//纳税规模
void Router::initTaxScale()
{
	BIND_GET_ROUTER(server, "/query-tax-scale", &TaxScaleController::queryTaxScale, nullptr);
}
void Router::initCurrencyType()
{
	//获取货币类型
	BIND_GET_ROUTER(server, "/query-Currency-Type", &CurrencyTypeController::queryCurrencyType, nullptr);
}

void Router::initDeliveryType()
{
	//获取交货方式
	BIND_GET_ROUTER(server, "/query-Delivery-Type", &DeliveryTypeController::queryDeliveryType, nullptr);
}

void Router::initWarehouse()
{
	//获取仓库
	BIND_GET_ROUTER(server, "/query-Warehouse", &WarehouseController::queryWarehouse, nullptr);
}

void Router::initbaSetting()
{
	BIND_GET_ROUTER(server, "/query-bankaccount-list", &BankAccountController::queryBankAccountList, nullptr);
}

void Router::initSupplier()
{
	//高级查询
	BIND_POST_ROUTER(server, "/advanced-query", &SupplierController::advancedquerySupplier, nullptr);
	//指定查询
	BIND_GET_ROUTER(server, "/Specified-Supplier-Data-Query", &SupplierController::specifiedquerySupplier, nullptr);
	//增加
	BIND_POST_ROUTER(server, "/add-supplier", &SupplierController::addSupplier, nullptr);
	//删除
	BIND_DEL_ROUTER(server, "/delete-supplier", &SupplierController::deleteSupplier, nullptr);
	//修改
	BIND_PUT_ROUTER(server, "/modify-supplier", &SupplierController::modifySupplier, nullptr);
	//供应商导入导出
	BIND_POST_ROUTER(server, "/import-supplier", &ImportSupplierController::importSupplier, nullptr);
	BIND_POST_ROUTER(server, "/export-supplier", &ExportSupplierController::exportSupplier, nullptr);
	//供应商等级下拉列表
	BIND_GET_ROUTER(server, "/qurey-supplier-level", &SupplierLevelController::querySupplierLevel, nullptr);
	//供应商高级查询条件下拉列表
	BIND_GET_ROUTER(server, "/qurey-supplier-advanced_criteria", &SupplierQueryCriteriaController::querySupplierQueryCriteria, nullptr);

}

