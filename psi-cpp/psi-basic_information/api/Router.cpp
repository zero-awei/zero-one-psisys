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
#include "stdafx.h"
#include "Router.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"
#include "depot/DepotController.h"
#include "Measurement/MeasurementController.h"

#ifdef HTTP_SERVER_DEMO
#include "sample/SampleController.h"
#include "user/DepartController.h"
#include "uselib/ws/TestWs.h"
#endif
#include "currency/CurrencyController.h"

#include"BasMaterial/BasMaterialController.h"
#include "MaterialClassification/MaterialClassificationController.h"

Router::Router(http_server* sever)
{
	this->server = sever;
}

void Router::initRouter()
{
	//设置静态文件目录
	server->set_public_root_directory("public");
	server->set_static_dir("static/file");
	//#TIP :系统扩展路由定义，写在这个后面
	createDepotRouter();


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

	//#TIP :系统扩展路由定义，写在这个后面

	createCurrencyRouter();

	createBasMaterialRouter();

	createMaterialClassificationRouter();

	createMeasurementRouter();


}

#ifdef HTTP_SERVER_DEMO
void Router::createMeasurementRouter()
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


void Router::createDepotRouter()
{
	BIND_GET_ROUTER(server, "/query-depot", &DepotController::queryDepot, nullptr);
	BIND_GET_ROUTER(server, "/query-depot-kid", &DepotController::queryKidDepot, nullptr);
	BIND_GET_ROUTER(server, "/query-depot-detail", &DepotController::queryDetailDepot, nullptr);
	BIND_GET_ROUTER(server, "/query-depot-action-info", &DepotController::queryActionInfolDepot, nullptr);
	BIND_POST_ROUTER(server, "/add-depot", &DepotController::addDepot, nullptr);
	BIND_POST_ROUTER(server, "/add-depot-kid", &DepotController::addKidDepot, nullptr);
	BIND_PUT_ROUTER(server, "/modify-depot", &DepotController::modifyDepot, nullptr);
	BIND_DEL_ROUTER(server, "/remove-depot", &DepotController::removeDepot, nullptr);
	BIND_POST_ROUTER(server, "/add-depots", &DepotController::addDepots, nullptr);
	BIND_GET_ROUTER(server, "/export-depots", &DepotController::exportExecl, nullptr);
	BIND_GET_ROUTER(server, "/export-depot-by-only", &DepotController::exportExeclOnly, nullptr);
}

void Router::createBasMaterialRouter() {
	BIND_GET_ROUTER(server, "/get-basmaterial", &BasMaterialController::queryBasMaterial, nullptr);
	BIND_GET_ROUTER(server, "/get-basmaterial-detail", &BasMaterialController::queryDetailBasMaterial, nullptr);
	BIND_POST_ROUTER(server, "/post-add-basmaterial", &BasMaterialController::addBasMaterial, nullptr);
	BIND_PUT_ROUTER(server, "/put-modify-basmaterial", &BasMaterialController::modifyBasMaterial, nullptr);
	BIND_DEL_ROUTER(server, "/delete-basmaterial", &BasMaterialController::removeBasMaterial, nullptr);
	BIND_POST_ROUTER(server, "/post-import-basmaterial", &BasMaterialController::importBasMaterial, nullptr);
	BIND_GET_ROUTER(server, "/get-export-basmaterial", &BasMaterialController::exportExecl, nullptr);
}

void Router::createMaterialClassificationRouter() {
	BIND_GET_ROUTER(server, "/get-base", &MaterialClassificationController::queryMaterialClassification, nullptr);
	BIND_GET_ROUTER(server, "/get-children", &MaterialClassificationController::queryMaterialClassificationChild, nullptr);
	BIND_GET_ROUTER(server, "/get-detail", &MaterialClassificationController::queryMaterialClassificationDetail, nullptr);
	BIND_POST_ROUTER(server, "/post-add", &MaterialClassificationController::addMaterialClassification, nullptr);
	BIND_PUT_ROUTER(server, "/put-modify", &MaterialClassificationController::modifyMaterialClassification, nullptr);
	BIND_DEL_ROUTER(server, "/delete-by-id", &MaterialClassificationController::removeMaterialClassification, nullptr);
	BIND_POST_ROUTER(server, "/post-import", &MaterialClassificationController::importMaterialClassification, nullptr);
	BIND_GET_ROUTER(server, "/get-export", &MaterialClassificationController::exportMaterialClassification, nullptr);
}

void Router::createCurrencyRouter()
{
	BIND_GET_ROUTER(server, "/currency-query", &CurrencyController::queryCurrency, nullptr);
	BIND_GET_ROUTER(server, "/currency-detail", &CurrencyController::queryDetailCurrency, nullptr);
	//BIND_GET_ROUTER(server, "/currency-action-info", &CurrencyController::queryActionInfolCurrency, nullptr);

	BIND_POST_ROUTER(server, "/currency-execAddCurrency", &CurrencyController::addCurrency, nullptr);
	BIND_PUT_ROUTER(server, "/currency-modify", &CurrencyController::modifyCurrency, nullptr);
	BIND_DEL_ROUTER(server, "/currency-remove", &CurrencyController::removeCurrency, nullptr);
	BIND_POST_ROUTER(server, "/currency-add-Currencys", &CurrencyController::addCurrencys, nullptr);
	BIND_GET_ROUTER(server, "/currency-export", &CurrencyController::exportExecl, nullptr);
	//BIND_GET_ROUTER(server, "/currency-export-only", &CurrencyController::exportExeclOnly, nullptr);
}

void Router::createMeasurementRouter()
{
	BIND_GET_ROUTER(server, "/Measurement-get", &MeasurementController::queryMeasurement, nullptr);
	BIND_GET_ROUTER(server, "/Measurement-get-kid", &MeasurementController::queryKidMeasurement, nullptr);
	BIND_GET_ROUTER(server, "/Measurement-get-detail", &MeasurementController::queryDetailMeasurement, nullptr);
	BIND_POST_ROUTER(server, "/Measurement-post", &MeasurementController::addMeasurement, nullptr);
	BIND_PUT_ROUTER(server, "/Measurement-put", &MeasurementController::modifyMeasurement, nullptr);
	BIND_DEL_ROUTER(server, "/Measurement-delete", &MeasurementController::removeMeasurement, nullptr);
	BIND_POST_ROUTER(server, "/Measurement-addfile", &MeasurementController::addFileMeasurement, nullptr);
	BIND_POST_ROUTER(server, "/Measurement-export", &MeasurementController::exportExecl, nullptr);
}