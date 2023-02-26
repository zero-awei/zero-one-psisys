package com.zeroone.star.psisysmanagement.controller;


import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.dto.sysmanagement.permissionmanagement.PermissionDTO;
import com.zeroone.star.project.query.sysmanagement.permissionmanagement.PermissionQuery;
import com.zeroone.star.project.sysmanagement.PermissionApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.permissionmanagement.PermissionVO;
import com.zeroone.star.psisysmanagement.entity.Permission;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * @Author Freasy
 * @Version 1.0
 */
@RestController
@RequestMapping("/sysmanagement/permissionmanagement")
@Api(tags = "系统管理-权限管理接口")
public class PermissionController implements PermissionApis {

    @Resource
    private IPermissionService permissionService;

    @GetMapping("/query")
    @ApiOperation(value = "查询权限")
    @Override
    public JsonVO<PageVO<PermissionVO>> query(PermissionQuery condition) {
        PageVO<PermissionVO> resultPermissions = permissionService.listPermissions(condition);
        return JsonVO.success(resultPermissions);
    }

    @DeleteMapping("/delete")
    @ApiOperation(value = "删除权限")
    @Override
    public JsonVO<String> delete(PermissionDTO permissionInfo) {
        Permission permission = BeanUtil.copyProperties(permissionInfo, Permission.class);
        Boolean result = permissionService.removePermission(permission);
        return result ? JsonVO.success("删除成功") : JsonVO.fail("删除失败");
    }

    @PutMapping("/update")
    @ApiOperation(value = "更新权限信息")
    @Override
    public JsonVO<String> update(PermissionDTO permissionInfo) {
        Permission permission = BeanUtil.copyProperties(permissionInfo, Permission.class);
        Boolean result = permissionService.updatePermission(permission);
        return result ? JsonVO.success("更新成功") : JsonVO.fail("更新失败");
    }

    @PostMapping("/add")
    @ApiOperation(value = "添加权限")
    @Override
    public JsonVO<String> addPermission(PermissionDTO permissionInfo) {
        Permission permission = BeanUtil.copyProperties(permissionInfo, Permission.class);
        Boolean result = permissionService.savePermission(permission);
        return result ? JsonVO.success("添加成功") : JsonVO.fail("添加失败");
    }
}
