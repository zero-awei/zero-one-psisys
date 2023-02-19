#pragma once

#ifndef _AddQtrkBill_DTO_
#define _AddQtrkBill_DTO_
#include "../../GlobalInclude.h"
/**
 * 添加其他入库单传输对象
 */
class AddQtrkBillDTO
{
	//必填
	//单据编号
	CC_SYNTHESIZE(string, bill, Bill);//自动生成
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);

	//选填############
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//供应商
	CC_SYNTHESIZE(string, supplier, Supplier);
	//入库经办
	CC_SYNTHESIZE(string, handler, Handler);
	//明细*********
	//分录号
	CC_SYNTHESIZE(uint64_t, entryNo, EntryNo);
	//物料
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//规格型号
	CC_SYNTHESIZE(string, model, Model);
	//仓库
	CC_SYNTHESIZE(string, warehouseId, WarehouseId);
	//单位
	CC_SYNTHESIZE(string, depart, Depart);
	
	//入库数量
	CC_SYNTHESIZE(uint64_t, inhouse, Inhouse);
	//单位金额
	CC_SYNTHESIZE(double, permoney, Permoney);
	//入库金额
	CC_SYNTHESIZE(double, inCost, InCost);
	//明细：备注
	CC_SYNTHESIZE(string, remarK, RemarK);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);

	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);

	////单据阶段(不可填)
	//CC_SYNTHESIZE(string, billStage, BillStage);
	////已生效
	//CC_SYNTHESIZE(int, isEffective, IsEffective);
	////已关闭
	//CC_SYNTHESIZE(int, isClosed, IsClosed);
	////已作废
	//CC_SYNTHESIZE(int, isVoided, IsVoided);
	////生效时间
	//CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	////核批人 
	//CC_SYNTHESIZE(string, approver, Approver);
	////审批实例***
	//CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	////制单人*******
	//CC_SYNTHESIZE(string, createBy, CreateBy);
	////制单时间
	//CC_SYNTHESIZE(string, createTime, CreateTime);
	////制单部门
	//CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	////修改时间
	//CC_SYNTHESIZE(string, updateTime, UpdateTime);
	////修改人
	//CC_SYNTHESIZE(string, updateBy, UpdateBy);
	////自动单据
	//CC_SYNTHESIZE(int, isAuto, IsAuto);
	////红字单据
	//CC_SYNTHESIZE(int, isRubric, IsRubric);
	////有应付
	//CC_SYNTHESIZE(int, hasRp, HasRp);



public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddQtrkBillDTO& t); // NOLINT
	BIND_TO_JSON(AddQtrkBillDTO, bill, billDate, subject, supplier, handler, entryNo, materialId, model, warehouseId
		,depart, inhouse, permoney, inCost, remarK, remark, custom1, custom2, attachment);
};

#endif // !_AddQtrkBill_DTO_