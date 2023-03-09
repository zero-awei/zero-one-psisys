#pragma once
#ifndef _CGTHCK_MAPPER_
#define _CGTHCK_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Cgthck/CgthckDO.h"
using CgthckDO = StkIoDO;
using CgthckEntryDO = StkIoEntryDO;
/**
* 采购退货出库明细字段匹配映射类
*/
class CgthckEntryMapper : public Mapper<CgthckEntryDO>
{
public:
	CgthckEntryDO mapper(ResultSet* resultSet) const override
	{
		CgthckEntryDO data;
		data.setEntryNo(resultSet->getInt("entry_no"));
		data.setSrcNo(resultSet->getString("src_no"));
		data.setMaterialId(resultSet->getString("material_id"));
		data.setBatchNo(resultSet->getString("bill_no"));
		data.setWarehouseId(resultSet->getString("warehouse_id"));
		data.setUnitId(resultSet->getString("unit_id"));
		data.setSettleQty(resultSet->getDouble("settle_qty"));
		data.setTaxRate(resultSet->getDouble("tax_rate"));
		data.setPrice(resultSet->getDouble("price"));
		data.setDiscountRate(resultSet->getDouble("discount_rate"));
		data.setTax(resultSet->getDouble("tax"));
		data.setSettleAmt(resultSet->getDouble("settle_amt"));
		data.setQty(resultSet->getDouble("qty"));
		data.setCost(resultSet->getDouble("cost"));
		data.setInvoicedQty(resultSet->getDouble("invoiced_qty"));
		data.setInvoicedAmt(resultSet->getDouble("invoiced_amt"));
		data.setRemark(resultSet->getString("remark"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setCustom2(resultSet->getString("custom2"));
		return data;
	}
};

/**
* 采购退货出库字段导出匹配映射类
*/
class CgthckSheetMapper : public Mapper<CgthckDO>
{
public:
	CgthckDO mapper(ResultSet* resultSet) const override
	{
		CgthckDO data;
        data.setStockIoType(resultSet->getString("stock_io_type"));
        // 是否有往来
        data.setHasRp(resultSet->getInt("has_rp"));
        // 是否有涨吨
        data.setHasSwell(resultSet->getInt("has_swell"));
        // 供应商
        data.setSupplierId(resultSet->getString("supplier_id"));
        // 客户
        data.setCustomerId(resultSet->getString("customer_id"));
        // 发票类型
        data.setInvoiceType(resultSet->getString("invoice_type"));
        // 业务部门
        data.setOpDept(resultSet->getString("op_dept"));
        // 业务员
        data.setOperator1(resultSet->getString("operator"));
        // 出入库经办
        data.setHandler(resultSet->getString("handler"));
        // 成本
        data.setCost(resultSet->getDouble("cost"));
        // 结算金额
        data.setSettleAmt(resultSet->getDouble("settle_amt"));
        // 已结算金额
        data.setSettledAmt(resultSet->getDouble("settled_amt"));
        // 已开票金额
        data.setInvoicedAmt(resultSet->getDouble("invoiced_amt"));
        // 是否生效
        data.setIsEffective(resultSet->getInt("is_effective"));
        // 附件
        data.setAttachment(resultSet->getString("attachment"));
        // 源单id
        data.setSrcBillId(resultSet->getString("src_bill_id"));
        // 单据主题
        data.setSubject(resultSet->getString("subject"));
        // 单据阶段
        data.setBillStage(resultSet->getString("bill_stage"));
        // 源单号
        data.setSrcNo(resultSet->getString("src_no"));
        // 是否自动生成
        data.setIsAuto(resultSet->getInt("is_auto"));
        // 备注
        data.setRemark(resultSet->getString("remark"));
        // 审批实例id
        data.setBpmiInstanceId(resultSet->getString("bpmi_instance_id"));
        // 已作废
        data.setIsVoided(resultSet->getInt("is_voided"));
        // 单据编号
        data.setBillNo(resultSet->getString("bill_no"));
        // 是否红字
        data.setIsRubric(resultSet->getInt("is_rubric"));
        // 源单类型
        data.setSrcBillType(resultSet->getString("src_bill_type"));
        // 制单时间
        data.setCreateTime(resultSet->getString("create_time"));
        // 生效时间
        data.setEffectiveTime(resultSet->getString("effective_time"));
        // 核批人
        data.setApprover(resultSet->getString("approver"));
        // 修改人
        data.setUpdateBy(resultSet->getString("update_by"));
        // 制单部门
        data.setSysOrgCode(resultSet->getString("sys_org_code"));
        // 已关闭
        data.setIsClosed(resultSet->getInt("is_closed"));
        // 核批结合类型
        data.setApprovalResultType(resultSet->getString("approval_result_type"));
        // 单据日期
        data.setBillDate(resultSet->getString("bill_date"));
        // 制单人
        data.setCreateBy(resultSet->getString("create_by"));
        // 核批意见
        data.setApprovalRemark(resultSet->getString("approval_remark"));
        return data;
	}
};

/**
* 采购退货出库字段明细导出匹配映射类
*/
class CgthckSheetEntryMapper : public Mapper<CgthckEntryDO>
{
public:
	CgthckEntryDO mapper(ResultSet* resultSet) const override
	{
		CgthckEntryDO data;
        // 物料
        data.setMaterialId(resultSet->getString("material_id"));
        // 批次号
        data.setBatchNo(resultSet->getString("batch_no"));
        // 仓库
        data.setWarehouseId(resultSet->getString("warehouse_id"));
        // 出入方向
        data.setStockIoDirection(resultSet->getString("stock_io_direction"));
        // 供应商
        data.setSupplierId(resultSet->getString("supplier_id"));
        // 计量单位
        data.setUnitId(resultSet->getString("unit_id"));
        // 涨吨数量
        data.setSwellQty(resultSet->getDouble("swell_qty"));
        // 数量
        data.setQty(resultSet->getDouble("qty"));
        // 计入成本数量
        data.setExpense(resultSet->getDouble("expense"));
        // 成本
        data.setCost(resultSet->getDouble("cost"));
        // 结算数量
        data.setSettleQty(resultSet->getDouble("settle_qty"));
        // 税率%
        data.setTaxRate(resultSet->getDouble("tax_rate"));
        // 含税单价
        data.setPrice(resultSet->getDouble("price"));
        // 折扣率%
        data.setDiscountRate(resultSet->getDouble("discount_rate"));
        // 税额
        data.setTax(resultSet->getDouble("tax"));
        // 结算金额
        data.setSettleAmt(resultSet->getDouble("settle_amt"));
        // 已开票数量
        data.setInvoicedQty(resultSet->getDouble("invoiced_qty"));
        // 已开票金额
        data.setInvoicedAmt(resultSet->getDouble("invoiced_amt"));
        // 自定义1
        data.setCustom1(resultSet->getString("custom1")); 
        // 源点分录号
        data.setSrcNo(resultSet->getString("src_no"));
        // 分录号
        data.setEntryNo(resultSet->getInt("entry_no"));
        // 自定义2
        data.setCustom2(resultSet->getString("custom2"));
        // 源单分录id
        data.setSrcEntryId(resultSet->getString("src_entry_id"));
        // 源单类型
        data.setSrcBillType(resultSet->getString("src_bill_type"));
        // 备注
        data.setRemark(resultSet->getString("remark"));
        // 单据编号
        data.setBillNo(resultSet->getString("bill_no"));
        // 源单id
        data.setSrcBillId(resultSet->getString("mid"));

        return data;
	}
};
#endif // !_CGTHCK_MAPPER_
