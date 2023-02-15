#pragma once

#ifndef _PUR_REQ_CONTROLLER_
#define _PUR_REQ_CONTROLLER_

#include"api/ApiHelper.h"



//公共接口
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"

//查询单据列表
#include "../../domain/query/pur-req/PurReqFindBillQuery.h"
#include "../../domain/vo/pur-req/PurReqFindBillVO.h"

//查询指定单据列表
#include "../../domain/query/pur-req/PurReqFindDetailBillQuery.h"
#include "../../domain/vo/pur-req/PurReqFindDetailBillVO.h"

//导出
#include "../../domain/dto/pur-req/PurReqExportDTO.h"
//导入
#include "../../domain/dto/pur-req/PurReqIntoDTO.h"
#include "../../domain/vo/pur-req/PurReqIntoVO.h"

/**
 * 采购申请功能点
 */
class PurReqController
{
public:
	//接口1 导出申请单
	CREATE_API_FUN_BODY_PAYLOAD(queryPurReqExport, execPurReqExport, PurReqExportDTO);
  //接口2 导入申请单
	CREATE_API_FUN_BODY_FILE(modifyPurReqInto, execPurReqInto, PurReqIntoDTO);
	
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindBill, execQueryPurReqFindBill,PurReqFindBillQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindDetailBill, execQueryPurReqFindDetailBill, PurReqFindDetailBillQuery);
private:
	//查询单据列表
	JsonVO<PageVO<PurReqFindBillVO>> execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload);
	//查询指定单据详细信息
	JsonVO<PurReqFindDetailBillVO> execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload);
		//执行方法：导出
	nlohmann::json execPurReqExport(const PurReqExportDTO &dto, const PayloadDTO &payload);
	//执行方法：导入
	JsonVO<PurReqIntoVO> execPurReqInto(const PurReqIntoDTO& dto);
};
#endif 

