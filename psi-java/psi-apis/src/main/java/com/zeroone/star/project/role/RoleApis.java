package com.zeroone.star.project.role;

import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface RoleApis<T> {
    /**
     * 根据角色id查询角色所有能访问的菜单或权限列表
     * @param RId
     * @return 菜单或者权限列表
     */
    JsonVO<List<T>> showList(int RId);

    /**
     * 根据用户选择的权限增加该用户的菜单或者权限列表
     * @param listMenu
     * @return 是否添加成功
     */
    JsonVO<Boolean> addMenuOrJurisdiction(List<T> listMenu);

    /**
     * 根据用户的角色id和要删除的权限id，删除权限
     * @param RId
     * @param MId
     * @return 是否删除成功
     */
    JsonVO<Boolean> deleteMenuOrJurisdiction (int RId,int MId);
}
