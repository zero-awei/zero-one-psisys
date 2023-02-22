package com.zeroone.star.psisysmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.MenuQuery;
import com.zeroone.star.psisysmanagement.entity.SysMenu;

import java.util.List;

/**
*
* @Author:阿狸
* @Version:1.1
*/
public interface IMenuService extends IService<SysMenu> {

    /**
     * 查询角色菜单
     * @param RId
     * @return 角色的含有的相关菜单列表
     */
    List<MenuQuery> listAll(String RId) ;

    /**
     * 添加菜单
     * @param menu
     * @return 菜单是否添加成功
     */
    Boolean saveMenuOrPermission(MenuQuery menu) ;

    /**
     * 删除菜单
     * @param Id
     * @return 菜单是否删除成功
     */
    Boolean deleteMenuOrPermission(String Id) ;
}
