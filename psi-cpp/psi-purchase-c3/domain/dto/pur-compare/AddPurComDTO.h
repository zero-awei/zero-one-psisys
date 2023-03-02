#pragma once
#ifndef _ADD_PUR_COM_DTO_H_
#define _ADD_PUR_COM_DTO_H_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
#include "PurComDetailDTO.h"
#include <list>

//新增比价
// 数据仍有进步空间
class AddPurComDTO :public FileDTO
{
	// 数据id
	CC_SYNTHESIZE(string, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// 源单ID
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);

	// 源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// subject
	CC_SYNTHESIZE(string, subject, Subject);
	// 是否红字
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	// 候选报价单ids
	CC_SYNTHESIZE(string, candidateQuotIds, CandidateQuotIds);
	// 付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 交货时间
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// 附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 是否自动生成
	CC_SYNTHESIZE(int, isAuto, IsAuto);

	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	// 审核人
	CC_SYNTHESIZE(string, approver, Approver);
	// 审批实例id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	// 核批结果类型
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	// 核批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);

	// 是否生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	// 生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	// 已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	// 是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// 创建部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);

	// 创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// 版本
	CC_SYNTHESIZE(int, version, Version);
	
	//明细
	CC_SYNTHESIZE(list<PurComDetailDTO>, detail, Detail);


public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddPurComDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, srcBillType);
		BIND_FROM_TO_NORMAL(j, t, srcBillId);

		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_I(j, t, isRubric);
		BIND_FROM_TO_NORMAL(j, t, candidateQuotIds);
		BIND_FROM_TO_NORMAL(j, t, paymentMethod);

		BIND_FROM_TO_NORMAL(j, t, deliveryPlace);
		BIND_FROM_TO_NORMAL(j, t, deliveryTime);
		BIND_FROM_TO_NORMAL(j, t, attachment);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_I(j, t, isAuto);

		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_NORMAL(j, t, bpmiInstanceId);
		BIND_FROM_TO_NORMAL(j, t, approvalResultType);
		BIND_FROM_TO_NORMAL(j, t, approvalRemark);

		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_NORMAL(j, t, effectiveTime);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
		BIND_FROM_TO_NORMAL(j, t, sysOrgCode);

		BIND_FROM_TO_NORMAL(j, t, createBy);
		BIND_FROM_TO_NORMAL(j, t, createTime);
		BIND_FROM_TO_NORMAL(j, t, updateBy);
		BIND_FROM_TO_NORMAL(j, t, updateTime);
		BIND_FROM_TO_I(j, t, version);

		BIND_FROM_TO_OBJ(j, t, detail, list<PurComDetailDTO>);
	}
};

#endif // !_ADD_PUR_COM_DTO_

