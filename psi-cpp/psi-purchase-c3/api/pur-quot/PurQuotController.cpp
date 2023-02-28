#include "stdafx.h"
#include "PurQuotController.h"
#include "../../service/pur-quot/PurQuotService.h"

#if 0
开发日志2023年2月18日15:34 : 30：成功实现将部分字段（id、bill_no、bill_date、qty）上传至数据库
预计开发功能：
①在Controller中，检查是否收到传入数据库的必传字段id、bill_no、bill_date
②检查是否收到业务的必传字段....（罗列出必传字段）
②新增附件上传功能
③新增对明细列表的获取和上传，并检查明细列表是否有必传字段
④完成删除报价功能
⑤完成修改报价状态（关闭、作废、反关闭）功能
（需要判定当且报价状态，来看是否可以关闭 / 反关闭，那这个从数据库中获取报价状态内容的工作，是我们这个接口负责吗？前端如何传入修改报价状态的字段？
我们可以用其他不变，通过变得那个来进行整体判断，这样的变化是否符合业务）
⑥APIPost的批注

价值排序
①实现明细列表的上传———————新增PurQuotDetailDTO，并在service.cpp和dao.cpp中添加处理明细的代码——2023年2月21日18:13 : 24，完成
②实现新增附件的上传功能—————Controller.cpp中实现
③实现字段检查功能————————Controller.cpp中实现
④实现修改报价状态功能——————Controller.cpp, service.cpp, dao.cpp中实现————2023年2月21日21 : 15 : 40，实现
⑤实现删除功能——————————Controller.cpp, service.cpp, dao.cpp中实现————2023年2月21日18 : 46 : 08，实现
⑥APIPost的批注——————————APIPost.exe

2023年2月20日14:52 : 45
我们注意到，在api、domain / do、domain / vo中都有user文件夹，用于复杂数据上传，
我们之前只注意到了domain / do里的内容，AddDepartDTO、AddDepartMoreDTO
而忽略了api、domain / vo中DepartController，AddDepartVO、AddDepartMoreVO中的内容
现在，我们需要利用好这部分的内容，来改造过去的新增报价的代码



#endif

//添加供应报价
JsonVO<uint64_t> PurQuotController::execAddPurQuot(const AddPurQuotDTO& dto, const PayloadDTO& payload)
{
	//数据校验没有
	JsonVO<uint64_t> result;
	PurQuotService service;
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	return result;
}

//修改供应报价
JsonVO<uint64_t> PurQuotController::execModPurQuot(const ModPurQuotDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PurQuotService service;
	uint64_t id = service.updateData(dto, payload);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	return result;
}

//删除供应报价
JsonVO<uint64_t> PurQuotController::execDelPurQuot(const DelPurQuotDTO& dto)
{
	PurQuotService service;
	JsonVO<uint64_t> result;
	//执行数据删除
	uint64_t id = service.removeData(dto);

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

//修改报价状态——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execPurQuotModBillStatus(const PurQuotModBillStatusDTO& dto, const PayloadDTO& payload)
{
	PurQuotService service;
	JsonVO<uint64_t> result;
	//执行报价状态修改
	uint64_t id = service.UpdateDataBillStatus(dto);

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


//导出
JsonVO<PurQuotExportVO> PurQuotController::execPurQuotExport(const PurQuotExportQuery& query, const PayloadDTO& payload)
{
	//暂未完成数据校验
	PurQuotService service;
	PurQuotExportVO result = service.listPurQuotExportVO(query);
	std::cout << result.getFile_name() << std::endl;
	return JsonVO<PurQuotExportVO>(result, RS_SUCCESS);
}

//导入
uint64_t PurQuotController::execPurQuotInto(const PurQuotIntoDTO& dto)
{
	PurQuotService service;
	uint64_t result = service.updatePurQuotInto(dto);

	return result;
}

//查询单据列表
JsonVO<PageVO<PurQuotFindBillVO>> PurQuotController::execQueryPurQuotFindBill(const PurQuotFindBillQuery& query, const PayloadDTO& payload) {
	//暂未开始数据校验

	//定义一个Service
	PurQuotService service;
	//构建返回对象
	PageVO<PurQuotFindBillVO> result	= service.listPurQuotFindBillVO(query);
	//响应结果
	return JsonVO<PageVO<PurQuotFindBillVO>>(result, RS_SUCCESS);
}



//查询指定单据列表
JsonVO<PurQuotFindDetailBillVO> PurQuotController::execQueryPurQuotFindDetailBill(const PurQuotFindDetailBillQuery& query, const PayloadDTO& payload) {
	PurQuotFindDetailBillVO result;
	//暂时未进行数据校验
	if(query.getBill_no() == "") return JsonVO<PurQuotFindDetailBillVO>(result, RS_PARAMS_INVALID);
	PurQuotService service;
	result = service.getPurQuotFindDetailBillVO(query);
	//响应结果
	return JsonVO<PurQuotFindDetailBillVO>(result, RS_SUCCESS);
}

//询价单列表
JsonVO<list<PurQuotListVO>> PurQuotController::execQueryPurQuotList(const PurQuotListQuery& query, const PayloadDTO& payload)
{
	//构建返回对象
	list<PurQuotListVO> result;
	//数据校验
	if(query.getBill_no() == "") return JsonVO<list<PurQuotListVO>>(result, RS_PARAMS_INVALID);

	//数据校验成功,返回对应的对象
	PurQuotService service;	
	result = service.listPurQuotListVO(query);
	return JsonVO<list<PurQuotListVO>>(result, RS_SUCCESS);
}
//询价单分录列表
JsonVO<list<PurQuotDividedListVO>> PurQuotController::execQueryPurQuotDividedList(const PurQuotDividedListQuery& query, const PayloadDTO& payload)
{
	//构建返回对象
	list<PurQuotDividedListVO> result;
	//数据校验
	if(query.getBill_no() == "") return JsonVO<list<PurQuotDividedListVO>>(result, RS_PARAMS_INVALID);

	//数据校验成功,返回对应的对象
	PurQuotService service;
	result = service.listPurQuotDividedListVO(query);
	return JsonVO<list<PurQuotDividedListVO>>(result, RS_SUCCESS);
}

