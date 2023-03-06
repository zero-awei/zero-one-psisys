#include "stdafx.h"
#include "MaterialTypeTreeService.h"
#include"CharsetConvertHepler.h"
#include"../../dao/publicInterfaceDao/MaterialTypeTreeDAO.h"

PageVO<MaterialTypeTreeListVO> MaterialTypeTreeListService::listAll(const MaterialTypeItemQuery& query)
{

	//构建返回对象
	PageVO<MaterialTypeTreeListVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());
	//查询数据总条数
	MaterialTypeTreeDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	MaterialTypeTreeDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<MaterialTypeTreeDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<MaterialTypeTreeListVO> vp;
	//子节点list
	list<MaterialTypeTreeListVO> vc;
	for (MaterialTypeTreeDO sub : result)
	{
		//发现有子节点就开始遍历
		vector< MaterialTypeTreeListVO> res;
		if (sub.getHasChild() == "1") {
			MaterialTypeTreeListVO co;
			for (MaterialTypeTreeDO cb : result) {
				if (cb.getPid() == sub.getId()) {
					co.setCode(cb.getCode());
					co.setCreateBy(cb.getCreateBy());
					co.setCreateBy_dictText(CharsetConvertHepler::ansiToUtf8("管理员"));
					co.setCreateTime(cb.getCreateTime());
					co.setFullname(cb.getFullname());
					co.setHasChild(cb.getHasChild());
					co.setHasChild_dictText("");
					co.setId(cb.getId());
					co.setIsEnabled(cb.getIsEnabled());
					co.setIsEnabled_dictText(CharsetConvertHepler::ansiToUtf8("是"));
					co.setName(cb.getName());
					co.setPid(cb.getPid());
					co.setUpdateBy(cb.getUpdateBy());
					if (cb.getUpdateBy() == "admin")	co.setUpdateBy_dictText(CharsetConvertHepler::ansiToUtf8("管理员"));
					else co.setUpdateBy_dictText(u8"");
					co.setUpdateBy_dictText(u8"");
					co.setUpdateTime(cb.getUpdateTime());
					co.setVersion(cb.getVersion());
					res.push_back(co);
				}
			}
		}
		
		MaterialTypeTreeListVO vo;
		vo.setCode(sub.getCode());
		vo.setCreateBy(sub.getCreateBy());
		vo.setCreateBy_dictText(CharsetConvertHepler::ansiToUtf8("管理员"));
		vo.setCreateTime(sub.getCreateTime());
		vo.setFullname(sub.getFullname());
		vo.setHasChild(sub.getHasChild());
		vo.setHasChild_dictText(u8"");
		vo.setId(sub.getId());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setIsEnabled_dictText(CharsetConvertHepler::ansiToUtf8("是"));
		vo.setName(sub.getName());
		vo.setPid(sub.getPid());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setUpdateBy_dictText(CharsetConvertHepler::ansiToUtf8("管理员"));
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setVersion(sub.getVersion());
		vo.setChildren(res);

		vp.push_back(vo);
	}
	pages.setRows(vp);
	return pages;
}
