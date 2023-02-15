package com.zeroone.star.project.role;

import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface RoleApis<T> {
    /**
     * 根据角色id查询角色所有能访问的菜单或权限列表
     * @param RId
     * @return 菜单或者权限列表
     */
    JsonVO<List<T>> showList(String RId);

    /**
     * 根据用户选择的权限增加该用户的菜单或者权限列表
     * @param roles 要添加的权限id列表
     * @return 是否添加成功
     */
    JsonVO<Boolean> addMenuOrPermission(T roles);

    /**
     * 根据用户的角色id和要删除的权限id，删除权限
     * @param Id
     * @return 是否删除成功
     */
    JsonVO<Boolean> deleteMenuOrPermission (String Id);
}
