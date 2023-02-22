package com.zeroone.star.oauth2.service.impl;

import com.zeroone.star.oauth2.entity.SysRole;
import com.zeroone.star.oauth2.mapper.SysRoleMapper;
import com.zeroone.star.oauth2.service.ISysRoleService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
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

}
