package com.zeroone.star.login.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.login.entity.SysRole;
import com.zeroone.star.login.mapper.SysRoleMapper;
import com.zeroone.star.login.service.ISysRoleService;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 角色表 服务实现类
 * </p>
 *
 * @author Gerins
 * @since 2023-02-22
 */
@Service
public class SysRoleServiceImpl extends ServiceImpl<SysRoleMapper, SysRole> implements ISysRoleService {
    @Override
    public List<SysRole> listRoleByUserId(String userId) {
        return baseMapper.selectByUserId(userId);
    }

    @Override
    public List<SysRole> listRoleByMenuPath(String path) {
        return baseMapper.selectByMenuPath(path);
    }

    @Override
    public String getOrgCodeByUsername(String username) {
        return baseMapper.selectOrgCodeByUsername(username);
    }
}
