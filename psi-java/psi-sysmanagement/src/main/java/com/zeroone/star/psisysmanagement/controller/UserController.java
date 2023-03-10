package com.zeroone.star.psisysmanagement.controller;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.read.listener.PageReadListener;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.AddUserDTO;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.EditUserDTO;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.UserDTO;
import com.zeroone.star.project.query.sysmanagement.usermanagement.FindUserQuery;
import com.zeroone.star.project.query.sysmanagement.usermanagement.UserQuery;
import com.zeroone.star.project.sysmanagement.UserApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.AddUserVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.DepartVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.EditUserVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.UserVO;
import com.zeroone.star.psisysmanagement.entity.User;
import com.zeroone.star.psisysmanagement.service.DepartService;
import com.zeroone.star.psisysmanagement.service.IUserService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParams;
import io.swagger.annotations.ApiOperation;
import io.swagger.models.auth.In;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.apache.poi.ss.formula.functions.T;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;
import springfox.documentation.spring.web.json.Json;

import javax.annotation.Resource;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.NotNull;
import java.io.ByteArrayOutputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;


/**
 * <p>
 * ????????? ?????????
 * </p>
 *
 * @author axin
 * @since 2023-02-18
 */

@Slf4j
@RestController
@RequestMapping("/sysmanagement/usermanagement")
@Api(tags = "????????????-??????????????????")
@Validated
public class UserController implements UserApis {

    @Resource
    private DepartService departService;

    @Resource
    private IUserService iUserService;

    //    axin
    @ApiOperation(value = "??????????????????")
    @GetMapping("/list-all")
    @Override
    public JsonVO<PageVO<UserVO>> listAllUsers(@Validated UserQuery query) {
        return JsonVO.success(iUserService.listAllUsers(query));
    }

    //    axin
    @ApiOperation(value = "??????????????????")
    @GetMapping("/query-user")
    @Override
    public JsonVO<PageVO<UserVO>> listUser(@Validated FindUserQuery query) {
        return JsonVO.success(iUserService.listUser(query));
    }

    // dan
    @ApiOperation(value = "??????????????????????????????")
    @GetMapping("/review")
    @Override
    public JsonVO<EditUserVO> review(@NotBlank(message = "id ????????????") @RequestParam String id) {
        return JsonVO.success(iUserService.getUserInfo(id));
    }

    //    axin
    @ApiOperation(value = "????????????")
    @PostMapping("/add")
    @Override
    public JsonVO<String> addUser(@Validated AddUserDTO dto) {
        iUserService.saveUser(dto);
        return JsonVO.success("????????????");
    }

    // dan
    @ApiOperation(value = "????????????")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<String> deleteUser(@NotBlank(message = "id ????????????") @RequestParam String id) {
        if (iUserService.removeById(id)) return JsonVO.success("????????????");
        return JsonVO.fail("????????????");
    }

    // dan
    @ApiOperation(value = "????????????")
    @PutMapping("/modify")
    @Override
    public JsonVO<String> modifyUser(@Validated EditUserDTO dto) {
        if (iUserService.updateUser(dto)) return JsonVO.success("????????????");
        return JsonVO.fail("????????????");
    }

    // dan
    @ApiOperation(value = "??????/????????????")
    @ApiImplicitParams(value = {
            @ApiImplicitParam(name = "id", value = "??????id",dataType = "String", required = true),
            @ApiImplicitParam(name = "status", value = "?????????(1?????????/2?????????)",dataType = "String", required = true)
    })
    @PutMapping("/status")
    @Override
    public JsonVO<String> modifyStatus(
            @NotBlank(message = "id????????????") @RequestParam String id,
            @NotNull(message = "??????????????????") @RequestParam Integer status) {
        if (iUserService.updateStatus(id, status)) return JsonVO.success("????????????????????????");
        return JsonVO.fail("????????????");
    }

    @SneakyThrows
    @ApiOperation(value = "????????????")
    @PostMapping("/upload")
    @Override
    public JsonVO<String> upload(MultipartFile file) {
        if (file.isEmpty()) return JsonVO.fail("????????????????????????!");
        iUserService.saveUsers(file);
        return JsonVO.success("????????????");
    }

    // dan
    @SneakyThrows
    @ApiOperation(value = "????????????")
    @ApiImplicitParams(value = {
            @ApiImplicitParam(name = "ids", value = "??????id(??????)", allowMultiple = true, dataType = "String",required = true),
    })
    @GetMapping(value = "/get-user", produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> download(
            @NotEmpty(message = "????????????????????????0")
            @RequestParam(value = "ids") List<String> ids) {
        List<User> users = iUserService.listByIds(ids);
        return iUserService.getExcel(users);
    }

    // dan
    @SneakyThrows
    @ApiOperation(value = "??????????????????")
    @GetMapping(value = "/get-users", produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> downloadAllUsers() {
        List<User> users = iUserService.list();
        return iUserService.getExcel(users);
    }

    @ApiOperation(value = "???????????????????????????")
    @GetMapping("/list-depart")
    @Override
    public JsonVO<List<DepartVO>> listDepartment() {
        return JsonVO.success(departService.listDeparts());
    }

}