#pragma once
#include "../FileDTO.h"

#ifndef _IMPORT_CGRK_FILE_DTO_
#define _IMPORT_CGRK_FILE_DTO_
/**
 * 涨吨入库的数据传输模型
 */
class ImportCgrkFileDTO : public FileDTO
{

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ImportCgrkFileDTO& t) { // NOLINT

	}
};

#endif // _IMPORT_CGRK_FILE_DTO_