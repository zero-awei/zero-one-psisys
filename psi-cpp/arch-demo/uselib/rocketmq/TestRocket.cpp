/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:15:07
 
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
#include "TestRocket.h"
#include "domain/dto/sample/SampleDTO.h"

TestRocket::TestRocket()
{
	this->client = nullptr;
	this->cb = nullptr;
}

TestRocket::~TestRocket()
{
	if (client)
	{
		client->unsubscribe();
	}
}

void TestRocket::testRocket()
{
	// 创建客户端
	client = make_shared<RocketClient>("192.168.220.128:9876");
	// 创建发送消息回调
	cb = make_shared<RocketClient::RSendCallback>([](SendStatus staus)
		{
			cout << "RSendCallback send status: " << staus << endl;
		});
	
	// 测试开启订阅
	client->subscribe("hello");
	client->addListener(this);

	// 定义消息对象
	SampleDTO dto;
	dto.setName("cat");
	dto.setSex("man");
	dto.setAge(10);
	// 发送消息
	dto.setId(1);
	RC_PUBLISH_OBJ_MSG_ASYNC(client, "hello", dto, cb.get());
	dto.setId(2);
	RC_PUBLISH_OBJ_MSG_ASYNC(client, "hello", dto, nullptr);
	dto.setId(3);
	RC_PUBLISH_OBJ_MSG_SYNC(res1, client, "hello", dto);
	cout << "sync send result: " << res1 << endl;
}

void TestRocket::receiveMessage(std::string payload)
{
	RC_RECEIVER_MSG_CONVERT(dto, SampleDTO, payload);
	cout << "receiveMessage: " << dto.getId() << "-" << dto.getName() << "-" << dto.getSex() << "-" << dto.getAge() << endl;
}
