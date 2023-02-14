#pragma once

#ifndef _PUR_COMPARE_VO_
#define _PUR_COMPARE_VO_

#include "../../GlobalInclude.h"

/**
 * 比价单列表显示对象
 */
class PurComFindBillVO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// 付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	// 已生效
	CC_SYNTHESIZE(string, isEffective, IsEffective);
	// 已关闭
	CC_SYNTHESIZE(string, isClosed, IsClosed);
	// 已作废
	CC_SYNTHESIZE(string, isVoided, IsVoided);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自动单据
	CC_SYNTHESIZE(string, isAuto, IsAuto);
	// 红字单据
	CC_SYNTHESIZE(string, isRubric, IsRubric);
	// 生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
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
	BIND_TO_JSON(PurComFindBillVO, id, billNo, billDate, subject, srcNo, paymentMethod, deliveryTime, \
		billStage, isEffective, isClosed, isVoided, deliveryPlace, remark, isAuto, isRubric, \
		effectiveTime, approver, createTime, createBy, sysOrgCode, updateTime, updateBy);
};

/**
 * 指定的比价单详细信息显示对象
 */
class PurComFindDetailBillVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	// 已生效
	CC_SYNTHESIZE(string, isEffective, IsEffective);
	// 已关闭
	CC_SYNTHESIZE(string, isClosed, IsClosed);
	// 已作废
	CC_SYNTHESIZE(string, isVoided, IsVoided);
	// 生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
	// 核批实例
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	// 制单时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 制单部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	// 制单人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// 修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 自动单据
	CC_SYNTHESIZE(string, isAuto, IsAuto);
	// 红字单据
	CC_SYNTHESIZE(string, isRubric, IsRubric);
	// 源单类型
	CC_SYNTHESIZE(string, srcBilType, SrcBillType);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 源单号(采购询价单)
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// 付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 附件
	CC_SYNTHESIZE(std::list<std::string>, attachment, Attachment);
	// 核批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	// 核批结果
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurComFindDetailBillVO, billNo, billDate, billStage, isEffective, isClosed, isVoided, \
		effectiveTime, approver, bpmiInstanceId, createTime, sysOrgCode, createBy, updateTime, \
		updateBy, isAuto, isRubric, srcBillType, subject, srcNo, paymentMethod, deliveryTime, \
		deliveryPlace, remark, attachment, approvalRemark, approvalResultType);
};


/**
 * 报价单列表显示对象
 */
class PurComListVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	// 付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurComListVO, billNo, billDate, subject, supplierId, \
		paymentMethod, deliveryTime, deliveryPlace, remark);
};

/**
 * 报价单分录列表显示对象
 */
class PurComDividedListVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// #
	// 物料
	CC_SYNTHESIZE(string, materialId, MaterialId);
	// 规格型号
	CC_SYNTHESIZE(string, specifications, Specifications);
	// 单位
	CC_SYNTHESIZE(string, unitId, UnitId);
	// 数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 税率
	CC_SYNTHESIZE(uint64_t, taxRate, TaxRate);
	// 含税价格
	CC_SYNTHESIZE(double, price, Price);
	// 折扣率
	CC_SYNTHESIZE(uint64_t, discountRate, DiscountRate);
	// 含税金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurComListVO, billNo, materialId, specifications, unitId, qty, taxRate,\
		price, discountRate, amt, remark, custom1, custom2);
};
#endif 

