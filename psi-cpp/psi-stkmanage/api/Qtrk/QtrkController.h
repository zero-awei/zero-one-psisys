#pragma once

#ifndef _QTRK_CONTROLLER_
#define _QTRK_CONTROLLER_

#include "../../domain/query/Qtrk/QueryQtrkBillListQuery.h"
#include "../../domain/query/Qtrk/QueryQtrkBillDetailsQuery.h"
#include "../../domain/dto/Qtrk/AddQtrkBillDTO.h"
#include "../../domain/dto/Pyrk/ApprovalDTO.h"
#include "../../domain/dto/Qtrk/DeleteQtrkBillDTO.h"
#include "../../domain/dto/Qtrk/ModifyQtrkBillDTO.h"
#include "../../domain/dto/Qtrk/ImportQtrkFileDTO.h"
#include "../../domain/dto/Qtrk/ExportQtrkFileDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/Qtrk/QueryQtrkBillListVO.h"
#include "../../domain/vo/Qtrk/ImportQtrkFileVO.h"
#include "../../domain/vo/Qtrk/ExportQtrkFileVO.h"
#include "../../domain/vo/Qtrk/QueryQtrkBillDetailsVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


/**
 * 其他入库控制器，基础接口的使用
 */
class QtrkController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryQtrk, execQueryQtrk, QueryQtrkBillListQuery);
	CREATE_API_FUN_JSON_PAYLOAD(addQtrk, execAddQtrk, AddQtrkBillDTO);
	CREATE_API_FUN_JSON_PAYLOAD(modifyQtrk, execModifyQtrk, AddQtrkBillDTO);
	CREATE_API_FUN_BODY_PAYLOAD(modifyQtrkState, execModifyQtrkState, ModifyQtrkBillDTO);
	CREATE_API_FUN_BODY_PAYLOAD(modifyQtrkApproval, execModifyQtrkApproval, ApprovalDTO);
	CREATE_API_FUN_QUERY(queryQtrkBillDetails, execQueryQtrkBillDetails, QueryQtrkBillDetailsQuery);
	CREATE_API_FUN_BODY(removeQtrk, execRemoveQtrk, DeleteQtrkBillDTO);
	//CREATE_API_FUN_BODY_FILE(importFileQtrk, execImportFileQtrk, ImportQtrkFileDTO);
	//CREATE_API_FUN_QUERY3(exportFileQtrk, execExportFileQtrk);

private:
	//查询其他入库单据列表
	JsonVO<PageVO<QueryQtrkBillListVO>> execQueryQtrk(const QueryQtrkBillListQuery& query, const PayloadDTO& payload);
	//查询其他入库详细信息单据列表
	JsonVO<QueryQtrkBillDetailsVO> execQueryQtrkBillDetails(const QueryQtrkBillDetailsQuery& query);
	//添加其他入库单（保存/提交）
	JsonVO<int> execAddQtrk(const AddQtrkBillDTO& dto, const PayloadDTO& payload);
	//修改其他入库单数据
	JsonVO<int> execModifyQtrk(const AddQtrkBillDTO& dto, const PayloadDTO& payload);
	// 修改单据状态
	JsonVO<int> execModifyQtrkState(const ModifyQtrkBillDTO& dto, const PayloadDTO& payload);
	// 审核其他入库单
	JsonVO<int> execModifyQtrkApproval(const ApprovalDTO& dto, const PayloadDTO& payload);
	//演示删除数据
	JsonVO<uint64_t> execRemoveQtrk(const DeleteQtrkBillDTO& dto);
	//演示文件导入
	//JsonVO<uint64_t> execImportFileQtrk(const ImportQtrkFileDTO& dto);
	//演示文件导出
	//JsonVO<std::string> execExportFileQtrk();
};

#endif // _Qtrk_CONTROLLER_