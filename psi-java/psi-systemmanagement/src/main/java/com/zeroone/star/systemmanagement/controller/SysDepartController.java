package com.zeroone.star.systemmanagement.controller;


import com.zeroone.star.project.query.systemmanagement.organizationmanagement.OrganizationListQuery;
import com.zeroone.star.project.systemmanagement.organizationmanagement.OrganizationManagementApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationListVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationTreeVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 * 组织机构表 前端控制器
 * </p>
 *
 * @author Morrangee
 * @since 2023-02-12
 */
@RestController
@RequestMapping("/systemmanagement/sys-depart")
public class SysDepartController implements OrganizationManagementApis {

    @ApiOperation("查询组织结构")
    @GetMapping("/querylist")
    @Override
    public JsonVO<List<OrganizationListVO>> queryList(OrganizationListQuery condition) {
        return null;
    }

    @ApiOperation("查询指定组织结构树")
    @GetMapping("/querytree")
    @Override
    public JsonVO<List<OrganizationTreeVO>> queryTree(String departName) {
        return null;
    }

    @ApiOperation("新增组织结构")
    @GetMapping("/add")
    @Override
    public JsonVO add(OrganizationListVO data) {
        return null;
    }

    @ApiOperation("修改组织结构")
    @GetMapping("/modify")
    @Override
    public JsonVO modify(OrganizationListVO data) {
        return null;
    }

    @ApiOperation("删除组织结构")
    @GetMapping("/delete")
    @Override
    public JsonVO delete(String id) {
        return null;
    }
}

