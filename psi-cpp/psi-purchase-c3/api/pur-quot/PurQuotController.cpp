#include "stdafx.h"
#include "PurQuotController.h"


//添加供应报价——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execAddPurQuot(const AddPurQuotDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//修改供应报价——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execModPurQuot(const ModPurQuotDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//删除供应报价——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execDelPurQuotById(const DelPurQuotDTO& id)
{
	JsonVO<uint64_t> result;
	return result;
}

//修改报价状态——演示，尚未实现
JsonVO<uint64_t> PurQuotController::execPurQuotModBillStatus(const PurQuotModBillStatusDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}


//导出
nlohmann::json PurQuotController::execPurQuotExport(const PurQuotExportQuery& dto, const PayloadDTO& payload)
{
	//响应结果
	return nlohmann::json(JsonVO<std::string>());
}

//导入
JsonVO<uint64_t> PurQuotController::execPurQuotInto(const PurQuotIntoDTO& dto)
{
	//响应结果
	return JsonVO<uint64_t>();
}