#pragma once
#ifndef _PYRK_CONTROLLER_
#define _PYRK_CONTROLLER_
#include "../psi-stkmanage/domain/vo/JsonVO.h"
#include "../psi-stkmanage/domain/vo/Message.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/vo/Pyrk/QueryPyrkBillListVO.h"
#include "../psi-stkmanage/domain/vo/Pyrk/QueryPyrkDetailedBillVO.h"
#include"../psi-stkmanage/domain/query/Pyrk/QueryPyrkBillListQuery.h"
#include"../psi-stkmanage/domain/dto/Pyrk/PyrkBillDetailDTO.h"
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
private:
	// 查询单据列表
	JsonVO<PageVO<QueryPyrkBillListVO>> execQueryBillList(const QueryPyrkBillListQuery& query);
	// 查询单据详细信息
	JsonVO<QueryPyrkBillListVO> exeQueryBillDetailed(const QueryPyrkBillListQuery& query);
	// 新增单据详细信息
	JsonVO<int> exeAddBillDetailed(const PyrkBillDetailDTO& addMessage);
	// 修改单据详细信息
	JsonVO<int> exeUpdateBillDetailed(const PyrkBillDetailDTO& updateMessage);
};










#endif