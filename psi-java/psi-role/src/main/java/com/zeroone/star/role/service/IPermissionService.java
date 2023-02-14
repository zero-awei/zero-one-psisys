package com.zeroone.star.role.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.role.MenuQuery;
import com.zeroone.star.project.query.role.PermissionQuery;
import com.zeroone.star.role.entity.SysPermission;

import java.util.List;

public interface IPermissionService extends IService<SysPermission> {

    List<PermissionQuery> showList(int RId);

    Boolean addMenuOrJurisdiction(List<PermissionQuery> listMenu) ;

    Boolean deleteMenuOrJurisdiction(int RId, int MId) ;
}
