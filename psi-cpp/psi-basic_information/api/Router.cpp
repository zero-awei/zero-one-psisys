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


#ifdef HTTP_SERVER_DEMO
#include "sample/SampleController.h"
#include "user/DepartController.h"
#include "uselib/ws/TestWs.h"
#endif

#include"BasMaterial/BasMaterialController.h"
#include "MaterialClassification/MaterialClassificationController.h"

Router::Router(http_server* sever)
{
	this->server = sever;
}

void Router::initRouter()
{
	//���þ�̬�ļ�Ŀ¼
	server->set_public_root_directory("public");
	server->set_static_dir("static/file");
	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	createDepotRouter();

	
#ifdef HTTP_SERVER_DEMO
		//����ҳҳ��
		BIND_GET_ROUTER(server, "/", [](request& req, response& res) {
		res.render_raw_view("./public/test.html");
			}, nullptr);

	//��ʼ��һ���ļ��ϴ��ӿ�ʾ��
	BIND_POST_ROUTER(server, "/upload-file", [](request& req, response& res) {
		if (req.get_content_type() != content_type::multipart)
		{
			JsonVO vo = JsonVO("", RS_CONTENT_TYPE_ERR);
			nlohmann::json jvo = nlohmann::json(vo);
			jvo.erase("data");
			res.render_json(jvo);
			return;
		}
		//��ȡ��������
		std::cout << "nickname:" << req.get_multipart_value_by_key1("nickname") << std::endl;
		std::cout << "age:" << req.get_multipart_value_by_key1("age") << std::endl;
		//��ȡ�ļ�·��
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

	//#TIP :ϵͳ��չ·�ɶ��壬д���������

	createBasMaterialRouter();

	createMaterialClassificationRouter(); //


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

void Router::createDepotRouter()
{
	BIND_GET_ROUTER(server, "/query-depot", &DepotController::queryDepot, nullptr);
	BIND_GET_ROUTER(server, "/query-depot-kid", &DepotController::queryKidDepot, nullptr);
	BIND_GET_ROUTER(server, "/query-depot-detail", &DepotController::queryDetailDepot, nullptr);
	BIND_GET_ROUTER(server, "/query-depot-action-info", &DepotController::queryActionInfolDepot, nullptr);
	BIND_POST_ROUTER(server, "/add-depot", &DepotController::addDepot, nullptr);
	BIND_PUT_ROUTER(server, "/modify-depot", &DepotController::modifyDepot, nullptr);
	BIND_DEL_ROUTER(server, "/remove-depot", &DepotController::removeDepot, nullptr);
	BIND_POST_ROUTER(server, "/add-depots", &DepotController::addDepots, nullptr);
	BIND_GET_ROUTER(server, "/export-depots", &DepotController::exportExecl, nullptr);
	BIND_GET_ROUTER(server, "/export-depot-by-only", &DepotController::exportExeclOnly, nullptr);
}

void Router::createBasMaterialRouter() {
	BIND_GET_ROUTER(server, "/get-basmaterial", &BasMaterialController::queryBasMaterial, nullptr);
	BIND_GET_ROUTER(server, "/get-detail", &BasMaterialController::queryDetailBasMaterial, nullptr);
	BIND_POST_ROUTER(server, "/post-add", &BasMaterialController::addBasMaterial, nullptr);
	BIND_PUT_ROUTER(server, "/put-modify", &BasMaterialController::modifyBasMaterial, nullptr);
	BIND_DEL_ROUTER(server, "/delete", &BasMaterialController::removeBasMaterial, nullptr);
	BIND_POST_ROUTER(server, "/post-import", &BasMaterialController::importBasMaterial, nullptr);
	BIND_GET_ROUTER(server, "/get-export", &BasMaterialController::exportExecl, nullptr);
}

void Router::createMaterialClassificationRouter() {
	BIND_GET_ROUTER(server, "/get-base", &MaterialClassificationController::queryMaterialClassification, nullptr);
	BIND_GET_ROUTER(server, "/get-children", &MaterialClassificationController::queryMaterialClassificationChild, nullptr);
	BIND_GET_ROUTER(server, "/get-detail", &MaterialClassificationController::queryMaterialClassificationDetail, nullptr);
	BIND_POST_ROUTER(server, "/post-add", &MaterialClassificationController::addMaterialClassification, nullptr);
	BIND_PUT_ROUTER(server, "/put-modify", &MaterialClassificationController::modifyMaterialClassification, nullptr);
	BIND_DEL_ROUTER(server, "/delete", &MaterialClassificationController::removeMaterialClassification, nullptr);
	BIND_POST_ROUTER(server, "/post-import", &MaterialClassificationController::importMaterialClassification, nullptr);
	BIND_GET_ROUTER(server, "/get-export", &MaterialClassificationController::exportMaterialClassification, nullptr);
}