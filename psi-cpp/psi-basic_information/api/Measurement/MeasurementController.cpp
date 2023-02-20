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
#include <list>

/*
JsonVO<PageVO<MeasurementVO>> MeasurementController::execQueryMeasurement(const MeasurementQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	//MeasurementService service;
	//查询数据
	//PageVO<MeasurementVO> result = service.listAll(query);
	//响应结果
	//return JsonVO<PageVO<MeasurementVO>>(result, RS_SUCCESS);
	return JsonVO<PageVO<MeasurementVO>>();
}

JsonVO<uint64_t> MeasurementController::execAddMeasurement(const MeasurementDTO& dto)
{
	JsonVO<uint64_t> result;
	MeasurementService service;
	//执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//响应结果
	//return result;
}

JsonVO<uint64_t> MeasurementController::execModifyMeasurement(const MeasurementDTO& dto)
{
	MeasurementService service;
	JsonVO<uint64_t> result;
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	return result;
}

JsonVO<uint64_t> MeasurementController::execRemoveMeasurement(const MeasurementDTO& dto)
{
	MeasurementService service;
	JsonVO<uint64_t> result;
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

JsonVO<uint64_t> MeasurementController::execRemoveById(const IntID& id)
{
	MeasurementDTO dto;
	dto.setId(id.getId());
	return execRemoveMeasurement(dto);
}

JsonVO<MeasurementVO> MeasurementController::execJsonMeasurement(const MeasurementDTO& dto)
{
	//构建一个测试VO
	MeasurementVO vo;
	vo.setId(dto.getId());
	vo.setName(dto.getName());
	vo.setAge(dto.getAge());
	vo.setSex(dto.getSex());

	//响应结果
	return JsonVO<SampleVO>(vo, RS_API_UN_IMPL);
}

/*
JsonVO<UserVO> MeasurementController::execModifyUserInfo(const UserDTO& dto)
{
	//构建一个测试VO
	UserVO vo;
	vo.setNickname(dto.getNickname());
	vo.setIdCard(dto.getIdCard());
	vo.setAge(dto.getAge());

	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}

	//响应结果
	return JsonVO<UserVO>(vo, RS_API_UN_IMPL);
}
*/

//普通查询
JsonVO<PageVO<MeasurementVO>> MeasurementController::execQueryMeasurement(const MeasurementQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<MeasurementVO>> js;
	PageVO<MeasurementVO> data;
	list<MeasurementVO> rows;
	rows.push_back(MeasurementVO());
	rows.push_back(MeasurementVO());
	rows.push_back(MeasurementVO());
	data.setRows(rows);
	js.success(data);
	return js;
}

//查询指定单位子级列表
JsonVO<MeasurementVO> MeasurementController::execQueryKidMeasurement(const MeasurementQuery& query, const PayloadDTO& payload)
{
	JsonVO<MeasurementVO> js;
	//js.push_back(MeasurmentVO());
	js.success(MeasurementVO());
	return js;
}

//查询指定单位详细信息
JsonVO<MeasurementVO> MeasurementController::execQueryDetailMeasurement(const MeasurementQuery& query, const PayloadDTO& payload)
{
	JsonVO<MeasurementVO> js;
	//js.push_back(MeasurmentVO());
	js.success(MeasurementVO());
	return js;
}

//添加计量单位
JsonVO<PageVO<MeasurementVO>> MeasurementController::execAddMeasurement(const MeasurementDTO& dto)
{
	JsonVO<PageVO<MeasurementVO>> js;
	PageVO<MeasurementVO> data;
	list<MeasurementVO> rows;
	rows.push_back(MeasurementVO());
	rows.push_back(MeasurementVO());
	rows.push_back(MeasurementVO());
	data.setRows(rows);
	js.success(data);
	return js;
}

//修改计量单位
JsonVO<PageVO<MeasurementVO>> MeasurementController::execModifyMeasurement(const MeasurementDTO& dto)
{
	JsonVO<PageVO<MeasurementVO>> js;
	PageVO<MeasurementVO> data;
	list<MeasurementVO> rows;
	rows.push_back(MeasurementVO());
	rows.push_back(MeasurementVO());
	rows.push_back(MeasurementVO());
	data.setRows(rows);
	js.success(data);
	return js;
}

//删除计量单位(通过名称删除)
JsonVO<PageVO<MeasurementVO>> MeasurementController::execRemoveMeasurement(const MeasurementQueryDelete& dto)
{
	JsonVO<PageVO<MeasurementVO>> js;
	PageVO<MeasurementVO> data;
	list<MeasurementVO> rows;
	rows.push_back(MeasurementVO());
	rows.push_back(MeasurementVO());
	rows.push_back(MeasurementVO());
	data.setRows(rows);
	js.success(data);
	return js;
}

//文件导入
JsonVO<PageVO<MeasurementVO>> MeasurementController::execAddFileMeasurement(const MeasurementDTO& dto)
{
	JsonVO<PageVO<MeasurementVO>> js;
	PageVO<MeasurementVO> data;
	list<MeasurementVO> rows;
	rows.push_back(MeasurementVO());
	rows.push_back(MeasurementVO());
	rows.push_back(MeasurementVO());
	data.setRows(rows);
	js.success(data);
	return js;
}

//文件导出
JsonVO<string> MeasurementController::execExportExecl(const MeasurementQuery& query, const PayloadDTO& payload)
{
	JsonVO<string> js;
	//js.success();
	return js;
}
