#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 16:03:04
 
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
#ifndef _KAFKACLIENT_H_
#define _KAFKACLIENT_H_
#include <string>
#include <iostream>
#include <mutex>
#include "librdkafka/rdkafkacpp.h"

#if LINUX
#include <unistd.h>
#include <functional>
#endif

/**
 * 定义一个Kafka客户端，来封装常用操作。
 * 参考链接：
 * https://github.com/edenhill/librdkafka/tree/v1.8.2/examples
 * https://docs.confluent.io/kafka-clients/librdkafka/current/overview.html
 */
class KafkaClient
{
public:
	/**
	 * 消息交付回调
	 */
	class DeliveryReportCb : public RdKafka::DeliveryReportCb {
	private:
		std::function<void(RdKafka::Message&)> cf;
	public:
		explicit DeliveryReportCb(std::function<void(RdKafka::Message&)> cf);
		void dr_cb(RdKafka::Message& message) override;
	};

	/**
	 * 消费后台事件处理
	 */
	class ConsumerEventCb : public RdKafka::EventCb {
	public:
		void event_cb(RdKafka::Event& event) override;
	};

	/**
	 * 消费消息监听器
	 */
	class ConsumerMessageListener {
	public:
		// 订阅主题名称
		std::string topic;
		// 接收消息
		virtual void receiveMessage(std::string payload) = 0;
	};
private:
	// 服务器节点
	std::string m_brokers;
	// 分组ID
	std::string m_groupId;
	// 当前发送消息的主题
	std::string m_topic;
	// 生产者对象
	RdKafka::Producer* m_producer;
	// 消费者对象
	RdKafka::KafkaConsumer* m_consumer;
	// 接收消息事件通知集合
	std::vector<ConsumerMessageListener*> m_listeners;
	// 定义一个事件回调对象
	ConsumerEventCb m_ex_event_cb;
	// 是否接受消息
	bool isRevMessage;
	// 定义一个线程锁
	std::mutex lock;
	// 处理消费消息状态
	void msg_consume(RdKafka::Message* message);
public:
	//************************************
	// Method:    KafkaClient
	// FullName:  KafkaClient::KafkaClient
	// Access:    public 
	// Returns:   
	// Qualifier: 构造初始化
	// Parameter: const std::string & brokers 服务器节点，格式如：host1:port,host2:prot2
	// Parameter: const std::string & groupId 消费组名称，默认值cpp-kafka
	//************************************
	explicit KafkaClient(const std::string& brokers, const std::string& groupId = "cpp-kafka");
	// 析构释放资源
	~KafkaClient();
	//************************************
	// Method:    productMsg
	// FullName:  KafkaClient::productMsg
	// Access:    public 
	// Returns:   bool 生产成功返回true
	// Qualifier: 生产消息
	// Parameter: const std::string & topic 主题
	// Parameter: const std::string & message 消息内容
	// Parameter: DeliveryReportCb * cb 消息交付回调对象,默认值为nullptr
	//************************************
	bool productMsg(const std::string& topic, const std::string& message, DeliveryReportCb* cb = nullptr);
	//************************************
	// Method:    subscribe
	// FullName:  KafkaClient::subscribe
	// Access:    public 
	// Returns:   bool 订阅成功返回true
	// Qualifier: 订阅主题，注意：同一个KafkaClient对象只能订阅一次，后续订阅将无效
	// Parameter: const std::vector<std::string> & topics 主题列表
	//************************************
	bool subscribe(const std::vector<std::string>& topics);
	//************************************
	// Method:    unsubscribe
	// FullName:  KafkaClient::unsubscribe
	// Access:    public 
	// Returns:   void
	// Qualifier: 取消订阅
	//************************************
	void unsubscribe();
	//************************************
	// Method:    addListener
	// FullName:  KafkaClient::addListener
	// Access:    public 
	// Returns:   void
	// Qualifier: 添加订阅消息处理监听者
	// Parameter: ConsumerMessageListener * listener 监听者对象
	//************************************
	void addListener(ConsumerMessageListener* listener);
	//************************************
	// Method:    removeListener
	// FullName:  KafkaClient::removeListener
	// Access:    public 
	// Returns:   void
	// Qualifier: 移除订阅消息处理监听者
	// Parameter: ConsumerMessageListener * listener 监听者对象
	//************************************
	void removeListener(ConsumerMessageListener* listener);
};

// 发布对象消息，这里会将对象转换成Json字符串
#define KC_PUBLISH_OBJ_MSG(__VAR_RES__, __KAFKA_CLIENT__, __TOPIC__, __DATA_OBJ__, __CB_OBJ__) \
nlohmann::json jobj(__DATA_OBJ__); \
bool __VAR_RES__ = __KAFKA_CLIENT__->productMsg(__TOPIC__, jobj.dump(), __CB_OBJ__);

// 接收消息，将Json字符串转换成对象
#define KC_RECEIVER_MSG_CONVERT(__VAR_OBJ__, __TYPE__, __PAYLOAD__) \
nlohmann::json jobj = nlohmann::json::parse(__PAYLOAD__); \
__TYPE__ __VAR_OBJ__ = jobj.get<__TYPE__>();

#endif // _KAFKACLIENT_H_
