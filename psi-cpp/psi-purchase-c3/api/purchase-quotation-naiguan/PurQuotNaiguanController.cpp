#include "stdafx.h"
#include "PurQuotNaiguanController.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/purchase-quotation-naiguan/PurQuotNaiguanVO.h"
#include "../../domain/dto/purchase-quotation-naiguan/PurQuotNaiguanDTO.h"
#include "../../domain/query/purchase-quotation-naiguan/PurQuotNaiguanQUERY.h"
#include "../../service/purchase-quotation-naiguan/PurQuotNaiguanService.h"



//演示新增报价
//在头文件中做了如下声明：
//nlohmann::json execAddPurQuot(PurQuotNaiguanDTO dto);
nlohmann::json PurQuotNaiguanController::execAddPurQuot(PurQuotNaiguanQUERY query, PayloadDTO payload)
{
	//定义一个Service
	PurQuotNaiguanService service;
	//查询数据
	//PageVO<PurQuotVO> result = service.listAll(query);
	//未作初始化，通过默认构造函数对result进行初始化工作
	PageVO<AddPurQuotVO> result;
	//响应结果
	return nlohmann::json(JsonVO<PageVO<AddPurQuotVO>>(result, RS_SUCCESS));
}

//演示修改报价

nlohmann::json PurQuotNaiguanController::execModPurQuot(PurQuotNaiguanQUERY query, PayloadDTO payload)
{
	//定义一个Service
	PurQuotNaiguanService service;
	//查询数据
	//未作初始化，通过默认构造函数对result进行初始化工作
	PageVO<ModPurQuotVO> result;
	//响应结果
	return nlohmann::json(JsonVO<PageVO<ModPurQuotVO>>(result, RS_SUCCESS));
}


//演示删除报价
nlohmann::json PurQuotNaiguanController::execDelPurQuot(PurQuotNaiguanQUERY query, PayloadDTO payload)
{
	//定义一个Service
	PurQuotNaiguanService service;
	//查询数据
	//PageVO<PurQuotVO> result = service.listAll(query);
	//未作初始化，通过默认构造函数对result进行初始化工作
	PageVO<DelPurQuotVO> result;
	//响应结果
	return nlohmann::json(JsonVO<PageVO<DelPurQuotVO>>(result, RS_SUCCESS));
}


//修改报价状态（关闭、作废、反关闭）
nlohmann::json PurQuotNaiguanController::execPurQuotModBillStatus(PurQuotNaiguanQUERY query, PayloadDTO payload)
{
	//定义一个Service
	PurQuotNaiguanService service;
	//查询数据
	//PageVO<PurQuotVO> result = service.listAll(query);
//未作初始化，通过默认构造函数对result进行初始化工作
	PageVO<PurQuotModBillStatusVO> result;
	//响应结果
	return nlohmann::json(JsonVO<PageVO<PurQuotModBillStatusVO>>(result, RS_SUCCESS));
}



