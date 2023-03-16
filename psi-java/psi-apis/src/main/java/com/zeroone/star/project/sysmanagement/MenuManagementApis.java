package com.zeroone.star.project.sysmanagement;

import cn.hutool.db.Page;
import com.zeroone.star.project.dto.sysmanagement.menumanagement.MenuDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.sysmanagement.menumanagement.SysMenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import com.zeroone.star.project.vo.sysmanagement.menumanagement.MenuVO;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.List;

/**
 * 菜单管理
 * @author xiaoyolee
 * @version 1.0
 */
public interface MenuManagementApis {

    /**
     * 新增菜单
     * @param menuDTO
     * @return 是否新增成功
     */
    JsonVO<String> addMenu(MenuDTO menuDTO);

    /**
     * 修改菜单
     * @param menuDTO
     * @return 是否修改成功
     */
    JsonVO<String> updateMenu(MenuDTO menuDTO);

    /**
     * 删除菜单
     * @param id
     * @return 是否删除成功
     */
    JsonVO<String> deleteMenu(String id);

    /**
     * 查询菜单
     * @param sysMenuQuery
     * @return
     */
    JsonVO<PageVO<MenuVO>> queryMenus(SysMenuQuery sysMenuQuery);

    /**
     * 查询所有菜单
     * @param sysMenuQuery
     * @return
     */
    JsonVO<PageVO<MenuVO>> queryAllMenus(PageQuery sysMenuQuery);

}
