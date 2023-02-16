#pragma once
#ifndef _IMPORT_PYRK_FILE_DTO
#define _IMPORT_PYRK_FILE_DTO

#include "../FileDTO.h"

/**
* 导入盘盈入库单的数据传输模型
*/
class ImportPyrkFileDTO : public FileDTO
{
public:
	friend void from_json(const json& j, ImportPyrkFileDTO& t) { } // NOLINT
};

#endif // !_IMPORT_PYRK_FILE_DTO