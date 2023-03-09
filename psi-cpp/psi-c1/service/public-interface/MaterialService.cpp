#include "stdafx.h"
#include "MaterialService.h"
#include "../../domain/do/public-interface/MaterialQueryDO.h"
#include "../../dao/public-interface/MaterialDAO.h"
#include "../../domain/vo/public-interface/MaterialVO.h"

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
	vector<MaterialReturnDO> r(result.begin(), result.end());
	uint64_t time(query.getPageSize());
	//根据pageindx和pagesize放入返回的元素
	for (uint64_t i = (query.getPageIndex() - 1) * query.getPageSize();
		time > 0 && r.size() > i; i++, time--)
	{
		MaterialVO vo;
		vo.setId(r[i].getId());
		vo.setCode(r[i].getCode());
		vo.setName(r[i].getName());
		vo.setAuxName(r[i].getAuxName());
		vo.setCategoryId(r[i].getCategoryId());
		vo.setCategoryIdDictText(r[i].getCategoryIdDictText());
		vo.setModel(r[i].getModel());
		vo.setUnitIdDictText(r[i].getUnitIdDictText());
		vo.setPrice(r[i].getPrice());
		vo.setTaxCode(r[i].getTaxCode());
		vo.setIsEnabledDictText(r[i].getIsEnabledDictText());
		vo.setRemark(r[i].getRemark());
		vo.setCreateTime(r[i].getCreateTime());
		vo.setCreateBy(r[i].getCreateBy());
		vo.setUpdateTime(r[i].getUpdateTime());
		vo.setUpdateBy(r[i].getUpdateBy());
		vr.push_back(vo);
	}
  	rs.setRows(vr);
	return rs;
}
