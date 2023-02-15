
#include "stdafx.h"
#include "QtrkController.h"
//#include "../../service/sample/SampleService.h"

JsonVO<PageVO<QueryQtrkBillListVO>> QtrkController::execQueryQtrk(const QueryQtrkBillListQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	//SampleService service;
	//查询数据
	PageVO<QueryQtrkBillListVO> result ;
	//响应结果
	return JsonVO<PageVO<QueryQtrkBillListVO>>(result, RS_SUCCESS);
}

JsonVO<uint64_t> QtrkController::execAddQtrk(const AddQtrkBillDTO& dto)
{
	JsonVO<uint64_t> result;
	//SampleService service;
	//执行数据新增
	uint64_t id=1; //= service.saveData(dto);
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

JsonVO<uint64_t> QtrkController::execModifyQtrk(const ModifyQtrkBillDTO& dto)
{
	//SampleService service;
	JsonVO<uint64_t> result;
	if (1/*service.updateData(dto)*/) {
		result.success(1/*dto.getId()*/);
	}
	else
	{
		result.fail(1/*dto.getId()*/);
	}
	return result;
}

JsonVO<uint64_t> QtrkController::execRemoveQtrk(const DeleteQtrkBillDTO& dto)
{
	//SampleService service;
	JsonVO<uint64_t> result;
	//执行数据删除
	if (1/*service.removeData(dto.getId())*/) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	//响应结果
	return result;
}
//
//JsonVO<uint64_t> SampleController::execRemoveById(const IntID& id)
//{
//	SampleDTO dto;
//	dto.setId(id.getId());
//	return execRemoveSample(dto);
//}
//
//JsonVO<SampleVO> SampleController::execJsonSample(const SampleDTO& dto)
//{
//	//构建一个测试VO
//	SampleVO vo;
//	vo.setId(dto.getId());
//	vo.setName(dto.getName());
//	vo.setAge(dto.getAge());
//	vo.setSex(dto.getSex());
//
//	//响应结果
//	return JsonVO<SampleVO>(vo, RS_API_UN_IMPL);
//}
//
JsonVO<ImportQtrkFileVO> QtrkController::execImportFileQtrk(const ImportQtrkFileDTO& dto)
{
	//构建一个测试VO
	ImportQtrkFileVO vo;
	/*vo.setNickname(dto.getNickname());
	vo.setIdCard(dto.getIdCard());
	vo.setAge(dto.getAge());*/

	//输出测试上传文件路径列表
	/*for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}*/

	//响应结果
	return JsonVO<ImportQtrkFileVO>(vo, RS_API_UN_IMPL);
}
JsonVO<ExportQtrkFileVO> QtrkController::execExportFileQtrk(const ExportQtrkFileDTO& dto)
{
	//构建一个测试VO
	ExportQtrkFileVO vo;
	/*vo.setNickname(dto.getNickname());
	vo.setIdCard(dto.getIdCard());
	vo.setAge(dto.getAge());*/

	//输出测试上传文件路径列表
	/*for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}*/

	//响应结果
	return JsonVO<ExportQtrkFileVO>(vo, RS_API_UN_IMPL);
}
