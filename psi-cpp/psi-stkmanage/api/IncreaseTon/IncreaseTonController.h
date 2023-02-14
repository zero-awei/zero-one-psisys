#pragma once
#ifndef _QUERYDOCLIST_CONTROLLER_
#define _QUERYDOCLIST_CONTROLLER_

#include "../../domain/dto/IncreaseTon/DocStatDTO.h"
#include "../../domain/dto/IncreaseTon/DocFileDTO.h"
#include "../../domain/dto/IncreaseTon/DocNoDTO.h"
#include "../../domain/vo/IncreaseTon/SucVO.h"
#include "../../domain/dto/IncreaseTon/DocDTO.h"
#include "../../domain/vo/IncreaseTon/DocVO.h"
#include "../../domain/vo/IncreaseTon/QueryDocVO.h"
#include "../../domain\query\IncreaseTon\QueryDocQuery.h"
#include "../../domain/vo/IncreaseTon/DoclVO.h"
#include "../../domain\query\IncreaseTon\QueryDocListQuery.h"
#include "../../domain\dto\IncreaseTon\QueryDocDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


/**
 * 涨吨入库控制器
 */
class IncreaseTonController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(QueryDocIncreaseTon, execQueryDocIncreaseTon, QueryDocQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(QueryDocListIncreaseTon, execQueryDocListIncreaseTon, QueryDocListQuery);
	CREATE_API_FUN_JSON(AddDocIncreaseTon, execAddDocIncreaseTon, DocDTO);
	CREATE_API_FUN_JSON(ModifyDocIncreaseTon, execModifyDocIncreaseTon, DocDTO);
	CREATE_API_FUN_BODY(RemoveDocIncreaseTon, execRemoveDocIncreaseTon, DocNoDTO);
	CREATE_API_FUN_BODY(ModifyDocStatIncreaseTon, execModifyDocStatIncreaseTon, DocStatDTO);
	CREATE_API_FUN_BODY_FILE(ImportDocFileIncreaseTon, execImportDocFileIncreaseTon, DocFileDTO);
	CREATE_API_FUN_QUERY3(EmportDocFileIncreaseTon, execEmportDocFileIncreaseTon);
private:
	//查询单据详细信息
	JsonVO<QueryDocVO> execQueryDocIncreaseTon(const QueryDocQuery& query, const PayloadDTO& payload);
	//查询单据列表
	JsonVO<PageVO<DoclVO>> execQueryDocListIncreaseTon(const QueryDocListQuery& query, const PayloadDTO& payload);//**?负载信息
	//添加单据
	JsonVO<SucVO> execAddDocIncreaseTon(const DocDTO& dto);
	//修改单据
	JsonVO<SucVO> execModifyDocIncreaseTon(const DocDTO& dto);
	//删除单据
	JsonVO<SucVO> execRemoveDocIncreaseTon(const DocNoDTO& dto);
	//修改单据状态
	JsonVO<SucVO> execModifyDocStatIncreaseTon(const DocStatDTO& dto);
	//导入
	JsonVO<SucVO> execImportDocFileIncreaseTon(const DocFileDTO& dto);
	//导出
	JsonVO<std::string> execEmportDocFileIncreaseTon();
};

#endif // _QUERYDOCLIST_CONTROLLER_
