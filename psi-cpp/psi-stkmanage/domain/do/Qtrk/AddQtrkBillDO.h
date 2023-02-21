#pragma once

#ifndef _AddQtrkBill_DO_
#define _AddQtrkBill_DO_
#include "../../GlobalInclude.h"
/**
 * 添加其他入库单数据库实体类
 */
class AddQtrkBillDO
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
	AddQtrkBillDO() {
		bill = "qtrk";
		billDate = "2023-2-20";
		subject = -1;
		supplier = "wangwu";
		handler = "haahah";
		entryNo = 0;
		materialId= 1;
		model = 1;
		warehouseId = "f";
		depart = "efwf";
		inhouse = 1;
		permoney = 29.1;
		inCost = 23;
		remarK = "wag";
		custom1 = "dfef";
		custom2 = "sfe";
		remark = "wangwu";
		attachment = "wangwu";
	}
};

#endif // !_AddQtrkBill_DO_