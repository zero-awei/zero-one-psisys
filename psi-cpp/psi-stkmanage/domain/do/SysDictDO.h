#pragma once

#ifndef _SYS_DICT_DO_
#define _SYS_DICT_DO_
#include "./DoInclude.h"

/**
 * SysDict数据库实体类
 */
class SysDictDO {
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 字典名称
	CC_SYNTHESIZE(string, dictName, DictName);
	// 字典编码
	CC_SYNTHESIZE(string, dictCode, DictCode);
	// 描述
	CC_SYNTHESIZE(string, description, Description);
	// 删除状态
	CC_SYNTHESIZE(int, delFlag, DelFlag);
	// 创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//字典类型
	CC_SYNTHESIZE(int, type, Type);


public:
	SysDictDO() {
		id = "";
		dictName = "";
		dictCode = "";
		description = "";
		delFlag = 1;
		createBy = "";
		createTime = "";
		updateBy = "";
		updateTime = "";
		type = 1;
	}
};

#endif // !_SYS_DICT_DO_
