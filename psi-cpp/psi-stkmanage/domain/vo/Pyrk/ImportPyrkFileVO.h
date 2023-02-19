#pragma once
#ifndef _IMPORT_PYRK_FILE_VO_
#define _IMPORT_PYRK_FILE_VO_

#include "../../GlobalInclude.h"

/**
* 导入数据结果显示对象
*/
class ImportPyrkFileVO
{
	// 数据总条数
	CC_SYNTHESIZE(int, totalRows, TotalRows);
	// 是否成功
	CC_SYNTHESIZE(bool, success, Success);
	// 失败原因
	CC_SYNTHESIZE(string, failReason, FailReason);
public:
	ImportPyrkFileVO() {
		totalRows = 100;
		success = true;
		failReason = "";
	}
	// 绑定JSON转换方法
	BIND_TO_JSON(ImportPyrkFileVO, totalRows, success, failReason);
};

#endif // !_IMPORT_PYRK_FILE_VO_