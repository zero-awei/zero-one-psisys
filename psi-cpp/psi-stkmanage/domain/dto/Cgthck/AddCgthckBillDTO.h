#ifndef ADD_CGTHCK_BILL_DTO_
#define ADD_CGTHCK_BILL_DTO_

#include "../../GlobalInclude.h"
/**
* 采购退货出库(红入), 添加采购退货出库单数据传输对象
*/
class AddCgthckBillDTO
{
	// 单据日期
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(std::string, subject, Subject);
	// 源单业务人员
	CC_SYNTHESIZE(std::string, srcOperator, SrcOperator);
	// 业务部门
	CC_SYNTHESIZE(std::string, opDept, OpDept);
	// 供应商
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// 采购入库单
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// 出库经办
	CC_SYNTHESIZE(std::string, handler, Handler);
	// 结算数量
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	// 税额
	CC_SYNTHESIZE(double, tax, Tax);
	// 结算金额
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	// 采购费用
	CC_SYNTHESIZE(double, cost, Cost);
	// 备注
	CC_SYNTHESIZE(std::string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(std::string, custom2, Custom2);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddCgthckBillDTO& t) // NOLINT
	{
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, srcOperator);
		BIND_FROM_TO_NORMAL(j, t, opDept);
		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, handler);
		BIND_FROM_TO_D(j, t, settleQty);
		BIND_FROM_TO_D(j, t, tax);
		BIND_FROM_TO_D(j, t, settleAmt);
		BIND_FROM_TO_D(j, t, cost);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);
	}
};

#endif // !ADD_CGTHCK_BILL_DTO_
