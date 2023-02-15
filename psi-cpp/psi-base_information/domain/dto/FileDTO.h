#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:27:06

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
#ifndef _FILEDTO_H_
#define _FILEDTO_H_

#include "../GlobalInclude.h"
#include <list>

/**
 * 定义一个文件上传传输数据模型
 */
class FileDTO
{
private:
protected:
	// 上传文件路径列表
	CC_SYNTHESIZE_GET(std::list<std::string>, files, Files);
public:
	friend void from_json(const json& j, FileDTO& t) // NOLINT
	{

	}
	// 添加文件上传路径
	void addFile(std::string file) {
		files.push_back(file);
	}
};

#endif // _FILEDTO_H_