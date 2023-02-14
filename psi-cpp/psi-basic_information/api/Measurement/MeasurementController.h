#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _Measurement_CONTROLLER_
#define _Measurement_CONTROLLER_

#include "../../domain/query/Measurement/MeasurementQuery.h"
#include "../../domain/dto/Measurement/MeasurementDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/Measurement/MeasurementVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
//#include "../../domain/dto/user/UserDTO.h"
//#include "../../domain/vo/user/UserVO.h"

/**
 * 基础资料计量单位模块接口
 */
class SampleController
{
public:
	//前端传输给后端的各种请求
	CREATE_API_FUN_QUERY_PAYLOAD(queryMeasurement, execQueryMeasurement, MeasurementQuery);
	CREATE_API_FUN_BODY(addMeasurement, execAddMeasurement, MeasurementDTO);
	CREATE_API_FUN_BODY(modifyMeasurement, execModifyMeasurement, MeasurementDTO);
	CREATE_API_FUN_BODY(removeMeasurement, execRemoveMeasurement, MeasurementDTO);
	CREATE_API_FUN_JSON(jsonMeasurement, execJsonMeasurement, MeasurementDTO);
	CREATE_API_FUN_BODY_FILE(jsonMeasurement, execJsonMeasurement, MeasurementDTO);
	//CREATE_API_FUN_BODY_FILE(modifyUserInfo, execModifyUserInfo, UserDTO);
	//CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);
private:
	//后端传输给前端JsonVO
	//普通查询(分页查询)
	JsonVO<PageVO<MeasurementVO>> execQueryMeasurement(const MeasurementQuery& query, const PayloadDTO& payload);
	//添加计量单位(只一个数据)
	JsonVO<uint64_t> execAddMeasurement(const MeasurementDTO& dto);
	//修改计量单位
	JsonVO<uint64_t> execModifyMeasurement(const MeasurementDTO& dto);
	//删除计量单位(通过名称删除)
	JsonVO<uint64_t> execRemoveMeasurement(const MeasurementDTO& dto);
	//JsonVO<uint64_t> execRemoveById(const IntID& id);
	//JSON提交(单个数据)
	JsonVO<MeasurementVO> execJsonMeasurement(const MeasurementDTO& dto);
	//上传文件
	JsonVO<MeasurementVO> execJsonMeasurement(const MeasurementDTO& dto);
	//JsonVO<MeasurementVO> execModifyUserInfo(const MeasurementDTO& dto);
};

#endif // _Measurement_CONTROLLER_