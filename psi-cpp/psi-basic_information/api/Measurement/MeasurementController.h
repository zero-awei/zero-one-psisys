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

/**
 * 基础资料计量单位模块接口
 */
class MeasurementController
{
public:
	//前端传输给后端的各种请求
	CREATE_API_FUN_QUERY_PAYLOAD(queryMeasurement, execQueryMeasurement, MeasurementQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryKidMeasuremnet, execQueryKidMeasurement, MeasurementQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryDetailMeasurement, execQueryDetailMeasurement, MeasurementQuery);
	CREATE_API_FUN_BODY(addMeasurement, execAddMeasurement, MeasurementDTO);
	CREATE_API_FUN_BODY(modifyMeasurement, execModifyMeasurement, MeasurementDTO);
	CREATE_API_FUN_BODY(removeMeasurement, execRemoveMeasurement, MeasurementQuery);
	CREATE_API_FUN_BODY_FILE(addFileMeasurements, execAddFileMeasurements, MeasurementDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExecl, execExportExecl, MeasurementQuery);

private:
	//后端传输给前端JsonVO
	//普通查询(分页查询)
	JsonVO<PageVO<MeasurementVO>> execQueryMeasurement(const MeasurementQuery& query, const PayloadDTO& payload);
	//查询指定单位子级列表
	JsonVO<MeasurementVO> execQueryKidMeasurement(const MeasurementQuery& query, const PayloadDTO& payload);
	//查询指定单位详细信息
	JsonVO<MeasurementVO> execQueryDetailMeasurement(const MeasurementQuery& query, const PayloadDTO& payload);
	//添加计量单位
	JsonVO<PageVO<MeasurementVO>> execAddMeasurement(const MeasurementDTO& dto);
	//修改计量单位
	JsonVO<PageVO<MeasurementVO>> execModifyMeasurement(const MeasurementDTO& dto);
	//删除计量单位(通过名称删除)
	JsonVO<PageVO<MeasurementVO>> execRemoveMeasurement(const MeasurementDTO& dto);
	//文件导入
	JsonVO<PageVO<MeasurementVO>> execAddFileMeasurements(const MeasurementDTO& dto);
	//文件导出
	JsonVO<string> execExportExecl(const MeasurementQuery& query, const PayloadDTO& payload);
};

#endif // _Measurement_CONTROLLER_