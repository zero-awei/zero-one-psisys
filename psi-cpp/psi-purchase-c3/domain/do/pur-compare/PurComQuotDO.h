#pragma once
#ifndef _PUR_COM_QUOT_DO_H_
#define _PUR_COM_QUOT_DO_H_
#include "../../GlobalInclude.h"
//数据库表pur_quot的实体
class PurComQuotDO {
    //ID
    CC_SYNTHESIZE(string, id, Id);
    //单据编号
    CC_SYNTHESIZE(string, billNo, BillNo);
    //单据日期
    CC_SYNTHESIZE(string, billDate, BillDate);
    //源单类型
    CC_SYNTHESIZE(string, srcBillType, SrcBillType);
    //源单ID
    CC_SYNTHESIZE(string, srcBillId, SrcBillId);
    //源单号
    CC_SYNTHESIZE(string, srcNo, SrcNo);
    //主题
    CC_SYNTHESIZE(string, subject, Subject);
    //是否红字
    CC_SYNTHESIZE(string, isRubric, IsRubric);
    //是否临时供应商
    CC_SYNTHESIZE(string, isTempSupplier, IsTempSupplier);
    //供应商
    CC_SYNTHESIZE(string, supplierId, SupplierId);
    //供应商名称
    CC_SYNTHESIZE(string, supplierName, SupplierName);
    //付款方式
    CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
    //交货时间
    CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
    //交货地点
    CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
    //联系人
    CC_SYNTHESIZE(string, contact, Contact);
    //联系电话
    CC_SYNTHESIZE(string, phone, Phone);
    //传真
    CC_SYNTHESIZE(string, fax, Fax);
    //电子邮件
    CC_SYNTHESIZE(string, email, Email);
    //数量
    CC_SYNTHESIZE(string, qty, Qty);
    //金额
    CC_SYNTHESIZE(string, amt, Amt);
    //附件
    CC_SYNTHESIZE(string, attachment, Attachment);
    //备注
    CC_SYNTHESIZE(string, remark, Remark);
    //是否自动生成
    CC_SYNTHESIZE(string, isAuto, IsAuto);
    //单据阶段
    CC_SYNTHESIZE(string, billStage, BillStage);
    //审核人
    CC_SYNTHESIZE(string, approver, Approver);
    //审批实例ID
    CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
    //核批结果类型
    CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
    //核批意见
    CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
    //是否生效
    CC_SYNTHESIZE(string, isEffective, IsEffective);
    //生效时间
    CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
    //已关闭
    CC_SYNTHESIZE(string, isClosed, IsClosed);
    //是否作废
    CC_SYNTHESIZE(string, isVoided, IsVoided);
    //创建部门
    CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
    //创建人
    CC_SYNTHESIZE(string, createBy, CreateBy);
    //创建时间
    CC_SYNTHESIZE(string, createTime, CreateTime);
    //修改人
    CC_SYNTHESIZE(string, updateBy, UpdateBy);
    //修改时间
    CC_SYNTHESIZE(string, updateTime, UpdateTime);
    //版本
    CC_SYNTHESIZE(string, version, Version);
public:
    //数据库表对象初始化
    PurComQuotDO() {
        billNo = "";
    }
};

#endif // !_PUR_COM_QUOT_DO_H_
