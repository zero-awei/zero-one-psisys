package com.zeroone.star.login.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.login.entity.Menu;
import com.zeroone.star.login.mapper.MenuMapper;
import com.zeroone.star.login.service.IMenuService;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 菜单 服务实现类
 * </p>
 * @author 阿伟
 */
@Service
public class MenuServiceImpl extends ServiceImpl<MenuMapper, Menu> implements IMenuService {

    @Override
    public List<MenuTreeVO> listMenuByRoleName(List<String> roleNames) {
        //1 定义一个Menus数组用于存放Menus对象
        List<MenuTreeVO> result = new ArrayList<>();
        //2 遍历获取角色获取所有的菜单列表
        roleNames.forEach(roleName -> {
            //通过角色名获取菜单列表
            List<Menu> tMenus = baseMapper.selectByRoleName(roleName);
            tMenus.forEach(menu -> {
                MenuTreeVO vo = new MenuTreeVO();
                BeanUtils.copyProperties(menu, vo);
                result.add(vo);
            });
        });
        //返回查询结果
        return result;
    }
}
