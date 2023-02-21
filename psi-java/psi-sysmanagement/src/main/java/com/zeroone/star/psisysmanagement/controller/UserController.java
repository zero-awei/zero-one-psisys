package com.zeroone.star.psisysmanagement.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.EditUserDTO;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.UserDTO;
import com.zeroone.star.project.query.sysmanagement.usermanagement.FindUserQuery;
import com.zeroone.star.project.query.sysmanagement.usermanagement.UserQuery;
import com.zeroone.star.project.sysmanagement.UserApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.AddUserVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.EditUserVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.UserVO;
import com.zeroone.star.psisysmanagement.entity.User;
import com.zeroone.star.psisysmanagement.service.IUserService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParams;
import io.swagger.annotations.ApiOperation;
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


/**
 * <p>
 * 用户表 控制层
 * </p>
 *
 * @author axin
 * @since 2023-02-18
 */

@Slf4j
@RestController
@RequestMapping("/sysmanagement/usermanagement")
@Api(tags = "系统管理-用户管理接口")
@Validated
public class UserController implements UserApis {

    @Resource
    EasyExcelComponent excel;

    @Resource
    private IUserService iUserService;

    //    axin
    @ApiOperation(value = "查询用户列表")
    @GetMapping("/list-all")
    @Override
    public JsonVO<PageVO<UserVO>> listAllUsers(@Validated UserQuery query) {
        return JsonVO.success(iUserService.listAllUsers(query));
    }

    //    axin
    @ApiOperation(value = "模糊查询用户")
    @GetMapping("/query-user")
    @Override
    public JsonVO<PageVO<UserVO>> listUser(@Validated FindUserQuery query) {
        return JsonVO.success(iUserService.listUser(query));
    }

    // dan
    @ApiOperation(value = "修改用户时的信息回显")
    @GetMapping("/review")
    @Override
    public JsonVO<EditUserVO> review(@NotBlank(message = "id 不能为空") @RequestParam String id) {
        EditUserVO editUserVO = iUserService.getUserInfo(id);
        return JsonVO.create(editUserVO, ResultStatus.SUCCESS);
    }

    //    axin
    @ApiOperation(value = "添加用户")
    @PostMapping("/add")
    @Override
    public JsonVO<String> addUser(UserDTO dto) {
        return JsonVO.success("添加成功");
    }

    // dan
    @ApiOperation(value = "删除用户")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<String> deleteUser(@NotBlank(message = "id 不能为空") @RequestParam String id) {
        iUserService.removeById(id);
        return JsonVO.success("删除成功");
    }

    // dan
    @ApiOperation(value = "修改用户")
    @PutMapping("/modify")
    @Override
    public JsonVO<String> modifyUser(@Validated EditUserDTO dto) {
        iUserService.updateUser(dto);
        return JsonVO.success("修改成功");
    }

    // dan
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
        iUserService.updateStatus(id, status);
        return JsonVO.success("修改用户状态成功");
    }

    @ApiOperation(value = "导入用户")
    @PostMapping("/upload")
    @Override
    public JsonVO<String> upload() {
        return JsonVO.success("导入成功");
    }

    //    axin
    @SneakyThrows
    @ApiOperation(value = "导出用户")
    @GetMapping(value = "/get-user", produces = "application/octet-stream")
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

    // dan
//    @SneakyThrows
//    @ApiOperation(value = "导出用户")
//    @ApiImplicitParams(value = {
//            @ApiImplicitParam(name = "ids", value = "用户id(多选)", allowMultiple = true, dataType = "String",required = true),
//    })
//    @GetMapping(value = "/get-user", produces = "application/octet-stream")
//    @Override
//    public ResponseEntity<byte[]> download(
//            @NotEmpty(message = "导出用户必须大于0")
//            @RequestParam(value = "ids") List<String> ids) {
//        List<User> users = iUserService.listByIds(ids);
//        return iUserService.getExcel(users);
//    }

    // dan
    @SneakyThrows
    @ApiOperation(value = "导出所有用户")
    @GetMapping(value = "/get-users", produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> downloadAllUsers() {
        List<User> users = iUserService.list();
        return iUserService.getExcel(users);
    }

    @ApiOperation(value = "下拉框获取部门列表")
    @GetMapping("/list-depart")
    @Override
    public JsonVO<List<AddUserVO>> listDepartment() {
        return null;
    }
}