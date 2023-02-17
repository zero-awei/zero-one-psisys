package com.zeroone.star.psisysmanagement.controller;


import com.zeroone.star.project.dto.sysmanagement.permissionmanagement.PermissionDTO;
import com.zeroone.star.project.query.sysmanagement.permissionmanagement.PermissionQuery;
import com.zeroone.star.project.sysmanagement.PermissionApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.permissionmanagement.PermissionVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

/**
 * @Author Freasy
 * @Version 1.0
 */
@RestController
@RequestMapping("/sysmanagement/permissionmanagement")
@Api(tags = "系统管理-权限管理接口")
public class PermissionController implements PermissionApis {
    @GetMapping("/query-all")
    @ApiOperation(value = "分页查询所有权限数据")
    @Override
    public JsonVO<PageVO<PermissionVO>> queryAll(PermissionQuery condition) {
        return null;
    }

    @GetMapping("/query-condition")
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

    @PutMapping("/update")
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
