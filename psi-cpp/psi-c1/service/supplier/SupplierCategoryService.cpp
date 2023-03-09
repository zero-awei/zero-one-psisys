#include "stdafx.h"
#include "SupplierCategoryService.h"
#include "../../dao/supplier/SupplierCategoryDAO.h"
#include "../../domain/do/supplier/SupplierCategoryReturnDO.h"
std::list<SuppliersCategoryVO> SupplierCategoryService::listAll()
{
	//�������ض���
	list<SuppliersCategoryVO> vr;
	//����dao��
	SupplierCategoryDAO dao;
	list<SupplierCategoryReturnDO> result = dao.selectSupplierCategory();
	for (SupplierCategoryReturnDO sub : result)
	{
		SuppliersCategoryVO vo;
		vo.setName(sub.getName());
		vr.push_back(vo);
	}
	return vr;
}