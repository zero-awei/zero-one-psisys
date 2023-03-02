/*
 Copyright Zero One Star. All rights reserved.

 @Author: Adam
 @Date: 2023/2/22 9:08

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
#include "SimpleDateTimeFormat.h"
#include "SnowFlake.h"
#include "FastDfsClient.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "../../dao/pur-req/PurReqDAO.h"

//定义一个宏用来进行默认值的修改
#define MODIFY_DEFAULT(name) if (dto.get##name() != data.get##name()) {data.set##name(dto.get##name());}

//定义一个宏用来进行值的修改
#define MODIFY(name) data.set##name(dto.get##name());

//定义一个宏用来进行值压入导出数据表中
#define PUSH_VALUE(value) row.emplace_back(CharsetConvertHepler::ansiToUtf8(value));

//定义一个宏用来进行值从导入主的数据表进入DO中
#define GET_VALUE1(name, stox) data.set##name(stox(CharsetConvertHepler::utf8ToAnsi(r1[i++])));

//定义一个宏用来进行值从导入主的数据表进入DO中
#define GET_VALUE2(name, stox) data.set##name(stox(CharsetConvertHepler::utf8ToAnsi(r2[i++])));

string getTime()
{
	return SimpleDateTimeFormat::format();
}

uint64_t PurReqService::saveData(const AddPurReqDTO& dto,  const PayloadDTO& payload)
{
	//首先将订单本体添加进数据库
	//组装传输数据
	PurReqAdamDO data;
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
	data.setSysOrgCode(payload.getOrgCode());
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
	for (PurReqEntryDTO &dto : dto.getDetail()) {
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

uint64_t PurReqService::updateData(const ModifyPurReqDTO& dto, const PayloadDTO& payload)
{
	//首先将订单本体添加进数据库
	//组装传输数据
	PurReqAdamDO data;
	PurReqDAO dao;
	SnowFlake sf(1, 3);
	//使用雪花算法设置id
	string id = to_string(sf.nextId());
	string BillNo = dto.getBillNo();

	//进行id设置
	data.setId(id);
	//获取必填信息
	data.setBillNo(BillNo);
	MODIFY(BillDate);
	MODIFY(RequestDept);
	MODIFY(Requester);
	MODIFY(RequestTime);
	MODIFY(BillStage);
	MODIFY(SysOrgCode);
	MODIFY(CreateBy);
	MODIFY(CreateTime);
	//获取修改用户的信息，此处为添加订单人信息
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(getTime());
	//存在默认值时的处理
	MODIFY_DEFAULT(SrcBillType);
	MODIFY_DEFAULT(SrcBillId);
	MODIFY_DEFAULT(SrcNo);
	MODIFY_DEFAULT(Subject);
	MODIFY_DEFAULT(PurType);
	MODIFY_DEFAULT(Qty);
	MODIFY_DEFAULT(Amt);
	MODIFY_DEFAULT(OrderedQty);
	MODIFY_DEFAULT(Attachment);
	MODIFY_DEFAULT(Remark);
	MODIFY_DEFAULT(Version);
	//执行数据修改

	//然后将订单明细添加进数据库
	for (PurReqEntryDTO& dto : dto.getDetail()) {
		PurReqEntryAdamDO data;
		//首先是进行id设置,用雪花算法
		data.setId(to_string(sf.nextId()));
		//设置和主表的外键
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

uint64_t PurReqService::updateBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload)
{
	//组装传输数据
	PurReqAdamDO data;
	//必须传值接受
	MODIFY(IsEffective);
	MODIFY(EffectiveTime);
	MODIFY(IsClosed);
	MODIFY(IsVoided);
	MODIFY(BillNo);

	//获取修改人的信息和时间
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(getTime());

	//执行数据修改
	PurReqDAO dao;
	return dao.update(data) == 1;
}

bool PurReqService::removeData(string billNo)
{
	PurReqDAO dao;
	//首先获取附件信息
	list<PurReqAdamDO> getdata = dao.selectByBillNo(billNo);
	if (getdata.size() == 1)
	{
		PurReqAdamDO data = getdata.front();
		if (data.getAttachment() != "")
		{
#ifdef LINUX
			//定义客户端对象
			FastDfsClient client("conf/client.conf", 3);
#else
			//定义客户端对象
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

uint64_t PurReqService::getFromExecl(string fileName, const PayloadDTO& payload)
{
	//对一些值进行初始化
		//excel对象
	ExcelComponent excel;
		//雪花生成器
	SnowFlake sf(1, 3);
		//计数器
	int i = 0;
	PurReqDAO dao;
	//首先加载主表数据
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("采购申请单");
	auto readData = excel.readIntoVector(fileName, sheetName);
	//然后加载明细数据
	sheetName = CharsetConvertHepler::ansiToUtf8("采购申请单明细");
	auto readEntryData = excel.readIntoVector(fileName, sheetName);
	int row1 = 1, row2 = 1;//row1代表主表行号， row2代表明细表行号
	for (; row1 < readData.size(); ++row1)
	{
		//每个行数据的数组
		vector<string> r1 = readData[row1];
		PurReqAdamDO data;
		i = 0;
		//首先生成id
		string id = to_string(sf.nextId());
		data.setId(id);
		//获取时间
		string time = getTime();
		//获取身份
		data.setSysOrgCode(payload.getOrgCode());
		data.setCreateBy(payload.getUsername());
		data.setCreateTime(time);
		data.setUpdateBy(payload.getUsername());
		data.setUpdateTime(time);
		//获取数据表的信息
		GET_VALUE1(BillNo, );
		GET_VALUE1(BillDate, );
		GET_VALUE1(SrcBillType, );
		GET_VALUE1(SrcBillId, );
		GET_VALUE1(SrcNo, );
		GET_VALUE1(Subject, );
		GET_VALUE1(IsRubric, stoi);
		GET_VALUE1(PurType, );
		GET_VALUE1(RequestDept, );
		GET_VALUE1(Requester, );
		GET_VALUE1(RequestTime, );
		GET_VALUE1(Qty, stod);
		GET_VALUE1(Amt, stod);
		GET_VALUE1(OrderedQty, stod);
		GET_VALUE1(Attachment, );
		GET_VALUE1(Remark, );
		GET_VALUE1(IsAuto, stoi);
		GET_VALUE1(BillStage, );
		GET_VALUE1(Approver, );
		GET_VALUE1(BpmiInstanceId, );
		GET_VALUE1(ApprovalResultType, );
		GET_VALUE1(ApprovalRemark, );
		GET_VALUE1(IsEffective, stoi);
		GET_VALUE1(EffectiveTime, );
		GET_VALUE1(IsClosed, stoi);
		GET_VALUE1(IsVoided, stoi);
		GET_VALUE1(Version, stoi);
		//进行数据验证
		//进行必填参数检验
		if (data.getBillNo() == "" || data.getBillDate() == "" || data.getRequestDept() == ""
			|| data.getRequester() == "" || data.getRequestTime() == "" || data.getBillStage() == "") {
			return 0;
		}
		//将其加载进数据库
		if (dao.insert(data) == 0)
		{
			return  0;
		}
		string billNo = data.getBillNo();
		for (; row2 < readEntryData.size() && readEntryData[row2][0] == billNo; ++row2)
		{
			PurReqEntryAdamDO data;
			//每个行数据的数组
			vector<string> r2 = readEntryData[row2];
			i = 0;
			//首先生成id
			string id1 = to_string(sf.nextId());
			data.setId(id1);
			data.setMid(id);
			//获取数据表的信息
			GET_VALUE2(BillNo, );
			GET_VALUE2(EntryNo, stoi);
			GET_VALUE2(SrcBillType, );
			GET_VALUE2(SrcBillId, );
			GET_VALUE2(SrcEntryId, );
			GET_VALUE2(SrcNo, );
			GET_VALUE2(MaterialId, );
			GET_VALUE2(UnitId, );
			GET_VALUE2(Qty, stod);
			GET_VALUE2(TaxRate, stod);
			GET_VALUE2(Price, stod);
			GET_VALUE2(Amt, stod);
			GET_VALUE2(SuggestSupplierId, );
			GET_VALUE2(OrderedQty, stod);
			GET_VALUE2(Remark, );
			GET_VALUE2(Custom1, );
			GET_VALUE2(Custom2, );
			GET_VALUE2(Version, stoi);

			//数据检验
			//进行明细检验
			if (data.getEntryNo() < 0 || data.getMaterialId() == "" || data.getUnitId() == ""
				|| data.getQty() < 0 || data.getOrderedQty() < 0) {
				return 0;
			}
			//将其加载进数据库
			if (dao.insertEntry(data) == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

string PurReqService::getToExecl(list<string> billNoList)
{
	PurReqDAO dao;
	//查找主表获取数据 将得到的值填入data中
	vector<vector<std::string>> data;
	vector<std::string> row;
	ExcelComponent excel;
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	//定义客户端对象
	FastDfsClient client("1.15.240.108");
#endif
	//首先将列名加载进去
	vector<std::string> name = {
		CharsetConvertHepler::ansiToUtf8("单据编号"),
		CharsetConvertHepler::ansiToUtf8("单据日期"),
		CharsetConvertHepler::ansiToUtf8("源单类型"),
		CharsetConvertHepler::ansiToUtf8("源单id"),
		CharsetConvertHepler::ansiToUtf8("源单号"),
		CharsetConvertHepler::ansiToUtf8("主题"),
		CharsetConvertHepler::ansiToUtf8("是否红字"),
		CharsetConvertHepler::ansiToUtf8("采购类型"),
		CharsetConvertHepler::ansiToUtf8("需求部门"),
		CharsetConvertHepler::ansiToUtf8("需求人"),
		CharsetConvertHepler::ansiToUtf8("需求时间"),
		CharsetConvertHepler::ansiToUtf8("数量"),
		CharsetConvertHepler::ansiToUtf8("参考金额"),
		CharsetConvertHepler::ansiToUtf8("已订数量"),
		CharsetConvertHepler::ansiToUtf8("附件"),
		CharsetConvertHepler::ansiToUtf8("备注"),
		CharsetConvertHepler::ansiToUtf8("是否自动生成"),
		CharsetConvertHepler::ansiToUtf8("单据阶段"),
		CharsetConvertHepler::ansiToUtf8("审核人"),
		CharsetConvertHepler::ansiToUtf8("审批实例id"),
		CharsetConvertHepler::ansiToUtf8("核批结果类型"),
		CharsetConvertHepler::ansiToUtf8("核批意见"),
		CharsetConvertHepler::ansiToUtf8("是否生效"),
		CharsetConvertHepler::ansiToUtf8("生效时间"),
		CharsetConvertHepler::ansiToUtf8("已关闭"),
		CharsetConvertHepler::ansiToUtf8("是否作废"),
		CharsetConvertHepler::ansiToUtf8("创建部门"),
		CharsetConvertHepler::ansiToUtf8("创建人"),
		CharsetConvertHepler::ansiToUtf8("创建时间"),
		CharsetConvertHepler::ansiToUtf8("修改人"),
		CharsetConvertHepler::ansiToUtf8("修改时间"),
		CharsetConvertHepler::ansiToUtf8("版本")
	};
	data.emplace_back(name);
	//将获取的billNo获取到对应值 
	for (auto billNo : billNoList)
	{
		row.clear();
		list<PurReqAdamDO> dat = dao.selectByBillNo(billNo);
		//如果返回的不是只有一条数据的话就报错
		if (dat.size() != 1) {
			return "";
		}
		PurReqAdamDO dt = dat.front();
		//将信息输入到row中
		PUSH_VALUE(dt.getBillNo());
		PUSH_VALUE(dt.getBillDate());
		PUSH_VALUE(dt.getSrcBillType());
		PUSH_VALUE(dt.getSrcBillId());
		PUSH_VALUE(dt.getSrcNo());
		PUSH_VALUE(dt.getSubject());
		PUSH_VALUE(to_string(dt.getIsRubric()));
		PUSH_VALUE(dt.getPurType());
		PUSH_VALUE(dt.getRequestDept());
		PUSH_VALUE(dt.getRequester());
		PUSH_VALUE(dt.getRequestTime());

		PUSH_VALUE(to_string(dt.getQty()));
		PUSH_VALUE(to_string(dt.getAmt()));
		PUSH_VALUE(to_string(dt.getOrderedQty()));

		PUSH_VALUE(dt.getAttachment());
		PUSH_VALUE(dt.getRemark());
		PUSH_VALUE(to_string(dt.getIsAuto()));

		PUSH_VALUE(dt.getBillStage());
		PUSH_VALUE(dt.getApprover());
		PUSH_VALUE(dt.getBpmiInstanceId());

		PUSH_VALUE(dt.getApprovalResultType());
		PUSH_VALUE(dt.getApprovalRemark());
		PUSH_VALUE(to_string(dt.getIsEffective()));

		PUSH_VALUE(dt.getEffectiveTime());
		PUSH_VALUE(to_string(dt.getIsClosed()));
		PUSH_VALUE(to_string(dt.getIsVoided()));

		PUSH_VALUE(dt.getSysOrgCode());
		PUSH_VALUE(dt.getCreateBy());
		PUSH_VALUE(dt.getCreateTime());

		PUSH_VALUE(dt.getUpdateBy());
		PUSH_VALUE(dt.getUpdateTime());
		PUSH_VALUE(to_string(dt.getVersion()));
		//将该行数据压入
		data.emplace_back(row);
	}
	//将值加入到execl中
	//定义保存数据位置和页签名称
	std::string fileName = "./public/excel/pur_req.xlsx";//这个名字不知道怎么赋值，但是不重要

	std::string sheetName = CharsetConvertHepler::ansiToUtf8("采购申请单");
	//保存到文件
	excel.writeVectorToFile(fileName, sheetName, data);

	//然后是明细单
	data.clear();
	name.clear();
	//首先将列名加载进去
	name = {
	CharsetConvertHepler::ansiToUtf8("单据号"),
	CharsetConvertHepler::ansiToUtf8("分录号"),
	CharsetConvertHepler::ansiToUtf8("源单类型"),
	CharsetConvertHepler::ansiToUtf8("源单id"),
	CharsetConvertHepler::ansiToUtf8("源单分录id"),
	CharsetConvertHepler::ansiToUtf8("源单分录号"),
	CharsetConvertHepler::ansiToUtf8("物料"),
	CharsetConvertHepler::ansiToUtf8("计量单位"),
	CharsetConvertHepler::ansiToUtf8("数量"),
	CharsetConvertHepler::ansiToUtf8("税率%"),
	CharsetConvertHepler::ansiToUtf8("参考含税单价"),
	CharsetConvertHepler::ansiToUtf8("参考含税金额"),
	CharsetConvertHepler::ansiToUtf8("建议供应商"),
	CharsetConvertHepler::ansiToUtf8("已订购数量"),
	CharsetConvertHepler::ansiToUtf8("备注"),
	CharsetConvertHepler::ansiToUtf8("自定义1"),
	CharsetConvertHepler::ansiToUtf8("自定义2"),
	CharsetConvertHepler::ansiToUtf8("版本") };
	data.emplace_back(name);
	//将获取的billNo获取到对应值 
	for (auto billNo : billNoList)
	{
		row.clear();
		list<PurReqEntryAdamDO> dat = dao.selectEntryByBillNo(billNo);
		for (PurReqEntryAdamDO dt : dat)
		{
			//将信息输入到row中
			PUSH_VALUE(dt.getBillNo());
			PUSH_VALUE(to_string(dt.getEntryNo()));
			PUSH_VALUE(dt.getSrcBillType());
			PUSH_VALUE(dt.getSrcBillId());
			PUSH_VALUE(dt.getSrcEntryId());
			PUSH_VALUE(dt.getSrcNo());
			PUSH_VALUE(dt.getMaterialId());
			PUSH_VALUE(dt.getUnitId());
			PUSH_VALUE(to_string(dt.getQty()));
			PUSH_VALUE(to_string(dt.getTaxRate()));
			PUSH_VALUE(to_string(dt.getPrice()));
			PUSH_VALUE(to_string(dt.getAmt()));
			PUSH_VALUE(dt.getSuggestSupplierId());
			PUSH_VALUE(to_string(dt.getOrderedQty()));
			PUSH_VALUE(dt.getRemark());
			PUSH_VALUE(dt.getCustom1());
			PUSH_VALUE(dt.getCustom2());
			PUSH_VALUE(to_string(dt.getVersion()));
			//将该行数据压入
			data.emplace_back(row);
		}
	}
	//将值加入到execl中
	//定义保存数据位置和页签名称
	sheetName = CharsetConvertHepler::ansiToUtf8("采购申请单明细'");
	//保存文件
	excel.writeVectorToFile(fileName, sheetName, data);

	//将文件上传到fastdfs
	//上传
	std::string fieldName = client.uploadFile(fileName);

	//删除本地文件
	std::remove(fileName.c_str());

	//组装下载地址
	fieldName = "http://1.15.240.108:8888/" + fieldName;

	return  fieldName;
}

// 分页查询所有数据
PageVO<PurReqFindBillVO> PurReqService::listAll(const PurReqFindBillQuery& query) {
	//构建返回对象
	PageVO<PurReqFindBillVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	PurReqDO obj;
	obj.setBill_no(query.getBillNo());
	obj.setBill_date(query.getBillDate());
	obj.setSubject(query.getSubject());
	obj.setBill_stage(query.getBillStage());
	obj.setIs_effective(query.getIsEffective());
	obj.setIs_closed(query.getIsClose());
	obj.setIs_voided(query.getIsVoided());
	PurReqDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<PurReqDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<PurReqFindBillVO> vr;
	for (PurReqDO sub : result)
	{
		PurReqFindBillVO vo;
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setSubject(sub.getSubject());
		vo.setSrc_no(sub.getSrc_no());
		vo.setPur_type(sub.getPur_type());
		vo.setRequest_dept(sub.getRequest_dept());
		vo.setRequester(sub.getRequester());
		vo.setRequest_time(sub.getRequest_time());
		vo.setQty(sub.getQty());
		vo.setOrdered_qty(sub.getOrdered_qty());
		vo.setAmt(sub.getAmt());
		vo.setBill_stage(sub.getBill_stage());
		vo.setIs_effective(sub.getIs_effective());
		vo.setIs_closed(sub.getIs_closed());
		vo.setIs_voided(sub.getIs_voided());
		vo.setRemark(sub.getRemark());
		vo.setIs_auto(sub.getIs_auto());
		vo.setIs_rubric(sub.getIs_rubric());
		vo.setEffective_time(sub.getEffective_time());
		vo.setapprover(sub.getApprover());
		vo.setCreate_time(sub.getCreate_time());
		vo.setCreate_by(sub.getCreate_by());
		vo.setSys_org_code(sub.getSys_org_code());
		vo.setUpdate_time(sub.getUpdate_time());
		vo.setUpdate_by(sub.getUpdate_by());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}
//查询指定单据详细信息
PurReqFindDetailBillVO PurReqService::detailsOne(const PurReqFindDetailBillQuery& query) {
	PurReqDAO dao;
	list<PurReqDO> pus = dao.selectByNo(query.getBill_no());
	PurReqFindDetailBillVO po;
	if (!pus.empty()) {
		PurReqDO pu = *pus.begin();
		po.setBill_no(pu.getBill_no());
		po.setBill_date(pu.getBill_date());
		po.setIs_effective(pu.getIs_effective());
		po.setIs_closed(pu.getIs_closed());
		po.setIs_voided(pu.getIs_voided());
		po.setSubject(pu.getSubject());
		po.setPur_type(pu.getPur_type());
		po.setRequester(pu.getRequester());
		po.setRequest_dept(pu.getRequest_dept());
		po.setRequest_time(pu.getRequest_time());
		po.setOrdered_qty(pu.getOrdered_qty());

		list<PurReqEntryDO> detailsResult = pu.getDetail();
		list<PurReqDetailBillVO> pbVO;
		for (PurReqEntryDO re : detailsResult)
		{
			PurReqDetailBillVO tep;
			tep.setSrc_no(re.getSrc_no());
			tep.setMaterial_id(re.getMaterial_id());
			tep.setSrc_bill_type(re.getSrc_bill_type());
			tep.setUnit_id(re.getUnit_id());
			tep.setQty(re.getQty());
			tep.setOrdered_qty(re.getOrdered_qty());
			tep.setTax_rate(re.getTax_rate());
			tep.setPrice(re.getPrice());
			tep.setAmt(re.getAmt());
			tep.setSuggest_supplier_id(re.getSuggest_supplier_id());
			tep.setRemark(re.getRemark());
			tep.setCustom1(re.getCustom1());
			tep.setCustom2(re.getCustom2());
			pbVO.push_back(tep);
		}
		po.setDetailBillsVO(pbVO);
	}
	return po;
}