#pragma once
#ifndef _PUR_QUOT_ALL_DO_H_
#define _PUR_QUOT_ALL_DO_H_
#include "../../GlobalInclude.h"
//数据库表pur_quot和pur_quot_entry的实体
class PurQuotAllDO {
//pur_quot里面的字段
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
  CC_SYNTHESIZE(string, is_rubric, Is_rubric);
  //是否临时供应商
  CC_SYNTHESIZE(string, is_temp_supplier, Is_temp_supplier);
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
  CC_SYNTHESIZE(string, qty, Qty);
  //金额
  CC_SYNTHESIZE(string, amt, Amt);
  //附件
  CC_SYNTHESIZE(string, attachment, Attachment);
  //备注
  CC_SYNTHESIZE(string, remark, Remark);
  //是否自动生成
  CC_SYNTHESIZE(string, is_auto, Is_auto);
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
  CC_SYNTHESIZE(string, is_effective, Is_effective);
  //生效时间
  CC_SYNTHESIZE(string, effective_time, Effective_time);
  //已关闭
  CC_SYNTHESIZE(string, is_closed, Is_closed);
  //是否作废
  CC_SYNTHESIZE(string, is_voided, Is_voided);
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
  CC_SYNTHESIZE(string, version, Version);
//pur_quot_entry中的字段
  //ID
  CC_SYNTHESIZE(string, entry_id, Entry_id);
  //主表
  CC_SYNTHESIZE(string, entry_mid, Entry_mid);
  //单据号
  CC_SYNTHESIZE(string, entry_bill_no, Entry_bill_no);
  //分录号
  CC_SYNTHESIZE(string, entry_entry_no, Entry_entry_no);
  //源单类型
  CC_SYNTHESIZE(string, entry_src_bill_type, Entry_src_bill_type);
  //源单ID
  CC_SYNTHESIZE(string, entry_src_bill_id, Entry_src_bill_id);
  //源单分录ID
  CC_SYNTHESIZE(string, entry_src_entry_id, Entry_src_entry_id);
  //源单分录号
  CC_SYNTHESIZE(string, entry_src_no, Entry_src_no);
  //物料
  CC_SYNTHESIZE(string, entry_material_id, Entry_material_id);
  //计量单位
  CC_SYNTHESIZE(string, entry_unit_id, Entry_unit_id);
  //数量
  CC_SYNTHESIZE(string, entry_qty, Entry_qty);
  //税率
  CC_SYNTHESIZE(string, entry_tax_rate, Entry_tax_rate);
  //含税单价
  CC_SYNTHESIZE(string, entry_price, Entry_price);
  //折扣率
  CC_SYNTHESIZE(string, entry_discount_rate, Entry_discount_rate);
  //含税金额
  CC_SYNTHESIZE(string, entry_amt, Entry_amt);
  //备注
  CC_SYNTHESIZE(string, entry_remark, Entry_remark);
  //自定义1
  CC_SYNTHESIZE(string, entry_custom1, Entry_custom1);
  //自定义2
  CC_SYNTHESIZE(string, entry_custom2, Entry_custom2);
  //版本
  CC_SYNTHESIZE(string, entry_version, Entry_version);
public:
  //数据库表对象初始化
  PurQuotAllDO() {
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
    entry_id = "";
    entry_mid = "";
    entry_bill_no = "";
    entry_entry_no = "";
    entry_src_bill_type = "";
    entry_src_bill_id = "";
    entry_src_entry_id = "";
    entry_src_no = "";
    entry_material_id = "";
    entry_unit_id = "";
    entry_qty = "";
    entry_tax_rate = "";
    entry_price = "";
    entry_discount_rate = "";
    entry_amt = "";
    entry_remark = "";
    entry_custom1 = "";
    entry_custom2 = "";
    entry_version = "";
  }
};

#endif // !_PUR_QUOT_ALL_DO_H_
