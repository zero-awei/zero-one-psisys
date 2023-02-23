package com.zeroone.star.psisysmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.PermissionQuery;
import com.zeroone.star.psisysmanagement.entity.Permission;

import java.util.List;

/**
*
* @Author:阿狸
* @Version:1.1
*/
public interface IPermissionService extends IService<Permission> {

    /**
     * 查询角色权限
     * @param RId
     * @return 角色的含有的相关权限列表
     */
    List<PermissionQuery> listAll(String RId);

    /**
     * 添加权限
     * @param permissionQuery
     * @return 是否添加成功
     */
    Boolean savePermission(PermissionQuery permissionQuery) ;

    /**
     * 删除权限
     * @param permissionId
     * @return 权限是否删除成功
     */
    Boolean deletePermission(String permissionId) ;
}
