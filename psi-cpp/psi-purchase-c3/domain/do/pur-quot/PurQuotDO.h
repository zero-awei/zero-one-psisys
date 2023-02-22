#pragma once
#ifndef _PUR_QUOT_DO_H_
#define _PUR_QUOT_DO_H_
#include "../../GlobalInclude.h"
//数据库表pur_quot的实体
class PurQuotDO {
  //ID
  CC_SYNTHESIZE(string, id, Id);
  //单据编号
  CC_SYNTHESIZE(string, bill_no, Bill_no);
  //单据日期
  CC_SYNTHESIZE(string, bill_date, Bill_date);
  //源单类型
  CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
  //源单ID
  CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
  //源单号
  CC_SYNTHESIZE(string, src_no, Src_no);
  //主题
  CC_SYNTHESIZE(string, subject, Subject);
  //是否红字
  CC_SYNTHESIZE(int, is_rubric, Is_rubric);
  //是否临时供应商
  CC_SYNTHESIZE(int, is_temp_supplier, Is_temp_supplier);
  //供应商
  CC_SYNTHESIZE(string, supplier_id, Supplier_id);
  //供应商名称
  CC_SYNTHESIZE(string, supplier_name, Supplier_name);
  //付款方式
  CC_SYNTHESIZE(string, payment_method, Payment_method);
  //交货时间
  CC_SYNTHESIZE(string, delivery_time, Delivery_time);
  //交货地点
  CC_SYNTHESIZE(string, delivery_place, Delivery_place);
  //联系人
  CC_SYNTHESIZE(string, contact, Contact);
  //联系电话
  CC_SYNTHESIZE(string, phone, Phone);
  //传真
  CC_SYNTHESIZE(string, fax, Fax);
  //电子邮件
  CC_SYNTHESIZE(string, email, Email);
  //数量
  CC_SYNTHESIZE(double, qty, Qty);
  //金额
  CC_SYNTHESIZE(double, amt, Amt);
  //附件
  CC_SYNTHESIZE(string, attachment, Attachment);
  //备注
  CC_SYNTHESIZE(string, remark, Remark);
  //是否自动生成
  CC_SYNTHESIZE(int, is_auto, Is_auto);
  //单据阶段
  CC_SYNTHESIZE(string, bill_stage, Bill_stage);
  //审核人
  CC_SYNTHESIZE(string, approver, Approver);
  //审批实例ID
  CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
  //核批结果类型
  CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
  //核批意见
  CC_SYNTHESIZE(string, approval_remark, Approval_remark);
  //是否生效
  CC_SYNTHESIZE(int, is_effective, Is_effective);
  //生效时间
  CC_SYNTHESIZE(string, effective_time, Effective_time);
  //已关闭
  CC_SYNTHESIZE(int, is_closed, Is_closed);
  //是否作废
  CC_SYNTHESIZE(int, is_voided, Is_voided);
  //创建部门
  CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
  //创建人
  CC_SYNTHESIZE(string, create_by, Create_by);
  //创建时间
  CC_SYNTHESIZE(string, create_time, Create_time);
  //修改人
  CC_SYNTHESIZE(string, update_by, Update_by);
  //修改时间
  CC_SYNTHESIZE(string, update_time, Update_time);
  //版本
  CC_SYNTHESIZE(int, version, Version);
public:
  //数据库表对象初始化
  PurQuotDO() {
    id = "";
    bill_no = "";
    bill_date = "";
    src_bill_type = "";
    src_bill_id = "";
    src_no = "";
    subject = "";
    is_rubric = "";
    is_temp_supplier = "";
    supplier_id = "";
    supplier_name = "";
    payment_method = "";
    delivery_time = "";
    delivery_place = "";
    contact = "";
    phone = "";
    fax = "";
    email = "";
    qty = "";
    amt = "";
    attachment = "";
    remark = "";
    is_auto = "";
    bill_stage = "";
    approver = "";
    bpmi_instance_id = "";
    approval_result_type = "";
    approval_remark = "";
    is_effective = "";
    effective_time = "";
    is_closed = "";
    is_voided = "";
    sys_org_code = "";
    create_by = "";
    create_time = "";
    update_by = "";
    update_time = "";
    version = "";
  }
};

#endif // !_PUR_QUOT_DO_H_
