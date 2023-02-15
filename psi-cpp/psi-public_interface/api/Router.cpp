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
#include "api/setting-qiuqiu/MaterialTypeController.h"
#include "api/setting-qiuqiu/SuppliersNameController.h"
#include "api/setting-qiuqiu/DeliveryMethodController.h"
#include "api/setting-qiuqiu/PayMethodController.h"
#include "api/setting-qiuqiu/SuppliersNomalQueryController.h"


#include "api/InvoiceTypeController.h"
#include "api/InvoiceMethodController.h"
#include "api/SettleMethodController.h"
#include "api/TransportMethodController.h"

#include "api/BillStageController.h"
#include "api/PurTypeController.h"
#include "api/TaxRateController.h"
#include "api/TaxScaleController.h"
#include "CurrencyTypeController.h"
#include "DeliveryTypeController.h"
#include "WarehouseController.h"

#ifdef HTTP_SERVER_DEMO
#include "sample/SampleController.h"
#include "user/DepartController.h"
#include "uselib/ws/TestWs.h"
#endif
#include "api/ApiHelper.h"
#include "BankAccount/AddAccountController.h"
#include "BankAccount/EditAccountController.h"
#include "BankAccount/DeleteAccountController.h"
#include "BankAccount/ImportAccountController.h"

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

#ifdef HTTP_SERVER_DEMO
	//绑定首页页面
	BIND_GET_ROUTER(server, "/", [](request& req, response& res) {
		res.render_raw_view("./public/test.html");
		}, nullptr);

	//初始化一个文件上传接口示例
	BIND_POST_ROUTER(server, "/upload-file", [](request& req, response& res) {
		if (req.get_content_type() != content_type::multipart)
		{
			JsonVO vo = JsonVO("", RS_CONTENT_TYPE_ERR);
			nlohmann::json jvo = nlohmann::json(vo);
			jvo.erase("data");
			res.render_json(jvo);
			return;
		}
		//获取表单参数
		std::cout << "nickname:" << req.get_multipart_value_by_key1("nickname") << std::endl;
		std::cout << "age:" << req.get_multipart_value_by_key1("age") << std::endl;
		//获取文件路径
		auto& files = req.get_upload_files();
		std::vector<string> filePaths;
		for (auto& file : files) {
			filePaths.push_back(file.get_file_path().substr(1));
			std::cout << "path " << file.get_file_path() << ",size " << file.get_file_size() << std::endl;
		}
		res.render_json(nlohmann::json(JsonVO<std::vector<std::string>>(filePaths, RS_SUCCESS)));
		}, nullptr);

	createSampleRouter();
	createUserDepartRouter();
	TestWs::addChatHandler(server);




#endif
	initSuppliersSetting();
	//#TIP :系统扩展路由定义，写在这个后面
	initBankAccount();
	initCurrencyType();
	initDeliveryType();
	initWarehouse();
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	BIND_GET_ROUTER(server, "/get", &SampleController::querySample, nullptr);
	BIND_POST_ROUTER(server, "/post", &SampleController::addSample, nullptr);
	BIND_PUT_ROUTER(server, "/put", &SampleController::modifySample, nullptr);
	BIND_DEL_ROUTER(server, "/delete", &SampleController::removeSample, nullptr);
	BIND_DEL_ROUTER(server, "/delete-by-id", &SampleController::removeById, nullptr);
	BIND_POST_ROUTER(server, "/json", &SampleController::jsonSample, nullptr);
	BIND_POST_ROUTER(server, "/modify-user-info", &SampleController::modifyUserInfo, nullptr);
}

void Router::createUserDepartRouter()
{
	BIND_POST_ROUTER(server, "/depart-add", &DepartController::addDepart, nullptr);
	BIND_POST_ROUTER(server, "/depart-add-more", &DepartController::addDepartMore, nullptr);
}

#endif
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
	BIND_GET_ROUTER(server, "/query-Currency-Type", &CurrencyTypeController::queryCurrencyType, nullptr);
}

void Router::initDeliveryType()
{
	BIND_GET_ROUTER(server, "/query-Delivery-Type", &DeliveryTypeController::queryDeliveryType, nullptr);
}

void Router::initWarehouse()
{
	BIND_GET_ROUTER(server, "/query-Warehouse", &WarehouseController::queryWarehouse, nullptr);
}

