package com.zeroone.star.oauth2;

import com.zeroone.star.oauth2.entity.SysRole;
import com.zeroone.star.oauth2.service.ISysRoleService;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.security.crypto.password.PasswordEncoder;

import javax.annotation.Resource;
import java.util.List;

@SpringBootTest
class Oauth2ApplicationTests {
    @Resource
    ISysRoleService roleService;


    @Test
    public void testRoleService() {
        List<SysRole> sysRoles = roleService.listRoleByUserId("70f5dcf03f36471dabba81381919291f");
        sysRoles.forEach(System.out::println);
    }



}
