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
    PasswordEncoder passwordEncoder;

    @Test
    public void testPasswordEncoder() {
        System.out.println("------------------生成密码--------------------");
        System.out.println("123456: " + passwordEncoder.encode("123456"));
        System.out.println("admin: " + passwordEncoder.encode("admin"));
        System.out.println("root: " + passwordEncoder.encode("root"));
        System.out.println("------------------生成密码结束------------------");
    }

}
