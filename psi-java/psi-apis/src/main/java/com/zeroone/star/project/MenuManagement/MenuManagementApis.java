package com.zeroone.star.project.MenuManagement;

import com.zeroone.star.project.query.MenuManagement.SingleMenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.TreeNodeVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;

import java.util.List;

/**
 * 菜单管理
 * @author xiaoyolee
 * @version 1.0
 */
public interface MenuManagementApis {

    /**
     * 获取菜单数据
     * @return 菜单数据
     */
    JsonVO<List<TreeNodeVO<MenuTreeVO>>> queryAll();

    /**
     * 查询单一菜单
     * @param singleMenuQuery
     * @return
     */
    JsonVO<MenuTreeVO> querySingle(SingleMenuQuery singleMenuQuery);

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
     * @param singleMenuQuery
     * @return
     */
    JsonVO<ResultStatus> deleteMenu(SingleMenuQuery singleMenuQuery);
}
