#pragma once
#ifndef _DELETEACCOUNTSERVICE_H_
#define _DELETEACCOUNTSERVICE_H_

/*
* 账户删除
* @Author: Oxygen
* @Date: 2023/2/22 15:21:06
*/
class DeleteAccountService
{
public:
	// 通过ID删除数据
	bool removeData(std::string id);
};

#endif // _DELETEACCOUNTSERVICE_H_