#pragma once

#ifndef _PURINQUIRY_VO_
#define _PURINQUIRY_VO_

#include "../../GlobalInclude.h"

/**
 * 显示对象 —— 采购询价单列表、指定采购询价单列表、询价单明细（采购申请单）
 */


//采购询价单列表 - 基本信息
class PurInquiryFindBillVO
{
	//单据编号  
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    // varchar
	//单据日期
	CC_SYNTHESIZE(string, purInquiryBillDate, purInquiryBillDate);  // varchar
	//单据主题 
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);  // varchar
	//源单号
	CC_SYNTHESIZE(string, purInquirySrcBillId, PurInquirySrcBillId);  // varchar
	//交货日期
	CC_SYNTHESIZE(string, purInquiryDeliveryTime, purInquiryDeliveryTime);  //datatime
	//数量
	CC_SYNTHESIZE(double, purInquiryQty, purInquiryQty);  // decimal
	//参考金额
	CC_SYNTHESIZE(double, purInquiryAmt, purInquiryAmt);  // decimal
	//报价单数
	CC_SYNTHESIZE(int, purInquiryQuotCount, purInquiryQuotCount);   // int


	//单据阶段（公共接口）


	//是否生效
	CC_SYNTHESIZE(int, purInquiryIsEffective, PurInquiryIsEffective);  
	//是否关闭
	CC_SYNTHESIZE(int, purInquiryIsClosed, PurInquiryIsClosed);  
	//是否作废
	CC_SYNTHESIZE(int, purInquiryIsVoided, PurInquiryIsVoided); 
	//交货地点
	CC_SYNTHESIZE(string, purInquiryDeliveryPlace, PurInquiryDeliveryPlace);   
	//联系人
	CC_SYNTHESIZE(string, purInquiryContact, PurInquiryContact);  
	//联系电话
	CC_SYNTHESIZE(string, purInquiryPhone, PurInquiryPhone);  
	//传真
	CC_SYNTHESIZE(string, purInquiryFax, PurInquiryFax);  
	//电子邮件
	CC_SYNTHESIZE(string, purInquiryEmail, PurInquiryEmail);   
	//备注
	CC_SYNTHESIZE(string, purInquiryRemark, PurInquiryRemark);   
	//自动单据
	CC_SYNTHESIZE(int, purInquiryIsAuto, PurInquiryIsAuto);   
	//红字单据 
	CC_SYNTHESIZE(int, purInquiryIsRubric, PurInquiryIsRubric);   
	//生效时间
	CC_SYNTHESIZE(string, purInquiryEffectiveTime, PurInquiryEffectiveTime);   
	//核批人
	CC_SYNTHESIZE(string, purInquiryApprover, PurInquiryApprover);   
	//制单时间
	CC_SYNTHESIZE(string, purInquiryCreateTime, PurInquiryCreateTime);   
	//制单人
	CC_SYNTHESIZE(string, purInquiryCreateBy, PurInquiryCreateBy);   
	//制单部门
	CC_SYNTHESIZE(string, purInquirySysOrgCode, PurInquirySysOrgCode);   
	//修改时间
	CC_SYNTHESIZE(string, purInquiryUpdateTime, PurInquiryUpdateTime);   
	//修改人
	CC_SYNTHESIZE(string, purInquiryUpdateBy, PurInquiryUpdateBy);   

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurInquiryFindBillVO, purInquiryBillNo, purInquiryBillDate, purInquirySubject, purInquirySrcBillId,
		purInquiryDeliveryTime, purInquiryQty, purInquiryAmt, purInquiryQuotCount, purInquiryIsEffective, purInquiryIsClosed,
		purInquiryIsVoided, purInquiryDeliveryPlace, purInquiryContact, purInquiryPhone, purInquiryFax, purInquiryEmail,
		purInquiryRemark, purInquiryIsAuto, purInquiryIsRubric, purInquiryEffectiveTime, purInquiryApprover,
		purInquiryCreateTime, purInquiryCreateBy, purInquirySysOrgCode, purInquiryUpdateTime, purInquiryUpdateBy);
};


//指定询价单详细信息
class PurInquiryFindDetailBillVO
{
//基本信息
	//单据编号  
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);     
	//单据日期
	CC_SYNTHESIZE(string, purInquiryBillDate, purInquiryBillDate);   

	
	//单据阶段（公共接口）


//单据状态
	//是否生效
	CC_SYNTHESIZE(int, purInquiryIsEffective, PurInquiryIsEffective);  
	//是否关闭
	CC_SYNTHESIZE(int, purInquiryIsClosed, PurInquiryIsClosed);   
	//是否作废
	CC_SYNTHESIZE(int, purInquiryIsVoided, PurInquiryIsVoided);   
	//单据主题
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);   
	//付款方式
	CC_SYNTHESIZE(string, purInquiryPaymentMethod, PurInquiryPaymentMethod);   
	//交货地点
	CC_SYNTHESIZE(string, purInquiryDeliveryPlace, PurInquiryDeliveryPlace);    
	//联系人
	CC_SYNTHESIZE(string, purInquiryContact, PurInquiryContact);   
	//联系电话
	CC_SYNTHESIZE(string, purInquiryPhone, PurInquiryPhone);   
	//传真
	CC_SYNTHESIZE(string, purInquiryFax, PurInquiryFax);   
	//电子邮件
	CC_SYNTHESIZE(string, purInquiryEmail, PurInquiryEmail);   
	//报价单数
	CC_SYNTHESIZE(int, purInquiryQuotCount, purInquiryQuotCount);    

//附加
	//备注
	CC_SYNTHESIZE(string, purInquiryRemark, PurInquiryRemark);   
	//核批意见
	CC_SYNTHESIZE(string, purInquiryApprovalRemark, PurInquiryApprovalRemark);   
	//附件
	CC_SYNTHESIZE(string, purInquiryAttachment, PurInquiryAttachment);   
	//核批结果
	CC_SYNTHESIZE(string, purInquiryApprovalResultType, PurInquiryApprovalResultType);   

public:
// 绑定JSON转换方法
	BIND_TO_JSON(PurInquiryFindDetailBillVO, purInquiryBillNo, purInquiryBillDate, purInquiryIsEffective, purInquiryIsClosed,
		purInquiryIsVoided, purInquirySubject, purInquiryPaymentMethod, purInquiryDeliveryPlace, purInquiryContact,
		purInquiryPhone, purInquiryFax, purInquiryEmail, purInquiryQuotCount, purInquiryRemark, purInquiryApprovalRemark,
		purInquiryApprovalResultType);
};


//采购询价单明细—采购申请单
class EntryPurInquiryVO
{
	//源单类型
	CC_SYNTHESIZE(string, purReqSrcBillType, PurReqSrcBillType);
	//源单分录号
	CC_SYNTHESIZE(string, purReqSrcEntryNo, PurReqSrcEntryNo);
	//物料
	CC_SYNTHESIZE(string, purReqMaterialId, PurReqMaterialId);


	//规格型号（公共接口）
	

	//单位
	CC_SYNTHESIZE(string, purReqUnitId, PurReqUnitId);
	//数量
	CC_SYNTHESIZE(double, purReqQty, PurReqQty);
	//税率%
	CC_SYNTHESIZE(double, purReqTaxRate, PurReqTaxRate);
	//参考含税单价
	CC_SYNTHESIZE(double, purReqPrice, PurReqPrice);
	//参考含税金额
	CC_SYNTHESIZE(double, purReqAmt, PurReqAmt);
	//备注
	CC_SYNTHESIZE(string, purReqRemark, PurReqRemark);
	//自定义1
	CC_SYNTHESIZE(string, purReqCustom1, PurReqCustom1);
	//自定义2
	CC_SYNTHESIZE(string, purReqCustom2, PurReqCustom2);

public:
// 绑定JSON转换方法
	BIND_TO_JSON(EntryPurInquiryVO, purReqSrcBillType, purReqSrcEntryNo, purReqMaterialId, purReqUnitId,
		purReqQty, purReqTaxRate, purReqPrice, purReqAmt, purReqRemark, purReqCustom1, purReqCustom2);
};



#endif // !_PURINQUIRY_VO_
