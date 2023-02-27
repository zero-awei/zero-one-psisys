#pragma once
#ifndef _COMMON_DAO_
#define _COMMON_DAO_

#include "BaseDAO.h"

/*
* 用于进行查询指定数据和上传删除附件的DAO
*/
class CommonDAO : public BaseDAO
{
public:
	// 根据username查询其所属部门代码
	string selectOrgCodeByUsername(const string& username);
	// 根据单据编号查其id
	string selectBillIdByBillNo(const string& billNo);
	// 根据单据编号查其附件名
	string selectAttachmentByBillNo(const string& billNo);
	// 根据单据编号查询明细分录号列表
	list<int> selectEntryNoByBillNo(const string& billNo);
	// 上传附件
	string insertAttachment(const string& fileName);
	// 删除附件
	bool deleteAttachment(const string& fileName);
};

#endif // !_COMMON_DAO_