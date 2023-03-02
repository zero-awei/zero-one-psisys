package com.zeroone.star.login.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.login.entity.SysUser;
import com.zeroone.star.login.mapper.SysUserMapper;
import com.zeroone.star.login.service.ISysUserService;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 用户表 服务实现类
 * </p>
 *
 * @author Gerins
 * @since 2023-02-22
 */
@Service
public class SysUserServiceImpl extends ServiceImpl<SysUserMapper, SysUser> implements ISysUserService {

    @Override
    public String getCurrentPassword(String username) {
        LambdaQueryWrapper<SysUser> lambdaQueryWrapper = new LambdaQueryWrapper<>();
        lambdaQueryWrapper.eq(SysUser::getUsername, username);
        SysUser sysUser = baseMapper.selectOne(lambdaQueryWrapper);
        return sysUser.getPassword();
    }

    @Override
    public Boolean updatePassword(String username, String password) {
        SysUser sysUser = new SysUser();
        sysUser.setUsername(username);
        sysUser.setPassword(password);

        UpdateWrapper<SysUser> updateWrapper = new UpdateWrapper<>();
        updateWrapper.eq("username", username);

        int update = baseMapper.update(sysUser, updateWrapper);
        return update == 1;
    }
}
