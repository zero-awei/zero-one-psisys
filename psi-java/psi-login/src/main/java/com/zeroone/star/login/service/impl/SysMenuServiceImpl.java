package com.zeroone.star.login.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.login.entity.Menu;
import com.zeroone.star.login.entity.SysMenu;
import com.zeroone.star.login.mapper.SysMenuMapper;
import com.zeroone.star.login.service.ISysMenuService;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author Gerins
 * @since 2023-02-22
 */
@Service
public class SysMenuServiceImpl extends ServiceImpl<SysMenuMapper, SysMenu> implements ISysMenuService {

    @Override
    public List<SysMenu> listAllLinkUrl() {
        LambdaQueryWrapper<SysMenu> lambdaQueryWrapper = new LambdaQueryWrapper<>();
        lambdaQueryWrapper.select(SysMenu::getUrl);
        lambdaQueryWrapper.isNotNull(SysMenu::getUrl);
        return baseMapper.selectList(lambdaQueryWrapper);
    }

    /**
     * 通过角色名称获取，菜单资源
     * @param roleCodes 角色编码
     * @return 返回菜单列表
     */
    @Override
    public List<MenuTreeVO> listMenuByRoleCode(List<String> roleCodes) {
        //1 定义一个Menus数组用于存放Menus对象
        List<MenuTreeVO> result = new ArrayList<>();
        HashSet<String> menuIdSet = new HashSet<>();
        //2 遍历获取角色获取所有的菜单列表
        roleCodes.forEach(roleCode -> {
            //通过角色编码获取菜单列表
            List<SysMenu> tMenus = baseMapper.selectByRoleCode(roleCode);
            tMenus.forEach(menu -> {
                if (!menuIdSet.contains(menu.getId())) {
                    MenuTreeVO vo = new MenuTreeVO();
                    vo.setId(menu.getId());
                    vo.setName(menu.getName());
                    vo.setPath(menu.getUrl());
                    vo.setIcon(menu.getIcon());
                    vo.setParentMenuId(menu.getParentId());
                    result.add(vo);
                    menuIdSet.add(menu.getId());
                }
            });
        });
        //返回查询结果
        return result;
    }

}
