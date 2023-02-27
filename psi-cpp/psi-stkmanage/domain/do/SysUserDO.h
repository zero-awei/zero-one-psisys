#pragma once

#ifndef _SysUser_DO_
#define _SysUser_DO_
#include "./DoInclude.h"

/**
 * SysUser数据库实体类
 */
class SysUserDO
{
	// 用户id
	CC_SYNTHESIZE(string, id, Id);
	// 登录账号
	CC_SYNTHESIZE(string, username, Username);
	// 真实姓名
	CC_SYNTHESIZE(string, realname, Realname);
	// 密码
	CC_SYNTHESIZE(string, password, Password);
	// md5密码盐
	CC_SYNTHESIZE(string, salt, Salt);
	// 头像
	CC_SYNTHESIZE(string, avatar, Avatar);
	// 生日
	CC_SYNTHESIZE(string, birthday, Birthday);
	// 性别(0-默认未知,1-男,2-女)
	CC_SYNTHESIZE(int, sex, Sex);
	// 电子邮件
	CC_SYNTHESIZE(string, email, Email);
	// 电话
	CC_SYNTHESIZE(string, phone, Phone);
	// 登录会话的机构编码
	CC_SYNTHESIZE(string, org_code, Org_code);
	// 性别(1-正常,2-冻结)
	CC_SYNTHESIZE(int, status, Status);
	// 删除状态(0-正常,1-已删除)
	CC_SYNTHESIZE(int, del_flag, Del_flag);
	// 同步工作流引擎(1-同步,0-不同步)
	CC_SYNTHESIZE(int, activiti_sync, Activiti_sync);
	// 工号，唯一键
	CC_SYNTHESIZE(string, work_no, Work_no);
	// 职务，关联职务表
	CC_SYNTHESIZE(string,post, Post);
	// 座机号
	CC_SYNTHESIZE(string,telephone, Telephone);
	// 创建人
	CC_SYNTHESIZE(string, creat_by, Creat_by);
	// 创建时间
	CC_SYNTHESIZE(string, creat_time, Creat_time);
	// 更新人
	CC_SYNTHESIZE(string, update_by, Update_by);
	// 更新时间
	CC_SYNTHESIZE(string,update_time,Update_time);
	// 身份（1普通成员 2上级）
	CC_SYNTHESIZE(int, user_identity, User_identity);
	// 负责部门
	CC_SYNTHESIZE(string,depart_ids,Depart_ids);
	// 多租户标识
	CC_SYNTHESIZE(string,rel_tenant_ids,Rel_tenant_ids);
	// 设备ID
	CC_SYNTHESIZE(string,client_id,Client_id);
	
public:
	SysUserDO() {
		id = "";
		username = "";
		realname = "";
		password = "";
		salt = "";
		avatar = "";
		birthday = "";
		sex = 1;
		email = "";
		phone = "";
		org_code = "";
		status = 1;
		del_flag = 0;
		activiti_sync = 1;
		work_no = "";
		post = "";
		telephone = "";
		creat_by = "";
		creat_time = "";
		update_by = "";
		update_time = "";
		user_identity = 1;
		depart_ids = "";
		rel_tenant_ids = "";
		client_id = "";
	}
};

#endif // !_SAMPLE_DO_
