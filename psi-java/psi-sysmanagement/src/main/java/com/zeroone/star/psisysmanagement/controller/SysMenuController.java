package com.zeroone.star.psisysmanagement.controller;

import com.zeroone.star.project.dto.sysmanagement.menumanagement.MenuDTO;
import com.zeroone.star.project.query.sysmanagement.menumanagement.SingleMenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.sysmanagement.menumanagement.MenuVO;
import com.zeroone.star.psisysmanagement.entity.SysMenu;
import com.zeroone.star.psisysmanagement.service.ISysMenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.awt.*;
import java.util.List;

/**
 * <p>
 * 前端控制器
 * </p>
 *
 * @author 归、深夜梦想家
 * @since 2023-02-14
 */

@Api(tags = "系统管理-菜单管理接口")
@RestController
@RequestMapping("/sysmanagement/menumanagement/sys-menu")
public class SysMenuController {

    @Resource
    private ISysMenuService iSysMenuService;
    @Resource
    private SingleMenuQuery singleMenuQuery;

    @ResponseBody
    @SneakyThrows
    @ApiOperation(value = "新增菜单")
    @PostMapping("/add")
    public JsonVO<String> addMenu(MenuDTO menuDTO) {

        JsonVO<ResultStatus> resultStatus = iSysMenuService.addMenu(menuDTO);

        return resultStatus.getData().getCode() == 9999
                ? JsonVO.create("增加失败", ResultStatus.FAIL)
                : JsonVO.create("新增成功", ResultStatus.SUCCESS);
    }

    @SneakyThrows
    @ApiOperation(value = "修改菜单")
    @PutMapping("/update")
    public JsonVO<String> updateMenu(MenuDTO menuDTO) {

        JsonVO<ResultStatus> resultStatus = iSysMenuService.updateMenu(menuDTO);

        return resultStatus.getData().getCode() == 9999
                ? JsonVO.create("修改失败", ResultStatus.FAIL)
                : JsonVO.create("修改成功", ResultStatus.SUCCESS);
    }

    @ResponseBody
    @SneakyThrows
    @ApiOperation(value = "删除菜单")
    @DeleteMapping("/delete")
    public JsonVO<String> deleteMenu(int id) {

        singleMenuQuery.setId(String.valueOf(id));
        JsonVO<ResultStatus> resultStatus = iSysMenuService.deleteMenu(singleMenuQuery);

        return resultStatus.getData().getCode() == 9999
                ? JsonVO.create("删除失败", ResultStatus.FAIL)
                : JsonVO.create("删除成功", ResultStatus.SUCCESS);
    }


    @SneakyThrows
    @ApiOperation(value = "查询菜单")
    @GetMapping("/query")
    public JsonVO<MenuVO> queryMenu(int id) {

        SingleMenuQuery singleMenuQuery = new SingleMenuQuery();
        singleMenuQuery.setId(String.valueOf(id));

        return iSysMenuService.querySingle(singleMenuQuery);
    }

}

