package com.zeroone.star.psisysmanagement.controller;


import com.zeroone.star.project.dto.sysmanagement.rolemanagement.SysRoleDTO;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.SysRoleQuery;
import com.zeroone.star.project.sysmanagement.RoleManagementApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.rolemanagement.SysRoleVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.*;

/**
 * @author Gerins
 * @since 2023-02-16
 */
@Api(tags = "系统管理-角色管理接口")
@RestController
@RequestMapping("/sysmanagement/rolemanagement")
public class SysRoleController implements RoleManagementApis {

    @ApiOperation(value = "分页查询角色信息")
    @GetMapping("/query-all")
    @Override
    public JsonVO<PageVO<SysRoleVO>> queryAll(SysRoleQuery condition) {
        return null;
    }

    @Transactional
    @ApiOperation(value = "修改角色信息")
    @PutMapping("/update")
    @Override
    public JsonVO<String> updateById(SysRoleDTO sysRoleDTO) {
        return null;
    }

    @Transactional
    @ApiOperation(value = "新增角色")
    @PostMapping("/insert")
    @Override
    public JsonVO<String> insert(SysRoleDTO sysRoleDTO) {
        return null;
    }

    @Transactional
    @ApiOperation(value = "删除角色")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<String> deleteById(String id) {
        return null;
    }
}

