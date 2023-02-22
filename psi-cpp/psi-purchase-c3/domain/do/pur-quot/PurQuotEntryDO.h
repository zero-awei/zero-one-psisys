#pragma once
#ifndef _PUR_QUOT_ENTRY_DO_H_
#define _PUR_QUOT_ENTRY_DO_H_
#include "../../GlobalInclude.h"
//数据库表pur_quot_entry的实体
class PurQutoEntryDO {
private:
  string id;
  string mid;
  string bill_no;
  string entry_no;
  string src_bill_type;
  string src_bill_id;
  string src_entry_id;
  string src_no;
  string material_id;
  string unit_id;
  string qty;
  string tax_rate;
  string price;
  string discount_rate;
  string amt;
  string remark;
  string custom1;
  string custom2;
  string version;
  public:
  //数据库表对象初始化
  PurQutoEntryDO() {
    id = "";
    mid = "";
    bill_no = "";
    entry_no = "";
    src_bill_type = "";
    src_bill_id = "";
    src_entry_id = "";
    src_no = "";
    material_id = "";
    unit_id = "";
    qty = "";
    tax_rate = "";
    price = "";
    discount_rate = "";
    amt = "";
    remark = "";
    custom1 = "";
    custom2 = "";
    version = "";
  }
};

#endif 
