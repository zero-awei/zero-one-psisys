#include "stdafx.h"
#include "BasMaterialController.h"
#include <service/BasMaterial/BasMaterialService.h>

//普通查询数据
JsonVO<PageVO<BasMaterialVO>> execQueryBasMaterial(const BasMaterialQuery& query, const PayloadDTO& payload) {

	//查询数据
	PageVO<BasMaterialVO> result;
	//响应结果
	return JsonVO<PageVO<BasMaterialVO>>(result, RS_SUCCESS);
}
//查看指定物料详情信息，即上述所有信息
JsonVO<BasMaterialVO> execQueryDetail(const BasMaterialQuery& query, const PayloadDTO& payload) {

	JsonVO <BasMaterialVO> result;
	return result;
}
//新增数据
JsonVO<BasMaterialVO> execAddBasMaterial(const BasMaterialDTO& dto) {
	JsonVO <BasMaterialVO> result;
	return result;
}
//修改数据
JsonVO<BasMaterialVO> execModifyBasMaterial(const BasMaterialDTO& dto) {
	JsonVO <BasMaterialVO> result;
	return result;
}
//删除数据
JsonVO<BasMaterialVO> execRemoveBasMaterial(const BasMaterialDTO& dto) {
	JsonVO <BasMaterialVO> result;
	return result;
}
//导入
JsonVO<PageVO<BasMaterialVO>> execImportBasMaterial(const BasMaterialDTO& dto) {
	//查询数据
	PageVO<BasMaterialVO> result;
	//响应结果
	return JsonVO<PageVO<BasMaterialVO>>(result, RS_SUCCESS);
}
//导出
JsonVO<string> execExportExecl(const BasMaterialQuery& query, const PayloadDTO& payload) {
	JsonVO <string> result;
	return result;
}


JsonVO<PageVO<BasMaterialVO>> BasMaterialController::execQueryBasMaterial(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	return JsonVO<PageVO<BasMaterialVO>>();
}

JsonVO<BasMaterialVO> BasMaterialController::execQueryDetail(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	return JsonVO<BasMaterialVO>();
}

JsonVO<BasMaterialVO> BasMaterialController::execAddBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<BasMaterialVO>();
}

JsonVO<BasMaterialVO> BasMaterialController::execModifyBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<BasMaterialVO>();
}

JsonVO<BasMaterialVO> BasMaterialController::execRemoveBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<BasMaterialVO>();
}

JsonVO<PageVO<BasMaterialVO>> BasMaterialController::execImportBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<PageVO<BasMaterialVO>>();
}

JsonVO<string> BasMaterialController::execExportExecl(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	return JsonVO<string>();
}
*/
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
JsonVO<PageVO<BasMaterialVO>> BasMaterialController::execQueryBasMaterial(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	BasMaterialService service;
	//查询数据
	PageVO<BasMaterialVO> result = service.listAll(query);
	//响应结果
	return JsonVO<PageVO<BasMaterialVO>>(result, RS_SUCCESS);
}
JsonVO<BasMaterialVO> BasMaterialController::execQueryDetail(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	BasMaterialService service;
	//查询数据
	BasMaterialVO result = service.getData(query);
	//响应结果
	return JsonVO<BasMaterialVO>(result, RS_SUCCESS);
	
}
JsonVO<uint64_t> BasMaterialController::execAddBasMaterial(const BasMaterialDTO& dto)
{
	JsonVO<uint64_t> result;
	BasMaterialService service;
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
	return result;
}

////修改数据
//JsonVO<uint64_t> BasMaterialController::execModifyBasMaterial(const BasMaterialDTO& dto)
//{
//	BasMaterialService service;
//	JsonVO<uint64_t> result;
//	if (service.updateData(dto)) {
//		result.success(dto.getId());
//	}
//	else
//	{
//		result.fail(dto.getId());
//	}
//	return result;
//}
JsonVO<uint64_t> BasMaterialController::execModifyBasMaterial(const BasMaterialDTO& dto)
{
	BasMaterialService service;
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

//删除
JsonVO<uint64_t> BasMaterialController::execRemoveBasMaterial(const BasMaterialDTO& dto)
{
	BasMaterialService service;
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

JsonVO<uint64_t> BasMaterialController::execRemoveById(const IntID& id)
{
	BasMaterialDTO dto;
	dto.setId(id.getId());
	return execRemoveBasMaterial(dto);
}

JsonVO<PageVO<BasMaterialVO>> BasMaterialController::execImportBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<PageVO<BasMaterialVO>>();
}

JsonVO<string> BasMaterialController::execExportExecl(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	return JsonVO<string>();
}
//问题：文件导入，导出怎么实现？？

//JsonVO<BasMaterialVO> BasMaterialController::execJsonBasMaterial(const BasMaterialDTO& dto)
//{
//	//构建一个测试VO
//	BasMaterialVO vo;
//	vo.setId(dto.getId());
//	vo.setName(dto.getName());
//	vo.setAge(dto.getAge());
//	vo.setSex(dto.getSex());
//
//	//响应结果
//	return JsonVO<BasMaterialVO>(vo, RS_API_UN_IMPL);
//}

//JsonVO<UserVO> BasMaterialController::execModifyUserInfo(const UserDTO& dto)
//{
//	//构建一个测试VO
//	UserVO vo;
//	vo.setNickname(dto.getNickname());
//	vo.setIdCard(dto.getIdCard());
//	vo.setAge(dto.getAge());
//
//	//输出测试上传文件路径列表
//	for (auto file : dto.getFiles()) {
//		std::cout << "path " << file << std::endl;
//	}
//
//	//响应结果
//	return JsonVO<UserVO>(vo, RS_API_UN_IMPL);
//}
