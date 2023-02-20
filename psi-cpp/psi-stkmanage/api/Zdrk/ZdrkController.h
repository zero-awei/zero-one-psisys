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

/**
 * 涨吨入库控制器
 */
class ZdrkController
{
public:
	CREATE_API_FUN_QUERY(queryZdrkBillDetails, execQueryZdrkBillDetails, QueryZdrkBillDetailsQuery);
	CREATE_API_FUN_QUERY(queryZdrkBillList, execQueryZdrkBillList, QueryZdrkBillListQuery);
	CREATE_API_FUN_BODY(addZdrkBill, execAddZdrkBill, AddZdrkBillDTO); 
	CREATE_API_FUN_BODY(modifyZdrkBill, execModifyZdrkBill, ModifyZdrkBillDTO);
	CREATE_API_FUN_BODY(removeZdrkBill, execRemoveZdrkBill, StringID);
	CREATE_API_FUN_BODY(modifyZdrkBillState, execModifyZdrkBillState, ModifyZdrkBillStateDTO);
	CREATE_API_FUN_BODY_FILE(ImportZdrkFile, execImportZdrkFile, ImportZdrkFileDTO);
	CREATE_API_FUN_QUERY3(EmportZdrkFile, execEmportZdrkFile);
private:
	//查询单据详细信息
	JsonVO<PageVO<QueryZdrkBillDetailsVO>> execQueryZdrkBillDetails(const QueryZdrkBillDetailsQuery& query);
	//查询单据列表
	JsonVO<PageVO<QueryZdrkBillListVO>> execQueryZdrkBillList(const QueryZdrkBillListQuery& query);//**?负载信息
	//添加单据
	JsonVO<uint64_t> execAddZdrkBill(const AddZdrkBillDTO& dto);
	//修改单据
	JsonVO<uint64_t> execModifyZdrkBill(const ModifyZdrkBillDTO& dto);
	//删除单据
	JsonVO<uint64_t> execRemoveZdrkBill(const StringID& dto);
	//修改单据状态
	JsonVO<uint64_t> execModifyZdrkBillState(const ModifyZdrkBillStateDTO& dto);
	//导入
	JsonVO<uint64_t> execImportZdrkFile(const ImportZdrkFileDTO& dto);
	//导出
	JsonVO<std::string>  execEmportZdrkFile();
};

#endif // _QUERYDOCLIST_CONTROLLER_
