#include "stdafx.h"
#include "SupplierCategoryService.h"
#include "../../dao/supplierDAO/SupplierCategoryDAO.h"
#include "../../domain/do/supplierDO/SupplierCategoryReturnDO.h"
std::list<SuppliersCategoryVO> SupplierCategoryService::listAll(const SupplierCategoryQuery& query)
{
	//构建返回对象
	list<SuppliersCategoryVO> vr;
	//构建查询对象
	SupplierCategoryQueryDO obj;
	obj.setName(query.getName());
	//定义dao层
	SupplierCategoryDAO dao;
	list<SupplierCategoryReturnDO> result = dao.selectSupplierCategory(obj);
	for (SupplierCategoryReturnDO sub : result)
	{
		SuppliersCategoryVO vo;
		vo.setName(sub.getName());
		vr.push_back(vo);
	}
	return vr;
}
