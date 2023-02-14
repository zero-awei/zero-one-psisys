#include "stdafx.h"
#include "PurQuotController.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/purchase-quotation-naiguan/AddPurQuotVO.h"
#include "../../domain/vo/purchase-quotation-naiguan/DelPurQuotVO.h"
#include "../../domain/vo/purchase-quotation-naiguan/ModPurQuotVO.h"
#include "../../domain/vo/purchase-quotation-naiguan/PurQuotModBillStatusVO.h"
#include "../../domain/dto/purchase-quotation-naiguan/PurQuotDTO.h"
//#include "../../service/purchase-quotation-naiguan/PurQuotService.h"


//添加供应报价——演示，尚未实现
nlohmann::json PurQuotController::execAddPurQuot(PurQuotDTO dto)
{
	JsonVO<uint64_t> result;
	/*
	//暂时别动这部分注释！！！！！！！！！！！！
	//解释：这是定义接口的时候，参考Sample的案例，没有实现，仅用于APIPost测试
	PurQuotService service;
	//执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		result.success(id);
	}
	else {
		result.fail(id);
	}
	//响应结果
	*/
	return nlohmann::json(result);
}

//修改供应报价——演示，尚未实现
nlohmann::json PurQuotController::execModPurQuot(PurQuotDTO dto)
{
	JsonVO<int> result;
	/*
	//暂时别动这部分注释！！！！！！！！！！！！
	//解释：这是定义接口的时候，参考Sample的案例，没有实现，仅用于APIPost测试
	PurQuotService service;
	
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else {
		result.fail(dto.getId());
	}
	*/
	return nlohmann::json(result);
}

//删除供应报价——演示，尚未实现
nlohmann::json PurQuotController::execDelPurQuot(PurQuotDTO dto)
{
	JsonVO<int> result;
	/*
	//暂时别动这部分注释！！！！！！！！！！！！
	//解释：这是定义接口的时候，参考Sample的案例，没有实现，仅用于APIPost测试
	PurQuotService service;
	//执行数据删除
	if (service.removeData(dto.getId())) {
		result.success(dto.getId());
	}
	else {
		result.fail(dto.getId());
	}
	//响应结果
	*/
	return nlohmann::json(result);
}

//修改报价状态——演示，尚未实现
nlohmann::json PurQuotController::execPurQuotModBillStatus(PurQuotDTO dto)
{
	JsonVO<int> result;
	/*
	//暂时别动这部分注释！！！！！！！！！！！！
	//解释：这是定义接口的时候，参考Sample的案例，没有实现，仅用于APIPost测试
	PurQuotService service;

	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else {
		result.fail(dto.getId());
	}
	*/
	return nlohmann::json(result);
}


