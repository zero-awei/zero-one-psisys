package com.zeroone.star.project.systemmanagement.organizationmanagement;

import com.zeroone.star.project.query.systemmanagement.organizationmanagement.OrganizationListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationListVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationTreeVO;
import springfox.documentation.spring.web.json.Json;

/**
 *
 */
public interface OrganizationManagementApis {

    /**
     * 查询组织列表
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<OrganizationListVO>> queryList(OrganizationListQuery condition);

    /**
     * 查询指定组织结构树
     * @param departName 部门名称
     * @return
     */
    JsonVO<PageVO<OrganizationTreeVO>> queryTree(String departName);

    /**
     * 新增组织结构
     *
     * @param data 数据
     * @return
     */
    JsonVO<String> add(OrganizationListVO data);

    /**
     * 修改组织结构
     * @param data 数据
     * @return
     */
    JsonVO<String> modify(OrganizationListVO data);

    /**
     * 删除指定组织结构
     *
     * @param id 部门id
     * @return
     */
    JsonVO<String> delete(String id);

}
