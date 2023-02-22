package com.zeroone.star.oauth2.service.impl;

import com.zeroone.star.oauth2.entity.SysMenu;
import com.zeroone.star.oauth2.entity.SysRole;
import com.zeroone.star.oauth2.service.ISysMenuService;
import com.zeroone.star.oauth2.service.ISysRoleService;
import com.zeroone.star.project.constant.RedisConstant;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

/**
 * <p>
 * 描述：路径与角色资源服务器初始化服务
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author Gerins
 * @version 1.0.0
 */
@Service
public class ResourceServiceImpl {
    @Resource
    private RedisTemplate<String, Object> redisTemplate;
    @Resource
    private ISysMenuService menuService;
    @Resource
    private ISysRoleService roleService;

    @PostConstruct
    public void init() {
        // 定义缓存map
        Map<String, List<String>> resourceRolesMap = new TreeMap<>();
        // 1 获取所有菜单
        List<SysMenu> tMenus = menuService.listAllLinkUrl();
        tMenus.forEach(menu -> {
            // 2 获取菜单对应的角色
            List<SysRole> rolesMenu = roleService.listRoleByMenuPath(menu.getUrl());
            List<String> roles = new ArrayList<>();
            rolesMenu.forEach(role -> roles.add(role.getRoleCode()));
            resourceRolesMap.put(menu.getUrl(), roles);
        });

        //将资源缓存到redis
        redisTemplate.opsForHash().putAll(RedisConstant.RESOURCE_ROLES_MAP, resourceRolesMap);
    }
}
