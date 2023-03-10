#pragma once

#ifndef _FIN_PAYMENT_REQ_MANAGE_DO_
#define _FIN_PAYMENT_REQ_MANAGE_DO_
#include "../DoInclude.h"

/*
* 采购付款申请订单管理DO
*/
class FinPaymentReqManageDO
{
	//id
	CC_SYNTHESIZE(string, id, Id);
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//源单编号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	
	CC_SYNTHESIZE(string, subject, Subject);
	//是否红字
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//付款类型
	CC_SYNTHESIZE(string, paymentType, PaymentType);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//业务部门
	CC_SYNTHESIZE(string, opDept, OpDept);
	//业务员
	CC_SYNTHESIZE(string, operator1, Operator);
	//申请金额
	CC_SYNTHESIZE(double, amt, Amt);
	//已付金额
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//是否自动生成
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//审核人
	CC_SYNTHESIZE(string, approver, Approver);
	//审批实例id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//审批结果类型
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	//审批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//是否有效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//创建部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//版本
	CC_SYNTHESIZE(int, version, Version);
public:
	FinPaymentReqManageDO() {
		srcBillType = "";
		srcBillId = "";
		srcNo = "";
		subject = "";
		isRubric = 0;
		paymentType = "";
		supplierId = "";
		opDept = "";
		operator1 = "";
		amt = 0.00;
		paidAmt = 0.00;
		attachment = "";
		remark = "";
		isAuto = 0;
		approver = "";
		bpmiInstanceId = "";
		approvalResultType = "";
		approvalRemark = "";
		isEffective = 0;
		effectiveTime = "";
		isClosed = 0;
		isVoided = 0;
		updateBy = "";
		updateTime = "";
		version = -1;
	}
};

#endif // !_FIN_PAYMENT_REQ_MANAGE_DO_