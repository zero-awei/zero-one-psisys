#pragma once
#ifndef _QUERYDOCLIST_CONTROLLER_
#define _QUERYDOCLIST_CONTROLLER_

#include "../../domain/query/Zdrk/QueryZdrkBillListQuery.h"
#include "../../domain/query//Zdrk/QueryZdrkDBillDetailsQuery.h"
#include "../../domain/vo/Zdrk/QueryZdrkBillListVO.h"
#include "../../domain/vo/Zdrk/QueryZdrkBillDetailsVO.h"
#include "../../domain/dto/Zdrk/AddZdrkBillDTO.h"
#include "../../domain/dto/Zdrk/ModifyZdrkBillDTO.h"
#include "../../domain/dto/Zdrk/ModifyZdrkBillStateDTO.h"
#include "../../domain/dto/Zdrk/ImportZdrkFileDTO.h"
#include "../../domain/dto/FileDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/dto/Zdrk/ApprovalDTO.h"
/**
 * 涨吨入库控制器
 */
class ZdrkController
{
public:
	CREATE_API_FUN_QUERY(queryZdrkBillDetails, execQueryZdrkBillDetails, QueryZdrkBillDetailsQuery);
	CREATE_API_FUN_QUERY(queryZdrkBillList, execQueryZdrkBillList, QueryZdrkBillListQuery);

	//添加单据
	CREATE_API_FUN_JSON_PAYLOAD(addZdrkrkBill, execAddZdrkBill, AddZdrkBillDTO);
	// 审核单据
	CREATE_API_FUN_BODY_PAYLOAD(modifyBillApproval, execModifyBillApproval, ApprovalDTO);
	//修改单据
	CREATE_API_FUN_JSON_PAYLOAD(modifyZdrkBill, execModifyZdrkBill, ModifyZdrkBillDTO);
	//删除单据
	CREATE_API_FUN_BODY(removeZdrkBill, execRemoveZdrkBill, StringID);

	//修改单据状态 关闭反关闭作废
	CREATE_API_FUN_BODY(modifyZdrkBillState, execModifyZdrkBillState, ModifyZdrkBillStateDTO);
	CREATE_API_FUN_BODY_PAYLOAD(modifyZdrkBillStateToClose, execModifyZdrkBillStateToClose, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyZdrkBillStateToUnclose, execModifyZdrkBillStateToUnclose, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyZdrkBillStateToVoid, execModifyZdrkBillStateToVoid, StringID);

	//导入导出
	CREATE_API_FUN_BODY_FILE(ImportZdrkFile, execImportZdrkFile, ImportZdrkFileDTO);
	CREATE_API_FUN_QUERY3(EmportZdrkFile, execEmportZdrkFile);
private:
	//查询单据详细信息
	JsonVO<PageVO<QueryZdrkBillDetailsVO>> execQueryZdrkBillDetails(const QueryZdrkBillDetailsQuery& query);
	//查询单据列表
	JsonVO<PageVO<QueryZdrkBillListVO>> execQueryZdrkBillList(const QueryZdrkBillListQuery& query);//**?负载信息
	//添加单据
	JsonVO<uint64_t> execAddZdrkBill(const AddZdrkBillDTO& dto,const PayloadDTO& payload);
	//审核单据
	JsonVO<int> execModifyBillApproval(const ApprovalDTO& approval, const PayloadDTO& payload);
	//修改单据
	JsonVO<int> execModifyZdrkBill(const ModifyZdrkBillDTO& dto, const PayloadDTO& payload);
	//删除单据
	JsonVO<int> execRemoveZdrkBill(const StringID& dto);
	//修改单据状态
	JsonVO<uint64_t> execModifyZdrkBillState(const ModifyZdrkBillStateDTO& dto);
	// 关闭
	JsonVO<int> execModifyZdrkBillStateToClose(const StringID& id, const PayloadDTO& payload);
	// 反关闭
	JsonVO<int> execModifyZdrkBillStateToUnclose(const StringID& id, const PayloadDTO& payload);
	// 作废
	JsonVO<int> execModifyZdrkBillStateToVoid(const StringID& id, const PayloadDTO& payload);
	//导入
	JsonVO<uint64_t> execImportZdrkFile(const ImportZdrkFileDTO& dto);
	//导出
	JsonVO<std::string>  execEmportZdrkFile();
};

#endif // _QUERYDOCLIST_CONTROLLER_
