#pragma once

#ifndef _QueryQtrkBillDetails_DTO_
#define _QueryQtrkBillDetails_DTO_
#include "../../GlobalInclude.h"
#include "../FileDTO.h"
/**
 * ��ѯ�����б���ϸ��Ϣ�������
 */
class QueryQtrkBillDetailsDTO:public FileDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ��������-��ʼ
	CC_SYNTHESIZE(string, billDateStart, BillDateStart);
	// ��������-����
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	// �Ƿ���Ч
	CC_SYNTHESIZE(uint64_t, isEffective, IsEffective);
	// �Ƿ�ر�
	CC_SYNTHESIZE(uint64_t, isClosed, IsClosed);
	// �Ƿ�����
	CC_SYNTHESIZE(uint64_t, isVoided, IsVoided);


public:
	// ��JSONת������
	friend void from_json(const json& j, QueryQtrkBillDetailsDTO& t); // NOLINT
	BIND_TO_JSON(QueryQtrkBillDetailsDTO, id, billDateStart, billDateEnd, subject, supplierId, billStage, isEffective, isClosed, isVoided);
};

#endif // !_QueryBillList_DTO_