#pragma once

#ifndef _QueryDetailMessage_VO_
#define _QueryDetailMessage_VO_

#include "../../GlobalInclude.h"

/**
 * 查询单据列表显示对象
 */
class QueryDetailMessageVO
{
	//单据编号
	CC_SYNTHESIZE(string, id, Id);
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
	//审批实例
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
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
	//自动单据
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//红字单据
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//有应付
	CC_SYNTHESIZE(int, hasRp, HasRp);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//入库经办
	CC_SYNTHESIZE(string, handler, Handler);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, QueryDetailMessageVO& t); // NOLINT
	BIND_TO_JSON(QueryDetailMessageVO, id, billDate, billStage, isEffective, isClosed, isVoided, effectiveTime, approver,
		bpmiInstanceId, createBy, createTime, sysOrgCode, updateTime, updateBy, isAuto, isRubric, hasRp, subject,
		supplierId, handler);

};

#endif // !_QueryDetailMessage_VO_