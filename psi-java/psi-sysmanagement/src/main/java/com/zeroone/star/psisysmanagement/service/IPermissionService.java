package com.zeroone.star.psisysmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.PermissionQuery;
import com.zeroone.star.psisysmanagement.entity.Permission;

import java.util.List;

public interface IPermissionService extends IService<Permission> {

    List<PermissionQuery> showList(String RId);

    Boolean addMenuOrPermission(PermissionQuery permission) ;

    Boolean deleteMenuOrPermission(String Id) ;
}
