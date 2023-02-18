package com.zeroone.star.psisysmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.MenuQuery;
import com.zeroone.star.psisysmanagement.entity.SysMenu;
import com.zeroone.star.psisysmanagement.mapper.MenuMapper;
import com.zeroone.star.psisysmanagement.service.IMenuService;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class MenuService extends ServiceImpl<MenuMapper, SysMenu> implements IMenuService {

    @Override
    public List<MenuQuery> showList(String RId) {
        QueryWrapper<SysMenu> listMenu = new QueryWrapper<>();
        listMenu.eq("parent_id",RId);
        List<SysMenu> menus = baseMapper.selectList(listMenu);
        List<MenuQuery> list = new ArrayList<>();
        for (SysMenu menu : menus) {
            MenuQuery menuQuery = new MenuQuery();
            BeanUtil.copyProperties(menu,menuQuery);
            list.add(menuQuery);
        }
        return list;
    }

    /**
     * 用户选中菜单后，新增菜单
     * @param menu
     * @return
     */
    @Override
    public Boolean addMenuOrPermission(MenuQuery menu) { // 添加菜单
        SysMenu sysMenu = new SysMenu();
        BeanUtil.copyProperties(menu,sysMenu);
        int num = baseMapper.insert(sysMenu);
        if (num >= 1){
            return true;
        }
        return false;
    }

    /**
     * 根据ID删除菜单
     * @param Id
     * @return
     */
    @Override
    public Boolean deleteMenuOrPermission(String Id) {
        int num = baseMapper.deleteById(Id);
        if (num >= 1) {
            return true;
        }
        return false;
    }
}
