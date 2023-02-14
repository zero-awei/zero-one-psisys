package com.zeroone.star.role.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.role.MenuQuery;
import com.zeroone.star.role.entity.SysMenu;
import com.zeroone.star.role.mapper.MenuMapper;
import com.zeroone.star.role.service.IMenuService;

import java.util.ArrayList;
import java.util.List;

public class MenuService extends ServiceImpl<MenuMapper, SysMenu> implements IMenuService {


    @Override
    public List<MenuQuery> showList(int RId) {

        QueryWrapper<SysMenu> listMenu = new QueryWrapper<>();
        List<SysMenu> sysMenus = baseMapper.selectList(listMenu);
        List<MenuQuery> list = new ArrayList<>();
        System.out.println("+++++++++++++++++++++++++");
        for (SysMenu sysMenu : sysMenus) {
            MenuQuery menuQuery = null;
            SysMenu sysMenu1 = sysMenu;
            BeanUtil.copyProperties(sysMenu1,menuQuery);
            System.out.println(sysMenu1);
            list.add(menuQuery);
        }
        System.out.println("+++++++++++++++++++++++++");
        return list;
    }

    @Override
    public Boolean addMenuOrJurisdiction(List<MenuQuery> listMenu) {
        return null;
    }

    @Override
    public Boolean deleteMenuOrJurisdiction(int RId, int MId) {
        return null;
    }
}
