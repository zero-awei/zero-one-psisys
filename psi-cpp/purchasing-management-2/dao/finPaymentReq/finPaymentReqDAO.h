#pragma once

#ifndef _FIN_PAYMENT_REQ_DAO_
#define _FIN_PAYMENT_REQ_DAO_
#include "BaseDAO.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqManageDO.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqEntryManageDO.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqEntryDO.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqDO.h"


/**
 * ʾ�������ݿ����ʵ��
 */
class FinPaymentReqDAO : public BaseDAO
{
public:
	// ��������(����/�ύ) ��������
	uint64_t insert(const FinPaymentReqManageDO& obj);

	// ������ϸ����(����/�ύ) ��������
	uint64_t insertEntry(const FinPaymentReqEntryManageDO& obj);

	// ͨ��billNoɾ������
	int deleteByBillNo(string billNo);

	//ͨ��BillNo������������ ��������ֻ��һ������ֻ����һ��
	list<FinPaymentReqManageDO> selectByBillNo(const string& billNo);

	//ͨ��BillNo������ϸ������
	list<FinPaymentReqEntryManageDO> selectEntryByBillNo(const string& billNo);

	// ͳ����������
	uint64_t count(const FinPaymentReqDO& iObj);
	// ��ҳ��ѯ����
	list<FinPaymentReqDO> selectWithPage(const FinPaymentReqDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// ͨ����Ų鿴��ϸ��Ϣ
	list<FinPaymentReqDO> selectBillNo(const string& billNo);

};
#endif // _FIN_PAYMENT_REQ_DAO_