#ifndef _PUR_QUOT_CONTROLLER_
#define _PUR_QUOT_CONTROLLER_

#include "../../domain/query/purchase_quotation_naiguan/pur_quotQuery.h"
#include "../../domain/dto/purchase_quotation_naiguan/pur_quotDTO.h"
#include "domain/dto/IDDTO.h"

class pur_quotController
{
public:
	//添加报价
	//在添加报价中，里面还有一个查询采购询价单的选项，用于查询采购询价单
	//明细可能还需要额外的处理，它不是一行数据，而是很多行
	CREAT_API_FUN_BODY_PAYLOAD(addpur_quot, execAddpur_quot, pur_quotDTO);
	//修改报价
	CREATE_API_FUN_BODY_PAYLOAD(modifypur_quot, execModifypur_quot, pur_quotDTO);
	//删除报价
	CREATE_API_FUN_BODY(removepur_quot, execRemovepur_quot, pur_quotDTO);
	CREATE_API_FUN_BODY(removeById, execRemoveById, ID);
	//修改报价状态（关闭、作废、反关闭）
	CREATE_API_FUN_BODY(modifypur_quot_state, execModifypur_quot_state, pur_quotDTO);
	//导入报价
	CREATE_API_FUN_JSON(jsonpur_quot_import, execJsonpur_quot_import, pur_quotDTO);
	//导出报价
	CREATE_API_FUN_QUERY(jsonpur_quot_export, execJsonpur_quott_export, pur_quottDTO);
	CREATE_API_FUN_QUERY1(jsonpur_quot_export1, execJsonpur_quott_export1, pur_quottDTO);
	CREATE_API_FUN_QUERY2(jsonpur_quot_export2, execJsonpur_quott_export2, pur_quottDTO);
	CREATE_API_FUN_QUERY3(jsonpur_quot_export3, execJsonpur_quott_export3, pur_quottDTO);


private:
	//演示新增报价
	nlohmann::json execAddpur_quot(pur_quotDTO dto);
	//演示修改报价
	nlohmann::json execModifypur_quot(pur_quotDTO dto);
	//演示删除报价
	nlohmann::json execRemovepur_quot(pur_quotDTO dto);
	nlohmann::json execRemoveById(ID id);
	//演示JSON导入
	nlohmann::json execJsonpur_quot_import(pur_quot_importDTO dto);
	//演示JSON导出
	nlohmann::json execJsonpur_quot_export(pur_quotDTO dto);
	nlohmann::json execJsonpur_quot_export1(pur_quotDTO dto);
	nlohmann::json execJsonpur_quot_export2(pur_quotDTO dto);
	nlohmann::json execJsonpur_quot_export3(pur_quotDTO dto);
};

#endif // _SAMPLE_CONTROLLER_