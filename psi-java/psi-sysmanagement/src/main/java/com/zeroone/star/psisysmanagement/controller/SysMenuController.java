package com.zeroone.star.psisysmanagement.controller;

import com.zeroone.star.project.dto.sysmanagement.menumanagement.MenuDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.psisysmanagement.entity.SysMenu;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author 归、深夜梦想家 
 * @since 2023-02-14
 */

@Api(tags = "系统管理-菜单管理接口")
@RestController
@RequestMapping("/sysmanagement/menumanagement/sys-menu")
public class SysMenuController {

    @ResponseBody
    @SneakyThrows
    @ApiOperation(value = "新增菜单")
    @PostMapping("/add")
    public JsonVO<String> addMenu(SysMenu sysMenu){
        return JsonVO.create("新增成功", ResultStatus.SUCCESS);
    }

    @SneakyThrows
    @ApiOperation(value = "修改菜单")
    @PutMapping("/update")
    public JsonVO<String> updateMenu(int id){
        return JsonVO.create("修改成功", ResultStatus.SUCCESS);
    }

    @ResponseBody
    @SneakyThrows
    @ApiOperation(value = "删除菜单")
    @DeleteMapping("/delete")
    public JsonVO<String> deleteMenu(int id){
        return JsonVO.create("删除成功", ResultStatus.SUCCESS);
    }


    @SneakyThrows
    @ApiOperation(value = "查询菜单")
    @GetMapping("/query")
    public MenuDTO queryMenu(int id){
        return new MenuDTO();
    }

}

