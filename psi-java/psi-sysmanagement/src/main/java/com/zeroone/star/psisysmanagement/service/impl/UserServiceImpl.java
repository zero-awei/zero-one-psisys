package com.zeroone.star.psisysmanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.UserDTO;
import com.zeroone.star.project.query.sysmanagement.usermanagement.FindUserQuery;
import com.zeroone.star.project.query.sysmanagement.usermanagement.UserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.EditUserVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.UserVO;
import com.zeroone.star.psisysmanagement.entity.User;
import com.zeroone.star.psisysmanagement.mapper.UserMapper;
import com.zeroone.star.psisysmanagement.service.IUserService;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 用户表 服务实现类
 * </p>
 *
 * @author  axin
 * @since 2023-02-12
 */
@Service
public class UserServiceImpl extends ServiceImpl<UserMapper, User> implements IUserService {


    //    展示用户列表 finished tested（传id的情况下）
    @Override
    public PageVO<UserVO> listAllUsers(UserQuery query) {
        //        创建分页对象
        Page<User> userPage = new Page<>(query.getPageIndex(), query.getPageSize());
//        执行分页查询
        Page<User> result = baseMapper.selectPage(userPage,null);
        return PageVO.create(result, UserVO.class);
    }

    //    模糊查询用户 finished tested
    @Override
    public PageVO<UserVO> listUser(FindUserQuery query) {
        //        创建分页对象
        Page<User> userPage = new Page<>(query.getPageIndex(), query.getPageSize());
//        创建查询条件
        QueryWrapper<User> userQueryWrapper = new QueryWrapper<>();
        userQueryWrapper.like("realname",query.getName());
        userQueryWrapper.like("username",query.getName());
//        执行分页查询
        Page<User> result = baseMapper.selectPage(userPage, userQueryWrapper);
        return PageVO.create(result, UserVO.class);
    }

    @Override
    public JsonVO<EditUserVO> review(String id) {
        return null;
    }

}