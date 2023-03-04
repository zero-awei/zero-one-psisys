#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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

#ifndef _Measurement_DO_
#define _Measurement_DO_
#include "../DoInclude.h"
#include <string>
using namespace std;

/**
 * 数据库实体类
 */
class MeasurementDO
{
	// pid
	CC_SYNTHESIZE(string, pid, Pid);
	//是否有子级列表
	CC_SYNTHESIZE(uint64_t, has_child, Has_child);
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 符号
	CC_SYNTHESIZE(string, symbol, Symbol);
	// 换算系数
	CC_SYNTHESIZE(double, factor, Factor);
	// 启用
	CC_SYNTHESIZE(int, is_enabled, Is_enabled);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 创建人
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	// 修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
public:
	/*
	MeasurementDO() {
		id = "";
		name = "";
		symbol = "";
		factor = 1;
		is_enabled = "";		
		create_time = "";
		create_by = "";
		update_time = "";
		update_by = "";
	}
	*/
};

//导入文件DO
class MeasurementImportFileDO
{
protected:
	// 导入信息
	list<MeasurementDO> import;
public:
	const list<MeasurementDO>& getImport() const { return import; }
	void addImportItem(MeasurementDO doObj) { import.push_back(doObj); }
};

//导出文件DO
class StringIDsDO
{
	// Id
	CC_SYNTHESIZE(std::list<std::string>, ids, Ids);
};

#endif // !_Measurement_DO_
