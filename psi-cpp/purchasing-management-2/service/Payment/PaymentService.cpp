#include "stdafx.h"
#include "PaymentService.h"
#include "../../dao/Payment/PaymentDAO.h"

// 通过ID删除数据
bool PaymentService::DePayment(const DePaymentDTO& dto)
{
	//组装传输数据
	PaymentDAO dao;
	FinPayReqDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//执行数据修改
	if (dto.getId() != "" || dto.getBill_no() != "")
	{
		data.setId(dto.getId());
		return dao.deleteById(data) == 1;
	}
}

// 修改单据状态
bool PaymentService::ChangePayStatus(const PaymentChangeDTO& dto)
{
	//组装传输数据
	FinPayReqDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//执行数据修改
	PaymentDAO dao;
	if (dto.getOpType() == PaymentChangeDTO::CLOSE || dto.getOpType() == PaymentChangeDTO::UNCLOSE)
	{
		data.setIs_closed(dto.getIs_closed());
		return dao.ChangeStatusClose(data) == 1;
	}
	else if (dto.getOpType() == PaymentChangeDTO::CANCEL)
	{
		data.setIs_voided(dto.getIs_voided());
		return dao.ChangeStatusCancel(data) == 1;
	}
}

// 添加数据
bool PaymentService::AddPay(const AddPaymentDTO& dto)
{
	//组装传输数据
	FinPayReqDO data;
	data.setBill_no(dto.getBill_no());
	data.setId(dto.getId());
	//执行数据修改
	PaymentDAO dao;
	if ( dto.getBill_no() != "")
	{
		data.setId(dto.getId());
		return dao.insertPrepay(data) == 1;
	}
}

// 保存数据
uint64_t PaymentService::saveData(const AddPaymentDTO& dto, const PayloadDTO& payload)
{
	//首先将订单本体添加进数据库
	//组装传输数据
	FinPayReqDO data;
	SnowFlake sf(1, 3);
	string id = to_string(sf.nextId());
	string BillNo = dto.getBillNo();
	string time = getTime();
	//首先是进行id设置使用雪花算法
	data.setId(id);
	//获取必填信息
	data.setBillNo(BillNo);
	MODIFY(BillDate);
	MODIFY(RequestDept);
	MODIFY(Requester);
	MODIFY(RequestTime);
	MODIFY(BillStage);
	//获取用户的信息，此处为添加订单人信息
	data.setSysOrgCode(payload.getDepartment());
	data.setCreateBy(payload.getUsername());
	data.setCreateTime(time);
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(time);
	//特殊处理附件
	MODIFY_DEFAULT(Attachment);
	//存在默认值时的处理
	MODIFY_DEFAULT(SrcBillType);
	MODIFY_DEFAULT(SrcBillId);
	MODIFY_DEFAULT(SrcNo);
	MODIFY_DEFAULT(Subject);
	MODIFY_DEFAULT(PurType);
	MODIFY_DEFAULT(Qty);
	MODIFY_DEFAULT(Amt);
	MODIFY_DEFAULT(OrderedQty);
	MODIFY_DEFAULT(Remark);
	MODIFY_DEFAULT(Version);
	//执行数据修改
	PurReqDAO dao;
	//然后将订单明细添加进数据库
	for (PurReqEntryDTO& dto : dto.getDetail()) {
		PurReqEntryAdamDO data;
		//首先是进行id设置使用雪花算法
		data.setId(to_string(sf.nextId()));
		//设置和主表的链接键
		data.setMid(id);
		data.setBillNo(BillNo);
		//进行必填值的插入
		MODIFY(EntryNo);
		MODIFY(MaterialId);
		MODIFY(UnitId);
		MODIFY(Qty);
		MODIFY(OrderedQty);
		//默认值设置
		MODIFY_DEFAULT(SrcBillType);
		MODIFY_DEFAULT(SrcEntryId);
		MODIFY_DEFAULT(SrcNo);
		MODIFY_DEFAULT(TaxRate);
		MODIFY_DEFAULT(SrcNo);
		MODIFY_DEFAULT(Price);
		MODIFY_DEFAULT(Amt);
		MODIFY_DEFAULT(SuggestSupplierId);
		MODIFY_DEFAULT(Remark);
		MODIFY_DEFAULT(Custom1);
		MODIFY_DEFAULT(Custom2);
		MODIFY_DEFAULT(Version);
		dao.insertEntry(data);
	}
	return dao.insert(data);
}