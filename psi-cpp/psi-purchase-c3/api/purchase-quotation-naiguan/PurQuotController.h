#ifndef _PUR_QUOT_CONTROLLER_
#define _PUR_QUOT_CONTROLLER_

#include "../../domain/dto/purchase-quotation-naiguan/PurQuotDTO.h"
#include "domain/dto/IDDTO.h"

class PurQuotController
{
public:
	//添加报价
	//在添加报价中，里面还有一个查询采购询价单的选项，用于查询采购询价单
	//明细可能还需要额外的处理，它不是一行数据，而是很多行
	CREATE_API_FUN_BODY_PAYLOAD(addPurQuot, execAddPurQuot, PurQuotDTO);
	//修改报价
	CREATE_API_FUN_BODY_PAYLOAD(modPurQuot, execModPurQuot, PurQuotDTO);
	//删除报价
	CREATE_API_FUN_BODY(delPurQuot, execDelPurQuot, PurQuotDTO);
	//修改报价状态（关闭、作废、反关闭）
	CREATE_API_FUN_BODY(purQuotModBillStatus, execPurQuotModBillStatus, PurQuotDTO);


private:
	//演示新增报价
	nlohmann::json execAddPurQuot(PurQuotDTO dto);
	//演示修改报价
	nlohmann::json execModPurQuot(PurQuotDTO dto);
	//演示删除报价
	nlohmann::json execDelPurQuot(PurQuotDTO dto);
	//修改报价状态（关闭、作废、反关闭）
	nlohmann::json execPurQuotModBillStatus(PurQuotDTO dto);
};

#endif // _PUI_QUOT_CONTROLLER_