package com.zeroone.star.systemmanagement.controller;


import com.zeroone.star.project.query.systemmanagement.organizationmanagement.OrganizationListQuery;
import com.zeroone.star.project.systemmanagement.organizationmanagement.OrganizationManagementApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationListVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationTreeVO;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 组织机构表 前端控制器
 * </p>
 *
 * @author Morrangee
 * @since 2023-02-13
 */
@RestController
@RequestMapping("/systemmanagement/sys-depart")
public class SysDepartController implements OrganizationManagementApis {

    /**
     * 查询组织列表
     * @param condition 查询条件
     * @return
     */
    @Override
    public JsonVO<PageVO<OrganizationListVO>> queryList(OrganizationListQuery condition) {
        return null;
    }

    /**
     * 查询指定结构树
     * @param departName 部门名称
     * @return
     */
    @Override
    public JsonVO<PageVO<OrganizationTreeVO>> queryTree(String departName) {
        return null;
    }

    /**
     * 新增组织结构
     * @param data 数据
     * @return
     */
    @Override
    public JsonVO<String> add(OrganizationListVO data) {
        return null;
    }

    /**
     * 修改组织结构
     * @param data 数据
     * @return
     */
    @Override
    public JsonVO<String> modify(OrganizationListVO data) {
        return null;
    }

    /**
     * 删除组织结构
     * @param id 部门id
     * @return
     */
    @Override
    public JsonVO<String> delete(String id) {
        return null;
    }
}

