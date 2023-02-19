package com.zeroone.star.psisysmanagement.controller;

import com.zeroone.star.project.query.sysmanagement.rolemanagement.MenuQuery;
import com.zeroone.star.project.sysmanagement.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.psisysmanagement.service.IMenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.validation.constraints.NotBlank;
import java.util.List;


@RestController // 返回类型
@RequestMapping("/sysmanagement/rolemanagement/menu") // 请求前缀
@Api(tags = "系统管理-角色菜单管理接口")
@Validated
public class RoleMenuController implements RoleApis<MenuQuery> {

    @Autowired
    private IMenuService service;

    @GetMapping("/list")
    @ApiOperation(value = "查询菜单")
    @Override
    public JsonVO<List<MenuQuery>> showList(String RId) {
        return JsonVO.success(service.showList(RId));
    }



    @PostMapping("/add")
    @ApiOperation(value = "新增菜单")
    @Override
    public JsonVO<Boolean> addMenuOrPermission( MenuQuery menu) {
        return JsonVO.success(service.addMenuOrPermission(menu));
    }

    @DeleteMapping("/delete")
    @ApiOperation(value = "删除菜单")
    @Override
    public JsonVO<Boolean> deleteMenuOrPermission( String Id) {
        return JsonVO.success(service.deleteMenuOrPermission(Id));
    }

}
