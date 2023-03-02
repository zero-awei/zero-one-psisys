package com.zeroone.star.login.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.login.entity.SysRole;

import java.util.List;

/**
 * <p>
 * 角色表 服务类
 * </p>
 *
 * @author Gerins
 * @since 2023-02-22
 */
public interface ISysRoleService extends IService<SysRole> {
    /**
     * 通过用户编号获取角色列表
     * @param userId 用户编号
     * @return 角色列表
     */
    List<SysRole> listRoleByUserId(String userId);

    /**
     * 获取指定菜单路径有访问权限的角色
     * @param path 指定菜单路径
     * @return 角色列表
     */
    List<SysRole> listRoleByMenuPath(String path);

    /**
     * 通过用户名查询机构编码
     * @param username 用户名
     * @return 机构编码
     */
    String getOrgCodeByUsername(String username);

}
