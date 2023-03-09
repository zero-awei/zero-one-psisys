package com.zeroone.star.login.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.login.entity.SysUser;
import com.zeroone.star.project.dto.login.LoginDTO;

/**
 * <p>
 * 用户表 服务类
 * </p>
 *
 * @author Gerins
 * @since 2023-02-22
 */
public interface ISysUserService extends IService<SysUser> {

    /**
     * 通过用户名查询密码
     * @param username 用户名
     * @return 当前加密后的密码
     */
    String getCurrentPassword(String username);


    /**
     * 修改密码
     * @param username 用户名
     * @param password 密码
     * @return 是否修改成功
     */
    Boolean updatePassword(String username, String password);
}
