
//公共接口
#include "stdafx.h"
#include "Router.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"
#include "pur-quot/PurQuotController.h"


//
#include "pur-req/PurReqController.h"
#include "pur-compare/PurCompareController.h"
#include "pur-inquiry/PurInquiryController.h"


#ifdef HTTP_SERVER_DEMO
#include "sample/SampleController.h"
#include "user/DepartController.h"
#include "uselib/ws/TestWs.h"
#endif

#include "pur-req/PurReqController.h"

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
	createPurCompareRouter();
	createPurInquiryRouter();
	createPurReqRouter();
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


void Router::createPurReqRouter() {
	//查询比价单列表接口路由绑定
	BIND_GET_ROUTER(server, "/get-com-bill-list", &PurReqController::queryPurReqFindBill, nullptr);
	//查询指定比价单详细信息接口路由绑定
	BIND_GET_ROUTER(server, "/get-one-combill", &PurReqController::queryPurReqFindDetailBill, nullptr);
	//导出申请单接口路由绑定
	BIND_GET_ROUTER(server, "/pur-req-export", &PurReqController::queryPurReqExport, nullptr);
	//导入申请单接口路由绑定
	BIND_POST_ROUTER(server, "/pur-req-into", &PurReqController::modifyPurReqInto, nullptr);
	//采购订单添加接口
	BIND_POST_ROUTER(server, "/pur-req/post", &PurReqController::addPurReq, nullptr);
	//采购订单修改接口
	BIND_PUT_ROUTER(server, "/pur-req/put", &PurReqController::modifyPurReq, nullptr);
	//采购订单删除接口
	BIND_DEL_ROUTER(server, "/pur-req/delete-by-id", &PurReqController::removePurReqById, nullptr);
	//采购订单状态修改接口
	BIND_POST_ROUTER(server, "/pur-req/modify-bill-status", &PurReqController::modifyPurReqBillStatus, nullptr);

}
void Router::createPurCompareRouter()
{
	//查询比价单列表接口路由绑定
	BIND_GET_ROUTER(server, "/get-combill-list", &PurCompareController::queryPurComFindBill, nullptr);
	//查询指定比价单详细信息接口路由绑定
	BIND_GET_ROUTER(server, "/get-one-combill", &PurCompareController::queryPurComFindDetailBill, nullptr);
	//查询报价单接口路由绑定
	BIND_GET_ROUTER(server, "/get-quot-of-combill", &PurCompareController::queryPurComList, nullptr);
	//查询报价单分录接口路由绑定
	BIND_GET_ROUTER(server, "/get-quotentry-of-combill", &PurCompareController::queryPurComDividedList, nullptr);
	// 新增比价的接口
	BIND_POST_ROUTER(server, "/add-pur-com", &PurCompareController::addPurCom, nullptr);
	// 修改比价的接口
	BIND_POST_ROUTER(server, "/mod-pur-com", &PurCompareController::modifyPurCom, nullptr);
	// 删除比价的接口
	BIND_DEL_ROUTER(server, "/del-pur-com", &PurCompareController::removePurCom, nullptr);
	// 修改单据状态的接口
	BIND_POST_ROUTER(server, "/mod-pur-com-bill-status", &PurCompareController::purComModBillStatus, nullptr);
}


void Router::createPurInquiryRouter()
{
	//查询询价单列表接口路由绑定
	BIND_GET_ROUTER(server, "/pur-inquiry-find-bill", &PurInquiryController::queryPurInquiryFindBill, nullptr);
	//查看指定询价单详细信息接口路由绑定
	BIND_GET_ROUTER(server, "/pur-inquiry-find-detail-bill", &PurInquiryController::queryPurInquiryFindDetailBill, nullptr);
	BIND_POST_ROUTER(server, "/add", &PurInquiryController::addPurInquiry, nullptr);
	BIND_PUT_ROUTER(server, "/modify", &PurInquiryController::modifyPurInquiry, nullptr);
	BIND_DEL_ROUTER(server, "/delete", &PurInquiryController::removePurInquiry, nullptr);
	BIND_POST_ROUTER(server, "/purReqInto", &PurInquiryController::PurInquiryInto,nullptr);
	BIND_GET_ROUTER(server, "/purReqExport", &PurInquiryController::PurInquiryExport, nullptr);
}



//奶罐的代码
void Router::createPurQuotRouter()
{
	//新增供应报价
	BIND_POST_ROUTER(server, "/add-pur-quot", &PurQuotController::addPurQuot, nullptr);
	//修改供应报价
	BIND_PUT_ROUTER(server, "/mod-pur-quot", &PurQuotController::modPurQuot, nullptr);
	//删除供应报价
	BIND_DEL_ROUTER(server, "/del-pur-quot", &PurQuotController::delPurQuot, nullptr);
	//修改供应报价状态（关闭、作弊、反关闭）
	BIND_PUT_ROUTER(server, "/pur-quot-mod-bill-status", &PurQuotController::purQuotModBillStatus, nullptr);
	
}






