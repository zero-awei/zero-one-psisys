#pragma once
#ifndef _SYS_DICT_ITEM_DO_
#define _SYS_DICT_ITEM_DO_

#include "DoInclude.h"

/*
* sys_dict_item表实体类
*/
class SysDictItemDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 字典id
	CC_SYNTHESIZE(string, dictId, DictId);
	// 字典项文本
	CC_SYNTHESIZE(string, itemText, ItemText);
	// 字典项值
	CC_SYNTHESIZE(string, itemValue, ItemValue);
	// 描述
	CC_SYNTHESIZE(string, description, Description);
	// 排序
	CC_SYNTHESIZE(int, sortOrder, SortOrder);
	// 状态(1:启用, 2:不启用)
	CC_SYNTHESIZE(int, status, Status);
	// 创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	SysDictItemDO() {
		id = "";
		dictId = "";
		itemText = "";
		itemValue = "";
		description = "";
		sortOrder = -1;
		status = 2;
		createBy = "";
		createTime = "";
		updateBy = "";
		updateTime = "";
	}
};

#endif // !_SYS_DICT_ITEM_DO_