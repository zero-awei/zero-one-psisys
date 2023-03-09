#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 13:36:20
 
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
#ifndef _API_HELPER_
#define _API_HELPER_

#include "cinatra.hpp"
#include "JWTUtil.h"
using namespace cinatra;
using namespace nlohmann;
using namespace std;

/** 定义输出日志方法 */
#define LOG(data) std::cout << data << std::endl

/** 定义API方法开头 */
#define API_FUN_BEGIN(__FUN_NAME__) \
void __FUN_NAME__(request& req, response& res) \
{

/** 定义API方法结束 */
#define API_FUN_END \
	res.render_json(data); \
}

/** 定义执行方法调用宏 */
#define API_EXEC_FUN(__EXEC_FUN__) \
nlohmann::json data = nlohmann::json(__EXEC_FUN__(query));

/** 定义执行方法调用宏（无上传参数） */
#define API_EXEC_FUN1(__EXEC_FUN__) \
nlohmann::json data = nlohmann::json(__EXEC_FUN__());

/** 定义执行负载信息方法调用宏 */
#define API_EXEC_FUN_PAYLOAD(__EXEC_FUN__) \
PayloadDTO payload = req.get_user_payload().get<PayloadDTO>(); \
nlohmann::json data = nlohmann::json(__EXEC_FUN__(query, payload));

/** 定义执行负载信息方法调用宏（无上传参数） */
#define API_EXEC_FUN_PAYLOAD1(__EXEC_FUN__) \
PayloadDTO payload = req.get_user_payload().get<PayloadDTO>(); \
nlohmann::json data = nlohmann::json(__EXEC_FUN__(payload));

#pragma region 查询表单

#define API_QUERY_PARAM(__DATA_TYPE__) \
auto queries = req.queries(); \
nlohmann::json j; \
for (auto one : queries) { \
	j[one.first] = one.second; \
} \
__DATA_TYPE__ query = j.get<__DATA_TYPE__>();

/** 定义一个解析/*后面参数值的宏 */
#define API_QUERY_VALUES \
std::vector<std::string_view> query = req.get_query_values();

/** 定义一个解析/*后面参数值的宏（只提取一个参数） */
#define API_QUERY_VALUES1 \
std::string_view query = req.get_query_value(0);

/** 创建API方法宏定义,接收查询表单数据，最终统一下发JSON数据*/
#define CREATE_API_FUN_QUERY(__FUN_NAME__, __EXEC_FUN__, __DATA_TYPE__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_QUERY_PARAM(__DATA_TYPE__) \
	API_EXEC_FUN(__EXEC_FUN__) \
API_FUN_END

/** 创建API方法宏定义,接收/*后的查询参数，最终统一下发JSON数据 */
#define CREATE_API_FUN_QUERY1(__FUN_NAME__, __EXEC_FUN__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_QUERY_VALUES \
	API_EXEC_FUN(__EXEC_FUN__) \
API_FUN_END

/** 创建API方法宏定义,接收/*后的查询参数（只提取一个参数），最终统一下发JSON数据 */
#define CREATE_API_FUN_QUERY2(__FUN_NAME__, __EXEC_FUN__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_QUERY_VALUES1 \
	API_EXEC_FUN(__EXEC_FUN__) \
API_FUN_END

/** 创建API方法宏定义,无上传参数，最终统一下发JSON数据 */
#define CREATE_API_FUN_QUERY3(__FUN_NAME__, __EXEC_FUN__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_EXEC_FUN1(__EXEC_FUN__) \
API_FUN_END

/** 创建API方法宏定义,接收查询表单数据与负载数据，最终统一下发JSON数据*/
#define CREATE_API_FUN_QUERY_PAYLOAD(__FUN_NAME__, __EXEC_FUN__, __DATA_TYPE__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_QUERY_PARAM(__DATA_TYPE__) \
	API_EXEC_FUN_PAYLOAD(__EXEC_FUN__) \
API_FUN_END

/** 创建API方法宏定义,接收/*后的查询参数与负载数据，最终统一下发JSON数据*/
#define CREATE_API_FUN_QUERY_PAYLOAD1(__FUN_NAME__, __EXEC_FUN__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_QUERY_VALUES \
	API_EXEC_FUN_PAYLOAD(__EXEC_FUN__) \
API_FUN_END

/** 创建API方法宏定义,接收/*后的查询参数（只提取一个参数）与负载数据，最终统一下发JSON数据*/
#define CREATE_API_FUN_QUERY_PAYLOAD2(__FUN_NAME__, __EXEC_FUN__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_QUERY_VALUES1 \
	API_EXEC_FUN_PAYLOAD(__EXEC_FUN__) \
API_FUN_END

/** 创建API方法宏定义,仅接收负载数据，最终统一下发JSON数据*/
#define CREATE_API_FUN_QUERY_PAYLOAD3(__FUN_NAME__, __EXEC_FUN__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_EXEC_FUN_PAYLOAD1(__EXEC_FUN__) \
API_FUN_END

#pragma endregion

#pragma region BODY表单

// 定义Body表单参数解析宏
#define API_BODY_PARAM(__DATA_TYPE__) \
auto bodys = req.parse_query(req.body()); \
nlohmann::json j; \
for (auto one : bodys) { \
	j[one.first] = one.second; \
} \
if (req.queries().size()) { \
	nlohmann::json jq; \
	auto queries = req.queries(); \
	for (auto one : queries) { \
		jq[one.first] = one.second; \
	} \
	j.merge_patch(jq); \
} \
__DATA_TYPE__ query = j.get<__DATA_TYPE__>();

// 定义Body表单文件上传参数解析宏
#define API_BODY_PARAM_FILE(__DATA_TYPE__) \
nlohmann::json jf; \
for (auto one : req.get_form_url_map()) { \
	jf[one.first] = one.second; \
} \
__DATA_TYPE__ query = jf.get<__DATA_TYPE__>(); \
auto& files = req.get_upload_files(); \
for (auto& file : files) { \
	query.addFile(file.get_file_path()); \
}

/** 创建API方法宏定义,接收BODY表单数据，最终统一下发JSON数据 */
#define CREATE_API_FUN_BODY(__FUN_NAME__, __EXEC_FUN__, __DATA_TYPE__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_BODY_PARAM(__DATA_TYPE__) \
	API_EXEC_FUN(__EXEC_FUN__) \
API_FUN_END

/** 创建API方法宏定义,接收BODY文件表单数据，最终统一下发JSON数据 */
#define CREATE_API_FUN_BODY_FILE(__FUN_NAME__, __EXEC_FUN__, __DATA_TYPE__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_BODY_PARAM_FILE(__DATA_TYPE__) \
	API_EXEC_FUN(__EXEC_FUN__) \
API_FUN_END

/** 创建API方法宏定义,接收BODY表单数据和负载数据，最终统一下发JSON数据 */
#define CREATE_API_FUN_BODY_PAYLOAD(__FUN_NAME__, __EXEC_FUN__, __DATA_TYPE__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_BODY_PARAM(__DATA_TYPE__) \
	API_EXEC_FUN_PAYLOAD(__EXEC_FUN__) \
API_FUN_END

/** 创建API方法宏定义,接收BODY文件表单数据和负载数据，最终统一下发JSON数据 */
#define CREATE_API_FUN_BODY_PAYLOAD_FILE(__FUN_NAME__, __EXEC_FUN__, __DATA_TYPE__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_BODY_PARAM_FILE(__DATA_TYPE__) \
	API_EXEC_FUN_PAYLOAD(__EXEC_FUN__) \
API_FUN_END

#pragma endregion

#pragma region BODYJSON

#define API_BODY_JSON_PARAM(__DATA_TYPE__) \
nlohmann::json json = nlohmann::json::parse(req.body()); \
__DATA_TYPE__ query = json.get<__DATA_TYPE__>();

/** 创建API方法宏定义,接收JSON类型数据，最终统一下发JSON数据 */
#define CREATE_API_FUN_JSON(__FUN_NAME__, __EXEC_FUN__, __DATA_TYPE__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_BODY_JSON_PARAM(__DATA_TYPE__) \
	API_EXEC_FUN(__EXEC_FUN__) \
API_FUN_END

/** 创建API方法宏定义,接收JSON类型数据和负载数据，最终统一下发JSON数据 */
#define CREATE_API_FUN_JSON_PAYLOAD(__FUN_NAME__, __EXEC_FUN__, __DATA_TYPE__) \
API_FUN_BEGIN(__FUN_NAME__) \
	API_BODY_JSON_PARAM(__DATA_TYPE__) \
	API_EXEC_FUN_PAYLOAD(__EXEC_FUN__) \
API_FUN_END

#pragma endregion

/** 绑定路由宏定义 */
#define BIND_GET_ROUTER(__SERVER__, __PATH__, __FUN_NAME__, ...) \
__SERVER__->set_http_handler<GET, OPTIONS>(__PATH__, __FUN_NAME__, CROS(), Check(), __VA_ARGS__);

#define BIND_POST_ROUTER(__SERVER__,__PATH__, __FUN_NAME__, ...) \
__SERVER__->set_http_handler<POST, OPTIONS>(__PATH__, __FUN_NAME__, CROS(), Check(), __VA_ARGS__);

#define BIND_PUT_ROUTER(__SERVER__,__PATH__, __FUN_NAME__, ...) \
__SERVER__->set_http_handler<PUT, OPTIONS>(__PATH__, __FUN_NAME__, CROS(), Check(), __VA_ARGS__);

#define BIND_DEL_ROUTER(__SERVER__,__PATH__, __FUN_NAME__, ...) \
__SERVER__->set_http_handler<DEL, OPTIONS>(__PATH__, __FUN_NAME__, CROS(), Check(), __VA_ARGS__);

/** JSON绑定函数定义 */
#define BIND_TO_JSON(Type, ...)  \
friend void to_json(nlohmann::json& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) } // NOLINT
#define BIND_FROM_JSON(Type, ...) \
friend void from_json(const nlohmann::json& nlohmann_json_j, Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM, __VA_ARGS__)) } // NOLINT

/** JSON字段转换到对象字段宏定义 */
#define BIND_FROM_TO_NORMAL(nlohmann_json_j, nlohmann_json_t, field) \
if(nlohmann_json_j.contains(#field)) { \
	nlohmann::json jf = nlohmann_json_j.at(#field); \
	if(jf.is_string()) { \
		nlohmann_json_t.field = code_utils::url_decode(jf.get<string>()); \
	} else { \
		jf.get_to(nlohmann_json_t.field); \
	} \
}
#define BIND_FROM_TO_B(nlohmann_json_j, nlohmann_json_t, field) \
if(nlohmann_json_j.contains(#field)) { \
	nlohmann::json jf = nlohmann_json_j.at(#field); \
	if (jf.is_string()) { \
		std::string s = jf.get<string>(); \
		if (s == "true" || s == "1") nlohmann_json_t.field = true; \
		else nlohmann_json_t.field = false; \
	} else { \
		jf.get_to(nlohmann_json_t.field); \
	} \
}
#define BIND_FROM_TO(nlohmann_json_j, nlohmann_json_t, field, toFun) \
if(nlohmann_json_j.contains(#field)) {\
	nlohmann::json jf = nlohmann_json_j.at(#field); \
	if(jf.is_string()) { \
		nlohmann_json_t.field = toFun(jf.get<string>()); \
	} else { \
		jf.get_to(nlohmann_json_t.field); \
	} \
}
#define BIND_FROM_TO_I(nlohmann_json_j, nlohmann_json_t, field) BIND_FROM_TO(nlohmann_json_j, nlohmann_json_t, field, stoi)
#define BIND_FROM_TO_L(nlohmann_json_j, nlohmann_json_t, field) BIND_FROM_TO(nlohmann_json_j, nlohmann_json_t, field, stol)
#define BIND_FROM_TO_UL(nlohmann_json_j, nlohmann_json_t, field) BIND_FROM_TO(nlohmann_json_j, nlohmann_json_t, field, stoul)
#define BIND_FROM_TO_LL(nlohmann_json_j, nlohmann_json_t, field) BIND_FROM_TO(nlohmann_json_j, nlohmann_json_t, field, stoll)
#define BIND_FROM_TO_ULL(nlohmann_json_j, nlohmann_json_t, field) BIND_FROM_TO(nlohmann_json_j, nlohmann_json_t, field, stoull)
#define BIND_FROM_TO_F(nlohmann_json_j, nlohmann_json_t, field) BIND_FROM_TO(nlohmann_json_j, nlohmann_json_t, field, stof)
#define BIND_FROM_TO_D(nlohmann_json_j, nlohmann_json_t, field) BIND_FROM_TO(nlohmann_json_j, nlohmann_json_t, field, stod)
#define BIND_FROM_TO_LD(nlohmann_json_j, nlohmann_json_t, field) BIND_FROM_TO(nlohmann_json_j, nlohmann_json_t, field, stold)
#define BIND_FROM_TO_OBJ(nlohmann_json_j, nlohmann_json_t, field, __DATA_TYPE__) \
if(nlohmann_json_j.contains(#field)) { \
	nlohmann::json jf = nlohmann_json_j.at(#field); \
	__DATA_TYPE__ obj = jf.get<__DATA_TYPE__>(); \
	nlohmann_json_t.field = obj; \
}
#endif // !_API_HELPER_
