package com.zeroone.star.psisysmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.sysmanagement.permissionmanagement.PermissionQuery;
import com.zeroone.star.project.vo.sysmanagement.permissionmanagement.PermissionVO;
import com.zeroone.star.psisysmanagement.entity.Permission;
import com.zeroone.star.psisysmanagement.entity.SysPermission;
import com.zeroone.star.project.vo.PageVO;


import java.util.List;

public interface IPermissionService extends IService<Permission> {

    /**
     * 查询权限列表
     * @param condition 查询的条件
     * @return 查询到的集合
     */
    PageVO<PermissionVO> listPermissions(PermissionQuery condition);

    /**
     * 保存权限
     * @param permission 权限的信息
     * @return 保存的结果。0是失败，1是成功
     */
    Boolean savePermission(Permission permission);

    /**
     * 删除权限
     * @param permission 权限的信息
     * @return 删除的结果。0是失败，1是成功
     */
    Boolean removePermission(Permission permission);

    /**
     * 更新权限信息
     * @param permission 权限的信息
     * @return 更新的结果。0是失败，1是成功
     */
    Boolean updatePermission(Permission permission);

}
