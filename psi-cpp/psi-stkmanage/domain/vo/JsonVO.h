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
 * ǰ������ݶԽ����ݶ���
 */
template<class T>
class JsonVO
{
	// ״̬��
	CC_SYNTHESIZE(int, code, Code);
	// ��ʾ��Ϣ
	CC_SYNTHESIZE(string, message, Message);
	// ���ݶ���
	CC_SYNTHESIZE(T, data, Data);
public:
	JsonVO() {
		this->message = "";
	}
	JsonVO(T data, ResultStatus resultStatus) {
		this->setStatus(resultStatus); 
		this->setData(data);
	}
	// ����״̬
	void setStatus(ResultStatus resultStatus) {
		this->message = resultStatus.getMessage();
		this->code = resultStatus.getCode();
	}
	// �����ɹ���Ϣ
	void success(T data) {
		this->setStatus(RS_SUCCESS);
		this->setData(data);
	}
	// ����ʧ����Ϣ
	void fail(T data) {
		this->setStatus(RS_FAIL);
		this->setData(data);
	}
	// ��JSONת������
	friend void to_json(json& j, const JsonVO<T>& t) { // NOLINT
		j = json{ {"code", t.code}, {"message", t.message}, {"data",t.data} };
	}
};
#endif // !_JSON_VO_


