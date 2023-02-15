package com.zeroone.star.role.controller;

import com.zeroone.star.project.query.role.PermissionQuery;
import com.zeroone.star.project.role.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.role.entity.SysPermission;
import com.zeroone.star.role.service.IPermissionService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

@RestController // 返回类型
@RequestMapping("permission") // 请求前缀
@Api(tags = "角色权限管理接口")
public class PermissionController implements RoleApis<PermissionQuery> {

    @Resource
    private IPermissionService service;

    @GetMapping("list")
    @ApiOperation(value = "查询权限")
    @Override
    public JsonVO<List<PermissionQuery>> showList(String RId) {
        return JsonVO.success(service.showList(RId));
    }

    @GetMapping("add")
    @ApiOperation(value = "新增权限")
    @Override
    public JsonVO<Boolean> addMenuOrPermission(PermissionQuery permission) {
        return JsonVO.success(service.addMenuOrPermission(permission));
    }

    @GetMapping("delete")
    @ApiOperation(value = "删除权限")
    @Override
    public JsonVO<Boolean> deleteMenuOrPermission(String Id) {
        return JsonVO.success(service.deleteMenuOrPermission(Id));
    }
}
