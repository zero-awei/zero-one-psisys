
//公共接口
#include "stdafx.h"
#include "Router.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"
#include "pur-quot/PurQuotController.h"


//



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
	//设置静态文件目录
	server->set_public_root_directory("public");
	server->set_static_dir("static/file");


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
	createPurQuotRouter();

}





#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	//新增供应报价
	BIND_POST_ROUTER(server, "/post", &PurQuotController::addPurQuot, nullptr);
	//修改供应报价
	BIND_PUT_ROUTER(server, "/put", &PurQuotController::modPurQuot, nullptr);
	//删除供应报价
	BIND_DEL_ROUTER(server, "/delete", &PurQuotController::delPurQuot, nullptr);
	//修改供应报价状态（关闭、作弊、反关闭）
	BIND_PUT_ROUTER(server, "/put", &PurQuotController::purQuotModBillStatus, nullptr);
}

void Router::createUserDepartRouter()
{
	BIND_POST_ROUTER(server, "/depart-add", &DepartController::addDepart, nullptr);
	BIND_POST_ROUTER(server, "/depart-add-more", &DepartController::addDepartMore, nullptr);
}

#endif


//供应报价
void Router::createPurQuotRouter()
{
	//添加报价(保存/提交)
	BIND_POST_ROUTER(server, "/add-pur-quot", &PurQuotController::addPurQuot, nullptr);
	//修改报价(保存/提交/审核)
	BIND_PUT_ROUTER(server, "/mod-pur-quot", &PurQuotController::modPurQuot, nullptr);
	//删除报价
BIND_DEL_ROUTER(server, "/del-pur-quot", &PurQuotController::delPurQuotById, nullptr);
	//修改单据状态(关闭/作废/反关闭)
	BIND_PUT_ROUTER(server, "/pur-quot-mod-bill-status", &PurQuotController::purQuotModBillStatus, nullptr);
	//导入
	BIND_PUT_ROUTER(server, "/pur-quot-mod-into", &PurQuotController::modifyPurQuotInto, nullptr);
	//导出
	BIND_PUT_ROUTER(server, "/pur-quot-query-export", &PurQuotController::queryPurQuotExport, nullptr);
}





