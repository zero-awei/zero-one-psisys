package com.zeroone.star.psisysmanagement.controller;

import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.EditUserDTO;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.UserDTO;
import com.zeroone.star.project.query.sysmanagement.usermanagement.FindUserQuery;
import com.zeroone.star.project.query.sysmanagement.usermanagement.UserQuery;
import com.zeroone.star.project.sysmanagement.UserApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.AddUserVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.EditUserVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.UserVO;
import com.zeroone.star.psisysmanagement.entity.User;
import com.zeroone.star.psisysmanagement.service.IUserService;
import io.swagger.annotations.*;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.NotNull;
import java.io.ByteArrayOutputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

@Slf4j
@RestController
@RequestMapping("/sysmanagement/usermanagement")
@Api(tags = "系统管理-用户管理接口")
@Validated
public class UserController implements UserApis {

    @Resource
    IUserService userService;

    @ApiOperation(value = "查询用户列表")
    @GetMapping("/list-all")
    @Override
    public JsonVO<PageVO<UserVO>> listAllUsers(@Validated UserQuery query) {
        return null;
    }

    @ApiOperation(value = "查询用户")
    @GetMapping("/query-user")
    @Override
    public JsonVO<PageVO<UserVO>> queryUser(@Validated FindUserQuery query) {
        return null;
    }

    @ApiOperation(value = "修改用户时的信息回显")
    @GetMapping("/review")
    @Override
    public JsonVO<EditUserVO> review(@NotBlank(message = "id 不能为空") @RequestParam String id) {
        return null;
    }

    @ApiOperation(value = "添加用户")
    @PostMapping("/add")
    @Override
    public JsonVO<String> addUser(UserDTO dto) {
        return null;
    }

    @ApiOperation(value = "删除用户")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<String> deleteUser(@NotBlank(message = "id 不能为空") @RequestParam String id) {
        boolean success = userService.removeById(id);
        if (success) {
            return JsonVO.success("删除成功");
        }
        return JsonVO.fail("请勿重复删除");
    }

    @ApiOperation(value = "修改用户")
    @PutMapping("/modify")
    @Override
    public JsonVO<String> modifyUser(EditUserDTO dto) {
        userService.modifyUser(dto);
        return null;
    }

    @ApiOperation(value = "冻结/解冻用户")
    @ApiImplicitParams(value = {
            @ApiImplicitParam(name = "id", value = "用户id",dataType = "String", required = true),
            @ApiImplicitParam(name = "status", value = "状态码(1为正常/2为冻结)",dataType = "String", required = true)
    })
    @PutMapping("/status")
    @Override
    public JsonVO<String> modifyStatus(
            @NotBlank(message = "id不能为空") @RequestParam String id,
            @NotNull(message = "状态不能为空") @RequestParam Integer status) {
        userService.updateStatus(id, status);
        return JsonVO.success("修改用户状态成功");
    }

    @ApiOperation(value = "导入用户")
    @PostMapping("/upload")
    @Override
    public JsonVO<String> upload() {
        return null;
    }

    @SneakyThrows
    @ApiOperation(value = "导出用户")
    @ApiImplicitParams(value = {
            @ApiImplicitParam(name = "ids", value = "用户id(多选)", allowMultiple = true, dataType = "String",required = true),
    })
    @GetMapping(value = "/get-user", produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> download(
            @NotEmpty(message = "导出用户必须大于0")
            @RequestParam(value = "ids") List<String> ids) {
        List<User> users = userService.listByIds(ids);
        return userService.getExcel(users);
    }

    @SneakyThrows
    @ApiOperation(value = "导出所有用户")
    @GetMapping(value = "/get-users", produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> downloadAllUsers() {
        List<User> users = userService.list();
        return userService.getExcel(users);
    }

    @ApiOperation(value = "下拉框获取部门列表")
    @GetMapping("/list-depart")
    @Override
    public JsonVO<List<AddUserVO>> listDepartment() {
        return null;
    }

}