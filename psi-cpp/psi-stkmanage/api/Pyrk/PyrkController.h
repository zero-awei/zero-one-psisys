#pragma once
#ifndef _PYRK_CONTROLLER_
#define _PYRK_CONTROLLER_

#include "../psi-stkmanage/domain/vo/JsonVO.h"
#include "../psi-stkmanage/domain/vo/Message.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../psi-stkmanage/domain/vo/Pyrk/QueryPyrkBillListVO.h"
#include "../psi-stkmanage/domain/vo/Pyrk/QueryPyrkDetailedBillVO.h"
#include"../psi-stkmanage/domain/query/Pyrk/QueryPyrkBillListQuery.h"
#include"../psi-stkmanage/domain/dto/Pyrk/PyrkBillDetailDTO.h"
#include "../../domain/dto/Pyrk/ImportPyrkFileDTO.h"
#include "../../domain/vo/Pyrk/ImportPyrkFileVO.h"

class PyrkController {
public:
	// 查询单据列表
	CREATE_API_FUN_QUERY(queryQueryBillList, execQueryBillList, QueryPyrkBillListQuery);
	// 查询单据详细信息
	CREATE_API_FUN_QUERY(queryQueryBillDetailed, exeQueryBillDetailed, QueryPyrkBillListQuery);
	// 新增单据详细信息
	CREATE_API_FUN_BODY(addBillDetailed, exeAddBillDetailed, PyrkBillDetailDTO);
	// 修改单据详细信息
	CREATE_API_FUN_BODY(updateBillDetailed, exeUpdateBillDetailed, PyrkBillDetailDTO);
	CREATE_API_FUN_BODY(removePyrkBillById, execRemovePyrkBillById, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyPyrkBillStateToClose, execModifyPyrkBillStateToClose, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyPyrkBillStateToUnclose, execModifyPyrkBillStateToUnclose, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyPyrkBillStateToVoid, execModifyPyrkBillStateToVoid, StringID);
	CREATE_API_FUN_BODY_PAYLOAD_FILE(importPyrkFile, execImportPyrkFile, ImportPyrkFileDTO);
	CREATE_API_FUN_JSON(exportPyrkFile, execExportPyrkFile, StringIDs);
private:
	// 查询单据列表
	JsonVO<PageVO<QueryPyrkBillListVO>> execQueryBillList(const QueryPyrkBillListQuery& query);
	// 查询单据详细信息
	JsonVO<QueryPyrkDetailedBillVO> exeQueryBillDetailed(const QueryPyrkBillListQuery& query);
	// 新增单据详细信息
	JsonVO<int> exeAddBillDetailed(const PyrkBillDetailDTO& addMessage);
	// 修改单据详细信息
	JsonVO<int> exeUpdateBillDetailed(const PyrkBillDetailDTO& updateMessage);
	//删除单据
	JsonVO<uint64_t> execRemovePyrkBillById(const StringID& id);
	//修改单据状态
		// 关闭
	JsonVO<uint64_t> execModifyPyrkBillStateToClose(const StringID& id, const PayloadDTO& payload);
	// 反关闭
	JsonVO<uint64_t> execModifyPyrkBillStateToUnclose(const StringID& id, const PayloadDTO& payload);
	// 作废
	JsonVO<uint64_t> execModifyPyrkBillStateToVoid(const StringID& id, const PayloadDTO& payload);
	// 导入
	JsonVO<ImportPyrkFileVO> execImportPyrkFile(const ImportPyrkFileDTO& dto, const PayloadDTO& payload);
	// 导出
	JsonVO<string> execExportPyrkFile(const StringIDs& ids);
};

#endif // !_PYRK_CONTROLLER_

