package com.zeroone.star.psisysmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.sysmanagement.menumanagement.MenuDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.sysmanagement.menumanagement.SysMenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.sysmanagement.menumanagement.MenuVO;
import com.zeroone.star.psisysmanagement.entity.SysMenu;

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
     * @param sysMenuQuery
     * @return
     */
    JsonVO<ResultStatus> deleteMenu(SysMenuQuery sysMenuQuery);

    /**
     * 查询所有菜单
     * @param condition
     * @return 菜单列表
     */
    PageVO<MenuVO> selectAllMenus(PageQuery condition);

    /**
     * 查询菜单
     * @param sysMenuQuery
     * @return
     */
    PageVO<MenuVO> queryMenus(SysMenuQuery sysMenuQuery);

}

