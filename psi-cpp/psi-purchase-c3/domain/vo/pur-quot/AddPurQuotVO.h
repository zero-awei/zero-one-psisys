#ifndef _PUR_QUOT_VO_
#define _PUR_QUOT_VO_

#include "stdafx.h"
#include "../../GlobalInclude.h"




//新增供应报价单据
class AddPurQuotVO
{
	// 单据id
	CC_SYNTHESIZE(long, id, Id);
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//是否临时供应商
	CC_SYNTHESIZE(int, isTempSupplier, IsTempSupplier);
	//供应商
	CC_SYNTHESIZE(long, supplierId, SupplierId);
	//临时供应商名称
	CC_SYNTHESIZE(string, tempSupplierName, TempSupplierName);
	//付款方式
	CC_SYNTHESIZE(string, deliveryMethod, DeliveryMethod);
	//交货日期
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	//交货地点
	CC_SYNTHESIZE(string, deliveryAddress, DeliveryAddress);
	//联系人
	CC_SYNTHESIZE(string, contact, Contact);
	//联系电话
	CC_SYNTHESIZE(string, phone, Phone);
	//传真
	CC_SYNTHESIZE(string, tax, Tax);
	//电子邮件
	CC_SYNTHESIZE(string, email, Email);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//金额
	CC_SYNTHESIZE(double, amt, Amt);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//单据阶段
	CC_SYNTHESIZE(int, billStage, BillStage);
	//审核人
	CC_SYNTHESIZE(string, approver, Approver);
	//核批结果类型
	CC_SYNTHESIZE(int, approvalResultType, ApprovalResultType);
	//核批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//是否生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//是否已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//创建部门
	CC_SYNTHESIZE(string, sysOrdCode, SysOrdCode);
	//创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//修改时间
	CC_SYNTHESIZE(string, updateTime, updateTime);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(AddPurQuotVO, 
		id, billNo, billDate, subject,
		srcNo, isTempSupplier, supplierId, tempSupplierName,
		deliveryMethod, deliveryDate, deliveryAddress, contact,
		phone, tax, email, qty,
		amt, attachment, remark, billStage,
		approver, approvalResultType, approvalRemark, isEffective,
		effectiveTime, isClosed, isVoided, sysOrdCode,
		createBy, createTime, updateBy, updateTime);
};


#endif // !_PUR_QUOT_VO_