/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "MaterialClassificationService.h"
#include "../../dao/MaterialClassification/MaterialClassificationDAO.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../../lib-common/src/FastDfsClient.cpp"
#include "../../../lib-common/src/CharsetConvertHepler.cpp"
#include "../../lib-common/include/ExcelComponent.h"

//可能vo不需要分父类子类

const int datacenterId = 1;
const int machineId = 2;
PageVO<MaterialClassificationBaseVO> MaterialClassificationService::listAll(const MaterialClassificationQuery& query)
{
	//构建返回对象
	PageVO<MaterialClassificationBaseVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	MaterialClassificationDO obj;
	MaterialClassificationDAO dao;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	//如果名字和编码均为空，则显示所有物料分类根节点

	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	//分页查询数据 
	pages.setTotal(count);
	pages.calcPages();

	
	if (query.getCode() != "" || query.getName() != "") {//判断是不是子级，是则寻找根节点
		list<MaterialClassificationDO> father;
		if (query.getCode() != "") 
			father = dao.selectByCode(query.getCode());
		else if (query.getName() != "")
			father = dao.selectByName(query.getName());
		MaterialClassificationDO f;
		for (MaterialClassificationDO sub : father) {
			f.setId(sub.getId());
			f.setPid(sub.getPid());
		}	
		//输入的是子类的编码或者名称时，循环寻找根节点
			while (f.getPid() != "0") {
				father = dao.selectById(f.getPid());
				for (MaterialClassificationDO sub : father) {
					f.setId(sub.getId());
					f.setPid(sub.getPid());
				}
			}
			//找到根节点
			list<MaterialClassificationBaseVO> vr;
			for (MaterialClassificationDO sub : father)
			{
				MaterialClassificationBaseVO vo;
				vo.setId(sub.getId());
				vo.setName(sub.getName());
				vo.setCode(sub.getCode());
				vo.setFullname(sub.getFullname());
				vo.setIsEnabled(sub.getIsEnabled());
				vo.setCreateTime(sub.getCreateTime());
				vo.setCreateBy(sub.getCreateBy());
				vo.setUpdateTime(sub.getUpdateTime());
				vo.setUpdateBy(sub.getUpdateBy());

				vr.push_back(vo);
			}
			pages.setRows(vr);
			return pages;
	}
	else if (query.getCode() == "" && query.getName() == "") {//全空显示全部根节点

		list<MaterialClassificationDO> result = dao.selectWithPage( "0",query.getPageIndex(), query.getPageSize());
		list<MaterialClassificationBaseVO> vr;
		for (MaterialClassificationDO sub : result)
		{
			MaterialClassificationBaseVO vo;
			vo.setId(sub.getId());
			vo.setName(sub.getName());
			vo.setCode(sub.getCode());
			vo.setFullname(sub.getFullname());
			vo.setIsEnabled(sub.getIsEnabled());
			vo.setCreateTime(sub.getCreateTime());
			vo.setCreateBy(sub.getCreateBy());
			vo.setUpdateTime(sub.getUpdateTime());
			vo.setUpdateBy(sub.getUpdateBy());

			vr.push_back(vo);
		}
		pages.setRows(vr);
		return pages;
	}
}

//查询子类列表
list<MaterialClassificationChildVO> MaterialClassificationService::listChildren(const MaterialClassificationQuery& query) {
	MaterialClassificationDO obj;
	obj.setCode(query.getCode());//父类编码
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> father = dao.selectByCode(obj.getCode());//返回的是list
	MaterialClassificationDO f;
	f.setId(father.front().getId());
	
	list<MaterialClassificationDO> result = dao.selectByPid(f.getId());
	list<MaterialClassificationChildVO> vr;
	for (MaterialClassificationDO sub : result)
	{
		MaterialClassificationChildVO vo;
		vo.setId(sub.getId());
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setFullname(sub.getFullname());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());

		vr.push_back(vo);

	}

	return vr;

}


list<MaterialClassificationDetailVO> MaterialClassificationService::listDetail(const MaterialClassificationQuery& query) {
	MaterialClassificationDO obj;
	obj.setCode(query.getCode());
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> result = dao.selectByCode(obj.getCode());
	list<MaterialClassificationDetailVO> vr;
	for (MaterialClassificationDO sub : result)
	{
		MaterialClassificationDetailVO vo;
		vo.setId(sub.getId());
		vo.setPid(sub.getPid());
		vo.setHasChild(sub.getHasChild());
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setFullname(sub.getFullname());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());

		vr.push_back(vo);
	}

	return  vr;
}

int MaterialClassificationService::saveData(const MaterialClassificationDTO& dto, const string& userName)
{
	//新增数据应该不用管修改相关的信息

	//组装数据
	MaterialClassificationDO data;
	//应该是在这里生成id
	SnowFlake sf(datacenterId, machineId);
	data.setId(to_string(sf.nextId()));

	//添加下级的时候要获得pid，如果pid的父类一开始没有下级，则还要修改父类的has_child
	data.setPid(dto.getPid()==""? "0":dto.getPid());
	data.setHasChild(dto.getHasChild()==""? "0":dto.getHasChild());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setFullname(dto.getFullname());
	data.setIsEnabled(dto.getIsEnabled());
	data.setCreateBy(userName);

	//设置时间
	SimpleDateTimeFormat sdt;
	
	string nowTime  = sdt.format();//使用阿伟给的工具类
	//time_t nowtime;
	//time(&nowtime); //获取1900年1月1日0点0分0秒到现在经过的秒数
	//tm p;
	//localtime_s(&p,&nowtime); //将秒数转换为本地时间,年从1900算起,需要+1900,月为0-11,所以要+1
	////printf("%04d:%02d:%02d %02d:%02d:%02d\n", p.tm_year + 1900, p.tm_mon + 1, p.tm_mday,p.tm_hour,p.tm_min,p.tm_sec);
	//string nowTime = to_string(p.tm_year+1900) + "-" +to_string(p.tm_mon+1)+"-"+to_string(p.tm_mday) + " " + to_string(p.tm_hour)+":"+to_string(p.tm_min) +":"+to_string(p.tm_sec);

	data.setCreateTime(nowTime);
	data.setVersion(dto.getVersion());
	//执行数据添加
	MaterialClassificationDAO dao;

	int modify = 1;
	if (dto.getPid() != "") {//有父节点
		list<MaterialClassificationDO> father = dao.selectById(dto.getPid());
		MaterialClassificationDO f;
		for (MaterialClassificationDO sub : father) {
			f.setHasChild(sub.getHasChild());
		}
		if (f.getHasChild() == "0")
			modify = dao.updateHasChildById(dto.getPid(), "1");//通过id修改父节点的has_child
	}

	return (modify * dao.insert(data))==1;
}

int MaterialClassificationService::updateData(const MaterialClassificationDTO& dto, const PayloadDTO& payload)
{

	//修改数据要先拿到id,修改数据应该不用管创建相关的信息

	//组装传输数据
	MaterialClassificationDO data;
	data.setId(dto.getId());
	data.setPid(dto.getPid());
	data.setHasChild(dto.getHasChild());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setFullname(dto.getFullname());
	data.setIsEnabled(dto.getIsEnabled());


	SimpleDateTimeFormat sdt;
	string nowTime = sdt.format();
	//time_t nowtime;
	//time(&nowtime); //获取1900年1月1日0点0分0秒到现在经过的秒数
	//tm p;
	//localtime_s(&p, &nowtime); //将秒数转换为本地时间,年从1900算起,需要+1900,月为0-11,所以要+1
	//string nowTime = to_string(p.tm_year + 1900) + "-" + to_string(p.tm_mon + 1) + "-" + to_string(p.tm_mday) + " " + to_string(p.tm_hour) + ":" + to_string(p.tm_min) + ":" + to_string(p.tm_sec);

	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(nowTime);
	data.setVersion(dto.getVersion());
	//执行数据修改
	MaterialClassificationDAO dao;
	return dao.update(data) == 1;
}

//删除子级节点的函数
void removeNode(const MaterialClassificationDO& nodeChild) {
	MaterialClassificationDAO dao;
	if (nodeChild.getHasChild() == "0") {
		dao.deleteById(nodeChild.getId());
		return;
	}
	list<MaterialClassificationDO> children = dao.selectByPid(nodeChild.getId());
	for (MaterialClassificationDO node : children) {
		removeNode(node);
	}
	return;
}

int MaterialClassificationService::removeData(const MaterialClassificationDTO& dto)
{
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> info = dao.selectById(dto.getId());//获取当前节点的信息
	MaterialClassificationDO bro ;
	for (MaterialClassificationDO node : info) {
		bro.setPid(node.getPid());
		bro.setHasChild(node.getHasChild());
	}
		
	int d = 1;
	if (bro.getHasChild() == "1"){//如果有子级节点则删除
		for (MaterialClassificationDO node : info) {
			bro.setPid(node.getPid());
			if (node.getHasChild() == "1") {
				removeNode(node);
			}
		}
		d = dao.deleteByPid(dto.getId());
	}
	int myself = dao.deleteById(dto.getId());//删除自身

	//如果刚好其父节点没有了子节点，则还要修改父节点的has_child
	
	list<MaterialClassificationDO> brother = dao.selectByPid(bro.getPid());

	int tag = 0;
	for (MaterialClassificationDO sub : brother) {
		if (sub.getPid() != "0") {//有兄弟,不用改父节点
			tag++;
			break;
		}
	}
	
	int father = 1;
	if (tag == 0) {//没有兄弟，要修改父节点
		int father = dao.updateHasChildById(bro.getPid(),"0");
	}
	return (myself*d*father) == 1;
}


//导入数据
int MaterialClassificationService::importData(const MaterialClassificationDTO& dto) {
	MaterialClassificationDAO dao;
	ExcelComponent excel;
	list<MaterialClassificationDTO> Dto;
	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		string sheetName = CharsetConvertHepler::ansiToUtf8("物料分类");
		auto readData = excel.readIntoVector(file, sheetName);
		for (auto data : readData) {
			MaterialClassificationDTO saveDto;
			saveDto.setPid(CharsetConvertHepler::ansiToUtf8(data[0]));
			saveDto.setHasChild(CharsetConvertHepler::ansiToUtf8(data[1])=="是"? "1":"0");
			saveDto.setName(CharsetConvertHepler::ansiToUtf8(data[2]));
			saveDto.setCode(CharsetConvertHepler::ansiToUtf8(data[3]));
			saveDto.setFullname(CharsetConvertHepler::ansiToUtf8(data[4]));
			saveDto.setIsEnabled(CharsetConvertHepler::ansiToUtf8(data[5])=="是"? 1:0);

			Dto.push_back(saveDto);
		}

	} 

	int result = 1;
	for (MaterialClassificationDTO data:Dto) //把数据存入数据库
		result = saveData(data,"管理员");			//暂时还不知道怎么把创建人的信息输入进去，如果导入格式和导出文件格式一样，就可以截取出来

	return result;
}

//导出数据
string  MaterialClassificationService::exportData(const StringIDs& IDS,const PayloadDTO& payload) {
	list<string> ids = IDS.getId();
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> dos;
	//获取每个id的信息
	for (string id : ids) {
		dos.push_back((dao.selectById(id)).front());
	}
	//装入表框架
	string head = CharsetConvertHepler::ansiToUtf8("物料分类报表");	//表名
	string exporter = payload.getUsername();						//导出人
	//这两项怎么装入数组呢

	vector<vector<string>> data{ vector<string>{					//报表项
		CharsetConvertHepler::ansiToUtf8("父节点"),
			CharsetConvertHepler::ansiToUtf8("是否有子节点"),
			CharsetConvertHepler::ansiToUtf8("名称"),
			CharsetConvertHepler::ansiToUtf8("编码"),
			CharsetConvertHepler::ansiToUtf8("全名"),
			CharsetConvertHepler::ansiToUtf8("是否启用")
	}};

	//装入表数据
	for (MaterialClassificationDO sub:dos) {
		vector<string> rows;
		list<MaterialClassificationDO> father = dao.selectByPid(sub.getPid());
		string fName = father.front().getName();
		rows.push_back(CharsetConvertHepler::ansiToUtf8(fName));
		rows.push_back(CharsetConvertHepler::ansiToUtf8(sub.getHasChild()=="1" ? "是":"否"));
		rows.push_back(CharsetConvertHepler::ansiToUtf8(sub.getName()));
		rows.push_back(CharsetConvertHepler::ansiToUtf8(sub.getCode()));
		rows.push_back(CharsetConvertHepler::ansiToUtf8(sub.getFullname()));
		rows.push_back(CharsetConvertHepler::ansiToUtf8(sub.getIsEnabled() ==1 ? "是":"否"));

		data.push_back(rows);
	}

	// 定义保存数据位置和页签名称
	std::string fileName = CharsetConvertHepler::ansiToUtf8("../../public/excel/test.xlsx");
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("物料分类");//excel中sheetName
	//保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	// 上传到文件服务器
	/*FastDfsClient client("1.15.240.108");
	fileName = client.uploadFile(fileName)*/;

	return fileName;
}


