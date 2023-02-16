package com.zeroone.star.role.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.MenuQuery;
import com.zeroone.star.role.entity.SysMenu;

import java.util.List;

public interface IMenuService extends IService<SysMenu> {
    List<MenuQuery> showList(String RId) ;

    Boolean addMenuOrPermission(MenuQuery menu) ;

    Boolean deleteMenuOrPermission(String Id) ;
}
