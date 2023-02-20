package com.zeroone.star.psisysmanagement.controller;


import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.sysmanagement.rolemanagement.SysRoleDTO;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.SysRoleQuery;
import com.zeroone.star.project.sysmanagement.RoleManagementApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.rolemanagement.SysRoleVO;
import com.zeroone.star.psisysmanagement.entity.SysRole;
import com.zeroone.star.psisysmanagement.service.ISysRoleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * 系统管理-用户管理模块
 * 前端控制器
 * @author Gerins
 * @since 2023-02-16
 */
@Api(tags = "系统管理-角色管理接口")
@RestController
@RequestMapping("/sysmanagement/rolemanagement")
public class SysRoleController implements RoleManagementApis {

    @Resource
    ISysRoleService roleService;

    @ApiOperation(value = "分页查询角色信息")
    @GetMapping("/query-all")
    @Override
    public JsonVO<PageVO<SysRoleVO>> queryAll(SysRoleQuery condition) {
        return JsonVO.success(roleService.listAll(condition));
    }

    @Transactional
    @ApiOperation(value = "修改角色信息")
    @PutMapping("/update")
    @Override
    public JsonVO<String> updateById(@RequestBody SysRoleDTO sysRoleDTO) {
        Boolean isModify = roleService.modify(sysRoleDTO);
        if (isModify == true) {
            return JsonVO.success("修改成功！");
        }
        return JsonVO.fail("修改失败！");
    }

    @Transactional
    @ApiOperation(value = "新增角色")
    @PostMapping("/insert")
    @Override
    public JsonVO<String> insert(@RequestBody SysRoleDTO sysRoleDTO) {
        Boolean isSave = roleService.save(sysRoleDTO);
        if (isSave == true) {
            return JsonVO.success("新增成功！");
        }
        return JsonVO.fail("新增失败！");
    }

    @Transactional(rollbackFor = Exception.class, isolation = Isolation.REPEATABLE_READ, timeout = 600)
    @ApiOperation(value = "删除角色")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<String> deleteById(@RequestBody String ids[]) {
        Boolean isRemove = roleService.remove(ids);
        if (isRemove == true) {
            return JsonVO.success("删除成功！");
        }
        return JsonVO.fail("删除失败！");
    }
}

