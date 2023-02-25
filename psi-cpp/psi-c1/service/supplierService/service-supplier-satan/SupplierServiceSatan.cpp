#include "stdafx.h"
#include "SupplierServiceSatan.h"
#include "../../../dao/supplierDao/dao-Supplier-satan/SupplierDAO.h"
#include "../lib-common/include/SnowFlake.h"
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
	list<SupplierDO> result = dao.SpecifiedSelect(query.getCode());
	for (SupplierDO sub : result)
	{
		data.setCode(sub.getCode());
		data.setName(sub.getName());
		data.setAux_Name(sub.getAux_Name());
		data.setSupplier_Category(sub.getSupplier_Category());
		data.setSupplier_Level(sub.getSupplier_Level());
		data.setTax_Scale(sub.getTax_Scale());
		data.setAlter_Suppliers(sub.getAlter_Suppliers());
		data.setIs_Enabled(sub.getIs_Enabled());
		data.setRemark(sub.getRemark());
		data.setInvoice_Company(sub.getInvoice_Company());
		data.setInvoice_Tax_Code(sub.getInvoice_Tax_Code());
		data.setInvoice_Bank_Name(sub.getInvoice_Bank_Name());
		data.setInvoice_Bank_Code(sub.getInvoice_Bank_Code());
		data.setInvoice_Account(sub.getInvoice_Account());
		data.setInvoice_Phone(sub.getInvoice_Phone());
		data.setInvoice_Address(sub.getInvoice_Address());
		data.setReceipt_Company(sub.getReceipt_Company());
		data.setReceipt_Bank_Name(sub.getReceipt_Bank_Name());
		data.setReceipt_Bank_Code(sub.getReceipt_Bank_Code());
		data.setReceipt_Account(sub.getReceipt_Account());
		data.setRecv_Name(sub.getRecv_Name());
		data.setRecv_Phone(sub.getRecv_Phone());
		data.setRecv_Fax(sub.getRecv_Fax());
		data.setRecv_Email(sub.getRecv_Email());
		data.setRecv_Address(sub.getRecv_Address());
		data.setRecv_Postcode(sub.getRecv_Postcode());
		data.setFinancial_Contacts(sub.getFinancial_Contacts());
		data.setFinancial_Phone(sub.getFinancial_Phone());
		data.setShort_Name(sub.getShort_Name());
		data.setWebsite(sub.getWebsite());
		data.setLegal_Person(sub.getLegal_Person());
		data.setLegal_Person_Phone(sub.getLegal_Person_Phone());
		data.setHeadQuarters(sub.getHeadQuarters());
		data.setArea(sub.getArea());
		data.setBiz_Area(sub.getBiz_Area());
		data.setAddress(sub.getAddress());
		data.setAttachment(sub.getAttachment());
		data.setCreate_Time(sub.getCreate_Time());
		data.setCreate_By(sub.getCreate_By());
		data.setUpdate_Time(sub.getUpdate_Time());
		data.setUpdate_By(sub.getUpdate_By());
	}
	return data;
}
// 添加供应商
uint64_t SupplierService::addSupplierData(const AddSupplierDTO& dto)
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
	data.setCreate_Time(dto.getCreate_Time());
	data.setCreate_By(dto.getCreate_By());
	data.setUpdate_Time(dto.getUpdate_Time());
	data.setUpdate_By(dto.getUpdate_By());
	//将文件的上传路径也装入DO领域模型类中，在执行SupplierInsert进行返回
	string file_router;
	for (auto file_segment : dto.getFiles())
	{
		file_router = file_router + file_segment;
	}
	data.setAttachment(file_router);
	//生成id并转入DO类中
	
	//data里面装了41个数据
	//执行数据添加
	SupplierDAO dao;
	return dao.SupplierInsert(data);
}

// 修改供应商
uint64_t SupplierService::modifySupplierData(const ModifySupplierDTO& dto)
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
	data.setCreate_Time(dto.getCreate_Time());
	data.setCreate_By(dto.getCreate_By());
	data.setUpdate_Time(dto.getUpdate_Time());
	data.setUpdate_By(dto.getUpdate_By());

	//执行数据修改
	SupplierDAO dao;
	return dao.SupplierUpdateByCode(data) == 1;

}
//删除供应商
uint64_t SupplierService::deleteSupplierData(const DeleteSupplierDTO& dto)
{
	SupplierDAO dao;
	return dao.SupplierDeleteByCode(dto.getID()) == 1;
}