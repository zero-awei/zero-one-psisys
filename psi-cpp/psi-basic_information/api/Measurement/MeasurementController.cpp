/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "MeasurementController.h"
#include "../../service/Measurement/MeasurementService.h"
#include "../../../lib-common/include/ExcelComponent.h"
#include "../../../lib-common/include/CharsetConvertHepler.h"
#include "FastDfsClient.h"

//普通查询(分页查询)
JsonVO<PageVO<MeasurementVO>> MeasurementController::execQueryMeasurement(const MeasurementQuery& query)
{
	//定义一个Service
	MeasurementService service;
	//查询数据
	JsonVO<PageVO<MeasurementVO>> result;
	PageVO<MeasurementVO> vr = service.listAll(query);
	result.setData(vr);
	//响应结果
	return result;
}


//查询指定单位的子级列表
JsonVO<list<MeasurementVO>> MeasurementController::execQueryKidMeasurement(const MeasurementKidQuery& query)
{
	//todo:数据校验
	if (query.getId() == "")
	{
		return JsonVO<list<MeasurementVO>>({}, RS_PARAMS_INVALID);
	}
	MeasurementService service;
	JsonVO<list<MeasurementVO>> result;
	list<MeasurementVO> rows = service.queryKidData(query);
	result.setData(rows);
	return result;
}

//查询指定单位的详细信息
JsonVO<MeasurementVO> MeasurementController::execQueryDetailMeasurement(const MeasurementAppQuery& query)
{
	//todo:数据校验
	if (query.getId() == "")
	{
		return JsonVO<MeasurementVO>({}, RS_PARAMS_INVALID);
	}
	JsonVO<MeasurementVO> result;
	MeasurementService service;
	MeasurementVO vo = service.queryDetailData(query);
	result.success(vo);
	return result;
}

//新增计量单位
JsonVO<MeasurementVO> MeasurementController::execAddMeasurement(const MeasurementDTO& dto, const PayloadDTO& payload)
{
	//参数校验
	if (dto.getName().empty() ||
		dto.getSymbol().empty() ||
		dto.getFactor() <= 0 ||
		(dto.getIs_enabled() != CharsetConvertHepler::ansiToUtf8("是")
			&& dto.getIs_enabled() != CharsetConvertHepler::ansiToUtf8("否")))
	{
		return JsonVO<MeasurementVO>({}, RS_PARAMS_INVALID);
	}

	//执行数据业务
	JsonVO<MeasurementVO> result;
	MeasurementService service;
	MeasurementVO vo = service.save(dto, payload);
	if (vo.getCreate_time().empty())
	{
		result.fail(vo);
	}
	else
	{
		result.success(vo);
	}
	//响应结果
	return result;
}

//修改计量单位
JsonVO<MeasurementVO> MeasurementController::execModifyMeasurement(const MeasurementModifyDTO& dto, const PayloadDTO& payload)
{
	//参数校验
	if (dto.getName().empty() ||
		dto.getSymbol().empty() ||
		dto.getFactor() <= 0 ||
		(dto.getIs_enabled() != CharsetConvertHepler::ansiToUtf8("是")
			&& dto.getIs_enabled() != CharsetConvertHepler::ansiToUtf8("否")))
	{
		return JsonVO<MeasurementVO>({}, RS_PARAMS_INVALID);
	}
	MeasurementService service;
	MeasurementVO vo = service.updateData(dto, payload);
	JsonVO<MeasurementVO> result;
	result.setData(vo);
	result.success(vo);
	return result;
}

//删除计量单位
JsonVO<string> MeasurementController::execRemoveMeasurement(const MeasurementDeleteDTO& dto)
{
	MeasurementService service;
	JsonVO<string> result;
	result.setData(dto.getId());
	//执行数据删除
	if (service.removeData(dto.getId())) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	//响应结果
	return result;
}

//文件导入
JsonVO<bool> MeasurementController::execImportFileMeasurement(const MeasurementDTO& dto, const PayloadDTO& payload)
{
	JsonVO<bool> result;
	MeasurementService service;
	bool flag = service.saveFileData(dto, payload);
	if (flag)
	{
		result.success(true);
	}
	else
	{
		result.fail(false);
	}
	return result;
}

//文件导出
JsonVO<string> MeasurementController::execExportExcel(const StringIDs& dto)
{
	MeasurementService service;
	// 创建excel表
	string filename = "./public/bas_Unit/bas_Unit.xlsx";
	vector<vector<string>> data;
	data.emplace_back(vector<std::string>({
		CharsetConvertHepler::ansiToUtf8("名称"),
		CharsetConvertHepler::ansiToUtf8("符号"),
		CharsetConvertHepler::ansiToUtf8("是否基准"),
		CharsetConvertHepler::ansiToUtf8("基准单位"),
		CharsetConvertHepler::ansiToUtf8("换算系数"),
		CharsetConvertHepler::ansiToUtf8("是否启用"),
		}));
	// 查询数据
	if (!service.getData(dto, data))
		return JsonVO<string>(CharsetConvertHepler::ansiToUtf8("导出失败"), RS_FAIL);
	string sheetname = CharsetConvertHepler::ansiToUtf8("计算单位");
	ExcelComponent excel;
	excel.writeVectorToFile(filename, sheetname, data);
	// 上传到文件服务器
#ifdef LINUX
	FastDfsClient client("conf/client.conf", 3);
#else
	FastDfsClient client("1.15.240.108");

#endif // #ifdef LINUX
	filename = client.uploadFile(filename);
	// TODO:数据校验
	if (filename.empty())
	{
		JsonVO<string> result(filename, RS_FAIL);
		return result;
	}
	else
	{
		filename = "http://1.15.240.108:8888/" + filename;
		JsonVO<string> result(filename, RS_SUCCESS);
		return result;
	}
}