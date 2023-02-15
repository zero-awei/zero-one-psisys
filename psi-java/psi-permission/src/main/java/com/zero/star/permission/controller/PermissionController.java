package com.zero.star.permission.controller;

import com.zeroone.star.project.dto.permission.PermissionDTO;
import com.zeroone.star.project.permission.PermissionApis;
import com.zeroone.star.project.query.permission.PermissionQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.permission.PermissionVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @Author Freasy
 * @Version 1.0
 */
@RestController
@RequestMapping("/permission")
@Api(tags = "权限接口")
public class PermissionController implements PermissionApis {
    @PostMapping("/query-all")
    @ApiOperation(value = "分页查询所有权限数据")
    @Override
    public JsonVO<PageVO<PermissionVO>> queryAll(PermissionQuery condition) {
        return null;
    }

    @PostMapping("query-condition")
    @ApiOperation(value = "分页查询符合条件的权限")
    @Override
    public JsonVO<PageVO<PermissionVO>> queryByCondition(PermissionQuery condition) {
        return null;
    }

    @DeleteMapping("/delete")
    @ApiOperation(value = "删除权限")
    @Override
    public JsonVO<String> delete(PermissionDTO permissionInfo) {
        return null;
    }

    @PostMapping("/update")
    @ApiOperation(value = "更新权限信息")
    @Override
    public JsonVO<String> update(PermissionDTO permissionInfo) {
        return null;
    }

    @PostMapping("/add")
    @ApiOperation(value = "添加权限")
    @Override
    public JsonVO<String> addPermission(PermissionDTO permissionInfo) {
        return null;
    }
}
