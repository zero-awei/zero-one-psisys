#include "stdafx.h"

#include "../../GlobalInclude.h"
#include "../arch-demo/domain/query/PageQuery.h"

#ifndef __PURINQUIRYQUERY_H__
#define __PURINQUIRYQUERY_H__

//文件上传Query
class PurInquiryQurey : public PageQuery
{
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_Date);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//源单号			;
	CC_SYNTHESIZE(string, src_no, Src_no);
	//交货日期		   ;
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	//数量			 ;
	CC_SYNTHESIZE(double, qty, Qty);
	//参考金额		   ;
	CC_SYNTHESIZE(double, amt, Amt);
	//报价单数		   ;
	CC_SYNTHESIZE(int, quot_count, Quot_count);
	//单据阶段		   ;
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//已生效			;
	CC_SYNTHESIZE(int, is_effective, Is_effective)
		//已关闭			;
	CC_SYNTHESIZE(int, is_close, Is_close);
	//已作废			;
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//交货地点		   ;
	CC_SYNTHESIZE(string, deliver_place, Deliver_place);
	////联系人			;
	CC_SYNTHESIZE(string, contact, Contact);
	////联系电话	   ;
	CC_SYNTHESIZE(string, phone, Phone);
	////传真			 ;
	CC_SYNTHESIZE(string, fax, Fax);
	////电子邮箱	   ;
	CC_SYNTHESIZE(string, email, Email);
	////备注			 ;
	CC_SYNTHESIZE(string, remark, Remark);
	////自动单据	   ;
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	////生效时间	   ;
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//修改时间		   ;
	CC_SYNTHESIZE(string, create_time, Create_time);
	//修改人			;
	CC_SYNTHESIZE(string, update_by, Update_by);

public:

	friend void from_json(const json& j, PurInquiryQurey& t)
	{
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, src_no);
		BIND_FROM_TO_NORMAL(j, t, delivery_time);
		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, amt);
		BIND_FROM_TO_I(j, t, quot_count);
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		BIND_FROM_TO_I(j, t, is_effective);
		BIND_FROM_TO_I(j, t, is_close);
		BIND_FROM_TO_I(j, t, is_voided);
		BIND_FROM_TO_NORMAL(j, t, deliver_place);
		BIND_FROM_TO_NORMAL(j, t, contact);
		BIND_FROM_TO_NORMAL(j, t, phone);
		BIND_FROM_TO_NORMAL(j, t, fax);
		BIND_FROM_TO_NORMAL(j, t, email);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_I(j, t, is_auto);
		BIND_FROM_TO_NORMAL(j, t, effective_time);
		BIND_FROM_TO_NORMAL(j, t, create_time);
		BIND_FROM_TO_NORMAL(j, t, update_by);
	}
};


#endif  //__PURINQUIRYQUERY_H__

