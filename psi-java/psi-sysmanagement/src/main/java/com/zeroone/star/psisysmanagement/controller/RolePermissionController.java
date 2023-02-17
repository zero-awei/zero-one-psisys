package com.zeroone.star.psisysmanagement.controller;

import com.zeroone.star.project.query.sysmanagement.rolemanagement.PermissionQuery;
import com.zeroone.star.project.sysmanagement.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.psisysmanagement.service.IPermissionService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

@RestController // 返回类型
@RequestMapping("/sysmanagement/rolemanagement/permission") // 请求前缀
@Api(tags = "系统管理-角色权限管理接口")
public class RolePermissionController implements RoleApis<PermissionQuery> {

    @Resource
    private IPermissionService service;

    @GetMapping("/list")
    @ApiOperation(value = "查询权限")
    @Override
    public JsonVO<List<PermissionQuery>> showList(String RId) {

        return JsonVO.success(service.showList(RId));
    }

    @PostMapping("/add")
    @ApiOperation(value = "新增权限")
    @Override
    public JsonVO<Boolean> addMenuOrPermission(PermissionQuery permission) {
        return JsonVO.success(service.addMenuOrPermission(permission));
    }

    @DeleteMapping("/delete")
    @ApiOperation(value = "删除权限")
    @Override
    public JsonVO<Boolean> deleteMenuOrPermission(String Id) {
        return JsonVO.success(service.deleteMenuOrPermission(Id));
    }
}
