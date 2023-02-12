package com.zeroone.star.login.controller;

import com.zeroone.star.project.constant.AuthConstant;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.Map;

/**
 * @author Third uncle
 * @date 2023/2/12 - 16:12
 */
@RestController
@RequestMapping("test")
@Api(tags = "test123")
public class TestController {
    @ApiOperation(value = "test123")
    @PostMapping("auth-login2")
    public JsonVO<Oauth2TokenDTO> authLogin(LoginDTO loginDTO) {

        return null;
    }
}
