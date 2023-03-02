#pragma once
#ifndef _PUR_COM_QUOT_ENTRY_DO_H_
#define _PUR_COM_QUOT_ENTRY_DO_H_
#include "../../GlobalInclude.h"
//数据库表pur_quot_entry的实体
class PurComQuotEntryDO {
    //ID
    CC_SYNTHESIZE(string, id, Id);
    //主表
    CC_SYNTHESIZE(string, mid, Mid);
    //单据号
    CC_SYNTHESIZE(string, billNo, BillNo);
    //分录号
    CC_SYNTHESIZE(string, entryNo, EntryNo);
    //源单类型
    CC_SYNTHESIZE(string, srcBillType, SrcBillType);
    //源单ID
    CC_SYNTHESIZE(string, srcBillId, SrcBillId);
    //源单分录ID
    CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
    //源单分录号
    CC_SYNTHESIZE(string, srcNo, SrcNo);
    //物料
    CC_SYNTHESIZE(string, materialId, MaterialId);
    //计量单位
    CC_SYNTHESIZE(string, unitId, UnitId);
    //数量
    CC_SYNTHESIZE(string, qty, Qty);
    //税率
    CC_SYNTHESIZE(string, taxRate, TaxRate);
    //含税单价
    CC_SYNTHESIZE(string, price, Price);
    //折扣率
    CC_SYNTHESIZE(string, discountRate, DiscountRate);
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
    // 物料名字
    CC_SYNTHESIZE(string, materialName, MaterialName);
    // 单位名字
    CC_SYNTHESIZE(string, unitName, UnitName);
    // 规格型号
    CC_SYNTHESIZE(string, specifications, Specifications);
public:
    //数据库表对象初始化
    PurComQuotEntryDO() {
        billNo = "";
    }
};

#endif 