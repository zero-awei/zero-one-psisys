package com.zeroone.star.project.menumanagement;

import com.zeroone.star.project.query.menumanagement.SingleMenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.TreeNodeVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;

import java.util.List;

/**
 * <p>
 * 描述：菜单管理接口
 * </p>
 *
 * @author 归
 * @version 1.0.0
 */

public interface MenuManagement {

    /**
     *  <p>
     * 描述：查询菜单
     * </p>
     *
     * @author 归
     * @version 1.0.0
     */
    JsonVO<List<TreeNodeVO<MenuTreeVO>>> queryById(SingleMenuQuery singleMenuQuery);

    /**
     *  <p>
     * 描述：增加菜单
     * </p>
     *
     * @author 归
     * @version 1.0.0
     */
    JsonVO<ResultStatus> addMenu(MenuTreeVO menuTreeVO);
    /**
     *  <p>
     * 描述：修改菜单
     * </p>
     *
     * @author 归
     * @version 1.0.0
     */
    JsonVO<ResultStatus> updateMenu(MenuTreeVO menuTreeVO);
    /**
     *  <p>
     * 描述：查询菜单
     * </p>
     *
     * @author 归
     * @version 1.0.0
     */
    JsonVO<ResultStatus> deleteMenu(SingleMenuQuery singleMenuQuery);
}
