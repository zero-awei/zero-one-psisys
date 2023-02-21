#pragma once
#ifndef _Q_P_B_L_VO_
#define _Q_P_B_L_VO_
#include "../../GlobalInclude.h"
/*
* 返回给前端的数据
*/
class QueryPyrkBillListVO {
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
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(QueryPyrkBillListVO, id, data, theme, resourceId, handing, stage, isEffective,
		isClosed, isVoided, remarks, isAuto, effectiveData, checkPerson, makePerson, makeData,
		department, modifyData, modifyPerson);
	
	//测试
	/*QueryPyrkBillListVO() {
		id = "123",
			data = "2022221",
			theme = "asd",
			resourceId = "123",
			handing = "asd",
			stage = 1;
	}*/
};


#endif