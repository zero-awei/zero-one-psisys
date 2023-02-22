package com.zeroone.star.psisysmanagement.controller;

import com.zeroone.star.project.query.sysmanagement.rolemanagement.MenuQuery;
import com.zeroone.star.project.sysmanagement.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.psisysmanagement.service.IMenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;


/**
*
* @Author:阿狸
* @Version:1.1
*/
@RestController // 返回类型
@RequestMapping("/sysmanagement/rolemanagement/menu") // 请求前缀
@Api(tags = "系统管理-角色菜单管理接口")
@Validated
public class RoleMenuController implements RoleApis<MenuQuery> {

    @Resource
    private IMenuService service;

    /**
     * 查询角色菜单
     * @param RId
     * @return 角色的含有的相关菜单列表
     */
    @GetMapping("/list")
    @ApiOperation(value = "查询菜单")
    @Override
    public JsonVO<List<MenuQuery>> listAll(String RId) {
        return JsonVO.success(service.listAll(RId));
    }


    /**
     * 添加菜单
     * @param menu
     * @return 菜单是否添加成功
     */
    @PostMapping("/add")
    @ApiOperation(value = "新增菜单")
    @Override
    public JsonVO<Boolean> saveMenuOrPermission(MenuQuery menu) {
        return JsonVO.success(service.saveMenuOrPermission(menu));
    }

    /**
     * 删除菜单
     * @param Id
     * @return 菜单是否删除成功
     */
    @DeleteMapping("/delete")
    @ApiOperation(value = "删除菜单")
    @Override
    public JsonVO<Boolean> deleteMenuOrPermission(String Id) {
        return JsonVO.success(service.deleteMenuOrPermission(Id));
    }

}
