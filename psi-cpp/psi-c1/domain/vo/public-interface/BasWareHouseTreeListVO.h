#pragma once
#ifndef _BASWAREHOUSETREELISTVO_H_
#define _BASWAREHOUSETREELISTVO_H_

#include"../../GlobalInclude.h"

class BasWareHouseTreeListVO {

	CC_SYNTHESIZE(std::string, auxName, AuxName);
	CC_SYNTHESIZE(std::string, code, Code);
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	CC_SYNTHESIZE(std::string, createBy_dictText, CreateBy_dictText);
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	CC_SYNTHESIZE(std::string, hasChild, HasChild);
	CC_SYNTHESIZE(std::string, id,Id);
	CC_SYNTHESIZE(int, isEnabled,IsEnabled);
	CC_SYNTHESIZE(std::string,isEnabled_dictText, IsEnable_dictText);
	CC_SYNTHESIZE(std::string, name, Name);
	CC_SYNTHESIZE(std::string, phone, Phone);
	CC_SYNTHESIZE(std::string, pid, Pid);
	CC_SYNTHESIZE(std::string, remark, Remark);
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
	CC_SYNTHESIZE(std::string, updateBy_dictText, UpdateBy_dictText);
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	CC_SYNTHESIZE(std::string, version, Version);
	CC_SYNTHESIZE(vector<BasWareHouseTreeListVO>, children, Children);




public:

	BIND_TO_JSON(BasWareHouseTreeListVO, auxName, code, createBy, createBy_dictText, createTime,hasChild, id, isEnabled, isEnabled_dictText, name, phone, pid, remark, updateBy,
		updateBy, updateBy_dictText, updateTime, version, children);

	BasWareHouseTreeListVO() {
		auxName = u8"二级库";
		code = u8"二级库";
		createBy = u8"psi";
		createBy_dictText = u8"管理员";
		createTime = u8"2023-01-09 12:44:08";
		hasChild = u8"1";
		id = "1623573442275351578";
		isEnabled = 1;
		isEnabled_dictText = u8"是";
		name = u8"二级库";
		phone = "";
		pid = "0";
		remark = "";
		updateBy = u8"psi";
		updateBy_dictText = u8"管理员";
		updateTime = "2023-02-09 14:44:20";
		version = "";
	}

};


#endif