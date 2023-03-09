#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:24:25

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
#ifndef _JSON_VO_
#define _JSON_VO_

#include "../GlobalInclude.h"
#include "Message.h"


/**
 * 前后端数据对接数据对象
 */
template<class T>
class JsonVO
{
	// 状态码
	CC_SYNTHESIZE(int, code, Code);
	// 提示消息
	CC_SYNTHESIZE(string, message, Message);
	// 数据对象
	CC_SYNTHESIZE(T, data, Data);
public:
	JsonVO() {
		this->message = "";
	}
	JsonVO(T data, ResultStatus resultStatus) {
		this->setStatus(resultStatus);
		this->setData(data);
	}
	// 设置状态
	void setStatus(ResultStatus resultStatus) {
		this->message = resultStatus.getMessage();
		this->code = resultStatus.getCode();
	}
	// 构建成功消息
	void success(T data) {
		this->setStatus(RS_SUCCESS);
		this->setData(data);
	}
	// 构建失败消息
	void fail(T data) {
		this->setStatus(RS_FAIL);
		this->setData(data);
	}
	// 绑定JSON转换方法
	friend void to_json(json& j, const JsonVO<T>& t) { // NOLINT
		j = json{ {"code", t.code}, {"message", t.message}, {"data",t.data} };
	}
};
#endif // !_JSON_VO_


