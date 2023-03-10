package com.zeroone.star.psisysmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.MenuQuery;
import com.zeroone.star.psisysmanagement.entity.SysMenu;
import com.zeroone.star.psisysmanagement.mapper.MenuMapper;
import com.zeroone.star.psisysmanagement.service.IRoleMenuService;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
*
* @Author:阿狸
* @Version:1.1
*/
@Service
public class RoleMenuServiceImpl extends ServiceImpl<MenuMapper, SysMenu> implements IRoleMenuService {


    @Override
    public List<MenuQuery> listAll(String RId) {
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
     * @param menuQuery
     * @return
     */
    @Override
    public Boolean saveMenu(MenuQuery menuQuery) { // 添加菜单
        SysMenu sysMenu = new SysMenu();
        BeanUtil.copyProperties(menuQuery,sysMenu);
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
    public Boolean deleteMenu(String Id) {
        int num = baseMapper.deleteById(Id);
        if (num >= 1) {
            return true;
        }
        return false;
    }
}
