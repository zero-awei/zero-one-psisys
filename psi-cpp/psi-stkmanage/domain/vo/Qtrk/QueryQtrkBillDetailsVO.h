#pragma once

#ifndef _QueryQtrkBillDetails_VO_
#define _QueryQtrkBillDetails_VO_

#include "../../GlobalInclude.h"

/**
 * 查询单据列表详细信息显示对象
 */
class QueryQtrkBillDetailsVO
{
	//单据编号
	CC_SYNTHESIZE(string, id, Id);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//已生效
	CC_SYNTHESIZE(uint64_t, isEffective, IsEffective);
	//已关闭
	CC_SYNTHESIZE(uint64_t, isClosed, IsClosed);
	//已作废
	CC_SYNTHESIZE(uint64_t, isVoided, IsVoided);
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
	CC_SYNTHESIZE(uint64_t, isAuto, IsAuto);
	//红字单据
	CC_SYNTHESIZE(uint64_t, isRubric, IsRubric);
	//有应付
	CC_SYNTHESIZE(uint64_t, hasRp, HasRp);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//入库经办
	CC_SYNTHESIZE(string, handler, Handler);
public:
	QueryQtrkBillDetailsVO()
	{
		id = "12334";
		billDate = "2023 - 2 - 17";
		billStage = "ing";
		isEffective = 0;
		isClosed = 0;
		isVoided = 0;
		effectiveTime = "2023-2-17";
		approver = "aaaa";
		bpmiInstanceId = "";
		createBy = "gonverner";
		createTime = "2023-2-17";
		sysOrgCode = "research gorver";
		updateTime = "2023-2-17";
		updateBy = "wangwu";
		isAuto = 0;
		isRubric = 0;
		hasRp = 0;
		subject = "sgrg";
		supplierId = "wangwu";
		handler = "aafef";
	}
	// 绑定JSON转换方法
	friend void from_json(const json& j, QueryQtrkBillDetailsVO& t); // NOLINT
	BIND_TO_JSON(QueryQtrkBillDetailsVO, id, billDate, billStage, isEffective, isClosed, isVoided, effectiveTime, approver,
		bpmiInstanceId, createBy, createTime, sysOrgCode, updateTime, updateBy, isAuto, isRubric, hasRp, subject,
		supplierId, handler);

};

#endif // !_QueryQtrkBillDetails_VO_