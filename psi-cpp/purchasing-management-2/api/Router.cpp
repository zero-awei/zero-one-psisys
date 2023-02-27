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

#include "finPaymenReq/FinPaymentReqControlle.h"
#include "payment/PaymentController.h"


#define PURORDER
#include "PurOrder/PurOrderController.h"
#include "prepayment/PrePayController.h"
#ifdef HTTP_SERVER_DEMO
#include "sample/SampleController.h"
#include "user/DepartController.h"
#include "uselib/ws/TestWs.h"
#endif

#include "statis/StatisController.h"

#define PURORDER
#include "PurOrder/PurOrderController.h"
#include "PueReq/PurReqController.h"
#include "PurCom/PurComController.h"
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

	////新增供应报价
	//BIND_POST_ROUTER(server, "/post", &PurQuotController::addPurQuot, nullptr);
	////修改供应报价
	//BIND_PUT_ROUTER(server, "/put", &PurQuotController::modPurQuot, nullptr);
	////删除供应报价
	//BIND_DEL_ROUTER(server, "/delete", &PurQuotController::delPurQuot, nullptr);
	////修改供应报价状态（关闭、作弊、反关闭）
	//BIND_PUT_ROUTER(server, "/put", &PurQuotController::purQuotModBillStatus, nullptr);

	createPayRouter();
	BIND_GET_ROUTER(server, "/query/ExecuteStatus", &StatisController::queryExeStatus, nullptr);
	BIND_GET_ROUTER(server, "/query-all", &StatisController::queryStatis, nullptr);
	BIND_GET_ROUTER(server, "/query-byDept", &StatisController::queryStatisByDept, nullptr);
	BIND_GET_ROUTER(server, "/query-byOperator", &StatisController::queryStatisByOperator, nullptr);
	BIND_GET_ROUTER(server, "/query-bySupplier", &StatisController::queryStatisBySupplier, nullptr);
	BIND_GET_ROUTER(server, "/query-byMaterial", &StatisController::queryStatisByMaterial, nullptr);

	BIND_GET_ROUTER(server, "/export/ExecuteStatus", &StatisController::exportExeStatus, nullptr);
	BIND_GET_ROUTER(server, "/export-all", &StatisController::exportStatis, nullptr);
	BIND_GET_ROUTER(server, "/export-byDept", &StatisController::exportStatisByDept, nullptr);
	BIND_GET_ROUTER(server, "/export-byOperator", &StatisController::exportStatisByOperator, nullptr);
	BIND_GET_ROUTER(server, "/export-bySupplier", &StatisController::exportStatisBySupplier, nullptr);
	BIND_GET_ROUTER(server, "/export-byMaterial", &StatisController::exportStatisByMaterial, nullptr);

#ifdef PURORDER
	createPurOrderRouter();
	createPurReqRouter();
	createPurComRouter();
#endif

	// 分页数据
	BIND_GET_ROUTER(server, "/purOrder/list", &PurOrderController::listPurOrder, nullptr);
	// 单个数据
	BIND_GET_ROUTER(server, "/purOrder/queryEntryByMainId", &PurOrderController::getPurOrder, nullptr);
	// 新增数据
	BIND_POST_ROUTER(server, "/purOrder/add", &PurOrderController::addPurOrder, nullptr);
	// 修改数据
	BIND_PUT_ROUTER(server, "/purOrder/edit", &PurOrderController::modifyPurOrder, nullptr);
	// 修改状态
	BIND_PUT_ROUTER(server, "/purOrder/status", &PurOrderController::statusPurOrder, nullptr);
	// 删除数据
	BIND_DEL_ROUTER(server, "/purOrder/delete", &PurOrderController::removePurOrder, nullptr);
	// 删除ById
	BIND_DEL_ROUTER(server, "/purOrder/deleteById", &PurOrderController::removeById, nullptr);

	//查询单据列表
	BIND_GET_ROUTER(server, "/get-bill-list", &PrePayController::queryPayFindBill, nullptr);
	//查询指定单据详细信息
	BIND_GET_ROUTER(server, "/get-detail-bill", &PrePayController::queryPayFinDetailBill, nullptr);
	//导出
	BIND_GET_ROUTER(server, "/pay-export", &PrePayController::queryPayExport, nullptr);
	//添加申请(保存/提交)
	BIND_POST_ROUTER(server, "/post-add", &PrePayController::addPay, nullptr);
	//修改申请(保存/提交/审核)
	BIND_PUT_ROUTER(server, "/put-modifyPay", &PrePayController::modifyPay, nullptr);
	//删除申请
	BIND_DEL_ROUTER(server, "/delete-id", &PrePayController::removePayById, nullptr);
	//修改单据状态(关闭/作废/反关闭)
	BIND_POST_ROUTER(server, "/modify-bill-status", &PrePayController::modifyPurReqBillStatus, nullptr);
	//导入
	BIND_POST_ROUTER(server, "/pay-into", &PrePayController::modifyPayInto, nullptr);
	createPaymentRouter();
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

void Router::createPayRouter() {
	//查询单据列表
	BIND_GET_ROUTER(server, "/get-bill-list", &PrePayController::queryPayFindBill, nullptr);
	//查询指定单据详细信息
	BIND_GET_ROUTER(server, "/get-detail-bill", &PrePayController::queryPayFinDetailBill, nullptr);
	//导出
	BIND_GET_ROUTER(server, "/pay-export", &PrePayController::queryPayExport, nullptr);
	//添加申请(保存/提交)
	BIND_POST_ROUTER(server, "/post-add", &PrePayController::addPay, nullptr);
	//修改申请(保存/提交/审核)
	BIND_PUT_ROUTER(server, "/put-modifyPay", &PrePayController::modifyPay, nullptr);
	//删除申请
	BIND_DEL_ROUTER(server, "/delete-id", &PrePayController::removePayById, nullptr);
	//修改单据状态(关闭/作废/反关闭)
	BIND_POST_ROUTER(server, "/modify-bill-status", &PrePayController::modifyPurReqBillStatus, nullptr);
	//导入
	BIND_POST_ROUTER(server, "/pay-into", &PrePayController::modifyPayInto, nullptr);
}

void Router::createPurOrderRouter()
{
	// 分页数据
	BIND_GET_ROUTER(server, "/purOrder/list", &PurOrderController::listPurOrder, nullptr);
	// 单个数据
	BIND_GET_ROUTER(server, "/purOrder/queryEntryByMainId", &PurOrderController::getPurOrder, nullptr);
	// 新增数据
	BIND_POST_ROUTER(server, "/purOrder/add", &PurOrderController::addPurOrder, nullptr);
	// 修改数据
	BIND_PUT_ROUTER(server, "/purOrder/edit", &PurOrderController::modifyPurOrder, nullptr);
	// 删除数据
	BIND_DEL_ROUTER(server, "/purOrder/delete", &PurOrderController::removePurOrder, nullptr);
	// 删除ById
	BIND_DEL_ROUTER(server, "/purOrder/deleteById", &PurOrderController::removeById, nullptr);
}

void Router::createPurReqRouter() {
	// 分页数据
	BIND_GET_ROUTER(server, "/purReq/list", &PurReqController::listPurReq, nullptr);
	// 单个数据
	BIND_GET_ROUTER(server, "/purReq/queryEntryByMainId", &PurReqController::getPurReq, nullptr);
}

void Router::createPurComRouter() {
	// 分页数据
	BIND_GET_ROUTER(server, "/purCom/list", &PurComController::listPurCom, nullptr);
	// 单个数据
	BIND_GET_ROUTER(server, "/purCom/queryEntryByMainId", &PurComController::getPurCom, nullptr);
}

void Router::createPaymentRouter()
{
	BIND_PUT_ROUTER(server, "/payment-change", &PaymentController::changePayment, nullptr);
	BIND_DEL_ROUTER(server, "/delete-by-id", &PaymentController::deleteById, nullptr);
	BIND_POST_ROUTER(server, "/payment-export", &PaymentController::exportPayment, nullptr);
	BIND_POST_ROUTER(server, "/payment-import", &PaymentController::importPayment, nullptr);
}

void Router::createPayApplyRouter() {
	BIND_GET_ROUTER(server, "/finPaymenReq", &FinPaymentReqControlle::finPaymentReq, nullptr);
	BIND_GET_ROUTER(server, "/finPaymentReqEntry", &FinPaymentReqControlle::finPaymentReqEntry, nullptr);
	BIND_POST_ROUTER(server, "/paymentReq/add", &FinPaymentReqControlle::addPaymentReq, nullptr);
	BIND_PUT_ROUTER(server, "/paymentReq/mod", &FinPaymentReqControlle::modPaymentReq, nullptr);
}