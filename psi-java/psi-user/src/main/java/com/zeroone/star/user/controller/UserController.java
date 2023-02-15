package com.zeroone.star.user.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.user.UserDTO;
import com.zeroone.star.project.query.user.FindUserQuery;
import com.zeroone.star.project.query.user.UserQuery;
import com.zeroone.star.project.user.UserApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.user.AddUserVO;
import com.zeroone.star.project.vo.user.EditUserVO;
import com.zeroone.star.project.vo.user.UserVO;
import com.zeroone.star.user.entity.User;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.NotNull;
import java.nio.charset.StandardCharsets;
import java.util.List;
import java.io.ByteArrayOutputStream;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;

@Slf4j
@RestController
@RequestMapping("/user")
@Api(tags = "用户管理示例接口")
@Validated
public class UserController implements UserApis {

    @Resource
    EasyExcelComponent excel;

    @ApiOperation(value = "查询用户列表")
    @GetMapping("list-all")
    @Override
    public JsonVO<PageVO<UserVO>> listAllUsers(@Validated UserQuery query) {
        return null;
    }

    @ApiOperation(value = "查询用户")
    @GetMapping("query-user")
    @Override
    public JsonVO<PageVO<UserVO>> queryUser(@Validated FindUserQuery query) {
        return null;
    }

    @ApiOperation(value = "修改用户时的信息回显")
    @GetMapping("review")
    @Override
    public JsonVO<EditUserVO> review(@NotBlank(message = "id 不能为空") @RequestParam String id) {
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

    @SneakyThrows
    @ApiOperation(value = "导出用户")
    @GetMapping(value = "download", produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> download(@NotEmpty(message = "导出用户必须大于0") @RequestParam(value = "id") List<String> id) {
        log.info("id = {}", id);
        List<User> users = new ArrayList<>();
        for (int i = 1; i <= 50; i++) {
            User u = new User();
            u.setId(i + "");
            u.setUsername("用户" + i);
            u.setPhone("1234567" + i);
            users.add(u);
        }
        // 导出Excel
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("测试", out, User.class, users);
        // 创建响应头
        HttpHeaders headers = new HttpHeaders();
        // 构建一个下载的文件名称
        String fileName = "test-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        fileName = new String(fileName.getBytes(StandardCharsets.UTF_8), StandardCharsets.ISO_8859_1);
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;
    }

    @ApiOperation(value = "导出所有用户")
    @GetMapping(value = "download-all", produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> downloadAllUsers() {
        return null;
    }

    @ApiOperation(value = "下拉框获取部门列表")
    @GetMapping("list-depart")
    @Override
    public JsonVO<List<AddUserVO>> listDepartment() {
        return null;
    }
}