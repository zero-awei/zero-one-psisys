package com.zeroone.star.oauth2.service;

import com.zeroone.star.oauth2.entity.SysRole;
import com.baomidou.mybatisplus.extension.service.IService;

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
}
