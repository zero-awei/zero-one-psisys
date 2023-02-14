package com.zeroone.star.role.controller;

import com.zeroone.star.project.query.role.PermissionQuery;
import com.zeroone.star.project.role.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
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

//    @Resource
    @Resource
    private IPermissionService service;

    @GetMapping("list")
    @ApiOperation(value = "查询角色权限或菜单列表")
    @Override
    public JsonVO<List<PermissionQuery>> showList(int RId) {
        return null;
    }

    @GetMapping("add")
    @ApiOperation(value = "查询角色权限或菜单列表")
    @Override
    public JsonVO<Boolean> addMenuOrJurisdiction(List<PermissionQuery> listMenu) {
        return null;
    }

    @GetMapping("delete")
    @ApiOperation(value = "删除角色权限或菜单列表")
    @Override
    public JsonVO<Boolean> deleteMenuOrJurisdiction(int RId, int MId) {
        return null;
    }
}
