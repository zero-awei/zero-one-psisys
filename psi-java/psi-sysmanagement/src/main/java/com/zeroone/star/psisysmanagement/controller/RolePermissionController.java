package com.zeroone.star.psisysmanagement.controller;

import com.zeroone.star.project.query.sysmanagement.rolemanagement.PermissionQuery;
import com.zeroone.star.project.sysmanagement.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.psisysmanagement.service.IPermissionService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;


/**
*
* @Author:阿狸
* @Version:1.1
*/
@RestController // 返回类型
@RequestMapping("/sysmanagement/rolemanagement/permission") // 请求前缀
@Api(tags = "系统管理-角色权限管理接口")
public class RolePermissionController implements RoleApis<PermissionQuery> {

    @Autowired
    private IPermissionService service;

    /**
     * 查询角色权限
     * @param RId
     * @return 角色的含有的相关权限列表
     */
    @GetMapping("/list")
    @ApiOperation(value = "查询权限")
    @Override
    public JsonVO<List<PermissionQuery>> listAll(String RId) {

        return JsonVO.success(service.listAll(RId));
    }

    /**
     * 添加权限
     * @param permission
     * @return 是否添加成功
     */
    @PostMapping("/add")
    @ApiOperation(value = "新增权限")
    @Override
    public JsonVO<Boolean> saveMenuOrPermission(PermissionQuery permission) {
        return JsonVO.success(service.saveMenuOrPermission(permission));
    }

    /**
     * 删除权限
     * @param permissionId
     * @return 权限是否删除成功
     */
    @DeleteMapping("/delete")
    @ApiOperation(value = "删除权限")
    @Override
    public JsonVO<Boolean> deleteMenuOrPermission(String permissionId) {
        return JsonVO.success(service.deleteMenuOrPermission(permissionId));
    }
}
