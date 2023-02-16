#include "stdafx.h"
#include "domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/dto/pur-quot/AddPurQuotDTO.h"
#include "../../domain/dto/pur-quot/DelPurQuotDTO.h"
#include "../../domain/dto/pur-quot/ModPurQuotDTO.h"
#include "../../domain/dto/pur-quot/PurQuotModBillStatusDTO.h"
#include "../../domain/vo/pur-quot/AddPurQuotVO.h"
#include "../../domain/vo/pur-quot/DelPurQuotVO.h"
#include "../../domain/vo/pur-quot/ModPurQuotVO.h"
#include "../../domain/vo/pur-quot/PurQuotModBillStatusVO.h"

#ifndef _PUR_QUOT_CONTROLLER_
#define _PUR_QUOT_CONTROLLER_



class PurQuotController
{
public:
	//添加报价
	//CREATE_API_FUN_BODY_PAYLOAD(addPurQuot, execAddPurQuot, PurQuotDTO);
	CREATE_API_FUN_BODY(addPurQuot, execAddPurQuot, AddPurQuotDTO);
	//修改报价
	//CREATE_API_FUN_BODY_PAYLOAD(modPurQuot, execModPurQuot, PurQuotDTO);
	CREATE_API_FUN_BODY(modPurQuot, execModPurQuot, ModPurQuotDTO);
	//删除报价
	CREATE_API_FUN_BODY(delPurQuot, execDelPurQuot, DelPurQuotDTO);
	//修改报价状态（关闭、作废、反关闭）
	CREATE_API_FUN_BODY(purQuotModBillStatus, execPurQuotModBillStatus, PurQuotModBillStatusDTO);


private:
	//演示新增报价
	JsonVO<uint64_t> execAddPurQuot(const AddPurQuotDTO& dto);
	//演示修改报价
	JsonVO<uint64_t> execModPurQuot(const ModPurQuotDTO& dto);
	//演示删除报价
	JsonVO<uint64_t> execDelPurQuot(const DelPurQuotDTO& dto);
	//修改报价状态（关闭、作废、反关闭）
	JsonVO<uint64_t> execPurQuotModBillStatus(const PurQuotModBillStatusDTO& dto);
};

#endif // _PUI_QUOT_CONTROLLER_