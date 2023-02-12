package com.zeroone.star.basedetail.controller;

import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @Description
 * @Author 苏乞儿
 * @Date 2023/2/12
 */

@RestController
@RequestMapping("user")
@Api(tags = "用户")
public class UserController {

    @RequestMapping("queryall")
    @ApiOperation("查询所有用户")
    public JsonVO<String> queryAll(){
        return null;
    }
}
