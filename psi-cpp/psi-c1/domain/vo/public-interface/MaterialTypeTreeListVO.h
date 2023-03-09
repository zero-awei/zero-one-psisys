#pragma once
#ifndef _MATERIALTYPETREELISTVO_H_
#define _MATERIALTYPETREELISTVO_H_
#include"../../GlobalInclude.h"


class MaterialTypeTreeListVO {
	CC_SYNTHESIZE(std::string, code, Code);
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	CC_SYNTHESIZE(std::string, createBy_dictText, CreateBy_dictText);
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	CC_SYNTHESIZE(std::string, fullname, Fullname);
	CC_SYNTHESIZE(std::string, hasChild, HasChild);
	CC_SYNTHESIZE(std::string, hasChild_dictText, HasChild_dictText);
	CC_SYNTHESIZE(std::string, id, Id);
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
	CC_SYNTHESIZE(std::string, isEnabled_dictText, IsEnabled_dictText);
	CC_SYNTHESIZE(std::string, name, Name);
	CC_SYNTHESIZE(std::string, pid, Pid);
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
	CC_SYNTHESIZE(std::string, updateBy_dictText, UpdateBy_dictText);
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	CC_SYNTHESIZE(std::string, version, Version);
	CC_SYNTHESIZE(std::vector<MaterialTypeTreeListVO>, children,Children);

public:
	BIND_TO_JSON(MaterialTypeTreeListVO, code, createBy, createBy_dictText, createTime, fullname, hasChild, hasChild_dictText,id, isEnabled, isEnabled_dictText,
		name, pid, updateBy, updateBy_dictText,updateTime, version, children);

	MaterialTypeTreeListVO() {
		code = u8"02";
		createBy = u8"psi";
		createBy_dictText = u8"管理员";
		createTime = "2023-02-09 16:59:48";
		fullname = "";
		hasChild = "1";
		hasChild_dictText = u8"是";
		id = "1623607583641477122";
		isEnabled = 1;
		isEnabled_dictText = u8"是";
		name = u8"水果";
		pid = "0";
		updateBy = u8"psi";
		updateBy_dictText = u8"管理员";
		updateTime = "2023-02-012 14:56:14";
		version = "";
	}

};
#endif