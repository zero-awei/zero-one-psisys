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
#ifndef _MEASUREMENT_CONTROLLER_
#define _MEASUREMENT_CONTROLLER_

#include "../../domain/query/Measurement/MeasurementQuery.h"
#include "../../domain/dto/Measurement/MeasurementDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/dto/FileDTO.h"
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
	CREATE_API_FUN_QUERY(queryMeasurement, execQueryMeasurement, MeasurementQuery);
	CREATE_API_FUN_QUERY(queryKidMeasurement, execQueryKidMeasurement, MeasurementKidQuery);
	CREATE_API_FUN_QUERY(queryDetailMeasurement, execQueryDetailMeasurement, MeasurementAppQuery);
	CREATE_API_FUN_BODY_PAYLOAD(addMeasurement, execAddMeasurement, MeasurementDTO);
	CREATE_API_FUN_BODY_PAYLOAD(modifyMeasurement, execModifyMeasurement, MeasurementModifyDTO);
	CREATE_API_FUN_BODY(removeMeasurement, execRemoveMeasurement, MeasurementDeleteDTO);
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addFileMeasurement, execImportFileMeasurement, MeasurementDTO);
	CREATE_API_FUN_JSON(exportExecl, execExportExcel, StringIDs);
private:
	//后端传输给前端JsonVO
	//普通查询(分页查询)
	JsonVO<PageVO<MeasurementVO>> execQueryMeasurement(const MeasurementQuery& query);
	//查询指定单位子级列表
	JsonVO<list<MeasurementVO>> execQueryKidMeasurement(const MeasurementKidQuery& query);
	//查询指定单位详细信息
	JsonVO<MeasurementVO> execQueryDetailMeasurement(const MeasurementAppQuery& query);
	//新增计量单位
	JsonVO<MeasurementVO> execAddMeasurement(const MeasurementDTO& dto, const PayloadDTO& payload);
	//新增计量单位的子级计量单位
	//JsonVO<MeasurementVO> execAddKidMeasurement(const MeasurementKidDTO& dto, const PayloadDTO& payload);
	//修改计量单位
	JsonVO<MeasurementVO> execModifyMeasurement(const MeasurementModifyDTO& dto, const PayloadDTO& payload);
	//删除计量单位
	JsonVO<string> execRemoveMeasurement(const MeasurementDeleteDTO& dto);
	//文件导入
	//JsonVO<string> execImportFileMeasurement(const MeasurementImportFileDTO& dto, const PayloadDTO& payload);
	JsonVO<bool> execImportFileMeasurement(const MeasurementDTO& dto, const PayloadDTO& payload);
	//文件导出
	JsonVO<string> execExportExcel(const StringIDs& dto);
};

#endif // !_MEASUREMENT_CONTROLLER_