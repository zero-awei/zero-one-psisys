#pragma once
#ifndef _DETAIL_DTO_
#define _DETAIL_DTO_

#include "../../GlobalInclude.h"

/*
* 单据明细DTO
*/
class DetailDTO {
	// # (分录号)
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	// 物料
	CC_SYNTHESIZE(string, material, Material);
	// 仓库
	CC_SYNTHESIZE(string, warehouse, Warehouse);
	// 单位
	CC_SYNTHESIZE(string, unit, Unit);
	// 入库数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 入库金额
	CC_SYNTHESIZE(double, cost, Cost);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, DetailDTO& t); // NOLINT
};

#endif // !_DETAIL_DTO_