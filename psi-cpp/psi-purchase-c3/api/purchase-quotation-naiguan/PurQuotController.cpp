#include "PurQuotController.h"

//#include "../../service/purchase-quotation-naiguan/PurQuotService.h"


//添加供应报价——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execAddPurQuot(const PurQuotDTO& dto)
{
	JsonVO<uint64_t> result;
	/*
//暂时别动这部分注释！！！！！！！！！！！！
//解释：这是定义接口的时候，参考Sample的案例，没有实现，仅用于APIPost测试
//DTO这里，还没有写默认构造函数，因此getId()没有值
//另外，Servie部分还没有写，因此没有SampleService类，无法做service.updateData(dto)的条件判断（虽然可以用其他方式替代）
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
	*/
	return result;
}

//修改供应报价——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execModPurQuot(const PurQuotDTO& dto)
{
	JsonVO<uint64_t> result;
	/*
//暂时别动这部分注释！！！！！！！！！！！！
//解释：这是定义接口的时候，参考Sample的案例，没有实现，仅用于APIPost测试
//DTO这里，还没有写默认构造函数，因此getId()没有值
//另外，Servie部分还没有写，因此没有SampleService类，无法做service.updateData(dto)的条件判断（虽然可以用其他方式替代）

	SampleService service;
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	*/
	return result;
}

//删除供应报价——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execDelPurQuot(const PurQuotDTO& dto)
{
	JsonVO<uint64_t> result;
	/*
//暂时别动这部分注释！！！！！！！！！！！！
//解释：这是定义接口的时候，参考Sample的案例，没有实现，仅用于APIPost测试
//DTO这里，还没有写默认构造函数，因此getId()没有值
//另外，Servie部分还没有写，因此没有SampleService类，无法做service.updateData(dto)的条件判断（虽然可以用其他方式替代）
	SampleService service;
	//执行数据删除
	if (service.removeData(dto.getId())) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	//响应结果
	*/
	return result;
}

//修改报价状态——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execPurQuotModBillStatus(const PurQuotDTO& dto)
{
	JsonVO<uint64_t> result;
	/*
//暂时别动这部分注释！！！！！！！！！！！！
//解释：这是定义接口的时候，参考Sample的案例，没有实现，仅用于APIPost测试
//DTO这里，还没有写默认构造函数，因此getId()没有值
//另外，Servie部分还没有写，因此没有SampleService类，无法做service.updateData(dto)的条件判断（虽然可以用其他方式替代）

	SampleService service;
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	*/
	return result;
}


