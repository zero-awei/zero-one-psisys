#include "stdafx.h"
#include "SupplierServiceSatan.h"
#include "../../../dao/supplierDAO/dao-Supplier-satan/SupplierDAO.h"
#include "../lib-common/include/SnowFlake.h"
#include <sstream>
#include "../lib-common/include/SimpleDateTimeFormat.h"
#include "../lib-http/include/JWTUtil.h"

// 高级查询
PageVO<AdvancedQueryVO> SupplierService::advancedListSupplierData(const AdvancedQuery& query)
{
	//构建返回对象
	PageVO<AdvancedQueryVO> pages;//分页返回返回的就是页面，页面里面存储着数据
	//在返回对象VO中存入返回页数
	/*query.setPageSize(9);
	query.setPageIndex(1);*/
	pages.setPageIndex(query.getPageIndex());//设置当前页码
	pages.setPageSize(query.getPageSize());//设置每页最大数据条数
	//利用dao中的count()函数：查询数据总条数
	SupplierDAO dao;
	uint64_t count = dao.count(query);//count函数就是执行在数据库中进行查找数据页数的函数
	if (count <= 0)
	{
		return pages;//查找不到数据，直接返回0页
	}
	//记录查询数据页数
	pages.setTotal(count);
	pages.calcPages();                                            
	//执行DAO层的高级查询函数
	list<SupplierDO> result = dao.AdvancedSelectWithPage(query.getPageIndex(), query.getPageSize(),query);
	list<AdvancedQueryVO> vr;
	for (SupplierDO sub : result)
	{
		AdvancedQueryVO vo;
		vo.setCode(sub.getCode());
		vo.setName(sub.getName());
		vo.setAux_Name(sub.getAux_Name());
		vo.setSupplier_Category(sub.getSupplier_Category());
		vo.setSupplier_Level(sub.getSupplier_Level());
		vo.setTax_Scale(sub.getTax_Scale());
		vo.setHeadQuarters(sub.getHeadQuarters());
		vo.setBiz_Area(sub.getBiz_Area());
		vo.setArea(sub.getArea());
		vo.setAddress(sub.getAddress());
		vo.setWebsite(sub.getWebsite());
		vo.setAlter_Suppliers(sub.getAlter_Suppliers());
		vo.setIs_Enabled(sub.getIs_Enabled());
		vo.setRemark(sub.getRemark());
		vo.setCreate_By(sub.getCreate_By());
		vo.setUpdate_Time(sub.getUpdate_Time());
		vo.setUpdate_By(sub.getUpdate_By());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;

}

//查询指定供应商详细数据
SpecifiedSupplierDataQueryVO  SupplierService::specifiedListSupplierData(const SpecifiedSupplierDataQuery& query)
{
	//构建返回对象
	SpecifiedSupplierDataQueryVO data;
	//利用DO类和DAO类查询数据
	SupplierDAO dao;
	SupplierDO result = dao.SpecifiedSelect(query.getID());
	data.setCode(result.getCode());
	data.setName(result.getName());
	data.setAux_Name(result.getAux_Name());
	data.setSupplier_Category(result.getSupplier_Category());
	data.setSupplier_Level(result.getSupplier_Level());
	data.setTax_Scale(result.getTax_Scale());
	data.setAlter_Suppliers(result.getAlter_Suppliers());
	data.setIs_Enabled(result.getIs_Enabled());
	data.setRemark(result.getRemark());
	data.setInvoice_Company(result.getInvoice_Company());
	data.setInvoice_Tax_Code(result.getInvoice_Tax_Code());
	data.setInvoice_Bank_Name(result.getInvoice_Bank_Name());
	data.setInvoice_Bank_Code(result.getInvoice_Bank_Code());
	data.setInvoice_Account(result.getInvoice_Account());
	data.setInvoice_Phone(result.getInvoice_Phone());
	data.setInvoice_Address(result.getInvoice_Address());
	data.setReceipt_Company(result.getReceipt_Company());
	data.setReceipt_Bank_Name(result.getReceipt_Bank_Name());
	data.setReceipt_Bank_Code(result.getReceipt_Bank_Code());
	data.setReceipt_Account(result.getReceipt_Account());
	data.setRecv_Name(result.getRecv_Name());
	data.setRecv_Phone(result.getRecv_Phone());
	data.setRecv_Fax(result.getRecv_Fax());
	data.setRecv_Email(result.getRecv_Email());
	data.setRecv_Address(result.getRecv_Address());
	data.setRecv_Postcode(result.getRecv_Postcode());
	data.setFinancial_Contacts(result.getFinancial_Contacts());
	data.setFinancial_Phone(result.getFinancial_Phone());
	data.setShort_Name(result.getShort_Name());
	data.setWebsite(result.getWebsite());
	data.setLegal_Person(result.getLegal_Person());
	data.setLegal_Person_Phone(result.getLegal_Person_Phone());
	data.setHeadQuarters(result.getHeadQuarters());
	data.setArea(result.getArea());
	data.setBiz_Area(result.getBiz_Area());
	data.setAddress(result.getAddress());
	data.setAttachment(result.getAttachment());
	data.setCreate_Time(result.getCreate_Time());
	data.setCreate_By(result.getCreate_By());
	data.setUpdate_Time(result.getUpdate_Time());
	data.setUpdate_By(result.getUpdate_By());
	
	return data;
}

// 添加供应商
uint64_t SupplierService::addSupplierData(const AddSupplierDTO& dto,const PayloadDTO& payload)
{
	//组装数据
	SupplierDO data;
	data.setCode(dto.getCode());
	data.setName(dto.getName());
	data.setAux_Name(dto.getAux_Name());
	data.setSupplier_Category(dto.getSupplier_Category());
	data.setSupplier_Level(dto.getSupplier_Level());
	data.setTax_Scale(dto.getTax_Scale());
	data.setAlter_Suppliers(dto.getAlter_Suppliers());
	data.setIs_Enabled(dto.getIs_Enabled());
	data.setRemark(dto.getRemark());
	data.setInvoice_Company(dto.getInvoice_Company());
	data.setInvoice_Tax_Code(dto.getInvoice_Tax_Code());
	data.setInvoice_Bank_Name(dto.getInvoice_Bank_Name());
	data.setInvoice_Bank_Code(dto.getInvoice_Bank_Code());//这一行在第二轮大检查的时候发现漏了
	data.setInvoice_Account(dto.getInvoice_Account());
	data.setInvoice_Phone(dto.getInvoice_Phone());
	data.setInvoice_Address(dto.getInvoice_Address());
	data.setReceipt_Company(dto.getReceipt_Company());
	data.setReceipt_Bank_Name(dto.getReceipt_Bank_Name());
	data.setReceipt_Bank_Code(dto.getReceipt_Bank_Code());
	data.setReceipt_Account(dto.getReceipt_Account());
	data.setRecv_Name(dto.getRecv_Name());
	data.setRecv_Phone(dto.getRecv_Phone());
	data.setRecv_Fax(dto.getRecv_Fax());
	data.setRecv_Email(dto.getRecv_Email());
	data.setRecv_Address(dto.getRecv_Address());
	data.setRecv_Postcode(dto.getRecv_Postcode());
	data.setFinancial_Contacts(dto.getFinancial_Contacts());
	data.setFinancial_Phone(dto.getFinancial_Phone());
	data.setShort_Name(dto.getShort_Name());
	data.setWebsite(dto.getWebsite());
	data.setLegal_Person(dto.getLegal_Person());
	data.setLegal_Person_Phone(dto.getLegal_Person_Phone());
	data.setHeadQuarters(dto.getHeadQuarters());
	data.setArea(dto.getArea());
	data.setBiz_Area(dto.getBiz_Area());
	data.setAddress(dto.getAddress());
	//data.setCreate_Time(dto.getCreate_Time());————设置时间使用format函数
	//data.setCreate_By(dto.getCreate_By());————设置用户信息使用payloaddto类
	//data.setUpdate_Time(dto.getUpdate_Time());
	//data.setUpdate_By(dto.getUpdate_By());
	//将文件的上传路径也装入DO领域模型类中，在执行SupplierInsert进行返回
	string file_router;
	for (auto file_segment : dto.getFiles())
	{
		file_router = file_router + file_segment;
	}
	data.setAttachment(file_router);
	//用雪花算法生成id并转入DO类中
	SnowFlake sf(1, 1);
	uint64_t id_int = sf.nextId();
	//将int转化为string
	ostringstream stream;
	stream << id_int;  //n为int类型
	string id_string=stream.str();
	data.setID(id_string);
	//用format生成create_time创建时间和update_time修改时间
	SimpleDateTimeFormat time;
	string create_time = time.format();
	string update_time = create_time;
	data.setCreate_Time(create_time);
	data.setUpdate_Time(update_time);
	//用PayloadDTO生成Create_By和Update_By
	string create_by= payload.getUsername();
	string update_by = payload.getUsername();
	data.setCreate_By(create_by);
	data.setUpdate_By(update_by);
	//data里面装了42个数据
	//执行数据添加
	SupplierDAO dao;
	return dao.SupplierInsert(data);
}

// 修改供应商
uint64_t SupplierService::modifySupplierData(const ModifySupplierDTO& dto, const PayloadDTO& payload)
{
	//组装数据
	SupplierDO data;
	data.setCode(dto.getCode());
	data.setName(dto.getName());
	data.setAux_Name(dto.getAux_Name());
	data.setSupplier_Category(dto.getSupplier_Category());
	data.setSupplier_Level(dto.getSupplier_Level());
	data.setTax_Scale(dto.getTax_Scale());
	data.setAlter_Suppliers(dto.getAlter_Suppliers());
	//is_enable要单独处理，因为我希望它显示到前端的时候只能是0或1
	//if(dto.getIs_Enabled())
	data.setIs_Enabled(dto.getIs_Enabled());
	data.setRemark(dto.getRemark());
	data.setInvoice_Company(dto.getInvoice_Company());
	data.setInvoice_Tax_Code(dto.getInvoice_Tax_Code());
	data.setInvoice_Bank_Name(dto.getInvoice_Bank_Name());
	data.setInvoice_Account(dto.getInvoice_Account());
	data.setInvoice_Phone(dto.getInvoice_Phone());
	data.setInvoice_Address(dto.getInvoice_Address());
	data.setReceipt_Company(dto.getReceipt_Company());
	data.setReceipt_Bank_Name(dto.getReceipt_Bank_Name());
	data.setReceipt_Bank_Code(dto.getReceipt_Bank_Code());
	data.setReceipt_Account(dto.getReceipt_Account());
	data.setRecv_Name(dto.getRecv_Name());
	data.setRecv_Phone(dto.getRecv_Phone());
	data.setRecv_Fax(dto.getRecv_Fax());
	data.setRecv_Email(dto.getRecv_Email());
	data.setRecv_Address(dto.getRecv_Address());
	data.setRecv_Postcode(dto.getRecv_Postcode());
	data.setFinancial_Contacts(dto.getFinancial_Contacts());
	data.setFinancial_Phone(dto.getFinancial_Phone());
	data.setShort_Name(dto.getShort_Name());
	data.setWebsite(dto.getWebsite());
	data.setLegal_Person(dto.getLegal_Person());
	data.setLegal_Person_Phone(dto.getLegal_Person_Phone());
	data.setHeadQuarters(dto.getHeadQuarters());
	data.setArea(dto.getArea());
	data.setBiz_Area(dto.getBiz_Area());
	data.setAddress(dto.getAddress());
	//data.setCreate_Time(dto.getCreate_Time());————设置时间使用format函数
	//data.setCreate_By(dto.getCreate_By());————设置用户信息使用payloaddto类
	//data.setUpdate_Time(dto.getUpdate_Time());————设置时间使用format函数
	//data.setUpdate_By(dto.getUpdate_By());————设置用户信息使用payloaddto类
	data.setID(dto.getID());
	//用format生成update_time修改时间
	SimpleDateTimeFormat time;
	string update_time = time.format();
	data.setUpdate_Time(update_time);
	//用PayloadDTO生成Update_By修改人
	string update_by = payload.getUsername();
	data.setUpdate_By(update_by);
	//执行数据修改
	SupplierDAO dao;
	return dao.SupplierUpdateByCode(data) ;

}

//删除供应商
uint64_t SupplierService::deleteSupplierData(const DeleteSupplierDTO& dto)
{
	SupplierDAO dao;
	return dao.SupplierDeleteByCode(dto.getID()) == 1;
}