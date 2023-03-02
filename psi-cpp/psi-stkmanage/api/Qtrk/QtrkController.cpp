
#include "stdafx.h"
#include "QtrkController.h"
#include"service/Qtrk/QtrkService.h"
//#include "../../service/sample/SampleService.h"

JsonVO<PageVO<QueryQtrkBillListVO>> QtrkController::execQueryQtrk(const QueryQtrkBillListQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	//SampleService service;
	//查询数据
	PageVO<QueryQtrkBillListVO> data;
	list<QueryQtrkBillListVO> rows;
	rows.push_back(QueryQtrkBillListVO());
	rows.push_back(QueryQtrkBillListVO());
	rows.push_back(QueryQtrkBillListVO());
	data.setRows(rows);
	//响应结果
	return JsonVO<PageVO<QueryQtrkBillListVO>>(data, RS_SUCCESS);
}

JsonVO<PageVO<QueryQtrkBillDetailsVO>> QtrkController::execQueryDetailsQtrk(const QueryQtrkBillDetailsQuery& query, const PayloadDTO& payload)
{
	//定义一个Service
	//SampleService service;
	//查询数据
	PageVO<QueryQtrkBillDetailsVO> data;
	list<QueryQtrkBillDetailsVO> rows;
	rows.push_back(QueryQtrkBillDetailsVO());
	rows.push_back(QueryQtrkBillDetailsVO());
	rows.push_back(QueryQtrkBillDetailsVO());
	data.setRows(rows);
	//响应结果
	return JsonVO<PageVO<QueryQtrkBillDetailsVO>>(data, RS_SUCCESS);
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
	QtrkService cs;
	JsonVO<uint64_t> result;

	if (cs.updataBillStatus(dto)) {
		result.success(1);
	}
	else
	{
		result.fail(0);
	}
	return result;
}

JsonVO<uint64_t> QtrkController::execRemoveQtrk(const DeleteQtrkBillDTO& dto)
{
	JsonVO<uint64_t> result;
	//执行数据删除
	QtrkService cs;

	if (cs.deleteBill(dto)) {
		result.success(1);
	}
	else
	{
		result.fail(0);
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
JsonVO<uint64_t> QtrkController::execImportFileQtrk(const ImportQtrkFileDTO& dto)
{
	//JsonVO<string> result;
	//	//构建一个测试VO
	//	//输出测试上传文件路径列表
	//	for (auto file : dto.getFiles()) {
	//		std::cout << "path " << file << std::endl;
	//	}

	//	
		//响应结果
		return JsonVO<uint64_t>();
}
JsonVO<std::string> QtrkController::execExportFileQtrk()
{
	
	//return JsonVO<std::string>();
	


	//响应结果

	return JsonVO<string>();
}
