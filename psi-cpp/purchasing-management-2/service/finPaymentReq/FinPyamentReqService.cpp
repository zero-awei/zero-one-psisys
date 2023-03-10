#include "stdafx.h"
#include "FinPyamentReqService.h"
#include "../../dao/finPaymentReq/FinPaymentReqDAO.h"
#include "../../lib-common/include/SimpleDateTimeFormat.h"

// 定义名字
#define MODIFY_DEFAULT(name) if (dto.get##name() != data.get##name()) {data.set##name(dto.get##name());}

// 添加采购付款申请订单
#define MODIFY(name) data.set##name(dto.get##name());


uint64_t FinPyamentReqService::saveData(const AddPaymentReqDTO& dto, const PayloadDTO& payload)
{
	// 组装数据
	FinPaymentReqManageDO data;
	SnowFlake sf(1, 3);
	string id = to_string(sf.nextId());
	string BillNo = dto.getBillNo();
	string time = SimpleDateTimeFormat::format();
	// 获取id
	data.setId(id);
	// 获取用户默认值
	data.setBillNo(BillNo);
	MODIFY(BillDate);
	MODIFY(SupplierId);
	MODIFY(OpDept);
	MODIFY(PaymentType);
	MODIFY(Operator);
	MODIFY(BillStage);
	// 获取用户信息
	data.setSysOrgCode(payload.getDepartment());
	data.setCreateBy(payload.getUsername());
	data.setCreateTime(time);
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(time);
	// 获取默认值
	MODIFY_DEFAULT(SrcBillType);
	MODIFY_DEFAULT(SrcBillId);
	MODIFY_DEFAULT(SrcNo);
	MODIFY_DEFAULT(Subject);
	MODIFY_DEFAULT(SupplierId);
	MODIFY_DEFAULT(OpDept);
	MODIFY_DEFAULT(Amt);
	MODIFY_DEFAULT(Remark);
	MODIFY_DEFAULT(Version);
	// 连接DAO层
	FinPaymentReqDAO dao;
	//然后将订单明细添加进数据库
	for (FinPaymentReqEtryDTO& dto : dto.getDetail()) {
		FinPaymentReqEntryManageDO data;
		//首先是进行id设置使用雪花算法
		data.setId(to_string(sf.nextId()));
		//设置和主表的链接键
		data.setMid(id);
		data.setBillNo(BillNo);
		// 进行必填值的插入
		MODIFY(EntryNo);
		// 默认值设置
		MODIFY_DEFAULT(SrcBillType);
		MODIFY_DEFAULT(SrcEntryId);
		MODIFY_DEFAULT(SrcNo);
		MODIFY_DEFAULT(Amt);
		MODIFY_DEFAULT(PaidAmt);
		MODIFY_DEFAULT(Remark);
		MODIFY_DEFAULT(Custom1);
		MODIFY_DEFAULT(Custom2);
		MODIFY_DEFAULT(Version);
		dao.insertEntry(data);
	}
	return dao.insert(data);
}

// 修改采购付款申请订单
uint64_t FinPyamentReqService::updateData(const ModPyamentReqDTO& dto, const PayloadDTO& payload)
{
	// 组装数据
	FinPaymentReqManageDO data;
	FinPaymentReqDAO dao;
	SnowFlake sf(1, 3);
	// 获取id
	string id = to_string(sf.nextId());
	string BillNo = dto.getBillNo();

	//获取用户默认值
	data.setId(id);
	//获取必填信息
	data.setBillNo(BillNo);
	MODIFY(BillDate);
	MODIFY(SupplierId);
	MODIFY(OpDept);
	MODIFY(Operator);
	MODIFY(CreateBy);
	MODIFY(CreateTime);
	//获取修改用户的信息，此处为添加订单人信息
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(SimpleDateTimeFormat::format());
	//存在默认值时的处理
	MODIFY_DEFAULT(SrcBillType);
	MODIFY_DEFAULT(SrcBillId);
	MODIFY_DEFAULT(SrcNo);
	MODIFY_DEFAULT(Subject);
	MODIFY_DEFAULT(Amt);
	MODIFY_DEFAULT(PaidAmt);
	MODIFY_DEFAULT(Attachment);
	MODIFY_DEFAULT(Remark);
	MODIFY_DEFAULT(Version);

	//将订单明细添加进数据库
	for (FinPaymentReqEtryDTO& dto : dto.getDetail()) {
		FinPaymentReqEntryManageDO data;
		//首先是进行id设置,用雪花算法
		data.setId(to_string(sf.nextId()));
		//设置和主表的外键
		data.setMid(id);
		data.setBillNo(BillNo);
		//进行必填值的插入
		MODIFY(EntryNo);
		//默认值设置
		MODIFY_DEFAULT(SrcBillType);
		MODIFY_DEFAULT(SrcEntryId);
		MODIFY_DEFAULT(SrcNo);
		MODIFY_DEFAULT(Amt);
		MODIFY_DEFAULT(PaidAmt);
		MODIFY_DEFAULT(Remark);
		MODIFY_DEFAULT(Custom1);
		MODIFY_DEFAULT(Custom2);
		MODIFY_DEFAULT(Version);
		dao.insertEntry(data);
	}
	return dao.insert(data);
}

bool FinPyamentReqService::removeData(string billNo)
{
	FinPaymentReqDAO dao;
	//首先获取附件信息
	list<FinPaymentReqManageDO> getdata = dao.selectByBillNo(billNo);
	if (getdata.size() == 1)
	{
		FinPaymentReqManageDO data = getdata.front();
		if (data.getAttachment() != "")
		{
#ifdef LINUX
			//Linux端读取配置文件
			FastDfsClient client("conf/client.conf", 3);
#else
			//windows端读取配置文件
			FastDfsClient client("1.15.240.108");
#endif
			string fieldName = data.getAttachment();
			//删除文件
			if (!fieldName.empty())
			{
				client.deleteFile(fieldName);
			}
		}
	}
	return dao.deleteByBillNo(billNo);
}

// 分页查询所有数据
PageVO<FinPaymentReqVO> FinPyamentReqService::queryList(const FinPaymentReqQuery& query) {
	// 组装数据
	PageVO<FinPaymentReqVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	FinPaymentReqDO obj;
	obj.setBill_no(query.getBillNo());
	obj.setBill_date(query.getBillDate());
	obj.setSubject(query.getSubject());
	obj.setBill_stage(query.getBillStage());
	obj.setIs_effective(query.getIsEffective());
	obj.setIs_closed(query.getIsClosed());
	obj.setIs_voided(query.getIsVoided());
	FinPaymentReqDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<FinPaymentReqDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<FinPaymentReqVO> vr;
	for (FinPaymentReqDO sub : result)
	{
		FinPaymentReqVO vo;
		vo.setBillNo(sub.getBill_no());
		vo.setBillDate(sub.getBill_date());
		vo.setSubject(sub.getSubject());
		vo.setSrcNo(sub.getSrc_no());
		vo.setSupplierId(sub.getSupplier_id());
		vo.setOpDept(sub.getOp_dept());
		vo.setOperator(sub.getOperator());
		vo.setAmt(sub.getAmt());
		vo.setPaidAmt(sub.getPaid_amt());
		vo.setBillStage(sub.getBill_stage());
		vo.setIsEffective(sub.getIs_effective());
		vo.setIsClosed(sub.getIs_closed());
		vo.setIsVoided(sub.getIs_voided());
		vo.setRemark(sub.getRemark());
		vo.setIsAuto(sub.getIs_auto());
		vo.setIsRubric(sub.getIs_rubric());
		vo.setEffectiveTime(sub.getEffective_time());
		vo.setApprover(sub.getApprover());
		vo.setCreateTime(sub.getCreate_time());
		vo.setCreateBy(sub.getCreate_by());
		vo.setSysOrgCode(sub.getSys_org_code());
		vo.setUpdateTime(sub.getUpdate_time());
		vo.setUpdateBy(sub.getUpdate_by());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}
//查询指定单据详细信息
FinPaymentDetailVO FinPyamentReqService::detailDate(const FinPaymentReqEntryQuery& query) {
	FinPaymentReqDAO dao;
	list<FinPaymentReqDO> pus = dao.selectBillNo(query.getBillNo());
	FinPaymentDetailVO po;
	if (!pus.empty()) {
		FinPaymentReqDO pu = *pus.begin();
		po.setBillNo(pu.getBill_no());
		po.setBillDate(pu.getBill_date());
		po.setIsEffective(pu.getIs_effective());
		po.setIsClosed(pu.getIs_closed());
		po.setIsVoided(pu.getIs_voided());
		po.setSubject(pu.getSubject());

		list<FinPaymentReqEntryDO> detailsResult = pu.getDetail();
		list<FinPaymentReqEntryVO> pbVO;
		for (FinPaymentReqEntryDO re : detailsResult)
		{
			FinPaymentReqEntryVO tep;
			tep.setSrcNo(re.getSrcNo());;
			tep.setAmt(re.getAmt());
			tep.setPaidAmt(re.getPaidAmt());
			tep.setRemark(re.getRemark());
			tep.setCustom1(re.getCustom1());
			tep.setCustom2(re.getCustom2());
			pbVO.push_back(tep);
		}
		po.setDetailBillsVO(pbVO);
	}
	return po;
}