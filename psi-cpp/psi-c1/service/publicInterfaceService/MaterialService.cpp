#include "stdafx.h"
#include "MaterialService.h"
#include "../../domain/do/publicInterfaceDO/MaterialQueryDO.h"
#include "../../dao/publicInterfaceDAO/MaterialDAO.h"
#include "../../domain/vo/publicInterfaceVO/MaterialVO.h"

PageVO<MaterialVO> MaterialService::listAll(const MaterialQuery& query)
{
	//构建返回对象
	PageVO<MaterialVO> rs;
	rs.setPageIndex(query.getPageIndex());
	rs.setPageSize(query.getPageSize());

	//构建查询do对象
	MaterialQueryDO obj;
	obj.setCode(query.getCode());
	obj.setName(query.getName());
	obj.setType(query.getType());
	obj.setTaxCode(query.getTaxCode());

	MaterialDAO dao;
	
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return rs;
	}

	//分页查询数据
	rs.setTotal(count);
	rs.calcPages();

	list<MaterialReturnDO>result = dao.selecMaterialWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<MaterialVO> vr;
	for (MaterialReturnDO sub : result)
	{
		MaterialVO vo;
		vo.setId(sub.getId());
		vo.setCode(sub.getCode());
		vo.setName(sub.getName());
		vo.setAuxName(sub.getAuxName());
		vo.setCategoryId(sub.getCategoryId());
		vo.setCategoryIdDictText(sub.getCategoryIdDictText());
		vo.setModel(sub.getModel());
		vo.setUnitIdDictText(sub.getUnitIdDictText());
		vo.setPrice(sub.getPrice());
		vo.setTaxCode(sub.getTaxCode());
		vo.setIsEnabledDictText(sub.getIsEnabledDictText());
		vo.setRemark(sub.getRemark());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vr.push_back(vo);
	}
  	rs.setRows(vr);
	return rs;
}
