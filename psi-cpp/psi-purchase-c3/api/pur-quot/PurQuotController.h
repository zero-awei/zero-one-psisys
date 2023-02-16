<<<<<<< HEAD
//公共头文件
=======
#ifndef _PUR_QUOT_CONTROLLER_
#define _PUR_QUOT_CONTROLLER_

>>>>>>> remotes/origin/c3-improve-api-domain-naiguan
#include "stdafx.h"
#include "domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"

//query
#include "../../domain/query/pur-quot/PurQuotExportQuery.h"
//dto
#include "../../domain/dto/pur-quot/PurQuotIntoDTO.h"
#include "../../domain/dto/pur-quot/AddPurQuotDTO.h"
#include "../../domain/dto/pur-quot/DelPurQuotDTO.h"
#include "../../domain/dto/pur-quot/ModPurQuotDTO.h"
#include "../../domain/dto/pur-quot/PurQuotModBillStatusDTO.h"
//vo

#include "../../domain/vo/pur-quot/PurQuotExportVO.h"



class PurQuotController
{
public:
	//添加报价
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPurQuot, execAddPurQuot, AddPurQuotDTO);
	//修改报价
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modPurQuot, execModPurQuot, ModPurQuotDTO);
	//删除报价
	CREATE_API_FUN_BODY(delPurQuotById, execDelPurQuotById, DelPurQuotDTO);
	//修改报价状态（关闭、作废、反关闭）
	CREATE_API_FUN_BODY(purQuotModBillStatus, execPurQuotModBillStatus, PurQuotModBillStatusDTO);
	CREATE_API_FUN_BODY_PAYLOAD(purQuotModBillStatus, execPurQuotModBillStatus, PurQuotModBillStatusDTO);
	//导出
	CREATE_API_FUN_BODY_PAYLOAD(queryPurQuotExport, execPurQuotExport, PurQuotExportQuery);
	//导入
	CREATE_API_FUN_BODY_FILE(modifyPurQuotInto, execPurQuotInto, PurQuotIntoDTO);
	
private:
	//新增报价
	JsonVO<uint64_t> execAddPurQuot(const AddPurQuotDTO& dto, const PayloadDTO& payload);
	//修改报价
	JsonVO<uint64_t> execModPurQuot(const ModPurQuotDTO& dto, const PayloadDTO& payload);
	//删除报价
	JsonVO<uint64_t> execDelPurQuotById(const DelPurQuotDTO& dto);
	//修改报价状态（关闭、作废、反关闭）
	JsonVO<uint64_t> execPurQuotModBillStatus(const PurQuotModBillStatusDTO& dto, const PayloadDTO& payload);
	//导出
	nlohmann::json execPurQuotExport(const PurQuotExportQuery& dto, const PayloadDTO& payload);
	//导入
	JsonVO<uint64_t> execPurQuotInto(const PurQuotIntoDTO& dto);


};


#endif // _PUI_QUOT_CONTROLLER_