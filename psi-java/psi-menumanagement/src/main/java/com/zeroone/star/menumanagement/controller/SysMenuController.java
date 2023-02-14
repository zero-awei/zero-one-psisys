package com.zeroone.star.menumanagement.controller;


import com.zeroone.star.menumanagement.entity.SysMenu;
import com.zeroone.star.project.dto.menumanagement.MenuDto;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author 归、深夜梦想家 
 * @since 2023-02-14
 */

@Api(tags = "菜单管理")
@RestController
@RequestMapping("/menumanagement/sys-menu")
public class SysMenuController {

    @ResponseBody
    @SneakyThrows
    @ApiOperation(value = "新增菜单")
    @PostMapping("/add")
    public boolean addMenu(SysMenu sysMenu){
        return true;
    }

    @SneakyThrows
    @ApiOperation(value = "修改菜单")
    @PostMapping("/update")
    public boolean updateMenu(int id){
        return true;
    }

    @ResponseBody
    @SneakyThrows
    @ApiOperation(value = "删除菜单")
    @PostMapping("/delete")
    public boolean deleteMenu(int id){
        return true;
    }


    @SneakyThrows
    @ApiOperation(value = "查询菜单")
    @GetMapping("/query")
    public MenuDto queryMenu(int id){
        return new MenuDto();
    }

}

