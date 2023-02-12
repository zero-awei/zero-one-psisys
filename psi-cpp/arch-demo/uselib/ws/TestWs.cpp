/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:11:30
 
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
#include "TestWs.h"
#include "StringUtil.h"

// 定义一个连接对象池
std::map<std::string_view, conn_type*> conn_pool;
// 定义一个锁对象
std::mutex some_mutex;

void TestWs::addChatHandler(http_server* server)
{
	server->set_http_handler<GET, POST>("/chat/*", [](request& req, response& res) {
		// 判断content-type类型
		assert(req.get_content_type() == content_type::websocket);
		// 打开连接
		req.on(ws_open, [](request& req) {
			// 获取客户端ID
			std::string_view id = req.get_query_value("id");
			// 判断客户端对象是否存在
			std::lock_guard<std::mutex> guard(some_mutex);
			if (conn_pool.find(id) != conn_pool.end()) {
				// 关闭拒绝连接
				req.get_conn()->on_close();
				// 设置一个标记数据
				req.set_part_data("reason id");
				return;
			}
			// 添加到连接池中
			conn_pool.insert(std::make_pair(id, req.get_conn()));
			std::cout << "client(" << id << "): open connection" << std::endl;
			});
		// 接收消息
		req.on(ws_message, [](request& req) {
			// 获取消息数据
			auto part_data = req.get_part_data();
			std::string str = std::string(part_data.data(), part_data.length());
			// 解析消息 => ID::消息内容
			std::vector<string> msgs = StringUtil::split(str, "::");
			// 群发消息ID=all表示群发
			if ("all" == msgs[0])
			{
				std::lock_guard<std::mutex> guard(some_mutex);
				for (auto one : conn_pool)
				{
					// 排除自己
					if (one.second == req.get_conn())
					{
						continue;
					}
					// 发送消息
					one.second->send_ws_string(msgs[1]);
				}
			}
			// 指定发送
			else
			{
				std::lock_guard<std::mutex> guard(some_mutex);
				auto iter = conn_pool.find(msgs[0]);
				if (iter != conn_pool.end())
				{
					iter->second->send_ws_string(msgs[1]);
				}
			}
			req.get_conn()->send_ws_string("message send success");
			});
		// 出现异常
		req.on(ws_error, [](request& req) {
			// 获取客户端ID
			std::string_view id = req.get_query_value("id");
			// 处理客户端移除
			if ("reason id" != req.get_part_data())
			{
				// 打印提示信息
				std::cout << "client(" << id << "): pack error or network error" << std::endl;
				std::cout << "client(" << id << "): close connection" << std::endl;
				// 将连接对象从map中移除
				std::lock_guard<std::mutex> guard(some_mutex);
				conn_pool.erase(id);
			}
			else
			{
				// 输出客户端拒绝连接
				std::cout << "client(" << id << "): id has been used" << std::endl;
			}
			});
		}
	);
}
