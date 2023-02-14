#pragma once
#pragma once
#ifndef _QUERYDOCLIST_DO_
#define _QUERYDOCLIST_DO_
#include "../DoInclude.h"

/**
 * 涨吨入库，查询单据详细数据库实体类
 */
class QueryDocListDO
{
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//业务部门
	CC_SYNTHESIZE(string, opDept, opDept);
	//业务员
	CC_SYNTHESIZE(string, operatoR, Operator);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//已生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//备注
	CC_SYNTHESIZE(int,isAuto, IsAuto);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//核批人 
	CC_SYNTHESIZE(string, approver, Approver);
	//制单人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//制单时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//制单部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);

public:
	QueryDocListDO() {
		billNo = "";
		billDate = "";
		opDept = "";
		operatoR = "";
		billStage = "";
		isEffective = -1;
		isClosed = 1;
		isVoided = -1;
		remark = "";
		isAuto = -1;
		effectiveTime = "";
		approver = "";
		createBy = "";
		createTime = "";
		sysOrgCode = "";
		updateTime = "";
		updateBy = "";


	}
};

#endif // __QUERYDOC_DO_
