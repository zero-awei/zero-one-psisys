#pragma once


#ifndef _REQELEANOR_CONTROLLER_
#define _REQELEANOR_CONTROLLER_

#include "../../domain/dto/req-eleanor/ReqEleanorDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/req-eleanor/ReqEleanorVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/user/UserDTO.h"
#include "../../domain/vo/user/UserVO.h"


/**
 * 示例控制器，演示接口的使用
 */
class ReqEleanorController
{
	//导出申请单、导入申请单
public:
	//接口1 导出申请单

	//接口2 导入申请单
	CREATE_API_FUN_BODY_FILE(modifyReqEleanorInfo, execModifyReqEleanorInfo, ReqEleanorDTO);

	
private:


	//演示文件上传
	JsonVO<ReqEleanorVO> execModifyReqEleanorInfo(const ReqEleanorDTO& dto);
};



#endif // _REQYELEANOR__CONTROLLER_