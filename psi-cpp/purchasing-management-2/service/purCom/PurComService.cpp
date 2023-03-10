/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/17 11:13:11

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
#include "PurComService.h"
#include "../../dao/purCom/PurComDAO.h"
#include "../../dao/purOrder/PurOrderDAO.h"

// 分页查询所有数据
// 负责人：J4nnA
PageVO<PurComVO> PurComService::listAll(const PurComQuery& query)
{
	// 构建返回对象
	PageVO<PurComVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	// 构造DO
	PurComDO obj;
	obj.setBill_no(query.getBill_no());
	obj.setBill_date(query.getBill_date());
	
	// 生成DAO层对象
	PurComDAO dao;
	
	//查询数据总条数
	uint64_t count = dao.count(obj);
	//
	//待加入筛选条件
	//
	if (count <= 0)
	{
		return pages;
	}

	// 调用DAO层功能,传入DO
	pages.setTotal(count);
	pages.calcPages();
	list<PurComDO> result = dao.selectPurCom(obj, query.getPageIndex(), query.getPageSize());
	list<PurComVO> vr;		//分页查询返回的VO列表
	// 根据DAO层返回的DO，对VO成员进行赋值

	for (PurComDO sub : result)
	{
		// 构造用于返回的VO
		PurComVO vo;

		vo.setId(sub.getId());
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());

		vo.setSrc_bill_type(sub.getSrc_bill_type());
		vo.setSrc_bill_id(sub.getSrc_bill_id());
		vo.setSrc_no(sub.getSrc_no());

		vo.setSubject(sub.getSubject());
		vo.setIs_rubric(sub.getIs_rubric());
		vo.setCandidate_quot_ids(sub.getCandi_date_quot_ids());
		
		vo.setPayment_method(sub.getPayment_method());
		vo.setDelivery_place(sub.getDelivery_place());
		vo.setDelivery_time(sub.getDelivery_time());

		vo.setAttachment(sub.getAttachment());
		vo.setRemark(sub.getRemark());
		vo.setIs_auto(sub.getIs_auto());

		vo.setBill_stage(sub.getBill_stage());
		vo.setApprover(sub.getApprover());
		vo.setBpmi_instance_id(sub.getBpmi_instance_id());

		vo.setApproval_result_type(sub.getApproval_result_type());
		vo.setApproval_remark(sub.getApproval_remark());
		vo.setIs_effective(sub.getIs_effective());
		
		vo.setEffective_time(sub.getEffective_time());
		vo.setIs_closed(sub.getIs_closed());
		vo.setIs_voided(sub.getIs_voided());

		vo.setSys_org_code(sub.getSys_org_code());
		vo.setCreate_by(sub.getCreate_by());
		vo.setCreate_time(sub.getCreate_time());
		
		vo.setUpdate_by(sub.getUpdate_by());
		vo.setUpdate_time(sub.getUpdate_time());
		vo.setVersion(sub.getVersion());

		vr.push_back(vo);
	}
	// 将vr填入pages中，并返回pages
	pages.setRows(vr);
	return pages;
}

// 查询单个数据
// 负责人：J4nnA
PurComVO PurComService::getData(uint64_t id) {
	PurComVO data;

	return data;
}

// 查询指定比价单的明细列表
// 负责人：J4nnA
PageVO<PurComEntryVO> PurComService::listEntry(const PurComEntryQuery& query)
{
	// 构造返回对象
	PageVO<PurComEntryVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	// 构造DO
	PurComEntryDO obj;
	obj.setMid(query.getId());

	// 生成DAO层对象
	PurComDAO dao;

	//------------------------------------------------------未实现
	uint64_t count = 1;
	
	// 查询数据总条数
	//uint64_t count = dao.countEntrys(obj);
	//
	// 待加入筛选条件
	//
	if (count <= 0)
	{
		return pages;
	}
	
	// 调用DAO层功能,传入DO
	pages.setTotal(count);
	pages.calcPages();
	list<PurComEntryDO> result = dao.selectPurComEntry(obj, query.getPageIndex(), query.getPageSize());
	list<PurComEntryVO> vr;		//明细列表查询返回的VO列表

	// 根据DAO层返回的DO，对VO成员进行赋值
	for (PurComEntryDO sub : result)
	{
		// 构造用于返回的VO
		PurComEntryVO vo;

		vo.setId(sub.getId());
		vo.setMid(sub.getMid());
		vo.setBill_no(sub.getBill_no());
		vo.setEntry_no(sub.getEntry_no());
		vo.setSrc_bill_type(sub.getSrc_bill_type());
		vo.setSrc_bill_id(sub.getSrc_bill_id());

		vo.setSrc_entry_id(sub.getSrc_entry_id());
		vo.setSrc_no(sub.getSrc_no());
		vo.setSupplier_id(sub.getSupplier_id());

		vo.setMaterial_id(sub.getMaterial_id());
		vo.setUnit_id(sub.getUnit_id());
		vo.setQty(sub.getQty());

		vo.setTax_rate(sub.getTax_rate());
		vo.setPrice(sub.getPrice());
		vo.setDiscount_rate(sub.getDiscount_rate());

		vo.setAmt(sub.getAmt());
		vo.setRanking(sub.getRanking());
		vo.setRemark(sub.getRemark());
		vo.setCustom1(sub.getCustom1());

		vo.setCustom2(sub.getCustom2());
		vo.setVersion(sub.getVersion());

		vr.push_back(vo);
	}
	// 将vr填入pages中，并返回pages
	pages.setRows(vr);
	return pages;
}

list<PurOrderDividedListVO> PurComService::listPurOrderDividedListDO(const PurOrderDividedListQuery& query) {
	//设置查询条件
	PurOrderDividedListDO obj;
	obj.setBillNo(query.getBillNo());
	//接收查询到的DO
	PurComDAO dao;
	list<PurOrderDividedListDO> result = dao.selectPurOrderDividedListDO(obj);

	//构建返回对象vo
	list<PurOrderDividedListVO> vr;
	if (!result.empty()) {
		for (PurOrderDividedListDO sub : result) {
			PurOrderDividedListVO vo;
			vo.setBillNo(sub.getBillNo());
			vo.setEntryNo(sub.getEntryNo());
			vo.setMaterialId(sub.getMaterialId());
			vo.setUnitId(sub.getUnitId());
			vo.setQty(sub.getQty());
			vo.setOrderedQty(sub.getOrderedQty());
			vo.setTaxRate(sub.getTaxRate());
			vo.setPrice(sub.getPrice());
			vo.setAmt(sub.getAmt());
			vo.setSuggestSupplierId(sub.getSuggestSupplierId());
			vo.setRemark(sub.getRemark());
			vo.setCustom1(sub.getCustom1());
			vo.setCustom2(sub.getCustom2());
			vr.push_back(vo);
		}
	}
	return vr;
}