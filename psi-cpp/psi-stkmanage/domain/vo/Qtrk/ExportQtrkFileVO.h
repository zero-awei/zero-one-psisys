#pragma once

#ifndef _ExportQtrkFileVO_H_
#define _ExportQtrkFileVO_H_

#include "../../GlobalInclude.h"

/**
 * 导出信息结果显示对象
 */
class ExportQtrkFileVO
{
	// 单据编号
	CC_SYNTHESIZE(std::string, id, Id);
	
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(ExportQtrkFileVO, id);
};

#endif // _ExportQtrkFileVO_H_