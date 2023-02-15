package com.zeroone.star.user.service.impl;

import com.zeroone.star.user.entity.User;
import com.zeroone.star.user.mapper.UserMapper;
import com.zeroone.star.user.service.IUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 用户表 服务实现类
 * </p>
 *
 * @author axin
 * @since 2023-02-12
 */
@Service
public class UserServiceImpl extends ServiceImpl<UserMapper, User> implements IUserService {

}
