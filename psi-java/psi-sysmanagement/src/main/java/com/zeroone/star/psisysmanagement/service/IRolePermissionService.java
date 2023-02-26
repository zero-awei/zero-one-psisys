package com.zeroone.star.psisysmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.sysmanagement.permissionmanagement.PermissionQuery;
import com.zeroone.star.project.vo.sysmanagement.permissionmanagement.PermissionVO;
import com.zeroone.star.psisysmanagement.entity.Permission;
import com.zeroone.star.project.vo.PageVO;


import java.util.List;

public interface IRolePermissionService extends IService<Permission> {

    /**
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
     * @return 权限是否删除成功
     */
    Boolean deletePermission(String permissionId) ;
}

