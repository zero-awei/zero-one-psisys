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
#include "Zdrk/ZdrkController.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"
#include "api/Cgthck/CgthckController.h"
#include "Cgrk/CgrkController.h"

#ifdef HTTP_SERVER_DEMO
#include "sample/SampleController.h"
#include "user/DepartController.h"
#include "uselib/ws/TestWs.h"
#endif

Router::Router(http_server* sever)
{
	this->server = sever;
}

void Router::initRouter()
{
	//���þ�̬�ļ�Ŀ¼
	server->set_public_root_directory("public");
	server->set_static_dir("static/file");

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

	//createSampleRouter();
	//createUserDepartRouter();
	TestWs::addChatHandler(server);
#endif
	createCgrkRouter();
	createIncreaseTonRouter();

	//#TIP :系统扩展路由定义，写在这个后面
	createCgthckRouter();
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

void Router::createCgrkRouter()
{
	BIND_GET_ROUTER(server, "/query-cgrk-bill-list", &CgrkController::queryCgrkBillList, nullptr);
	BIND_GET_ROUTER(server, "/query-cgrk-bill-list-advanced", &CgrkController::queryCgrkBillListAdvanced, nullptr);
	BIND_GET_ROUTER(server, "/query-cgrk-bill-details", &CgrkController::queryCgrkBillDetails, nullptr);
	BIND_GET_ROUTER(server, "/query-pur-order-list", &CgrkController::queryPurOrderList, nullptr);
	BIND_GET_ROUTER(server, "/query-pur-order-entry", &CgrkController::queryPurOrderEntry, nullptr);
	BIND_POST_ROUTER(server, "/add-cgrk-bill", &CgrkController::addCgrkBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-cgrk-bill", &CgrkController::modifyCgrkBill, nullptr);
	BIND_DEL_ROUTER(server, "/delete-cgrk-bill", &CgrkController::removeCgrkBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-cgrk-bill-state", &CgrkController::modifyCgrkBillState, nullptr);
	BIND_POST_ROUTER(server, "/import-cgrk-file", &CgrkController::importCgrkFile, nullptr);
	BIND_GET_ROUTER(server, "/export-cgrk-file", &CgrkController::exportCgrkFile, nullptr);
}

void Router::createIncreaseTonRouter()
{
	BIND_GET_ROUTER(server, "/query-zdrk-bill-list", &ZdrkController::queryZdrkBillList, nullptr);
	BIND_GET_ROUTER(server, "/query-zdrk-bill-details", &ZdrkController::queryZdrkBillDetails, nullptr);
	BIND_POST_ROUTER(server, "/add-zdrk-bill", &ZdrkController::addZdrkBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-zdrk-bill", &ZdrkController::modifyZdrkBill, nullptr);
	BIND_DEL_ROUTER(server, "/delete-zdrk-bill", &ZdrkController::removeZdrkBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-zdrk-bill-state", &ZdrkController::modifyZdrkBillState, nullptr);
	BIND_POST_ROUTER(server, "/import-zdrk-file", &ZdrkController::ImportZdrkFile, nullptr);
	BIND_GET_ROUTER(server, "/emport-zdrk-file", &ZdrkController::EmportZdrkFile, nullptr);
}

void Router::createCgthckRouter()
{
	BIND_GET_ROUTER(server, "/get-cgthck-bill-list", &CgthckController::queryCgthcBillk, nullptr);
	BIND_GET_ROUTER(server, "/get-cgthck-bill-details", &CgthckController::queryCgthckBillDetail, nullptr);
	BIND_POST_ROUTER(server, "/post-cgthck-bill", &CgthckController::addCgthckBill, nullptr);
	BIND_PUT_ROUTER(server, "/put-cgthck-bill", &CgthckController::modifyCgthckBill, nullptr);
	BIND_DEL_ROUTER(server, "/delete-cgthck-bill-by-id", &CgthckController::deleteCgthckBill, nullptr);
	BIND_POST_ROUTER(server, "/import-cgthck-file", &CgthckController::importCgthckFile, nullptr);
	BIND_GET_ROUTER(server, "/export-cgthck-file", &CgthckController::exportCgthckFile, nullptr);
}