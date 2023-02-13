#ifndef _PUR_QUOT_NAIGUAN_CONTROLLER_
#define _PUR_QUOT_NAIGUAN_CONTROLLER_
//因为有多个人同时写PUR_QUOT的功能，因此，为了防止这个地方重复，我先加上NAIGUAN以作区分
//后续再做更改

#include "../../domain/query/purchase-quotation-naiguan/PurQuotNaiguanQUERY.h"
#include "../../domain/dto/purchase-quotation-naiguan/PurQuotNaiguanDTO.h"
#include "domain/dto/IDDTO.h"

class PurQuotNaiguanController
{
public:
	//添加报价
	//在添加报价中，里面还有一个查询采购询价单的选项，用于查询采购询价单
	//明细可能还需要额外的处理，它不是一行数据，而是很多行
	CREATE_API_FUN_BODY_PAYLOAD(addPurQuot, execAddPurQuot, PurQuotNaiguanDTO);
	//修改报价
	CREATE_API_FUN_BODY_PAYLOAD(modPurQuot, execModPurQuot, PurQuotNaiguanDTO);
	//删除报价
	CREATE_API_FUN_BODY(delPurQuot, execDelPurQuot, PurQuotNaiguanDTO);
	//修改报价状态（关闭、作废、反关闭）
	CREATE_API_FUN_BODY(purQuotModBillStatus, execPurQuotModBillStatus, PurQuotNaiguanDTO);


private:
	//演示新增报价
	nlohmann::json execAddPurQuot(PurQuotNaiguanDTO dto);
	//演示修改报价
	nlohmann::json execModPurQuot(PurQuotNaiguanDTO dto);
	//演示删除报价
	nlohmann::json execDelPurQuot(PurQuotNaiguanDTO dto);
	//修改报价状态（关闭、作废、反关闭）
	nlohmann::json execPurQuotModBillStatus(PurQuotNaiguanDTO dto);
};

#endif // _PUI_QUOT_NAIGUAN_CONTROLLER_