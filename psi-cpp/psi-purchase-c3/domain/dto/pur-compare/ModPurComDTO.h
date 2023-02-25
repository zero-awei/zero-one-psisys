#pragma once
#ifndef _MOD_PUR_COM_DTO_H_
#define _MOD_PUR_COM_DTO_H_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
class ModPurComDTO : public FileDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 已生效
	CC_SYNTHESIZE(string, isEffect, IsEffect);
	// 已关闭
	CC_SYNTHESIZE(string, isClose, IsClose);
	// 已作废
	CC_SYNTHESIZE(string, isCancelled, IsCancelled);
	// 生效时间
	CC_SYNTHESIZE(string, effectDate, EffectDate);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
	// 审批实例
	// 制单时间
	CC_SYNTHESIZE(string, makeBillDate, MakeBillDate);
	// 制单部门
	CC_SYNTHESIZE(string, makeBillDept, MakeBillDept);
	// 制单人
	CC_SYNTHESIZE(string, makeBillPerson, MakeBillPerson);
	// 修改时间
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// 修改人
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);
	// 自动单据
	CC_SYNTHESIZE(string, autoBill, AutoBill);
	// 红字单据
	CC_SYNTHESIZE(string, redBill, RedBill);
	// 源单类型
	CC_SYNTHESIZE(string, billType, BillType);
	// 单据主题
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// 单据阶段
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// 采购询价单（单据编号）
	CC_SYNTHESIZE(string, inqueryBill, InqueryBill);
	// 付款方式
	CC_SYNTHESIZE(string, payMethod, PayMethod);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 核批结果
	CC_SYNTHESIZE(string, auditResult, AuditResult);
	// 核批意见
	CC_SYNTHESIZE(string, auditRemark, AuditRemark);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ModPurComDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billId);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, isEffect);
		BIND_FROM_TO_NORMAL(j, t, isClose);
		BIND_FROM_TO_NORMAL(j, t, isCancelled);
		BIND_FROM_TO_NORMAL(j, t, effectDate);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_NORMAL(j, t, makeBillDate);
		BIND_FROM_TO_NORMAL(j, t, makeBillDept);
		BIND_FROM_TO_NORMAL(j, t, makeBillPerson);
		BIND_FROM_TO_NORMAL(j, t, updateDate);
		BIND_FROM_TO_NORMAL(j, t, updatePerson);
		BIND_FROM_TO_NORMAL(j, t, autoBill);
		BIND_FROM_TO_NORMAL(j, t, redBill);
		BIND_FROM_TO_NORMAL(j, t, billType);
		BIND_FROM_TO_NORMAL(j, t, billTheme);
		BIND_FROM_TO_NORMAL(j, t, billStatus);
		BIND_FROM_TO_NORMAL(j, t, inqueryBill);
		BIND_FROM_TO_NORMAL(j, t, payMethod);
		BIND_FROM_TO_NORMAL(j, t, deliveryDate);
		BIND_FROM_TO_NORMAL(j, t, deliveryPlace);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, auditResult);
		BIND_FROM_TO_NORMAL(j, t, auditRemark);

	}
};


#endif 

