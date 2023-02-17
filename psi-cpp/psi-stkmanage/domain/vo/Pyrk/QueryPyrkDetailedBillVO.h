#pragma once
#ifndef _Q_P_D_B_VO_
#define _Q_P_D_B_VO_
#include "../../GlobalInclude.h"
#include"QueryPyrkBillListVO.h"
class QueryPyrkDetailedBillVO  {
	// 单据编号
	CC_SYNTHESIZE(string, id, Id);
	// 单据日期
	CC_SYNTHESIZE(string, data, Data);
	// 单据主题
	CC_SYNTHESIZE(string, theme, Theme);
	// 源单号
	CC_SYNTHESIZE(string, resourceId, ResourceId);
	// 盘点经办
	CC_SYNTHESIZE(string, handing, Handing);
	// 单据阶段
	CC_SYNTHESIZE(int, stage, Stage);
	// 已生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	// 已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	// 已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// 备注
	CC_SYNTHESIZE(string, remarks, Remarks);
	// 自动单据
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	// 生效时间
	CC_SYNTHESIZE(string, effectiveData, EffectiveData);
	// 核批人
	CC_SYNTHESIZE(string, checkPerson, CheckPerson);
	// 制单人
	CC_SYNTHESIZE(string, makePerson, MakePerson);
	// 制单时间
	CC_SYNTHESIZE(string, makeData, MakeData);
	// 制单部门
	CC_SYNTHESIZE(string, department, Department);
	// 修改时间
	CC_SYNTHESIZE(string, modifyData, ModifyData);
	// 修改人
	CC_SYNTHESIZE(string, modifyPerson, ModifyPerson);
	// 审批实例
	CC_SYNTHESIZE(string, checkInstanceId, CheckInstanceId);
	// 有应付
	CC_SYNTHESIZE(int, hasYF, HasYF);
	// 红字单据
	CC_SYNTHESIZE(int, redBill, RedBill);
	// 源单类型
	CC_SYNTHESIZE(string, sourceBillType, SourceBillType);
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
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(QueryPyrkDetailedBillVO, id, data, theme, resourceId, handing, stage, isEffective,
		isClosed, isVoided, remarks, isAuto, effectiveData, checkPerson, makePerson, makeData,
		department, modifyData, modifyPerson, checkInstanceId, hasYF, redBill, sourceBillType,
		sourceBillId, materialId, model, warehouse, unit, inNum, inMoney, custom1, custom2);

};








#endif