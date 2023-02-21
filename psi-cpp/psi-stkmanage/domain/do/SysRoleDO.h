#pragma once

#ifndef _SYS_ROLE_DO_
#define _SYS_ROLE_DO_
#include "./DoInclude.h"

/**
 * SysRole数据库实体类
 */
class SysRoleDO {
	// 角色ID
	CC_SYNTHESIZE(string, id, RoleId);
	// 角色状态 
	CC_SYNTHESIZE(string, state, State);
	// 角色名称
	CC_SYNTHESIZE(string, name, RoleName);
	// 角色创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);


public:
	SysRoleDO() {
		id = "";
		state = "";
		name = "";
		createTime = "";
	}
};

#endif // !_SYS_ROLE_DO_