#pragma once
#ifndef _Q_C_B_L_R_DO
#define _Q_C_B_L_R_DO

#include "../../GlobalInclude.h"

class QueryCgthrkBillListReturnDO {
	// 单据编号
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(std::string, subject, Subject);
	// 源单号
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// 供应商
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// 业务部门
	CC_SYNTHESIZE(std::string, optDept, OptDept);
	// 业务员
	CC_SYNTHESIZE(std::string, srcOperator, SrcOperator);
	// 入库金额
	CC_SYNTHESIZE(double, inAmt, InAmt);
	// 结算金额
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	// 已结算金额
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	// 已开票金额
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	// 发票类型
	CC_SYNTHESIZE(std::string, invoiceType, InvoiceType);
	// 出库经办
	CC_SYNTHESIZE(std::string, handler, Handler);
	// 单据阶段
	CC_SYNTHESIZE(std::string, billStage, BillStage);
	// 是否生效
	CC_SYNTHESIZE(bool, isEff, IsEff);
	// 是否关闭
	CC_SYNTHESIZE(bool, isClosed, IsClosed);
	// 是否作废
	CC_SYNTHESIZE(bool, isVoided, IsVoided);
	// 自动单据
	CC_SYNTHESIZE(bool, isAuto, IsAuto);
	// 红字单据
	CC_SYNTHESIZE(bool, isRubric, IsRubric);
	// 备注
	CC_SYNTHESIZE(std::string, remark, Remark);
	// 生效时间
	CC_SYNTHESIZE(std::string, effTime, EffTime);
	// 核批人
	CC_SYNTHESIZE(std::string, approver, Approver);
	// 制单时间
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	// 制单人
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	// 制单部门
	CC_SYNTHESIZE(std::string, sysOrgCode, SysOrgCode);
	// 修改时间
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	// 修改人
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
};


#endif