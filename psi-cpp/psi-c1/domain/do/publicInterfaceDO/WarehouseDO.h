#pragma once
#ifndef _WAREHOUSE_DO_
#define _WAREHOUSE_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class WarehouseDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 仓库名
	CC_SYNTHESIZE(string, name, Name);
public:
	WarehouseDO() {
		id = 0;
		name = "";
	}
};

#endif // !_WAREHOUSE_DO_