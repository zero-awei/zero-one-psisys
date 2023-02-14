package com.zeroone.star.user.controller;

import com.zeroone.star.project.dto.user.UserDTO;
import com.zeroone.star.project.query.user.UserQuery;
import com.zeroone.star.project.user.UserApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.user.UserVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.util.List;

@Slf4j
@RestController
@RequestMapping("/user")
@Api(tags = "用户管理示例接口")
@Validated
public class UserController implements UserApis {

    @ApiOperation(value = "查询用户列表")
    @GetMapping("list-all")
    @Override
    public JsonVO<PageVO<UserVO>> listAllUsers(@Validated UserQuery query) {
        return null;
    }

    @ApiOperation(value = "查询用户")
    @GetMapping("query-user")
    @Override
    public JsonVO<PageVO<UserVO>> queryUser(@Validated UserQuery query) {
        return null;
    }

    @ApiOperation(value = "用户信息回显")
    @GetMapping("review")
    @Override
    public JsonVO<UserVO> review(@NotBlank(message = "id 不能为空") @RequestParam String id) {
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
    public JsonVO<String> deleteUser(@NotBlank(message = "id 不能为空") @RequestParam String id) {
        log.info("id = {}", id);
        return JsonVO.success("删除成功");
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
    public JsonVO<String> modifyStatus(@NotBlank(message = "id 不能为空") @RequestParam String id) {
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