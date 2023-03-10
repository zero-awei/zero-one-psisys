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
#include "PurReqService.h"
//#include "../../dao/PurReq/PurReqDAO.h"

// 分页查询所有数据
PageVO<PurReqVO> PurReqService::listAll(const PurReqQuery& query)
{
	//构建返回对象
	PageVO<PurReqVO> pages;

	return pages;
}

// 查询单个数据
PurReqVO PurReqService::getData(uint64_t id) {
	PurReqVO data;
	
	return data;
}

// 查询所有数据
list<PurReqVO> PurReqService::listAllData(const PurReqQuery& query)
{
	PurOrderEntryDAO dao;
	list<PurReqVO> pur_req_vo_list;
	list<PurReqDO> ls = dao.selectPurReqList();

	for (auto do_data : ls)
	{
		PurReqVO pur_req_vo;
		pur_req_vo.setId(do_data.getId());
		pur_req_vo.setBill_no(do_data.getBill_no());
		pur_req_vo.setBill_date(do_data.getBill_date());
		pur_req_vo.setSrc_bill_type(do_data.getSrc_bill_type());
		pur_req_vo.setSrc_bill_id(do_data.getSrc_bill_id());
		pur_req_vo.setSrc_no(do_data.getSrc_no());
		pur_req_vo.setSubject(do_data.getSubject());
		pur_req_vo.setIs_rubric(do_data.getIs_rubric());
		pur_req_vo.setPur_type(do_data.getPur_type());
		pur_req_vo.setRequest_dept(do_data.getRequest_dept());
		pur_req_vo.setRequester(do_data.getRequester());
		pur_req_vo.setRequest_time(do_data.getRequest_time());
		pur_req_vo.setQty(do_data.getQty());
		pur_req_vo.setAmt(do_data.getAmt());
		pur_req_vo.setOrdered_qty(do_data.getOrdered_qty());
		pur_req_vo.setAttachment(do_data.getAttachment());
		pur_req_vo.setRemark(do_data.getRemark());
		pur_req_vo.setIs_auto(do_data.getIs_auto());
		pur_req_vo.setBill_stage(do_data.getBill_stage());
		pur_req_vo.setApprover(do_data.getApprover());
		pur_req_vo.setBpmi_instance_id(do_data.getBpmi_instance_id());
		pur_req_vo.setApproval_result_type(do_data.getApproval_result_type());
		pur_req_vo.setApproval_remark(do_data.getApproval_remark());
		pur_req_vo.setIs_effective(do_data.getIs_effective());
		pur_req_vo.setEffective_time(do_data.getEffective_time());
		pur_req_vo.setIs_closed(do_data.getIs_closed());
		pur_req_vo.setIs_voided(do_data.getIs_voided());
		pur_req_vo.setSys_org_code(do_data.getSys_org_code());
		pur_req_vo.setCreate_by(do_data.getCreate_by());
		pur_req_vo.setCreate_time(do_data.getCreate_time());
		pur_req_vo.setUpdate_by(do_data.getUpdate_by());
		pur_req_vo.setUpdate_time(do_data.getUpdate_time());
		pur_req_vo.setVersion(do_data.getVersion());
		pur_req_vo_list.push_back(pur_req_vo);
	}
	return pur_req_vo_list;
}