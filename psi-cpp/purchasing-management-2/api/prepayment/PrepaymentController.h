#pragma once
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "../../domain/query/prepaymentbill/PrepaymentBillQuery.h"
#include "../../domain/query/prepaymentbill/PrepaymentDetailBillQuery.h"
#include "../../domain/dto/prepayment/PrepaymentDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/prepayment/PrepaymentVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/prepayment/"
#include "../../domain/vo/user/UserVO.h"

/**
 * 示例控制器，演示基础接口的使用
 */
class PrepaymentController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryPrepayment, execQueryPrepayment, PrepaymentQuery);
	CREATE_API_FUN_BODY(addPrepayment, execAddPrepayment, PrepaymentDTO);
	CREATE_API_FUN_BODY(modifyPrepayment, execModifyPrepayment, PrepaymentDTO);
	CREATE_API_FUN_BODY(removePrepayment, execRemovePrepayment, PrepaymentDTO);
	CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);
	CREATE_API_FUN_JSON(jsonPrepayment, execJsonPrepayment, PrepaymentDTO);
	CREATE_API_FUN_BODY_FILE(modifyUserInfo, execModifyUserInfo, UserDTO);
private:
	//演示查询数据
	JsonVO<PageVO<PrepaymentVO>> execQueryPrepayment(const PrepaymentBillQuery& query, const PayloadDTO& payload);
	//演示新增数据
	JsonVO<uint64_t> execAddPrepayment(const PrepaymentDTO& dto);
	//演示修改数据
	JsonVO<uint64_t> execModifyPrepayment(const PrepaymentDTO& dto);
	//演示删除数据
	JsonVO<uint64_t> execRemovePrepayment(const PrepaymentDTO& dto);
	JsonVO<uint64_t> execRemoveById(const IntID& id);
	//演示JSON提交
	JsonVO<PrepaymentVO> execJsonPrepayment(const PrepaymentDTO& dto);
	//演示文件上传
	JsonVO<UserVO> execModifyUserInfo(const UserDTO& dto);
};

#endif // _SAMPLE_CONTROLLER_