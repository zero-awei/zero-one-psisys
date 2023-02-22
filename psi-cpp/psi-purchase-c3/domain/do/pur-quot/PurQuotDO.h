#pragma once
#ifndef _PUR_QUOT_DO_H_
#define _PUR_QUOT_DO_H_
#include "../../GlobalInclude.h"
//数据库表pur_quot的实体
class PurQutoDO {
private:
  std::string id;
  std::string bill_no;
  std::string bill_date;
  std::string src_bill_type;
  std::string src_bill_id;
  std::string src_no;
  std::string subject;
  std::string is_rubric;
  std::string is_temp_supplier;
  std::string supplier_id;
  std::string supplier_name;
  std::string payment_method;
  std::string delivery_time;
  std::string delivery_place;
  std::string contact;
  std::string phone;
  std::string fax;
  std::string email;
  std::string qty;
  std::string amt;
  std::string attachment;
  std::string remark;
  std::string is_auto;
  std::string bill_stage;
  std::string approver;
  std::string bpmi_instance_id;
  std::string approval_result_type;
  std::string approval_remark;
  std::string is_effective;
  std::string effective_time;
  std::string is_closed;
  std::string is_voided;
  std::string sys_org_code;
  std::string create_by;
  std::string create_time;
  std::string update_by;
  std::string update_time;
  std::string version;
public:
  //数据库表对象初始化
  PurQutoDO() {
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
