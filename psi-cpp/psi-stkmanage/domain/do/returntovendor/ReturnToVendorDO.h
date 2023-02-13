#ifndef _RETURN_TO_VENDOR_DO_
#define _RETURN_TO_VENDOR_DO_
#include "../DoInclude.h"

/**
* 采购退货出库(红入), 查询单据列表数据库实体类
*/
class RtvDocDO
{
	// 单据编号
	CC_SYNTHESIZE(std::string, bill_no, BillNo);
	// 单据日期
	CC_SYNTHESIZE(std::string, bill_date, BillDate);
	// 单据阶段
	CC_SYNTHESIZE(std::string, bill_stage, BillStage);
	// 已生效
	CC_SYNTHESIZE(bool, is_eff, IsEff);
	// 已关闭
	CC_SYNTHESIZE(bool, is_closed, IsClosed);
	// 已作废
	CC_SYNTHESIZE(bool, is_voided, IsVoided);
	// 生效时间
	CC_SYNTHESIZE(std::string, eff_time, EffTime);
	// 核批人
	CC_SYNTHESIZE(std::string, approver, Approver);
	// 审批实例
	CC_SYNTHESIZE(std::string, bpmi_instance_id, BpmiInstanceId);
	// 制单时间
	CC_SYNTHESIZE(std::string, create_time, CreateTime);
	// 制单部门
	CC_SYNTHESIZE(std::string, sys_org_code, SysOrgCode);
	// 制单人
	CC_SYNTHESIZE(std::string, create_by, CreateBy);
	// 修改时间
	CC_SYNTHESIZE(std::string, update_time, UpdateTime);
	// 修改人
	CC_SYNTHESIZE(std::string, update_by, UpdateBy);
	// 是否自动单据
	CC_SYNTHESIZE(bool, is_auto, IsAuto);
	// 是否红字
	CC_SYNTHESIZE(bool, is_rubric, IsRubric);
	// 有应付
	CC_SYNTHESIZE(bool, has_rp, HasRp);
	// 有涨吨
	CC_SYNTHESIZE(bool, has_swell, HasSwell);
	// 源单类型
	CC_SYNTHESIZE(std::string, src_bill_type, SrcBillType);
	// 单据主题
	CC_SYNTHESIZE(std::string, subject, Subject);
	// 源单业务人员
	CC_SYNTHESIZE(std::string, src_operator, SrcOperator);
	// 业务部门
	CC_SYNTHESIZE(std::string, op_dept, OpDept);
	// 供应商
	CC_SYNTHESIZE(std::string, supplier_id, SupplierId);
	// 采购入库单
	CC_SYNTHESIZE(std::string, src_no, SrcNo);
	// 发票类型
	CC_SYNTHESIZE(std::string, invoice_type, InvoiceType);
	// 出库经办
	CC_SYNTHESIZE(std::string, handler, Handler);
	// 已结算金额
	CC_SYNTHESIZE(double, settled_amt, SettledAmt);
	// 备注
	CC_SYNTHESIZE(std::string, remark, Remark);
	// 附件
	CC_SYNTHESIZE(std::string, attachment, Attachment);
	// 核批意见
	CC_SYNTHESIZE(std::string, apv_remark, ApvRemark);
	// 核批结果类型
	CC_SYNTHESIZE(std::string, apv_res_type, ApvResType);
};

/**
* 采购退货出库(红入), 查询单据列表明细数据库实体类
*/
class RtvEntryDO
{
	// 源单分录号
	CC_SYNTHESIZE(std::string, src_no, SrcNo);
	// 物料
	CC_SYNTHESIZE(std::string, material_id, MaterialId);
	// 规格型号
	CC_SYNTHESIZE(std::string, model, Model);
	// 仓库
	CC_SYNTHESIZE(std::string, warehouse_id, WarehouseId);
	// 单位
	CC_SYNTHESIZE(std::string, unit_id, UnitId);
	// 结算数量
	CC_SYNTHESIZE(double, settle_qty, SettleQty);
	// 税率
	CC_SYNTHESIZE(double, tax_rate, TaxRate);
	// 含税单价
	CC_SYNTHESIZE(double, price, Price);
	// 折扣率
	CC_SYNTHESIZE(double, discount_rate, DiscountRate);
	// 税额
	CC_SYNTHESIZE(double, tax, Tax);
	// 结算金额
	CC_SYNTHESIZE(double, settle_amt, SettleAmt);
	// 入库数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 采购费用
	CC_SYNTHESIZE(double, cost, Cost);
	// 入库金额 (应该是计算值)
	// 已开票数量
	CC_SYNTHESIZE(double, invoiced_qty, InvoicedQty);
	// 已开票金额
	CC_SYNTHESIZE(double, invoiced_amt, InvoicedAmt);
	// 备注
	CC_SYNTHESIZE(std::string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(std::string, custom2, Custom2);
};

#endif // !_RETURN_TO_VENDOR_DO_