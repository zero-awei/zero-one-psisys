#pragma once
#ifndef _QUERY_ZDRK_BILL_LIST_VO_
#define _QUERY_ZDRK_BILL_LIST_VO_

#include "../../GlobalInclude.h"

/**
 * 查询单据列表显示对象
 */
class QueryZdrkBillListVO
{
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//核批结果类型
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	//修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//已生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//单据类型
	CC_SYNTHESIZE(string, billType, BillType);
	//核批人
	CC_SYNTHESIZE(string, approver, Approver);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//核批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//是否自动生成
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//红字单据
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//制单部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//制单时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//制单人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//版本
	CC_SYNTHESIZE(string, version, Version);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//审批实例id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//出入库类型
	CC_SYNTHESIZE(string, stockIoType, StockIoType);
	//有来往
	CC_SYNTHESIZE(int, hasRp, HasRp);
	//是否有涨吨
	CC_SYNTHESIZE(int, hasSwell, HasSwell);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//客户
	CC_SYNTHESIZE(string, customerId, CustomerId);
	//发票类型
	CC_SYNTHESIZE(string, invoiceType, InvoiceType);
	//业务部门
	CC_SYNTHESIZE(string, opDept, OpDept);
	//业务员
	CC_SYNTHESIZE(string, operator1, Operator1);
	//出入库经办
	CC_SYNTHESIZE(string, handler, Handler);
	//成本
	CC_SYNTHESIZE(double, cost, Cost);
	//结算金额
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//已结算金额
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	//已开票金额
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//是否退货退票
	CC_SYNTHESIZE(int, isReturned, IsReturned);


public:
	QueryZdrkBillListVO() {
		remark = "";
		billNo = "CGRK-230101-001";
		approvalResultType = "123";
		approvalResultType = "";
		updateBy = "psi";
		isEffective = 0;
		isVoided = 0;
		billType = "StkIo:101";
		approver = "";
		billDate = "2023-02-11";
		srcBillType = "PurOrder";
		approvalRemark = "";
		srcNo = "CGDD-230211-005";
		updateTime = "2023-02-12 11:35:31";
		isAuto = 0;
		isRubric = 0;
		sysOrgCode = "A01A05";
		createTime = "2023-02-11 14:26:56";
		createBy = "psi";
		srcBillId = "1624292548494532610";
		effectiveTime = "";
		billStage = "14";
		version = "";
		attachment = "";
		subject = u8"饮料";
		id = "1624293891909132289";
		isClosed = 0;
		bpmiInstanceId = "";
		stockIoType = "101";
		hasRp = 1;
		hasSwell = 0;
		supplierId = "1624286740595646466";
		customerId = "";
		invoiceType = "0";
		opDept = "A01";
		operator1 = "jeecg";
		handler = "jeecg";
		cost = 3;
		settleAmt = 3;
		settledAmt = 0;
		invoicedAmt = 0;
		isReturned = 0;




	}
	// 绑定JSON转换方法
	BIND_TO_JSON(QueryZdrkBillListVO, remark, billNo, approvalResultType, updateBy, isEffective, isVoided, billType, approver, billDate, srcBillType, approvalRemark, srcNo, updateTime, isAuto,
		isRubric, sysOrgCode, createTime, createBy, srcBillId, effectiveTime, billStage, version, attachment, subject, id, isClosed, bpmiInstanceId, stockIoType, hasRp, hasSwell, supplierId, customerId,
		invoiceType, opDept, operator1, handler, cost, settleAmt, settledAmt, invoicedAmt, isReturned);


};

#endif // !QueryZdrkBillListVO
