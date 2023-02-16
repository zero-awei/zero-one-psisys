package com.zeroone.star.role.controller;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.PermissionQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;

import javax.annotation.Resource;

public abstract class RoleController<T,S extends IService<T>> {

    @Autowired
    protected S service;

    @GetMapping("add")
    @ApiOperation(value = "新增权限")
    public abstract JsonVO<Boolean> addMenuOrPermission(PermissionQuery permission);
}
