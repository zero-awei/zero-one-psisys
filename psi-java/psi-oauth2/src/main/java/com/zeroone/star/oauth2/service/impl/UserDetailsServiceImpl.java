package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.oauth2.entity.*;
import com.zeroone.star.oauth2.service.ISysRoleService;
import com.zeroone.star.oauth2.service.ISysUserService;
import com.zeroone.star.project.components.easyexcel.constant.AuthConstant;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：用户权限权限服务实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author Gerins
 * @version 1.0.0
 */
@Service
public class UserDetailsServiceImpl implements UserDetailsService {
    @Resource
    ISysUserService userService;
    @Resource
    ISysRoleService roleService;
    @Resource
    HttpServletRequest request;

    @Override
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        String clientId = request.getParameter("client_id");
        if (AuthConstant.CLIENT_MANAGER.equals(clientId)) {
            //1 通过用户名查找用户对象
            SysUser user = new SysUser();
            user.setUsername(username);

            user = userService.getOne(new QueryWrapper<>(user));
            if (user == null) {
                throw new UsernameNotFoundException("用户名或密码错误");
            }

            //2 通过用户ID获取角色列表
            List<SysRole> roles = roleService.listRoleByUserId(user.getId());

            /*
            通过username查询orgCode
             */
            String orgCode = roleService.getOrgCodeByUsername(user.getUsername());

            //3 将数据库角色转换成Security权限对象
            List<GrantedAuthority> authorities = new ArrayList<>();
            roles.forEach(role -> authorities.add(new SimpleGrantedAuthority(role.getRoleCode())));
            //4 构建权限角色对象 TODO: 扩展存储对象在这里通过数据库查询获取并注入到SecurityUser对象中
            return new SecurityUser(user, orgCode, authorities);

        } else if (AuthConstant.CLIENT_APP.equals(clientId)) {
            throw new UsernameNotFoundException("用户端查找用户尚未实现");
        }
        throw new UsernameNotFoundException("登录客户端ID错误");
    }
}
