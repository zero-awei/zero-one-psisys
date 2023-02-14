#pragma once
#ifndef _QUERYDOC_DO_
#define __QUERYDOC_DO_
#include "../DoInclude.h"

/**
 * 涨吨入库，查询单据详细数据库实体类
 */
class QueryDocDO
{
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//已生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
    //核批人 
	CC_SYNTHESIZE(string, approver, Approver);
	//审批实例***
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//制单人*******
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//制单时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//制单部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//自动单据
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//红字单据
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//有应付
	CC_SYNTHESIZE(int,hasRp, HasRp);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//业务部门
	CC_SYNTHESIZE(string, opDept, opDept);
	//业务员
	CC_SYNTHESIZE(string, operatoR, Operator);
	//入库经办
	CC_SYNTHESIZE(string, handler, Handler);
	//分录号
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//物料
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//规格型号
	CC_SYNTHESIZE(string, model, Model);
	//仓库
	CC_SYNTHESIZE(string,warehouseId, WarehouseId);
	//单位
	CC_SYNTHESIZE(string, unitId, UnitId);
	//涨吨数量
	CC_SYNTHESIZE(double, swellQty, SwellQty);
	//入库金额
	CC_SYNTHESIZE(double, inCost, InCost);
	//明细：备注
	CC_SYNTHESIZE(string, remarK, RemarK);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//核批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//核批结果
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);

	
	
	
public:
	QueryDocDO() {
		billNo = "";
		billDate = "";
		billStage = "";
		isEffective = -1;
		isClosed = -1;
		isVoided = -1;
		effectiveTime = "";
		approver = "";
		bpmiInstanceId = "";
		createBy = "";
		createTime = "";
		sysOrgCode = "";
		updateTime = "";
		updateBy = "";
		isAuto = -1;
		isRubric = -1;
		hasRp = -1;
		subject = "";
		opDept = "";
		operatoR = "";
		handler = "";
		entryNo = 0;
		materialId = "";
		model = "";
		warehouseId = "";
		unitId = "";
		swellQty = 0;
		inCost = 0;
		remarK = "";
		approvalRemark = "";
		custom1 = "";
		custom2 = "";
		remark = "";
		approvalRemark = "";
		approvalResultType = "";
	}
};

#endif // __QUERYDOC_DO_