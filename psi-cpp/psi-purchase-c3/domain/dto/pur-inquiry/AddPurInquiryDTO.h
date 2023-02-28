#pragma once

#ifndef __ADD_PUR_INQUIRY_DTO_H__
#define __ADD_PUR_INQUIRY_DTO_H__
#include "../../GlobalInclude.h"
#include "../FileDTO.h"
#include "../IDDTO.h"
#include <list>
#include "AddPurInquiryEntryDTO.h"
//增加和修改DTO
class AddPurInquiryDTO : public FileDTO
{
	//ID
	CC_SYNTHESIZE(std::string, id, Id);
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//付款方式
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	//交货地点
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
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
	//红字单据(是否红字)
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	////自动单据	   ;
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	////生效时间	   ;
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//制单时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//制单部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//单据阶段		   ;
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_Date);
	//明细
	CC_SYNTHESIZE(list<AddPurInquiryEntryDTO>, detail, Detail);

	/*修改专属*/
	//审核是否通过
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	//审核意见
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	//修改时间		   ;
	CC_SYNTHESIZE(string, update_time, Update_time);
	//修改人			;
	CC_SYNTHESIZE(string, update_by, Update_by);
	//核批人
	CC_SYNTHESIZE(string, approver, Approver);

public:
	friend void from_json(const json& j, AddPurInquiryDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, payment_method);
		BIND_FROM_TO_NORMAL(j, t, delivery_place);
		BIND_FROM_TO_NORMAL(j, t, contact);
		BIND_FROM_TO_NORMAL(j, t, phone);
		BIND_FROM_TO_NORMAL(j, t, fax);
		BIND_FROM_TO_NORMAL(j, t, email);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_I(j, t, is_rubric);
		BIND_FROM_TO_I(j, t, is_auto);
		BIND_FROM_TO_NORMAL(j, t, update_time);
		BIND_FROM_TO_NORMAL(j, t, update_by);
		BIND_FROM_TO_NORMAL(j, t, effective_time);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_NORMAL(j, t, create_time);
		BIND_FROM_TO_NORMAL(j, t, sys_org_code);
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		BIND_FROM_TO_NORMAL(j, t, approval_result_type);
		BIND_FROM_TO_NORMAL(j, t, approval_remark);
		BIND_FROM_TO_OBJ(j, t, detail,list<AddPurInquiryEntryDTO>);
	}


};


#endif  //__ADDPURINQUIRYDTO_H__


