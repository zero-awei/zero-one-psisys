/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:38:49
 
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
#include "api/Aspect.h"
#include "JWTUtil.h"
#include "../domain/vo/JsonVO.h"
#include <sstream>

// std::unique_ptr<std::string> RSA_PUB_KEY = std::make_unique<std::string>(R"(
// -----BEGIN PUBLIC KEY-----
// MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA2CUog6kdKUOlOtdOHFcs
// ts0KHt5eg8UPF6Yj/jte7jgxOWsYB571rdMzTDIYo1UIaYVOJcd3oio9QlebUZD7
// O4GL8oJmj9rNCVk60xfx3vhYISzdHbwQhUUgx+YDmDr5UJV/D/uhCdFKziTUBMjD
// otSQXvCsbWIMGGEFbPXKe9VRmgqtjdNfWvjMa7spQwiy0gj7GeOUiIttkVZna6qF
// FZRSRAxp3NJ9ELbcW7Kd9u5IFzrvxXNiYPOtIiw+zqJTYsSXUJTI7YQAXy9zqGtT
// 7QUFUjxUf+7b1DELpGZPmwGd5Jzj+zfTNsS3DRNuPQJPkPbpUo1qCsU55sXgcNrf
// zwIDAQAB
// -----END PUBLIC KEY-----)");

// RSA公钥
std::unique_ptr<std::string> RSA_PUB_KEY = nullptr;

#ifndef CHECK_TOKEN

//开启凭证检查，解开下一行注释即可
//#define CHECK_TOKEN

#endif

//测试负载数据注入
#define TEST_PAYLOAD_INJECTION(__req__) \
PayloadDTO payload; \
payload.setId("1"); \
payload.setUsername("admin"); \
payload.setUserDept("develop"); \
payload.getAuthorities().push_back("ADMIN"); \
payload.getAuthorities().push_back("TEST"); \
__req__.set_user_payload(nlohmann::json(payload));

void checkCommonSender(string message, response* res) {
	JsonVO vo = JsonVO("", RS_UNAUTHORIZED);
	vo.setMessage(message);
	nlohmann::json jvo = nlohmann::json(vo);
	jvo.erase("data");
	res->render_json(jvo);
}

bool CROS::before(request& req, response& res)
{
#ifndef CLOSE_CROS_SUPPORT
	res.add_header("Access-Control-Allow-Origin", "*");
	res.add_header("Access-Control-Allow-Methods", "*");
	res.add_header("Access-Control-Expose-Headers", "*");
	//允许携带cookie凭证
	res.add_header("Access-Control-Allow-Credentials", "true");
	res.add_header("Access-Control-Allow-Headers", "Content-Type,Access-Token");
	if (req.get_method() == "OPTIONS") {
		res.set_status_and_content(status_type::ok);
		return false;
	}
#endif
	return true;
}

Check::Check()
{
	//读取公钥
	if (!RSA_PUB_KEY)
	{
		std::string pubKey = "";
		ifstream ifs("public.pem");
		if (ifs.is_open())
		{
			std::string tmp;
			while (std::getline(ifs, tmp))
			{
				pubKey += tmp + "\n";
			}
			ifs.close();
		}
		RSA_PUB_KEY = std::make_unique<std::string>(pubKey);
	}
}

bool Check::before(request& req, response& res)
{
#ifdef CHECK_TOKEN
	//获取请求凭证
	string_view token = req.get_header_value("Authorization");
	if (token.empty()) {
		checkCommonSender("empty token", &res);
		return false;
	}
	//解析凭证
	string_view prefix = "Bearer ";
	if (token.find_first_of(prefix) != 0) {
		checkCommonSender("prefix error", &res);
		return false;
	}
	//1 去掉前缀
	token.remove_prefix(prefix.size());
	//2 解析凭证
	PayloadDTO payload = JWTUtil::verifyTokenByRsa(string(token), RSA_PUB_KEY->c_str());
	if (payload.getCode() != PayloadCode::SUCCESS) {
		stringstream ss;
		ss << "check fail code : " << static_cast<int>(payload.getCode());
		checkCommonSender(ss.str(), &res);
		return false;
	}
	//3 将解析数据放到请求对象中
	req.set_user_payload(nlohmann::json(payload));
	return true;
#else
	TEST_PAYLOAD_INJECTION(req);
	return true;
#endif
}

bool Check::after(request& req, response& res)
{
	std::cout << "<" << req.get_url() << "> exec finish" << std::endl;
	return true;
}
