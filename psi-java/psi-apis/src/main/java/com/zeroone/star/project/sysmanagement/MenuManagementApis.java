package com.zeroone.star.project.sysmanagement;

import com.zeroone.star.project.query.sysmanagement.menumanagement.SysMenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.login.MenuTreeVO;

/**
 * 菜单管理
 * @author xiaoyolee
 * @version 1.0
 */
public interface MenuManagementApis {


    /**
     * 查询单一菜单
     * @param sysMenuQuery
     * @return
     */
    JsonVO<MenuTreeVO> querySingle(SysMenuQuery sysMenuQuery);

    /**
     * 新增菜单
     * @param menuTreeVO
     * @return
     */
    JsonVO<ResultStatus> addMenu(MenuTreeVO menuTreeVO);

    /**
     * 修改菜单
     * @param menuTreeVO
     * @return
     */
    JsonVO<ResultStatus> updateMenu(MenuTreeVO menuTreeVO);

    /**
     * 删除菜单
     * @param sysMenuQuery
     * @return
     */
    JsonVO<ResultStatus> deleteMenu(SysMenuQuery sysMenuQuery);
}
