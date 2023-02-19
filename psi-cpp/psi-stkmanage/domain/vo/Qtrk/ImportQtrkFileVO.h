#pragma once

#ifndef _ImportQtrkFileVO_H_
#define _ImportQtrkFileVO_H_

#include "../../GlobalInclude.h"

/**
 * 上传信息结果显示对象
 */
class ImportQtrkFileVO
{
	// 单据编号
	CC_SYNTHESIZE(std::string, id, Id);
	
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(ImportQtrkFileVO, id);
};

#endif // _ImportQtrkFileVO_H_