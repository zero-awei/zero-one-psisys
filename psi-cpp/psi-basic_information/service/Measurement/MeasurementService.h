#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _MEASUREMENT_SERVICE_
#define _MEASUREMENT_SERVICE_
#include <list>
#include "../../domain/vo/measurement/MeasurementVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/query/measurement/MeasurementQuery.h"
#include "../../domain/dto/Measurement/MeasurementDTO.h"
#include "../../../lib-http/include/JWTUtil.h"

/**
 * 计量单位服务实现
 */
class MeasurementService
{
public:
	// 分页查询所有数据
	PageVO<MeasurementVO> listAll(const MeasurementQuery& query);
	//查询指定单位的子级列表
	list<MeasurementVO> queryKidData(const MeasurementKidQuery& query);
	//查询指定单位的详细信息
	MeasurementVO queryDetailData(const MeasurementAppQuery& query);
	// 新增记录单位
	MeasurementVO save(const MeasurementDTO& dto, const PayloadDTO& payload);
	// 新增计量单位
	string saveData(const MeasurementDTO& dto, const PayloadDTO& payload);
	// 新增计量单位的子级计量单位
	string saveKidData(const MeasurementDTO& dto, const PayloadDTO& payload);
	// 修改数据
	MeasurementVO updateData(const MeasurementModifyDTO& dto, const PayloadDTO& payload);
	//删除数据
	bool removeData(const string& id);
	//文件导入
	bool saveFileData(const MeasurementDTO& dto, const PayloadDTO& payload);
	//文件导出
	bool getData(const StringIDs& dto, vector<vector<string>>& data);
};

#endif // !_Measurement_SERVICE_