#pragma once
#ifndef _PUR_QUOT_ENTRY_DO_H_
#define _PUR_QUOT_ENTRY_DO_H_
#include "../../GlobalInclude.h"
//数据库表pur_quot_entry的实体
class PurQuotEntryDO {
  //ID
  CC_SYNTHESIZE(string, id, Id);
  //主表
  CC_SYNTHESIZE(string, id, Id);
  //单据号
  CC_SYNTHESIZE(string, id, Id);
  //分录号
  CC_SYNTHESIZE(string, id, Id);
  //源单类型
  CC_SYNTHESIZE(string, id, Id);
  //源单ID
  CC_SYNTHESIZE(string, id, Id);
  //源单分录ID
  CC_SYNTHESIZE(string, id, Id);
  //源单分录号
  CC_SYNTHESIZE(string, id, Id);
  //物料
   CC_SYNTHESIZE(string, id, Id);
  //计量单位
   CC_SYNTHESIZE(string, id, Id);
  //数量
   CC_SYNTHESIZE(string, id, Id);
  //税率
   CC_SYNTHESIZE(string, id, Id);
  //含税单价
   CC_SYNTHESIZE(string, id, Id);
  //折扣率
   CC_SYNTHESIZE(string, id, Id);
  //含税金额
   CC_SYNTHESIZE(string, id, Id);
  //备注
   CC_SYNTHESIZE(string, id, Id);
  //自定义1
   CC_SYNTHESIZE(string, id, Id);
  //自定义2
   CC_SYNTHESIZE(string, id, Id);
  //版本
   CC_SYNTHESIZE(string, id, Id);
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
