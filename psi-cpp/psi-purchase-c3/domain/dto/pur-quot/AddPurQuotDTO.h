#pragma once
#ifndef _ADD_PUR_QUOT_DTO_
#define _ADD_PUR_QUOT_DTO_


#include "../../GlobalInclude.h"
#include "../FileDTO.h"
#include "PurQuotDetailDTO.h"
#include <list>
#include <vector>
#include "cinatra.hpp"
#include "JWTUtil.h"
using namespace cinatra;
using namespace nlohmann;


class AddPurQuotDTO :public FileDTO{

	// 单据id
	CC_SYNTHESIZE(string, id, Id);								
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);						
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);					
	//源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);			

	//源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);				
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);						
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//是否红字
	CC_SYNTHESIZE(int, isRubric, IsRubric);


	//是否临时供应商
	CC_SYNTHESIZE(int, isTempSupplier, IsTempSupplier);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
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
	CC_SYNTHESIZE(string, fax, Fax);
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
	//是否自动生成
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);

	//审核人
	CC_SYNTHESIZE(string, approver, Approver);
	//示例id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//核批结果类型
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
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
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//版本
	CC_SYNTHESIZE(int, version, Version);

	//新增明细
	CC_SYNTHESIZE(list<PurQuotDetailDTO>, detail, Detail);

public:
	//绑定JSON转换方法
	friend void from_json(const json& j, AddPurQuotDTO& t) {

		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, amt);

		BIND_FROM_TO_I(j, t, isRubric);
		BIND_FROM_TO_I(j, t, version);
		BIND_FROM_TO_I(j, t, isAuto);
		BIND_FROM_TO_I(j, t, isTempSupplier);
		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);

		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, srcBillId);
		BIND_FROM_TO_NORMAL(j, t, srcBillType);
		BIND_FROM_TO_NORMAL(j, t, bpmi_instance_id);
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, tempSupplierName);
		BIND_FROM_TO_NORMAL(j, t, deliveryMethod);
		BIND_FROM_TO_NORMAL(j, t, deliveryDate);
		BIND_FROM_TO_NORMAL(j, t, deliveryAddress);
		BIND_FROM_TO_NORMAL(j, t, contact);
		BIND_FROM_TO_NORMAL(j, t, phone);
		BIND_FROM_TO_NORMAL(j, t, fax);
		BIND_FROM_TO_NORMAL(j, t, email);
		BIND_FROM_TO_NORMAL(j, t, attachment);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_NORMAL(j, t, approvalResultType);
		BIND_FROM_TO_NORMAL(j, t, billStage);

		BIND_FROM_TO_NORMAL(j, t, approvalRemark);
		BIND_FROM_TO_NORMAL(j, t, effectiveTime);
		BIND_FROM_TO_NORMAL(j, t, sysOrdCode);
		BIND_FROM_TO_NORMAL(j, t, createBy);
		BIND_FROM_TO_NORMAL(j, t, createTime);
		BIND_FROM_TO_NORMAL(j, t, updateBy);
		BIND_FROM_TO_NORMAL(j, t, updateTime);

		BIND_FROM_TO_OBJ(j, t, detail, list<PurQuotDetailDTO>);
	}
};

#endif // !_ADD_PUR_QUOT_DTO_