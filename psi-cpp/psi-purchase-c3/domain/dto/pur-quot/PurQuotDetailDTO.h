#pragma once
#ifndef _PUR_QUOT_DETAIL_DTO_
#define _PUR_QUOT_DETAIL_DTO_

#include "stdafx.h"
#include "../../GlobalInclude.h"

class PurQuotDetailDTO
{
	//以下字段属于，pur_quot_entry表中的字段；
	// 单据id
	CC_SYNTHESIZE(string, id, Id);								//主键，默认为0，不能重复
	//主表
	CC_SYNTHESIZE(string, mid, Mid);							//数据库必传值，唯一约束，不能重复
	//单据号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//分录号
	CC_SYNTHESIZE(int, entry_no, Entry_no);						//数据库必传值，，唯一约束，不能重复

	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//srcbillid
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//源单分录id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//源单分录号
	CC_SYNTHESIZE(string, src_no, Src_no);

	//物料
	CC_SYNTHESIZE(string, material_id, Material_id);			//数据库必传值
	//计量单位
	CC_SYNTHESIZE(string, unit_id, Unit_id);					//数据库必传值
	//数量
	CC_SYNTHESIZE(double, qty, Qty);							//数据库必传值
	//税率%
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);					//数据库必传值

	//含税单价
	CC_SYNTHESIZE(double, price, Price);						//数据库必传值
	//折扣率%
	CC_SYNTHESIZE(double, discount_rate, Discount_rate);
	//含税金额
	CC_SYNTHESIZE(double, amt, Amt);							//数据库必传值
	//备注
	CC_SYNTHESIZE(string, remark, Remark);

	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//版本
	CC_SYNTHESIZE(int, version, Version);

public:
	//这样写以后，前端json数据传过来后，如果detail中有三条数据，会自动形成三条数据吗？
	//绑定JSON转换方法
	friend void from_json(const json& j, PurQuotDetailDTO& t) {

		BIND_FROM_TO_I(j, t, entry_no);
		BIND_FROM_TO_I(j, t, version);

		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, amt);
		BIND_FROM_TO_D(j, t, tax_rate);
		BIND_FROM_TO_D(j, t, price);
		BIND_FROM_TO_D(j, t, discount_rate);

		//BIND_FROM_TO_NORMAL(j, t, mid);		不用另外接收，而是在组装数据的时候，将主表名称放进去
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, src_bill_type);
		BIND_FROM_TO_NORMAL(j, t, src_bill_id);
		BIND_FROM_TO_NORMAL(j, t, src_entry_id);
		BIND_FROM_TO_NORMAL(j, t, src_no);
		BIND_FROM_TO_NORMAL(j, t, material_id);
		BIND_FROM_TO_NORMAL(j, t, unit_id);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);
	}
};

#endif // !_PUR_QUOT_DETAIL_DTO_