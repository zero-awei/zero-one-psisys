#ifndef _QUERY_CGTHCK_BILL_VO_
#define _QUERY_CGTHCK_BILL_VO_

#include "../../GlobalInclude.h"

/**
* 采购退货出库(红入), 单据显示对象
*/
class QueryCgthckBillVO
{
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
public:
	BIND_TO_JSON
	(
		QueryCgthckBillVO, billNo, billDate, subject, srcNo, supplierId, optDept, srcOperator,
		inAmt, settleAmt, settledAmt, invoicedAmt, invoiceType, handler, billStage, isEff,
		isClosed, isVoided, isAuto, isRubric, remark, effTime, approver, createTime, createBy,
		sysOrgCode, updateTime, updateBy
	);
};

/**
*  采购退货出库(红入), 单据明细显示对象
*/
class QueryCgthckBillDetailVO : public QueryCgthckBillVO
{
	// 审批实例
	CC_SYNTHESIZE(std::string, bpmiInstanceId, BpmiInstanceId);
	// 有应付
	CC_SYNTHESIZE(bool, hasRp, HasRp);
	// 有涨吨
	CC_SYNTHESIZE(bool, hasSwell, HasSwell);
	// 源单类型
	CC_SYNTHESIZE(std::string, srcBillType, SrcBillType);
	// 物料
	CC_SYNTHESIZE(std::string, materialId, MaterialId);
	// 规格型号
	CC_SYNTHESIZE(std::string, moddel, Moddel);
	// 仓库
	CC_SYNTHESIZE(std::string, warehouseId, WarehouseId);
	// 单位
	CC_SYNTHESIZE(std::string, unitId, UnitId);
	// 结算数量
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	// 税率
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	// 含税单价
	CC_SYNTHESIZE(double, price, Price);
	// 折扣率
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	// 税额
	CC_SYNTHESIZE(double, tax, Tax);
	// 入库数量
	CC_SYNTHESIZE(double, inQty, InQty);
	// 采购费用
	CC_SYNTHESIZE(double, cost, Cost);
	// 自定义1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(std::string, custom2, Custom2);
public:
	BIND_TO_JSON
	(
		QueryCgthckBillDetailVO, billNo, billDate, subject, srcNo, supplierId, optDept, srcOperator,
		inAmt, settleAmt, settledAmt, invoicedAmt, invoiceType, handler, billStage, isEff,
		isClosed, isVoided, isAuto, isRubric, remark, effTime, approver, createTime, createBy,
		sysOrgCode, updateTime, updateBy, bpmiInstanceId, hasRp, hasSwell, srcBillType,
		materialId, moddel, warehouseId, unitId, settleQty, taxRate, price, discountRate, tax,
		inQty, cost, custom1, custom2
	);
};

#endif // ! _QUERY_CGTHCK_BILL_VO_

