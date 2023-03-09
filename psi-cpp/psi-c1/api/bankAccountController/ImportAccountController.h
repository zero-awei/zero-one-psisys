#pragma once

#ifndef _IMPORTACCOUNTCONTROLLER_H_
#define _IMPORTACCOUNTCONTROLLER_H_
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/FileDTO.h"
#include "api/ApiHelper.h"

/*
* 账户信息导入
* @Author: Oxygen
* @Date: 2023/2/14 16:42:51
*/
class ImportAccountController
{
public:
	CREATE_API_FUN_BODY_FILE(modifyAccountInfo, execModifyAccountInfo, FileDTO);
private:
	// 返回bool值，表示成功导入与否
	JsonVO<bool> execModifyAccountInfo(const FileDTO& dto);
};

#endif // _IMPORTACCOUNTCONTROLLER_H_