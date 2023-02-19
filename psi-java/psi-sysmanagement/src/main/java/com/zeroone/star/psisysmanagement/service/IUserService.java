package com.zeroone.star.psisysmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.UserDTO;
import com.zeroone.star.project.query.sysmanagement.usermanagement.FindUserQuery;
import com.zeroone.star.project.query.sysmanagement.usermanagement.UserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.EditUserVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.UserVO;
import com.zeroone.star.psisysmanagement.entity.User;

/**
 * <p>
 * 用户表 服务类
 * </p>
 *
 * @author axin
 * @since 2023-02-12
 */
public interface IUserService extends IService<User> {

//    查询用户列表（通过UserQuery中的id属性）
    PageVO<UserVO> listAllUsers(UserQuery query);

//    查询用户信息（通过FindUserQuery中的name属性）
    PageVO<UserVO> queryUser(FindUserQuery query);

//    回显出用户信息（通过id）
    JsonVO<EditUserVO> review(String id);

//    添加用户（通过UserDTO）
     void insert(UserDTO dto);

//    通过id删除用户（通过id）
    void deleteUser(String id);

//    修改用户（通过UserDTO）
    void modifyUser(UserDTO dto);

//    修改冻结状态（通过id）
    void modifyStatus(String id);


}
