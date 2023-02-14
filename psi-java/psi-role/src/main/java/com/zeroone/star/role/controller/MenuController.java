package com.zeroone.star.role.controller;

import com.zeroone.star.project.query.role.MenuQuery;
import com.zeroone.star.project.role.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
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
public class MenuController implements RoleApis<MenuQuery> {

//    @Resource
    @Autowired
    private IMenuService service;

    @GetMapping("list")
    @ApiOperation(value = "查询角色权限或菜单列表")
    @Override
    public JsonVO<List<MenuQuery>> showList(int RId) {

        return JsonVO.success(service.showList(RId));
    }

    @GetMapping("add")
    @ApiOperation(value = "新增角色权限或菜单列表")
    @Override
    public JsonVO<Boolean> addMenuOrJurisdiction(List<MenuQuery> listMenu) {
        return JsonVO.success(service.addMenuOrJurisdiction(listMenu));
    }

    @GetMapping("delete")
    @ApiOperation(value = "删除角色权限或菜单列表")
    @Override
    public JsonVO<Boolean> deleteMenuOrJurisdiction(int RId, int MId) {
        return JsonVO.success(service.deleteMenuOrJurisdiction(RId,MId));
    }
}
