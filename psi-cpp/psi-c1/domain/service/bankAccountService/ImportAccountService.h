#pragma once
#include "../arch-demo/domain/dto/FileDTO.h"
#ifndef _IMPORTACCOUNTSERVICE_H_
#define _IMPORTACCOUNTSERVICE_H_

/*
* 账户信息导入
* @Author: Oxygen
* @Date: 2023/2/22 12:23:18
*/
class ImportAccountService
{
public:
	uint64_t saveData(const FileDTO& dto);
};

#endif // _IMPORTACCOUNTSERVICE_H_