#pragma once
#ifndef _QUERYZDRKBILLLIST_VO_
#define _QUERYZDRKBILLLIST_VO_

#include "../../GlobalInclude.h"

/**
 * 查询单据列表显示对象
 */
class QueryZdrkBillListVO
{
	//单据编号     
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期    
	CC_SYNTHESIZE(string, billDate, BillDate);
	//业务部门   
	CC_SYNTHESIZE(string, opDept, OpDept);
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
	//自动     
	CC_SYNTHESIZE(int, isAuto, IsAuto);
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
	// 绑定JSON转换方法    
	BIND_TO_JSON(QueryZdrkBillListVO, billNo, billDate, billStage, isEffective, isClosed, isVoided, effectiveTime, approver, createBy, createTime, sysOrgCode, updateTime, updateBy, isAuto, opDept, operatoR, remark);
};

#endif // !QueryZdrkBillListVO
