#ifndef _CGTHCK_DO_
#define _CGTHCK_DO_
#include "../DoInclude.h"

/**
* 采购退货出库(红入), 查询单据列表数据库实体类
*/
class CgthckBillListDO
{
	// 单据编号
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// 单据阶段
	CC_SYNTHESIZE(std::string, billStage, BillStage);
	// 已生效
	CC_SYNTHESIZE(bool, isEff, IsEff);
	// 已关闭
	CC_SYNTHESIZE(bool, isClosed, IsClosed);
	// 已作废
	CC_SYNTHESIZE(bool, isVoided, IsVoided);
	// 生效时间
	CC_SYNTHESIZE(std::string, effTime, EffTime);
	// 核批人
	CC_SYNTHESIZE(std::string, approver, Approver);
	// 审批实例
	CC_SYNTHESIZE(std::string, bpmiInstanceId, BpmiInstanceId);
	// 制单时间
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	// 制单部门
	CC_SYNTHESIZE(std::string, sysOrgCode, SysOrgCode);
	// 制单人
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	// 修改时间
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	// 修改人
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
	// 是否自动单据
	CC_SYNTHESIZE(bool, isAuto, IsAuto);
	// 是否红字
	CC_SYNTHESIZE(bool, isRubric, IsRubric);
	// 有应付
	CC_SYNTHESIZE(bool, hasRp, HasRp);
	// 有涨吨
	CC_SYNTHESIZE(bool, hasSwell, HasSwell);
	// 源单类型
	CC_SYNTHESIZE(std::string, srcBillType, SrcBillType);
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
	// 发票类型
	CC_SYNTHESIZE(std::string, invoiceType, InvoiceType);
	// 出库经办
	CC_SYNTHESIZE(std::string, handler, Handler);
	// 已结算金额
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	// 备注
	CC_SYNTHESIZE(std::string, remark, Remark);
	// 附件
	CC_SYNTHESIZE(std::string, attachment, Attachment);
	// 核批意见
	CC_SYNTHESIZE(std::string, apvRemark, ApvRemark);
	// 核批结果类型
	CC_SYNTHESIZE(std::string, apvResType, ApvResType);
public:
	CgthckBillListDO()
	{
		billNo = "";
		billDate = "";
		billStage = "";
		isEff = true;
		isClosed = false;
		isVoided = false;
		isAuto = false;
		isRubric = true;
		hasRp = true;
		hasSwell = false;
	}
};

/**
* 采购退货出库(红入), 查询单据列表明细数据库实体类
*/
class CgthckBillDetailDO : public CgthckBillListDO
{
	// 源单分录号
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// 物料
	CC_SYNTHESIZE(std::string, materialId, MaterialId);
	// 规格型号
	CC_SYNTHESIZE(std::string, model, Model);
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
	// 结算金额
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	// 入库数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 采购费用
	CC_SYNTHESIZE(double, cost, Cost);
	// 入库金额 (应该是计算值)
	CC_SYNTHESIZE(double, inAmt, InAmt);
	// 已开票数量
	CC_SYNTHESIZE(double, invoicedQty, InvoicedQty);
	// 已开票金额
	CC_SYNTHESIZE(double, invoicedQmt, InvoicedAmt);
	// 备注
	CC_SYNTHESIZE(std::string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(std::string, custom2, Custom2);
};

#endif // !_CGTHCK_DO_