#pragma once

#ifndef _PAYMENT_BILL_VO_
#define _PAYMENT_BILL_VO_

#include "../../GlobalInclude.h"

/*
查询单据列表
*/
class PaymentBillVO {
	// 单据编号
	CC_SYNTHESIZE(string, billNo, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, Bill_date);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplierId, Supplier_id)
	// 业务部门
	CC_SYNTHESIZE(string, opDept, Op_dept)
	// 业务员
	CC_SYNTHESIZE(string, operator,Operator)
	// 源单号
	CC_SYNTHESIZE(string,srcNo,SrcNo)
	// 申请金额
	CC_SYNTHESIZE(double, amt, Amt)
	// 已付金额
	CC_SYNTHESIZE(double, paidAmt, PaidAmt)
	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//已生效			
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//已关闭			
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废			
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// 自动单据
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	// 红字单据
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 生效时间
	CC_SYNTHESIZE(int, effectiveTime, EffectiveTime);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
	// 制单时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 制单人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 制单部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// 修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PaymentBillVO, billNo, billDate, subject, supplierId, opDept,
		operator, srcNo, amt, paidAmt, billStage, isEffective, isClosed, isVoided,
		isAuto, isRubric, remark, effectiveTime,
		approver, createTime, createBy, sysOrgCode, updateTime, updateBy);
};



/*
查询单据列表
*/
class PaymentBillDetailQuery : public PaymentBillVO {
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//申请金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 已付金额
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PaymentBillDetailQuery, srcNo, amt, paidAmt, remark, custom1, custom2);
};

#endif