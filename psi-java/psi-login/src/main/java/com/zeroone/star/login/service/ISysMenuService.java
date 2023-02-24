package com.zeroone.star.login.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.login.entity.SysMenu;

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
}
