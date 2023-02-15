package com.zeroone.star.role.controller;

import com.zeroone.star.project.query.role.MenuQuery;
import com.zeroone.star.project.role.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.role.entity.SysMenu;
import com.zeroone.star.role.service.IMenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;


@RestController // 返回类型
@RequestMapping("menu") // 请求前缀
@Api(tags = "角色菜单管理接口")
public class MenuController  implements RoleApis<MenuQuery> {

//    @Resource
    private IMenuService service;

    @GetMapping("list")
    @ApiOperation(value = "查询菜单")
    @Override
    public JsonVO<List<MenuQuery>> showList(String RId) {

        return JsonVO.success(service.showList(RId));
    }

    @GetMapping("add")
    @ApiOperation(value = "新增菜单")
    @Override
    public JsonVO<Boolean> addMenuOrPermission(MenuQuery menu) {
        return JsonVO.success(service.addMenuOrPermission(menu));
    }

    @GetMapping("delete")
    @ApiOperation(value = "删除菜单")
    @Override
    public JsonVO<Boolean> deleteMenuOrPermission(String Id) {
        return JsonVO.success(service.deleteMenuOrPermission(Id));
    }
}
