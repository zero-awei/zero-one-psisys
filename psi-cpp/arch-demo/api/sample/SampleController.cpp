
#include "stdafx.h"
#include "SampleController.h"
#include "../../service/sample/SampleService.h"

JsonVO<PageVO<SampleVO>> SampleController::execQuerySample(const SampleQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	SampleService service;
	//查询数据
	PageVO<SampleVO> result = service.listAll(query);
	//响应结果
	return JsonVO<PageVO<SampleVO>>(result, RS_SUCCESS);
}

JsonVO<uint64_t> SampleController::execAddSample(const SampleDTO& dto)
{
	JsonVO<uint64_t> result;
	SampleService service;
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

JsonVO<uint64_t> SampleController::execModifySample(const SampleDTO& dto)
{
	SampleService service;
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

JsonVO<uint64_t> SampleController::execRemoveSample(const SampleDTO& dto)
{
	SampleService service;
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

JsonVO<uint64_t> SampleController::execRemoveById(const IntID& id)
{
	SampleDTO dto;
	dto.setId(id.getId());
	return execRemoveSample(dto);
}

JsonVO<SampleVO> SampleController::execJsonSample(const SampleDTO& dto)
{
	//构建一个测试VO
	SampleVO vo;
	vo.setId(dto.getId());
	vo.setName(dto.getName());
	vo.setAge(dto.getAge());
	vo.setSex(dto.getSex());

	//响应结果
	return JsonVO<SampleVO>(vo, RS_API_UN_IMPL);
}

JsonVO<UserVO> SampleController::execModifyUserInfo(const UserDTO& dto)
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
