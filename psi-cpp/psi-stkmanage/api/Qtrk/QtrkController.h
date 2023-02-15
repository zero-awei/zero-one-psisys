#pragma once

#ifndef _QTRK_CONTROLLER_
#define _QTRK_CONTROLLER_

#include "../../domain/query/Qtrk/QueryBillListQuery.h"
#include "../../domain/query/Qtrk/QueryDetailMessageQuery.h"
#include "../../domain/dto/Qtrk/QueryBillListDTO.h"
#include "../../domain/dto/Qtrk/AddListDTO.h"
#include "../../domain/dto/Qtrk/DeleteBillDTO.h"
#include "../../domain/dto/Qtrk/QueryDetailMessageDTO.h"
#include "../../domain/dto/IDDTO.h"

#include "../../domain/vo/Qtrk/QueryBillListVO.h"
#include "../../domain/vo/Qtrk/QueryDetailMessageVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
//#include "../../domain/dto/user/UserDTO.h"
//#include "../../domain/vo/user/UserVO.h"

/**
 * 其他入库控制器，演示基础接口的使用
 */
class QtrkController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryQtrk, execQueryQtrk, QueryBillListQuery);
	//CREATE_API_FUN_QUERY_PAYLOAD(querydetailQtrk, execQuerydetailQtrk, QueryDetailMessageQuery);
	CREATE_API_FUN_BODY(addQtrk, execAddQtrk, AddListDTO);
	CREATE_API_FUN_BODY(modifyQtrk, execModifyQtrk, AddListDTO);
	CREATE_API_FUN_BODY(removeQtrk, execRemoveQtrk, DeleteBillDTO);
	//CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);
	//CREATE_API_FUN_JSON(jsonQtrk, execJsonQtrk, QueryBillListDTO);
	CREATE_API_FUN_BODY_FILE(uploadFile, execUploadFile, QueryDetailMessageDTO);
	//API_BODY_PARAM_FILE(uploadFile, execUploadFile, QueryDetailMessageDTO);
private:
	//查询其他入库单据列表
	JsonVO<PageVO<QueryBillListVO>> execQueryQtrk(const QueryBillListQuery& query, const PayloadDTO& payload);
	//查询其他入库单据列表
	//JsonVO<PageVO<QueryDetailMessageVO>> execQuerydetailQtrk(const QueryDetailMessageQuery& query, const PayloadDTO& payload);
	//添加其他入库单（保存/提交）
	JsonVO<uint64_t> execAddQtrk(const AddListDTO& dto);
	//演示修改数据
	JsonVO<uint64_t> execModifyQtrk(const AddListDTO& dto);
	//演示删除数据
	JsonVO<uint64_t> execRemoveQtrk(const DeleteBillDTO& dto);
	//JsonVO<uint64_t> execRemoveById(const IntID& id);
	////演示JSON提交
	//JsonVO<SampleVO> execJsonSample(const SampleDTO& dto);
	////演示文件上传
	JsonVO<QueryDetailMessageVO> execUploadFile(const QueryDetailMessageDTO& dto);
};

#endif // _Qtrk_CONTROLLER_