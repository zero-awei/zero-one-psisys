/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/20 15:07:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "PurCompareService.h"
#include "../../dao/pur-compare/PurCompareDAO.h"
#include "../../dao/pur-compare/PurCompareDAO.h"
#include "../../domain/do/pur-compare/AddPurComDO.h"
#include "../../domain/do/pur-compare/ModPurComDO.h"
#include "../../domain/do/pur-compare/DelPurComDO.h"
#include "../../domain/do/pur-compare/PurComModBillStatusDO.h"
#include "SnowFlake.h"


PageVO<PurComFindBillVO> PurCompareService::listPurComFindBill(const PurComFindBillQuery& query)
{
	//构建返回对象
	PageVO<PurComFindBillVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	PurCompareDO obj;
	obj.setBillNo(query.getBillNo());
	obj.setSubject(query.getSubject());
	obj.setBillDateBegin(query.getBillDateBegin());
	obj.setBillDateEnd(query.getBillDateEnd());
	obj.setBillStage(query.getBillStage());
	obj.setIsEffective(query.getIsEffective());
	obj.setIsClosed(query.getIsClosed());
	obj.setIsVoided(query.getIsVoided());
	PurCompareDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<PurCompareDO> result = dao.selectPurComFindBill(obj, query.getPageIndex(), query.getPageSize());
	list<PurComFindBillVO> vr;
	for (PurCompareDO sub : result)
	{
		PurComFindBillVO vo;
		vo.setId(sub.getId());
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setSubject(sub.getSubject());
		vo.setSrcNo(sub.getSrcNo());
		vo.setPaymentMethod(sub.getPaymentMethod());
		vo.setDeliveryTime(sub.getDeliveryTime());
		vo.setBillStage(sub.getBillStage());
		vo.setIsEffective(sub.getIsEffective());
		vo.setIsClosed(sub.getIsClosed());
		vo.setIsVoided(sub.getIsVoided());
		vo.setDeliveryPlace(sub.getDeliveryPlace());
		vo.setRemark(sub.getRemark());
		vo.setIsAuto(sub.getIsAuto());
		vo.setIsRubric(sub.getIsRubric());
		vo.setEffectiveTime(sub.getEffectiveTime());
		vo.setApprover(sub.getApprover());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setSysOrgCode(sub.getSysOrgCode());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

PurComFindDetailBillVO PurCompareService::getPurComFindDetailBill(const PurComFindDetailBillQuery& query)
{
	// 领域模型转换
	PurCompareDO obj;
	obj.setBillNo(query.getBillNo());
	PurCompareEntryDO obj2;
	obj2.setBillNo(query.getBillNo());
	// 查询数据：比价单信息
	PurCompareDAO dao;
	list<PurCompareDO> result = dao.selectPurComFindDetailBill(obj);
	PurComFindDetailBillVO vo;
	if(!result.empty())
	{
		auto sub = result.front();
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setBillStage(sub.getBillStage());
		vo.setIsEffective(sub.getIsEffective());
		vo.setIsClosed(sub.getIsClosed());
		vo.setIsVoided(sub.getIsVoided());
		vo.setEffectiveTime(sub.getEffectiveTime());
		vo.setApprover(sub.getApprover());
		vo.setBpmiInstanceId(sub.getBpmiInstanceId());
		vo.setCreateTime(sub.getCreateTime());
		vo.setSysOrgCode(sub.getSysOrgCode());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setIsAuto(sub.getIsAuto());
		vo.setIsRubric(sub.getIsRubric());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSubject(sub.getSubject());
		vo.setSrcNo(sub.getSrcNo());
		vo.setPaymentMethod(sub.getPaymentMethod());
		vo.setDeliveryTime(sub.getDeliveryTime());
		vo.setDeliveryPlace(sub.getDeliveryPlace());
		vo.setRemark(sub.getRemark());
		vo.setAttachment(sub.getAttachment());
		vo.setApprovalRemark(sub.getApprovalRemark());
		vo.setApprovalResultType(sub.getApprovalResultType());
	}
	// 查询数据：明细列表
	list<PurCompareEntryDO> details = dao.selectPurComFindDetailBillEntry(obj2);
	PurComDetailsVO detailsvo;
	list<PurComDetailsVO> lvo;
	for (PurCompareEntryDO ones : details)
	{
		detailsvo.setEntryNo(ones.getEntryNo());
		detailsvo.setSupplierName(ones.getSupplierName());//tomodify:supplierId->suppliername
		detailsvo.setSrcNo(ones.getSrcNo());
		detailsvo.setMaterialName(ones.getMaterialName());
		detailsvo.setSpecifications(ones.getSpecifications());
		detailsvo.setUnitName(ones.getUnitName());//tomodify:unitId->unitname
		detailsvo.setQty(ones.getQty());
		detailsvo.setTaxRate(ones.getTaxRate());
		detailsvo.setPrice(ones.getPrice());
		detailsvo.setDiscountRate(ones.getDiscountRate());
		detailsvo.setAmt(ones.getAmt());
		detailsvo.setRanking(ones.getRanking());
		detailsvo.setRemark(ones.getRemark());
		detailsvo.setCustom1(ones.getCustom1());
		detailsvo.setCustom2(ones.getCustom2());
		lvo.push_back(detailsvo);
	}
	vo.setDetailsList(lvo);
	return vo;
}

// 报价单列表
std::list<PurComListVO> PurCompareService::listPurComList(const PurComListQuery& query)
{
	// 构建返回对象
	list<PurComListVO> lvo;
	// 领域模型转换
	PurCompareDO obj,obj2;
	obj.setBillNo(query.getBillNo());
	// 查询候选报价单ids
	PurCompareDAO dao;
	list<PurCompareDO> CanIds = dao.selectCandidateQuot(obj);
	if (CanIds.empty()) return lvo;
	else obj2.setCandidateQuotIds(CanIds.front().getCandidateQuotIds());
	// 查询报价单列表
	list<PurComQuotDO> result = dao.selectPurComList(obj2);
	PurComListVO vo;
	for (PurComQuotDO ones : result)
	{
		vo.setBillNo(ones.getBillNo());
		vo.setBillDate(ones.getBillDate());
		vo.setSubject(ones.getSubject());
		vo.setSupplierName(ones.getSupplierName());
		vo.setPaymentMethod(ones.getPaymentMethod());
		vo.setDeliveryTime(ones.getDeliveryTime());
		vo.setDeliveryPlace(ones.getDeliveryPlace());
		vo.setRemark(ones.getRemark());
		lvo.push_back(vo);
	}
	return lvo;
}
// 报价单分录列表
std::list<PurComDividedListVO> PurCompareService::listPurComDividedList(const PurComDividedListQuery& query)
{
	// 构建返回对象
	list<PurComDividedListVO> lvo;
	// 领域模型转换
	PurComQuotEntryDO obj;
	obj.setBillNo(query.getBillNo());
	// 查询报价单分录列表
	PurCompareDAO dao;
	list<PurComQuotEntryDO> result = dao.selectPurComDividedList(obj);
	PurComDividedListVO vo;
	for (PurComQuotEntryDO ones : result)
	{
		vo.setBillNo(ones.getBillNo());
		vo.setEntryNo(ones.getEntryNo());
		vo.setMaterialName(ones.getMaterialName());
		vo.setSpecifications(ones.getSpecifications());
		vo.setUnitName(ones.getUnitName());
		vo.setQty(stod(ones.getQty()));
		vo.setTaxRate(stod(ones.getTaxRate()));
		vo.setPrice(stod(ones.getPrice()));
		vo.setDiscountRate(stod(ones.getDiscountRate()));
		vo.setAmt(stod(ones.getAmt()));
		vo.setRemark(ones.getRemark());
		vo.setCustom1(ones.getCustom1());
		vo.setCustom2(ones.getCustom2());
		lvo.push_back(vo);
	}
	return lvo;
}


uint64_t PurCompareService::savePurCom(const AddPurComDTO& dto, PayloadDTO payload)
{
	//组装数据
	AddPurComDO data;
	// 雪花算法生成id
	SnowFlake randomId(21, 22);
	data.setId(randomId.nextId());

	data.setBillId(dto.getBillId());
	data.setBillDate(dto.getBillDate());
	data.setIsEffect(dto.getIsEffect());
	data.setIsClose(dto.getIsClose());
	data.setIsCancelled(dto.getIsCancelled());
	data.setEffectDate(dto.getEffectDate());
	data.setApprover(dto.getApprover());
	// 创建时间的数据暂时使用sql语句的now()
	//data.setMakeBillDate(dto.getMakeBillDate());
	data.setMakeBillDept(dto.getMakeBillDept());
	// 从payload中获取创建人
	data.setMakeBillPerson(payload.getUsername());

	data.setUdpateDate(dto.getUdpateDate());
	data.setUdpatePerson(dto.getUdpatePerson());
	data.setAutoBill(dto.getAutoBill());
	data.setRedBill(dto.getRedBill());
	data.setBillType(dto.getBillType());
	data.setBillTheme(dto.getBillTheme());
	data.setBillStatus(dto.getBillStatus());
	data.setInqueryBill(dto.getInqueryBill());
	data.setPayMethod(dto.getPayMethod());
	data.setDeliveryDate(dto.getDeliveryDate());
	data.setDeliveryPlace(dto.getDeliveryPlace());
	data.setRemark(dto.getRemark());


	//执行数据添加
	PurCompareDAO dao;
	return dao.insertPurCom(data);
}

bool PurCompareService::updatePurCom(const ModPurComDTO& dto, PayloadDTO payload)
{
	//组装传输数据
	ModPurComDO data;
	data.setBillId(dto.getBillId());
	data.setBillDate(dto.getBillDate());
	data.setIsEffect(dto.getIsEffect());
	data.setIsClose(dto.getIsClose());
	data.setIsCancelled(dto.getIsCancelled());
	data.setEffectDate(dto.getEffectDate());
	data.setApprover(dto.getApprover());
	data.setMakeBillDate(dto.getMakeBillDate());
	data.setMakeBillDept(dto.getMakeBillDept());
	data.setMakeBillPerson(dto.getMakeBillPerson());
	// 修改时间的数据暂时用sql语句的now()
	//data.setUdpateDate(dto.getUdpateDate());
	// 从payload中获取修改人
	data.setUdpatePerson(payload.getUsername());

	data.setAutoBill(dto.getAutoBill());
	data.setRedBill(dto.getRedBill());
	data.setBillType(dto.getBillType());
	data.setBillTheme(dto.getBillTheme());
	data.setBillStatus(dto.getBillStatus());
	data.setInqueryBill(dto.getInqueryBill());
	data.setPayMethod(dto.getPayMethod());
	data.setDeliveryDate(dto.getDeliveryDate());
	data.setDeliveryPlace(dto.getDeliveryPlace());
	data.setRemark(dto.getRemark());
	data.setAuditResult(dto.getAuditResult());
	data.setAuditRemark(dto.getAuditRemark());

	//执行数据修改
	PurCompareDAO dao;
	return dao.updatePurCom(data) == 1;
}

bool PurCompareService::removePurCom(const DelPurComDTO& dto)
{
	DelPurComDO data;
	data.setBillId(dto.getBillId());

	PurCompareDAO dao;
	return dao.deletePurCom(data) == 1;
}

bool PurCompareService::updatePurComBillStatus(const PurComModBillStatusDTO& dto, PayloadDTO payload)
{
	ModPurComBillStatusDO data;
	data.setBillId(dto.getBillId());
	data.setIsEffect(dto.getIsEffect());
	data.setIsClose(dto.getIsClose());
	data.setIsCancelled(dto.getIsCancelled());

	data.setUpdatePerson(payload.getUsername());

	PurCompareDAO dao;
	return dao.updatePurComBillStatus(data) == 1;
}
