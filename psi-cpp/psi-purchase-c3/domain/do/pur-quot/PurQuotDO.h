#pragma once
#ifndef _PUR_QUOT_DO_H_
#define _PUR_QUOT_DO_H_
#include "../../GlobalInclude.h"
//数据库表pur_quot的实体
class PurQuotDO {
  //1ID1
  CC_SYNTHESIZE(string, id, Id);
  //2单据编号
  CC_SYNTHESIZE(string, bill_no, Bill_no);
  //3单据日期
  CC_SYNTHESIZE(string, bill_date, Bill_date);
  //4源单类型
  CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
  //5源单ID
  CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
  //6源单号
  CC_SYNTHESIZE(string, src_no, Src_no);
  //7主题
  CC_SYNTHESIZE(string, subject, Subject);
  //8是否红字
  CC_SYNTHESIZE(int, is_rubric, Is_rubric);
  //9是否临时供应商
  CC_SYNTHESIZE(int, is_temp_supplier, Is_temp_supplier);
  //10供应商
  CC_SYNTHESIZE(string, supplier_id, Supplier_id);
  //11供应商名称
  CC_SYNTHESIZE(string, supplier_name, Supplier_name);
  //12付款方式
  CC_SYNTHESIZE(string, payment_method, Payment_method);
  //13交货时间
  CC_SYNTHESIZE(string, delivery_time, Delivery_time);
  //14交货地点
  CC_SYNTHESIZE(string, delivery_place, Delivery_place);
  //15联系人
  CC_SYNTHESIZE(string, contact, Contact);
  //16联系电话
  CC_SYNTHESIZE(string, phone, Phone);
  //17传真
  CC_SYNTHESIZE(string, fax, Fax);
  //18电子邮件
  CC_SYNTHESIZE(string, email, Email);
  //19数量
  CC_SYNTHESIZE(double, qty, Qty);
  //20金额
  CC_SYNTHESIZE(double, amt, Amt);
  //21附件
  CC_SYNTHESIZE(string, attachment, Attachment);
  //22备注
  CC_SYNTHESIZE(string, remark, Remark);
  //23是否自动生成
  CC_SYNTHESIZE(int, is_auto, Is_auto);
  //24单据阶段
  CC_SYNTHESIZE(string, bill_stage, Bill_stage);
  //25审核人
  CC_SYNTHESIZE(string, approver, Approver);
  //26审批实例ID
  CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
  //27核批结果类型
  CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
  //28核批意见
  CC_SYNTHESIZE(string, approval_remark, Approval_remark);
  //29是否生效
  CC_SYNTHESIZE(int, is_effective, Is_effective);
  //30生效时间
  CC_SYNTHESIZE(string, effective_time, Effective_time);
  //31已关闭
  CC_SYNTHESIZE(int, is_closed, Is_closed);
  //32是否作废
  CC_SYNTHESIZE(int, is_voided, Is_voided);
  //33创建部门
  CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
  //34创建人
  CC_SYNTHESIZE(string, create_by, Create_by);
  //35创建时间
  CC_SYNTHESIZE(string, create_time, Create_time);
  //36修改人
  CC_SYNTHESIZE(string, update_by, Update_by);
  //37修改时间
  CC_SYNTHESIZE(string, update_time, Update_time);
  //38版本
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
    is_rubric = -1;
    is_temp_supplier = -1;
    supplier_id = "";
    supplier_name = "";
    payment_method = "";
    delivery_time = "";
    delivery_place = "";
    contact = "";
    phone = "";
    fax = "";
    email = "";
    qty = -1.0; //double
    amt = -1.0; //double
    attachment = -1;
    remark = "";
    is_auto = -1;
    bill_stage = -1;
    approver = "";
    bpmi_instance_id = "";
    approval_result_type = "";
    approval_remark = "";
    is_effective = -1;
    effective_time = "";
    is_closed = -1;
    is_voided = -1;
    sys_org_code = "";
    create_by = "";
    create_time = "";
    update_by = "";
    update_time = "";
    version = -1;
  }
};

#endif // !_PUR_QUOT_DO_H_
