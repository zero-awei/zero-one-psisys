#pragma once
#ifndef _D_M_
#define _D_M_
#include "../../GlobalInclude.h"
class DetailedMessage {
	// 源单分录号
	CC_SYNTHESIZE(string, sourceBillId, SourceBillId);
	// 物料
	CC_SYNTHESIZE(string, materialId, MaterialId);
	// 规格型号
	CC_SYNTHESIZE(string, model, Model);
	// 仓库
	CC_SYNTHESIZE(string, warehouse, Warehouse);
	// 单位
	CC_SYNTHESIZE(string, unit, Unit);
	// 入库数量
	CC_SYNTHESIZE(double, inNum, InNum);
	// 入库金额
	CC_SYNTHESIZE(double, inMoney, InMoney);
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
};





#endif