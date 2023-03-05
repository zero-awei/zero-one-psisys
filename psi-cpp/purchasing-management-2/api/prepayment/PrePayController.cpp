#include "stdafx.h"
#include "PrePayController.h"
#include "../../domain/query/prepaymentbill/PrePayExportQuery.h"
#include "../../service/prepayment/PrePayService.h"
#include "../lib-common/include/CharsetConvertHepler.h"
#include "../../domain/vo/PurOrder/PurOrderVO.h"


//
//负责人：Qi
JsonVO<PageVO<PrepaymentBillVO>> PrePayController::execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload)
{
	//��ѯ�ɹ�
	PrePayService service;
	PageVO<PrepaymentBillVO> result = service.listAll(query);
	return JsonVO<PageVO<PrepaymentBillVO>>(result, RS_SUCCESS);
}

//��ѯָ��������ϸ��Ϣ
// �����ˣ�Qi
JsonVO<PageVO<PrepaymentDetailBillVO>> PrePayController::execQueryPayDetailBill(const PrepayDetailBillQuery& query, const PayloadDTO& payload)
{
	PrePayService service;
	PageVO<PrepaymentDetailBillVO> result = service.getAll(query);
	if (result.getTotal() > 0) {
		return JsonVO<PageVO<PrepaymentDetailBillVO>>(result, RS_SUCCESS);
	}
	else {
		return JsonVO<PageVO<PrepaymentDetailBillVO>>(result, RS_PARAMS_INVALID);
	}

}

//����Ԥ�����뵥
// �����ˣ�Qi
JsonVO<uint64_t> PrePayController::execAddPay(const AddPayDTO& dto, const PayloadDTO& payload)
{
	//��Ӧ���
	JsonVO<uint64_t> result;
	PrePayService service;
	uint64_t id = service.saveData(dto, payload);
	if (id != 0) {
		result.success(id);
	}
	else {
		result.fail(id);
	}
	//��Ӧ���
	return result;
}

//�޸�Ԥ�����뵥
// �����ˣ�Qi
JsonVO<uint64_t> PrePayController::execModifyPay(const AddPayDTO& dto, const PayloadDTO& payload)
{
	PrePayService service;
	JsonVO<uint64_t> result;
	if (service.updateData(dto, payload)) {
		result.success(1);
	}
	else {
		result.fail(0);
	}
	return result;
}

// �޸ĵ���״̬
// �����ˣ�Andrew
JsonVO<string> PrePayController::execModifyPayBillStatus(const PayModBillStatusDTO& dto, const PayloadDTO& payload)
{
	PrePayService service;
	JsonVO<string> result;

	// ����У��
	if (dto.getId() == "" || dto.getBill_no() == "") // ���ID�͵��ݱ��Ϊ��
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	// ���������Ϊ�ջ��߲���ö������Ԫ�����������
	if (dto.getOpType() != dto.CLOSE && dto.getOpType() != dto.CANCEL && dto.getOpType() != dto.UNCLOSE)
		return JsonVO<string>({}, RS_PARAMS_INVALID);

	// ִ��
	if (service.updateStatus(dto, payload)) {
		result.success(dto.getId());
		switch (dto.getOpType())
		{
		case dto.CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("�رճɹ�"));
			break;
		case dto.UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("���رճɹ�"));
			break;
		case dto.CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("���ϳɹ�"));
			break;
		}
	}
	else {
		result.fail(dto.getId());
		switch (dto.getOpType())
		{
		case dto.CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("�ر�ʧ��"));
			break;
		case dto.UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("���ر�ʧ��"));
			break;
		case dto.CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("����ʧ��"));
			break;
		}
	}
	return result;
}
//�ɹ������б�
//�����ˣ��첻ϴ
JsonVO<PageVO<PurOrderVO>> PrePayController::execQuerypayFindBill(const PurOrderQuery& query, const PayloadDTO& payload)
{
	PrePayService service;
	PageVO<PurOrderVO> result = service.listAll(query);
	return JsonVO<PageVO<PurOrderVO>>(result, RS_SUCCESS);
}

//�ɹ��������б�
//�����ˣ��첻ϴ
JsonVO<PurOrderVO> PrePayController::execQueryPayDetailBill(const PurOrderQuery& query, const PayloadDTO& payload)
{
	if (query.getBill_no() == "") {
		return JsonVO<PurOrderVO>({}, RS_PARAMS_INVALID);
	}
	PrePayService service;
	PurOrderVO result = service.getAll(query);
	return JsonVO<PurOrderVO>({}, RS_SUCCESS);
}

//ɾ��
//�����ˣ��첻ϴ
JsonVO<string> PrePayController::execRemoveDePayId(const DePayDTO& dto)
{
	PrePayService service;
	JsonVO<string> result;
	// ����У��
	if (dto.getId() == "" || dto.getBill_no() == "") {// ���ID�͵��ݱ��Ϊ��
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	}
	//ִ������ɾ��
	if (service.DePrePayId(dto)) {
		result.success(dto.getId());
		result.setMessage(CharsetConvertHepler::ansiToUtf8("ɾ���ɹ�"));
	}
	else {
		result.fail(dto.getId());
		result.setMessage(CharsetConvertHepler::ansiToUtf8("ɾ��ʧ��"));
	}
	//��Ӧ���
	return result;
}