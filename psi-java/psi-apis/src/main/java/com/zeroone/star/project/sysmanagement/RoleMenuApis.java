package com.zeroone.star.project.sysmanagement;

import com.zeroone.star.project.query.sysmanagement.rolemanagement.MenuQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 角色管理：对菜单的操作
 * @Auther: 阿狸
 * @Version: 1.1
 */
public interface RoleMenuApis {
    /**
     * 根据角色id(父id)查询角色所有能访问的菜单列表
     * @param RId
     * @return 菜单列表
     */
    JsonVO<List<MenuQuery>> listAll(String RId);

    /**
     * 根据用户选择的菜单增加该用户的菜单列表
     * @param menuQuery 要添加的菜单id列表
     * @return 是否添加成功
     */
    JsonVO<Boolean> saveMenu(MenuQuery menuQuery);

    /**
     * 根据用户的角色id和要删除的菜单id，删除菜单
     * @param Id
     * @return 是否删除成功
     */
    JsonVO<Boolean> deleteMenu (String Id);
}
