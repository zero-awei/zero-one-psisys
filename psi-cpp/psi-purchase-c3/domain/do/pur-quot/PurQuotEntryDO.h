#pragma once
#ifndef _PUR_QUOT_ENTRY_DO_H_
#define _PUR_QUOT_ENTRY_DO_H_
#include "../../GlobalInclude.h"
//数据库表pur_quot_entry的实体
class PurQuotEntryDO {
  //ID
  CC_SYNTHESIZE(string, id, Id);
  //主表
  CC_SYNTHESIZE(string, mid, Mid);
  //单据号
  CC_SYNTHESIZE(string, bill_no, Bill_no);
  //分录号
  CC_SYNTHESIZE(string, entry_no, Entry_no);
  //源单类型
  CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
  //源单ID
  CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
  //源单分录ID
  CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
  //源单分录号
  CC_SYNTHESIZE(string, src_no, Src_no);
  //物料
   CC_SYNTHESIZE(string, material_id, Material_id);
  //计量单位
   CC_SYNTHESIZE(string, unit_id, Unit_id);
  //数量
   CC_SYNTHESIZE(string, qty, Qty);
  //税率
   CC_SYNTHESIZE(string, tax_rate, Tax_rate);
  //含税单价
   CC_SYNTHESIZE(string, price, Price);
  //折扣率
   CC_SYNTHESIZE(string, discount_rate, Discount_rate);
  //含税金额
   CC_SYNTHESIZE(string, amt, Amt);
  //备注
   CC_SYNTHESIZE(string, remark, Remark);
  //自定义1
   CC_SYNTHESIZE(string, custom1, Custom1);
  //自定义2
   CC_SYNTHESIZE(string, custom2, Custom2);
  //版本
   CC_SYNTHESIZE(string, version, version);
public:
  //数据库表对象初始化
  PurQuotEntryDO() {
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
