#include "stdafx.h"
#include "finPyamentReqService.h"
#include "../../dao/finPaymentReq/finPaymentReqDAO.h"

//����һ������������Ĭ��ֵ���޸�
#define MODIFY_DEFAULT(name) if (dto.get##name() != data.get##name()) {data.set##name(dto.get##name());}

//����һ������������ֵ���޸�
#define MODIFY(name) data.set##name(dto.get##name());

string getTime1()
{
	time_t now = time(0);
	struct tm t;

	localtime_s(&t, &now);

	// ����Ϣ������ַ�����
	stringstream ss;
	ss << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec;
	return ss.str();
}

uint64_t FinPyamentReqService::saveData(const AddPaymentReqDTO& dto, const PayloadDTO& payload)
{
	//���Ƚ������������ӽ����ݿ�
	//��װ��������
	FinPaymentReqManageDO data;
	SnowFlake sf(1, 3);
	string id = to_string(sf.nextId());
	string BillNo = dto.getBillNo();
	string time = getTime1();
	//�����ǽ���id����ʹ��ѩ���㷨
	data.setId(id);
	//��ȡ������Ϣ
	data.setBillNo(BillNo);
	MODIFY(BillDate);
	MODIFY(SupplierId);
	MODIFY(OpDept);
	MODIFY(PaymentType);
	MODIFY(Operator);
	MODIFY(BillStage);
	//��ȡ�û�����Ϣ���˴�Ϊ���Ӷ�������Ϣ
	data.setSysOrgCode(payload.getDepartment());
	data.setCreateBy(payload.getUsername());
	data.setCreateTime(time);
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(time);
	//����Ĭ��ֵʱ�Ĵ���
	MODIFY_DEFAULT(SrcBillType);
	MODIFY_DEFAULT(SrcBillId);
	MODIFY_DEFAULT(SrcNo);
	MODIFY_DEFAULT(Subject);
	MODIFY_DEFAULT(SupplierId);
	MODIFY_DEFAULT(OpDept);
	MODIFY_DEFAULT(Amt);
	MODIFY_DEFAULT(Remark);
	MODIFY_DEFAULT(Version);
	//ִ�������޸�
	FinPaymentReqDAO dao;
	//Ȼ�󽫶�����ϸ���ӽ����ݿ�
	for (FinPaymentReqEtryDTO& dto : dto.getDetail()) {
		FinPaymentReqEntryManageDO data;
		//�����ǽ���id����ʹ��ѩ���㷨
		data.setId(to_string(sf.nextId()));
		//���ú����������Ӽ�
		data.setMid(id);
		data.setBillNo(BillNo);
		//���б���ֵ�Ĳ���
		MODIFY(EntryNo);
		//Ĭ��ֵ����
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


uint64_t FinPyamentReqService::updateData(const ModPyamentReqDTO& dto, const PayloadDTO& payload)
{
	//���Ƚ������������ӽ����ݿ�
	//��װ��������
	FinPaymentReqManageDO data;
	FinPaymentReqDAO dao;
	SnowFlake sf(1, 3);
	//ʹ��ѩ���㷨����id
	string id = to_string(sf.nextId());
	string BillNo = dto.getBillNo();

	//����id����
	data.setId(id);
	//��ȡ������Ϣ
	data.setBillNo(BillNo);
	MODIFY(BillDate);
	MODIFY(SupplierId);
	MODIFY(OpDept);
	MODIFY(Operator);
	MODIFY(CreateBy);
	MODIFY(CreateTime);
	//��ȡ�޸��û�����Ϣ���˴�Ϊ���Ӷ�������Ϣ
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(getTime1());
	//����Ĭ��ֵʱ�Ĵ���
	MODIFY_DEFAULT(SrcBillType);
	MODIFY_DEFAULT(SrcBillId);
	MODIFY_DEFAULT(SrcNo);
	MODIFY_DEFAULT(Subject);
	MODIFY_DEFAULT(Amt);
	MODIFY_DEFAULT(PaidAmt);
	MODIFY_DEFAULT(Attachment);
	MODIFY_DEFAULT(Remark);
	MODIFY_DEFAULT(Version);
	//ִ�������޸�

	//Ȼ�󽫶�����ϸ���ӽ����ݿ�
	for (FinPaymentReqEtryDTO& dto : dto.getDetail()) {
		FinPaymentReqEntryManageDO data;
		//�����ǽ���id����,��ѩ���㷨
		data.setId(to_string(sf.nextId()));
		//���ú����������
		data.setMid(id);
		data.setBillNo(BillNo);
		//���б���ֵ�Ĳ���
		MODIFY(EntryNo);
		//Ĭ��ֵ����
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
	//���Ȼ�ȡ������Ϣ
	list<FinPaymentReqManageDO> getdata = dao.selectByBillNo(billNo);
	if (getdata.size() == 1)
	{
		FinPaymentReqManageDO data = getdata.front();
		if (data.getAttachment() != "")
		{
#ifdef LINUX
			//����ͻ��˶���
			FastDfsClient client("conf/client.conf", 3);
#else
			//����ͻ��˶���
			FastDfsClient client("1.15.240.108");
#endif
			string fieldName = data.getAttachment();
			//ɾ���ļ�
			if (!fieldName.empty())
			{
				client.deleteFile(fieldName);
			}
		}
	}
	return dao.deleteByBillNo(billNo);
}

PageVO<FinPaymentReqVO> FinPyamentReqService::queryList(const FinPaymentReqQuery& query) {
	//�������ض���
	PageVO<FinPaymentReqVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
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

	//��ҳ��ѯ����
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
//��ѯָ��������ϸ��Ϣ
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