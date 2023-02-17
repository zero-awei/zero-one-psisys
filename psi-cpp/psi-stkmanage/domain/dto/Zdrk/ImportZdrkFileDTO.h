#pragma once
#include "../FileDTO.h"

#ifndef _IMPORTZDRKFILE_DTO_
#define _IMPORTZDRKFILE_DTO_
/**
 * 涨吨入库的数据传输模型
 */
class ImportZdrkFileDTO : public FileDTO
{

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ImportZdrkFileDTO& t) { // NOLINT
	}
};

#endif // _IMPORTZDRKFILE_DTO_
