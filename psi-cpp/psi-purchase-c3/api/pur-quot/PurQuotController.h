
//公共头文件
#pragma once
#ifndef _PUR_QUOT_CONTROLLER_H_
#define _PUR_QUOT_CONTROLLER_H_
#include "domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"

//query
#include "../../domain/query/pur-quot/PurQuotExportQuery.h"
#include "../../domain/query/pur-quot/PurQuotFindBillQuery.h"
#include "../../domain/query/pur-quot/PurQuotFindDetailBillQuery.h"
#include "../../domain/query/pur-quot/PurQuotDividedListQuery.h"
#include "../../domain/query/pur-quot/PurQuotListQuery.h"


//dto
#include "../../domain/dto/pur-quot/PurQuotIntoDTO.h"
#include "../../domain/dto/pur-quot/AddPurQuotDTO.h"
#include "../../domain/dto/pur-quot/DelPurQuotDTO.h"
#include "../../domain/dto/pur-quot/ModPurQuotDTO.h"
#include "../../domain/dto/pur-quot/PurQuotModBillStatusDTO.h"
//vo

#include "../../domain/vo/pur-quot/PurQuotExportVO.h"
#include "../../domain/vo/pur-quot/PurQuotDividedListVO.h"
#include "../../domain/vo/pur-quot/PurQuotFindBillVO.h"
#include "../../domain/vo/pur-quot/PurQuotFindDetailBillVO.h"
#include "../../domain/vo/pur-quot/PurQuotListVO.h"


class PurQuotController
{
public:
	//查询
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurInquiryFindBill, execQueryPurQuotFindBill, PurQuotFindBillQuery);
	//查询
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurInquiryFindDetailBill, execQueryPurQuotFindDetailBill, PurQuotFindDetailBillQuery);
	//添加报价
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPurQuot, execAddPurQuot, AddPurQuotDTO);
	//修改报价
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modPurQuot, execModPurQuot, ModPurQuotDTO);
	//删除报价
	CREATE_API_FUN_BODY(delPurQuotById, execDelPurQuotById, DelPurQuotDTO);
	//修改报价状态（关闭、作废、反关闭）
	CREATE_API_FUN_BODY_PAYLOAD(purQuotModBillStatus, execPurQuotModBillStatus, PurQuotModBillStatusDTO);
	//导出
	CREATE_API_FUN_BODY_PAYLOAD(queryPurQuotExport, execPurQuotExport, PurQuotExportQuery);
	//导入
	CREATE_API_FUN_BODY_FILE(modifyPurQuotInto, execPurQuotInto, PurQuotIntoDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurQuotList, execQueryPurQuotList, PurQuotListQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurQuotDividedList, execQueryPurQuotDividedList, PurQuotDividedListQuery);
private:
	//查询单据列表
	JsonVO<PageVO<PurQuotFindBillVO>> execQueryPurQuotFindBill(const PurQuotFindBillQuery &query, const PayloadDTO& payload);

	//查询指定单据列表
	JsonVO<PurQuotFindDetailBillVO> execQueryPurQuotFindDetailBill(const PurQuotFindDetailBillQuery& query, const PayloadDTO& payload);

	//新增报价

	JsonVO<uint64_t> execAddPurQuot(const AddPurQuotDTO& dto, const PayloadDTO& payload);
	//修改报价
	JsonVO<uint64_t> execModPurQuot(const ModPurQuotDTO& dto, const PayloadDTO& payload);
	//删除报价
	JsonVO<uint64_t> execDelPurQuotById(const DelPurQuotDTO& dto);
	//修改报价状态（关闭、作废、反关闭）
	JsonVO<uint64_t> execPurQuotModBillStatus(const PurQuotModBillStatusDTO& dto, const PayloadDTO& payload);
	//导出
	JsonVO<PurQuotExportVO> execPurQuotExport(const PurQuotExportQuery& dto, const PayloadDTO& payload);
	//导入
	JsonVO<uint64_t> execPurQuotInto(const PurQuotIntoDTO& dto);
	// 查询询价单列表
	JsonVO<PageVO<PurQuotListVO>> execQueryPurQuotList(const PurQuotListQuery& query, const PayloadDTO& payload);
	// 查询询价单分录列表
	JsonVO<PageVO<PurQuotDividedListVO>> execQueryPurQuotDividedList(const PurQuotDividedListQuery& query, const PayloadDTO& payload);

};


#endif // _PUI_QUOT_CONTROLLER_