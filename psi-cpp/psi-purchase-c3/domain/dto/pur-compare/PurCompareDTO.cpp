#include "stdafx.h"
#include "PurCompareDTO.h"

// 新增比价
void from_json(const json& j, AddPurComDTO& t) { 
	BIND_FROM_TO_NORMAL(j, t, billId);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_I(j, t, isEffect);
	BIND_FROM_TO_I(j, t, isClose);
	BIND_FROM_TO_I(j, t, isCancelled);
	BIND_FROM_TO_NORMAL(j, t, effectDate);
	BIND_FROM_TO_NORMAL(j, t, approver);
	BIND_FROM_TO_NORMAL(j, t, makeBillDate);
	BIND_FROM_TO_NORMAL(j, t, makeBillDept);
	BIND_FROM_TO_NORMAL(j, t, makeBillPerson);
	BIND_FROM_TO_NORMAL(j, t, updateDate);
	BIND_FROM_TO_NORMAL(j, t, updatePerson);
	BIND_FROM_TO_I(j, t, autoBill);
	BIND_FROM_TO_I(j, t, redBill);
	BIND_FROM_TO_NORMAL(j, t, billTheme);
	BIND_FROM_TO_NORMAL(j, t, billStatus);
	BIND_FROM_TO_NORMAL(j, t, inquiryBill);
	BIND_FROM_TO_NORMAL(j, t, payMethod);
	BIND_FROM_TO_NORMAL(j, t, deliveryDate);
	BIND_FROM_TO_NORMAL(j, t, deliveryPlace);
	BIND_FROM_TO_NORMAL(j, t, remark);
}

// 修改比价
void from_json(const json& j, ModPurComDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, billId);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_I(j, t, isEffect);
	BIND_FROM_TO_I(j, t, isClose);
	BIND_FROM_TO_I(j, t, isCancelled);
	BIND_FROM_TO_NORMAL(j, t, effectDate);
	BIND_FROM_TO_NORMAL(j, t, approver);
	BIND_FROM_TO_NORMAL(j, t, makeBillDate);
	BIND_FROM_TO_NORMAL(j, t, makeBillDept);
	BIND_FROM_TO_NORMAL(j, t, makeBillPerson);
	BIND_FROM_TO_NORMAL(j, t, updateDate);
	BIND_FROM_TO_NORMAL(j, t, updatePerson);
	BIND_FROM_TO_I(j, t, autoBill);
	BIND_FROM_TO_I(j, t, redBill);
	BIND_FROM_TO_NORMAL(j, t, billTheme);
	BIND_FROM_TO_NORMAL(j, t, billStatus);
	BIND_FROM_TO_NORMAL(j, t, inquiryBill);
	BIND_FROM_TO_NORMAL(j, t, payMethod);
	BIND_FROM_TO_NORMAL(j, t, deliveryDate);
	BIND_FROM_TO_NORMAL(j, t, deliveryPlace);
	BIND_FROM_TO_NORMAL(j, t, remark);
}

// 删除比价
void from_json(const json& j, DelPurComDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, billId);
}

// 修改单据状态
void from_json(const json& j, PurComModBillStatusDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, billId);
	BIND_FROM_TO_I(j, t, isEffect);
	BIND_FROM_TO_I(j, t, isClose);
	BIND_FROM_TO_I(j, t, isCancelled);
}