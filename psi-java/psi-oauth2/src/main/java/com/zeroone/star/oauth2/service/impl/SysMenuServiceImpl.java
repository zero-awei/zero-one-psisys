package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.oauth2.entity.SysMenu;
import com.zeroone.star.oauth2.mapper.SysMenuMapper;
import com.zeroone.star.oauth2.service.ISysMenuService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

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

}
