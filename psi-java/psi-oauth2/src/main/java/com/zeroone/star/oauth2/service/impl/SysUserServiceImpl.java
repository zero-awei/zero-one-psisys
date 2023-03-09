package com.zeroone.star.oauth2.service.impl;

import com.zeroone.star.oauth2.entity.SysUser;
import com.zeroone.star.oauth2.mapper.SysUserMapper;
import com.zeroone.star.oauth2.service.ISysUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
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

}
