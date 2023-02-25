package com.zeroone.star.psisysmanagement.controller;

import com.zeroone.star.project.query.sysmanagement.rolemanagement.PermissionQuery;
import com.zeroone.star.project.sysmanagement.RolePermissionApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.psisysmanagement.service.IRolePermissionService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

@RestController // 返回类型
@RequestMapping("/sysmanagement/rolemanagement/permission") // 请求前缀
@Api(tags = "系统管理-角色权限管理接口")
public class RolePermissionController implements RolePermissionApis {

    @Resource
    private IRolePermissionService service;

    @GetMapping("/list")
    @ApiOperation(value = "查询权限")
    @Override
    public JsonVO<List<PermissionQuery>> listAll(String RId) {
        List<PermissionQuery> list = service.listAll(RId);
        if (list.size() == 0){
            return JsonVO.fail(list);
        }
        return JsonVO.success(list);
    }

    /**
     * 添加权限
     * @param permissionQuery
     * @return 是否添加成功
     */
    @PostMapping("/add")
    @ApiOperation(value = "新增权限")
    @Override
    public JsonVO<Boolean> savePermission(@Validated PermissionQuery permissionQuery) {
        if (service.savePermission(permissionQuery)){
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    @DeleteMapping("/delete")
    @ApiOperation(value = "删除权限")
    @Override
    public JsonVO<Boolean> deletePermission( String permissionId) {
        if (service.deletePermission(permissionId)){
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }
}
