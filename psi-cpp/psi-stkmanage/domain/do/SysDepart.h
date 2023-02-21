#pragma once
#ifndef _SYS_DEPART_
#define _SYS_DEPART_

#include "DoInclude.h"

/**
* sys_depart 组织机构表数据库实体类
*/

class SysDepartDO
{
	// ID
	CC_SYNTHESIZE(std::string, id, Id);
	// 父机构ID
	CC_SYNTHESIZE(std::string, parentId, ParentId);
	// 机构/部门名称
	CC_SYNTHESIZE(std::string, departName, DepartName);
	// 英文名
	CC_SYNTHESIZE(std::string, departNameEn, DepartNameEn);
	// 缩写
	CC_SYNTHESIZE(std::string, departNameAbbr, DepartNameAbbr);
	// 排序
	CC_SYNTHESIZE(int, departOrder, DepartOrder);
	// 描述
	CC_SYNTHESIZE(std::string, description, Description);
	// 机构类别 1组织机构，2岗位
	CC_SYNTHESIZE(std::string, orgCategory, OrgCategory);
	// 机构类型 1一级部门 2子部门
	CC_SYNTHESIZE(std::string, orgType, OrgType);
	// 机构编码
	CC_SYNTHESIZE(std::string, orgCode, OrgCode);
	// 手机号
	CC_SYNTHESIZE(std::string, mobile, Mobile);
	// 传真
	CC_SYNTHESIZE(std::string, fax, Fax);
	// 地址
	CC_SYNTHESIZE(std::string, address, Address);
	//备注
	CC_SYNTHESIZE(std::string, memo, Memo);
	// 状态(1启用, 0不启用)
	CC_SYNTHESIZE(std::string, status, Status);
	// 删除状态（0，正常，1已删除）
	CC_SYNTHESIZE(std::string, delFlag, DelFlag);
	// 对接企业微信的ID
	CC_SYNTHESIZE(std::string, qywxIdentifier, QywxIdentifier);
	// 创建人
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	// 创建日期
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	// 更新人
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
	// 更新日期
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
public:
	SysDepartDO() : id(""), parentId(""), departName(""), departNameEn(""), departNameAbbr(""),
		departOrder(0), description(""), orgCategory(""), orgType(""), orgCode(""), mobile(""),
		fax(""), address(""), memo(""), status(""), delFlag(""), qywxIdentifier(""), createBy(""),
		createTime(""), updateBy(""), updateTime("") {}
};

#endif // !_SYS_DEPART_
