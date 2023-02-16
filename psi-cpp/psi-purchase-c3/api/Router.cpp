
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


//采购申请
void Router::createPurReqRouter() {
	//查询单据列表
	BIND_GET_ROUTER(server, "/get-com-bill-list", &PurReqController::queryPurReqFindBill, nullptr);
	//查询指定单据详细信息
	BIND_GET_ROUTER(server, "/get-one-combill", &PurReqController::queryPurReqFindDetailBill, nullptr);
	//添加申请(保存/提交)
	BIND_POST_ROUTER(server, "/pur-req/post", &PurReqController::addPurReq, nullptr);
	//修改申请(保存/提交/审核)
	BIND_PUT_ROUTER(server, "/pur-req/put", &PurReqController::modifyPurReq, nullptr);
	//删除申请
	BIND_DEL_ROUTER(server, "/pur-req/delete-by-id", &PurReqController::removePurReqById, nullptr);
	//修改单据状态(关闭/作废/反关闭)
	BIND_POST_ROUTER(server, "/pur-req/modify-bill-status", &PurReqController::modifyPurReqBillStatus, nullptr);
	//导入
	BIND_POST_ROUTER(server, "/pur-req-into", &PurReqController::modifyPurReqInto, nullptr);
	//导出
	BIND_GET_ROUTER(server, "/pur-req-export", &PurReqController::queryPurReqExport, nullptr);
}
<<<<<<< HEAD
//采购询价
void Router::createPurInquiryRouter() {
	//查询单据列表
	BIND_GET_ROUTER(server, "/pur-inquiry-find-bill", &PurInquiryController::queryPurInquiryFindBill, nullptr);
	//查询指定单据详细信息
	BIND_GET_ROUTER(server, "/pur-inquiry-find-detail-bill", &PurInquiryController::queryPurInquiryFindDetailBill, nullptr);
	BIND_POST_ROUTER(server, "/add", &PurInquiryController::addPurInquiry, nullptr);
	BIND_PUT_ROUTER(server, "/modify", &PurInquiryController::modifyPurInquiry, nullptr);
	BIND_DEL_ROUTER(server, "/delete", &PurInquiryController::removePurInquiry, nullptr);
	BIND_PUT_ROUTER(server, "/modify-status", &PurInquiryController::modifyPurQuotModBillStatus, nullptr);
	BIND_POST_ROUTER(server, "/purReqInto", &PurInquiryController::PurInquiryInto,nullptr);
	BIND_GET_ROUTER(server, "/purReqExport", &PurInquiryController::PurInquiryExport, nullptr);

}

//供应报价
void Router::createPurQuotRouter()
{
	//添加报价(保存/提交)
	BIND_POST_ROUTER(server, "/add-pur-quot", &PurQuotController::addPurQuot, nullptr);
	//修改报价(保存/提交/审核)
	BIND_PUT_ROUTER(server, "/mod-pur-quot", &PurQuotController::modPurQuot, nullptr);
	//删除报价
	BIND_DEL_ROUTER(server, "/del-pur-quot", &PurQuotController::delPurQuot, nullptr);
	//修改单据状态(关闭/作废/反关闭)
	BIND_PUT_ROUTER(server, "/pur-quot-mod-bill-status", &PurQuotController::purQuotModBillStatus, nullptr);
	//导入
	BIND_PUT_ROUTER(server, "/pur-quot-mod-into", &PurQuotController::modifyPurQuotInto, nullptr);
	//导出
	BIND_PUT_ROUTER(server, "/pur-quot-query-export", &PurQuotController::queryPurQuotExport, nullptr);
}

//采购比价
void Router::createPurCompareRouter(){
	//查询单据列表
	BIND_GET_ROUTER(server, "/get-combill-list", &PurCompareController::queryPurComFindBill, nullptr);
	//查询指定单据详细信息
	BIND_GET_ROUTER(server, "/get-one-combill", &PurCompareController::queryPurComFindDetailBill, nullptr);
	//报价单列表
	BIND_GET_ROUTER(server, "/get-quot-of-combill", &PurCompareController::queryPurComList, nullptr);
	//报价单分录列表
	BIND_GET_ROUTER(server, "/get-quotentry-of-combill", &PurCompareController::queryPurComDividedList, nullptr);
	//添加比价(保存/提交)
	BIND_POST_ROUTER(server, "/add-pur-com", &PurCompareController::addPurCom, nullptr);
	//修改比较(保存/提交/审核)
	BIND_POST_ROUTER(server, "/mod-pur-com", &PurCompareController::modifyPurCom, nullptr);
	//删除比价
	BIND_DEL_ROUTER(server, "/del-pur-com", &PurCompareController::removePurCom, nullptr);
	//修改单据状态(关闭/作废/反关闭)
	BIND_POST_ROUTER(server, "/mod-pur-com-bill-status", &PurCompareController::purComModBillStatus, nullptr);
	//导入
	BIND_POST_ROUTER(server, "/pur-into-into", &PurCompareController::modifyPurComInto, nullptr);
	//导出
	BIND_GET_ROUTER(server, "/pur-com-export", &PurCompareController::queryPurComExport, nullptr);
}




