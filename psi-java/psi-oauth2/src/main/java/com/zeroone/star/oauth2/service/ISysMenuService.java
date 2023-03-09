package com.zeroone.star.oauth2.service;

import com.zeroone.star.oauth2.entity.SysMenu;
import com.baomidou.mybatisplus.extension.service.IService;

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
