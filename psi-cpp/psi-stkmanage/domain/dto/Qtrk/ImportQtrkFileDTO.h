#pragma once

#ifndef _ImportQtrkFileDTO_H_
#define _ImportQtrkFileDTO_H_

#include "../FileDTO.h"

/**
 * 导入文件数据传输模型
 */
class ImportQtrkFileDTO : public FileDTO
{
	// 单据编号
	//CC_SYNTHESIZE(std::string, id, Id);
	
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ImportQtrkFileDTO& t) { // NOLINT
		//BIND_FROM_TO_NORMAL(j, t, id);
		
	}
};

#endif // _ImportQtrkFile_H_