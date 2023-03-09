package com.zeroone.star.login.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.login.entity.SysMenu;
import com.zeroone.star.project.vo.login.MenuTreeVO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author Gerins
 * @since 2023-02-22
 */
public interface ISysMenuService extends IService<SysMenu> {
    /**
     * 获取菜单中的链接地址
     * @return 查询结果
     */
    List<SysMenu> listAllLinkUrl();

    /**
     * 通过角色名称获取，菜单资源
     * @param roleCodes 角色编码
     * @return 返回菜单列表
     */
    public List<MenuTreeVO> listMenuByRoleCode(List<String> roleCodes);
}
