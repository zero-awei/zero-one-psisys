#pragma once

#ifndef _ExportQtrkFileDTO_H_
#define _ExportQtrkFileDTO_H_

#include "../FileDTO.h"

/**
 * 导出文件数据传输模型
 */
class ExportQtrkFileDTO : public FileDTO
{
	// 单据编号
	CC_SYNTHESIZE(std::string, id, Id);
	
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ExportQtrkFileDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
		
	}
};

#endif // _ExportQtrkFile_H_