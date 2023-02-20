package com.zeroone.star.psisysmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.sysmanagement.menumanagement.MenuDTO;
import com.zeroone.star.project.query.sysmanagement.menumanagement.MenusQuery;
import com.zeroone.star.project.query.sysmanagement.menumanagement.SingleMenuQuery;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.MenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.sysmanagement.menumanagement.MenuVO;
import com.zeroone.star.psisysmanagement.entity.SysMenu;
import org.apache.commons.math3.analysis.function.Sin;

import java.awt.*;
import java.util.List;

/**
 * <p>
 * 服务类
 * </p>
 *
 * @author 归、深夜梦想家
 * @since 2023-02-14
 */
public interface ISysMenuService extends IService<SysMenu> {

    /**
     * 查询单一菜单
     *
     * @param singleMenuQuery
     * @return
     */
    JsonVO<MenuVO> querySingle(SingleMenuQuery singleMenuQuery);

    /**
     * 查询父节点下菜单组
     * @param menusQuery
     * @return
     */
    JsonVO<List<MenuVO>> queryMenus(MenusQuery menusQuery);

    /**
     * 新增菜单
     * @param menuDTO
     * @return
     */
    JsonVO<ResultStatus> addMenu(MenuDTO menuDTO);

    /**
     * 修改菜单
     * @param menuDTO
     * @return
     */
    JsonVO<ResultStatus> updateMenu(MenuDTO menuDTO);

    /**
     * 删除菜单
     * @param singleMenuQuery
     * @return
     */
    JsonVO<ResultStatus> deleteMenu(SingleMenuQuery singleMenuQuery);

}
