#include "stdafx.h"
#include "../../GlobalInclude.h"
#include <vector>
#ifndef __PUR_INQUIRYVO_H__
#define __PUR_INQUIRYVO_H__

//展示vo
 //   class Pur_inquiryVO
 //   {
 //       //单据编号
	//		CC_SYNTHESIZE(string, bill_no, Bill_no);
 //       //单据日期
	//		CC_SYNTHESIZE(string,bill_date,Bill_Date);
 //       //单据主题
	//		CC_SYNTHESIZE(string,subject,Subject);
 //       //源单号			;
	//		CC_SYNTHESIZE(string,src_no,Src_no);
	//	//交货日期		   ;
	//		CC_SYNTHESIZE(string,delivery_time,Delivery_time);
	//	//数量			 ;
	//		CC_SYNTHESIZE(double,qty,Qty);
	//	//参考金额		   ;
	//		CC_SYNTHESIZE(double,amt,Amt);
	//	//报价单数		   ;
	//		CC_SYNTHESIZE(int,quot_count,Quot_count);
	//	//单据阶段		   ;
	//		CC_SYNTHESIZE(string,bill_stage,Bill_stage);
	//	//已生效			;
	//		CC_SYNTHESIZE(int,is_effective,Is_effective)
	//	//已关闭			;
	//		CC_SYNTHESIZE(int,is_close,Is_close);
	//	//已作废			;
	//		CC_SYNTHESIZE(int,is_voided,Is_voided);
	//	//交货地点		   ;
	//		CC_SYNTHESIZE(string,deliver_place,Deliver_place);
	//	////联系人			;
	//		CC_SYNTHESIZE(string,contact,Contact);
	//	////联系电话	   ;
	//		CC_SYNTHESIZE(string,phone,Phone);
	//	////传真			 ;
	//		CC_SYNTHESIZE(string,fax,Fax);
	//	////电子邮箱	   ;
	//		CC_SYNTHESIZE(string,email,Email);
	//	////备注			 ;
	//		CC_SYNTHESIZE(string,remark,Remark);
	//	////自动单据	   ;
	//		CC_SYNTHESIZE(int,is_auto,Is_auto);
	//	////生效时间	   ;
	//		CC_SYNTHESIZE(string,effective_time,Effective_time);
	//	//修改时间		   ;
	//		CC_SYNTHESIZE(string,create_time,Create_time);
	//	//修改人			;
	//		CC_SYNTHESIZE(string,update_by,Update_by);

	//public:
	//	BIND_TO_JSON(Pur_inquiryVO, bill_no, bill_date, subject, src_no, 
	//		delivery_time, qty, amt, quot_count, bill_stage, is_effective
	//		, is_close, is_voided, deliver_place, contact, phone, fax, email
	//		, remark, is_auto, effective_time, create_time, update_by
	//	);
 //   };


	//付款方式
	class PaymentVO
	{
		CC_SYNTHESIZE(std::vector<string>, payment, Payment);

	public:
		BIND_TO_JSON(PaymentVO, payment);
		PaymentVO()
		{
			payment.push_back(u8"全款到发货");
			payment.push_back(u8"货到付全款");
			payment.push_back(u8"发票到付全款");
			payment.push_back(u8"发票到付余款 ");
		}
	};


#endif  //__PUR_INQUIRYVO_H__
