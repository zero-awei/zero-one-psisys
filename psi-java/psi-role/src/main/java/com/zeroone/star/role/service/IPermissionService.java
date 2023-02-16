package com.zeroone.star.role.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.PermissionQuery;
import com.zeroone.star.role.entity.SysPermission;

import java.util.List;

public interface IPermissionService extends IService<SysPermission> {

    List<PermissionQuery> showList(String RId);

    Boolean addMenuOrPermission(PermissionQuery permission) ;

    Boolean deleteMenuOrPermission(String Id) ;
}
