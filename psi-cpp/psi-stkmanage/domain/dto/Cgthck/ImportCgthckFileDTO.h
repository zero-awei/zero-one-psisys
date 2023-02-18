#pragma once
#ifndef _IMPORT_CGTHCK_FILE_DTO_
#define _IMPORT_CGTHCK_FILE_DTO_

#include "../FileDTO.h"
/**
* 采购退货出库的数据传输模型
*/
class ImportCgthckFileDTO : public FileDTO
{
public:
	// 绑定json转换方法
	friend void from_json(const json& j, ImportCgthckFileDTO& t) // NOLINT
	{
		// TO DO
	}
};
#endif // !_IMPORT_CGTHCK_FILE_DTO_
