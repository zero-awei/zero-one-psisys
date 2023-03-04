#pragma once
#ifndef _QUERY_CGTHCK_BILL_DEILED_VO_
#define _QUERY_CGTHCK_BILL_DEILED_VO_

#include "../../GlobalInclude.h"
#include"BillEntryDetailedVO.h"
class QueryCgthrkDetailedBillVO {
	//单据列表信息  开始---------
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
	CC_SYNTHESIZE(int, isEff, IsEff);
	// 是否关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	// 是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// 自动单据
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	// 红字单据
	CC_SYNTHESIZE(int, isRubric, IsRubric);
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
	//单据列表信息  结束---------

	//详细信息额外的 开始----------
	//详细信息额外的 结束----------



	//退货出库明细（这又是一个list）
	CC_SYNTHESIZE(list<BillEntryDetailedVO>, detail, Detail);
public:
	BIND_TO_JSON
	(
		QueryCgthrkDetailedBillVO, billNo, billDate, subject, srcNo, supplierId, optDept, srcOperator,
		inAmt, settleAmt, settledAmt, invoicedAmt, invoiceType, handler, billStage, isEff,
		isClosed, isVoided, isAuto, isRubric, remark, effTime, approver, createTime, createBy,
		sysOrgCode, updateTime, updateBy, detail
	);
};



#endif