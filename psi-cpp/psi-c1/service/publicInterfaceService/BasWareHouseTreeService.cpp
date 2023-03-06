#include "stdafx.h"
#include "BasWareHouseTreeService.h"
#include"CharsetConvertHepler.h"
#include"./dao/publicInterfaceDao/BasWareHouseTreeDAO.h"

PageVO<BasWareHouseTreeListVO> BasWareHouseTreeService::listAll(const BasWareHouseItemQuery& query)
{
	//构建返回对象
	PageVO<BasWareHouseTreeListVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());
	//查询数据总条数
	BasWareHouseTreeDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	BasWareHouseTreeDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	//分页查询数据
	cout << "count: " << count << endl;
	pages.setTotal(count);
	pages.calcPages();
	list<BasWareHouseTreeDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<BasWareHouseTreeListVO> vp;
	//子节点list
	list<BasWareHouseTreeListVO> vc;
	cout << "size" << result.size() << endl;
	for (BasWareHouseTreeDO sub : result)
	{
		//发现有子节点就开始遍历
		vector< BasWareHouseTreeListVO> res;
		if (sub.getHasChild() == "1") {
			BasWareHouseTreeListVO co;
			for (BasWareHouseTreeDO cb : result) {
				if (cb.getPid() == sub.getId()) {
					co.setCode(cb.getCode());
					co.setCreateBy(cb.getCreateBy());

					co.setCreateBy_dictText(CharsetConvertHepler::ansiToUtf8("管理员"));

					co.setCreateTime(cb.getCreateTime());
					co.setAuxName(cb.getAuxName());
					co.setHasChild(cb.getHasChild());
					co.setId(cb.getId());
					co.setIsEnabled(cb.getIsEnabled());

					co.setIsEnable_dictText(CharsetConvertHepler::ansiToUtf8("是"));

					co.setPhone(cb.getPhone());
					co.setName(cb.getName());
					co.setPid(cb.getPid());
					co.setRemark(cb.getRemark());
					co.setUpdateBy(cb.getUpdateBy());

					if (cb.getUpdateBy() == "admin")	co.setUpdateBy_dictText(CharsetConvertHepler::ansiToUtf8("管理员"));
					else co.setUpdateBy_dictText("");

					co.setUpdateTime(cb.getUpdateTime());
					co.setVersion(cb.getVersion());
					res.push_back(co);
				}
			}
		}

		BasWareHouseTreeListVO vo;
		vo.setCode(sub.getCode());
		vo.setCreateBy(sub.getCreateBy());
		vo.setCreateBy_dictText(CharsetConvertHepler::ansiToUtf8("管理员"));
		vo.setCreateTime(sub.getCreateTime());
		vo.setAuxName(sub.getAuxName());
		vo.setHasChild(sub.getHasChild());
		vo.setId(sub.getId());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setIsEnable_dictText(CharsetConvertHepler::ansiToUtf8("是"));
		vo.setName(sub.getName());

		vo.setPhone(sub.getPhone());
		vo.setRemark(sub.getRemark());
		vo.setPid(sub.getPid());
		vo.setUpdateBy(sub.getUpdateBy());
		if (sub.getUpdateBy() == "admin") vo.setUpdateBy_dictText(CharsetConvertHepler::ansiToUtf8("管理员"));
		else vo.setUpdateBy_dictText(u8"");
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setVersion(sub.getVersion());
		vo.setChildren(res);

		vp.push_back(vo);
	}
	pages.setRows(vp);
	return pages;
}
