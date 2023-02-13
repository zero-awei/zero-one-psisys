package com.zeroone.star.user.controller;


import com.zeroone.star.project.dto.user.UserDTO;
import com.zeroone.star.project.query.user.UserQuery;
import com.zeroone.star.project.user.UserApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.user.UserVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * <p>
 * 用户表 前端控制器
 * </p>
 *
 * @author axin
 * @since 2023-02-12
 */
@RestController
@RequestMapping("/user/sys-user")
public class UserController implements UserApis {

    @ApiOperation(value = "查询用户列表")
    @GetMapping("list-all")
    @Override
    public JsonVO<PageVO<UserVO>> listAllUsers(UserQuery query) {
        return null;
    }

    @ApiOperation(value = "查询用户")
    @GetMapping("query-user")
    @Override
    public JsonVO<PageVO<UserVO>> queryUser(UserQuery query) {
        return null;
    }

    @ApiOperation(value = "用户信息回显")
    @GetMapping("echo")
    @Override
    public JsonVO<UserVO> echo(String id) {
        return null;
    }


    @ApiOperation(value = "添加用户")
    @PostMapping("add")
    @Override
    public JsonVO<String> addUser(UserDTO dto) {
        return null;
    }

    @ApiOperation(value = "删除用户")
    @DeleteMapping("delete")
    @Override
    public JsonVO<String> deleteUser(String id) {
        return null;
    }

    @ApiOperation(value = "修改用户")
    @PutMapping("modify")
    @Override
    public JsonVO<String> modifyUser(UserDTO dto) {
        return null;
    }

    @ApiOperation(value = "冻结/解冻用户")
    @PutMapping("status")
    @Override
    public JsonVO<String> modifyStatus(String id) {
        return null;
    }

    @ApiOperation(value = "导入用户")
    @GetMapping("upload")
    @Override
    public JsonVO<String> upload() {
        return null;
    }

    @ApiOperation(value = "导出用户")
    @GetMapping(value = "get-user")
    @Override
    public JsonVO<String> download(List<String> id) {
        return null;
    }

    @ApiOperation(value = "导出所有用户")
    @GetMapping(value = "get-users")
    @Override
    public JsonVO<String> downloadAllUsers() {
        return null;
    }
}

