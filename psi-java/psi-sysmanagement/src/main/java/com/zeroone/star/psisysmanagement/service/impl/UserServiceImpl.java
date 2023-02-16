package com.zeroone.star.psisysmanagement.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.psisysmanagement.entity.User;
import com.zeroone.star.psisysmanagement.mapper.UserMapper;
import com.zeroone.star.psisysmanagement.service.IUserService;
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
